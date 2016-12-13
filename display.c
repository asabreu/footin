/* standard includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* application includes */
#include "display.h"
#include "storage.h"

#define KRESET			"\033[m"
#define KBROWN			"\x1B[33m"
#define KCYAN			"\x1B[36m"

#define KNAMEWIDTH		30	
#define KVALUEWIDTH		5

/* forward declaration */
void printContinentAndValue(char *continentName, int value);
void displayCountryInfo(struct country_st * country, const char * info);
char *leftAlignStr(char *str, int width);
char *rightAlignStr(char *str, int width);
char *repeatStr(char *str, size_t count);

void displayUsage()
{
	printf("usage: footin [-d | -w | -h] [-a | -r] 'iso country code' ...\n\n");
	
	printf("without option, display stored countries coverage list.\n\n");

	printf("with option:\n");
	printf("\t-d\tDisplay stored countries coverage with detailed list.\n");
	printf("\t-w\tWipe stored countries coverage list, the user is prompted for confirmation. \n");
	printf("\t-h\tDisplay this usage help.\n\n");
	
	printf("\t-a\tAdd country using ISO 3166-2 or ISO 3166-3 country code.\n");
	printf("\t-r\tRemove country using ISO 3166-2 or ISO 3166-3 country code.\n");
}

void displayStatsWithDetail(bool detail)
{
	// if with detail get the stored countries key list
	int count = 0;
	char ** keys = NULL;
	if (detail == true) {
		count = db_count();
		keys = db_allKeys(count);
	}

	// world value
	printf("\n");
 	printContinentAndValue("World", getWorldValueStats());
	printf("\n");

	// each continent
	int arraySize = sizeof(continents)/sizeof(continents[0]);
	for (int i = 0; i < arraySize; i++) {
		int value = (int)((countriesPerContinentCounter[i] * 100) / countriesPerContinent[i]);
		
		if (detail == true) {
			char name[KNAMEWIDTH];
			sprintf(name, "%s (%d from %d)", continents[i], countriesPerContinentCounter[i], countriesPerContinent[i]); 			
			printContinentAndValue((char *)name, value);
			
			if (keys != NULL) {
				for (int c = 0; c < count; c++) {
				 	// find country by code
					struct country_st * country = findCountry(keys[c]);
					if (country != NULL) {
						if (country->continentIndex == i) {
							printf("\t");
							displayCountryInfo(country, ""); 
						}
					}
				}
			}

		} else {
			printContinentAndValue((char *)continents[i], value);
		}
	}

 	printf("\n");
}

void displayCountryNotFoundWithCode(char *code)
{
	printf("Country with ISO 3166-%lu code '%s' not found!\n", strlen(code), code);
}

void displayCountryAdded(struct country_st * country)
{
	displayCountryInfo(country, "added");
}

void displayCountryRemoved(struct country_st * country)
{
	displayCountryInfo(country, "removed");
}

void displayCountryNotAdded(struct country_st * country)
{
	displayCountryInfo(country, "not added, record already exist!");
}
 
void displayCountryNotRemoved(struct country_st * country)
{
	displayCountryInfo(country, "not removed, record not found!");
}

/* private methods */

void printContinentAndValue(char *continentName, int value)
{
	char *str = leftAlignStr(continentName, KNAMEWIDTH);

	char valueStr[5];
	sprintf(valueStr, "%d", value);
	strcat(valueStr, "%");
    
	printf(KBROWN "%s" KRESET, str);
	printf("\t");
	printf(KCYAN "%s" KRESET, rightAlignStr((char *)valueStr, KVALUEWIDTH));

	printf("\n");
}

void displayCountryInfo(struct country_st * country, const char * info)
{
	char *codeAlpha3 = country->codeAlpha3;
	if (codeAlpha3 == NULL) {
		printf("%s (%s) %s\n", country->name, country->codeAlpha2, info);
	} else {
		printf("%s (%s, %s) %s\n", country->name, country->codeAlpha2, codeAlpha3, info);
	}
}

char *leftAlignStr(char *str, int width)
{
	int strLength = strlen(str);
	int rightPadding = width - strLength;
	if (rightPadding < 0) {
		rightPadding = 0;
	}
		
	char *padding = " ";
	char *rightString = repeatStr(padding, rightPadding);
	char *final = (char *) malloc(1 + width);
	strcat(final, str);
	strcat(final, rightString);

	return final;
}

char *rightAlignStr(char *str, int width)
{
	int strLength = strlen(str);
	int leftPadding = width - strLength;
	if (leftPadding < 0) {
		leftPadding = 0;
	}
		
	char *padding = " ";
	char *leftString = repeatStr(padding, leftPadding);
	char *final = (char *) malloc(1 + width);
	strcat(final, leftString);
	strcat(final, str);

	return final;
}

char *repeatStr(char *str, size_t count) 
{
    if (count == 0) return NULL;
    char *ret = malloc (strlen(str) * count + count);
    if (ret == NULL) return NULL;
    strcpy(ret, str);
    while (--count > 0) {
        strcat(ret, str);
    }

    return ret;
}

