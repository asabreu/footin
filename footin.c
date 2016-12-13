/* standard includes */
#include <stdio.h>
#include <string.h>

/* application includes */
#include "action.h"
#include "display.h"
#include "storage.h"

/* forward declaration */
void wipeData();

int main(int argc, char *argv[])
{
	// get actiuon type from command line arguments
	enum actionType action = getActionType(argc, argv);

	// Check if code argument is valid
	if (action == Add || action == Remove) {
		char *code = argv[2];
		if (strlen(code) != 2 && strlen(code) != 3) { // only accept iso code with 2 or 3 chars
			action = Help;
		}	
	}

	// initialize countries and stats if action requires it 
	if (action != Wipe && action != Help) {
		// initialize countries
		initCountries();

		// initialize stats
		initStats();

		/* load and process stored data */
		int count = db_count();
		char ** keys = db_allKeys(count);
		if (keys != NULL) {
			for (int i = 0; i < count; i++) {
				 // find country by code
				struct country_st * country = findCountry(keys[i]);
				if (country != NULL) {
					addCountryStats(country);
				}
			}
		}	
	}

	// process action
	switch (action) {
		case Display:
			displayStatsWithDetail(false);	
			break;

		case Add:
		case Remove: 
		{
			// find country by code argument
			struct country_st * country = findCountry(argv[2]);
			if (country == NULL) {
				displayCountryNotFoundWithCode(argv[2]);
			
			} else {
				bool success = false;
				
				if (action == Add) {
					/* attempt add country to storage */
					int r = db_add(country->codeAlpha2, country->name); 				
					if (r == 0) {
						success = true;
						addCountryStats(country);
						displayCountryAdded(country);				
					
					} else {
						displayCountryNotAdded(country);
					}
					
				} else if (action == Remove) {
					/* attempt remove country from storage */
					int r = db_rm(country->codeAlpha2);
					if (r == 0) {
						success = true;
						removeCountryStats(country);
						displayCountryRemoved(country);
					
					} else {
						displayCountryNotRemoved(country);
					}
				}
				
				// if operation succeeded then show stats
				if (success == true) displayStatsWithDetail(false);
			}
		}			
		break;

		case Detail: 
			displayStatsWithDetail(true);
		break;

		case Wipe:
			wipeData();
			break;

		default:
			displayUsage();
	}

	return 0;
}

/* private methods */

void wipeData()
{
	char answer;
	printf("This option will wipe all stored countries, do you want to continue (y/N)? ");
	scanf("%c", &answer);

	if (answer == 'y') {
		char *filepath = get_dbpath();
		int status = remove(filepath);
 
   		if (status != 0) {
			printf("Unable to delete the file %s\n", filepath);
      		perror("Error");
   		}
	}
}

