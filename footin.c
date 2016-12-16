/* standard includes */
#include <stdio.h>
#include <string.h>

/* application includes */
#include "action.h"
#include "display.h"
#include "storage.h"

/* forward declaration */
void wipe_data();

int main(int argc, char *argv[])
{
	// get action type from command line arguments
	enum action_type action = get_action_type(argc, argv);

	// check if code argument is valid
	if (action == Add || action == Remove) {
		char * code = argv[2];
		if (strlen(code) != 2 && strlen(code) != 3) { // only accept iso code with 2 or 3 chars
			action = Help;
		}
	}

	// initialize countries and stats if action requires it
	if (action != Wipe && action != Help) {
		// initialize countries
		init_countries();

		// initialize stats
		init_stats();

		/* load and process stored data */
		int count = db_count();
		char ** keys = db_all_keys(count);
		if (keys != NULL) {
			for (int i = 0; i < count; i++) {
				 // find country by code
				struct country_st * country = find_country(keys[i]);
				if (country != NULL) {
					add_country_stats(country);
				}
			}
		}
	}

	// process action
	switch (action) {
		case Display:
			display_stats_with_detail(false);
			break;

		case Add:
		case Remove:
		{
			// find country by code argument
			struct country_st * country = find_country(argv[2]);
			if (country == NULL) {
				display_country_not_found_with_code(argv[2]);

			} else {
				bool success = false;

				if (action == Add) {
					/* attempt add country to storage */
					int r = db_add(country->code_alpha_2);
					if (r == 0) {
						success = true;
						add_country_stats(country);
						display_country_added(country);

					} else {
						display_country_not_added(country);
					}

				} else if (action == Remove) {
					/* attempt remove country from storage */
					int r = db_rm(country->code_alpha_2);
					if (r == 0) {
						success = true;
						remove_country_stats(country);
						display_country_removed(country);

					} else {
						display_country_not_removed(country);
					}
				}

				// if operation succeeded then show simple stats
				if (success == true) display_stats_with_detail(false);
			}
		}
		break;

		case Detail:
			display_stats_with_detail(true);
		break;

		case Wipe:
			wipe_data();
			break;

		default:
			display_usage();
	}

	return 0;
}

/* private methods */

void wipe_data()
{
	char answer;
	printf("This option will wipe all stored countries, do you want to continue (y/N)? ");
	scanf("%c", &answer);

	if (answer == 'y') {
		char * file_path = get_db_path();
		int status = remove(file_path);

   		if (status != 0) {
					printf("Unable to delete the file %s\n", file_path);
					perror("Error");
   		}
	}
}
