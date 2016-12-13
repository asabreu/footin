/* standard includes */
#include <stdio.h>
#include <stdlib.h>

/* application includes */
#include "stats.h"

void initStats()
{
	int arraySize = sizeof(continents)/sizeof(continents[0]);

	countriesPerContinentCounter = malloc(sizeof(int) * arraySize);
	countriesPerContinent = malloc(sizeof(int) * arraySize); 

	// initialize all containers to zero
	int i;
	for (i = 0; i < arraySize; i++) {
		countriesPerContinentCounter[i] = 0;
		countriesPerContinent[i] = 0;
	}  

	// count countries per continent
	for (i = 0; i < numberOfCountries; i++) {
		struct country_st country = countries[i];
		int continentIndex = country.continentIndex;
		countriesPerContinent[continentIndex]++;
	}
}

void addCountryStats(struct country_st * country)
{
	int continentIndex = country->continentIndex;
	countriesPerContinentCounter[continentIndex]++;
}

void removeCountryStats(struct country_st * country)
{
	int continentIndex = country->continentIndex;
	countriesPerContinentCounter[continentIndex]--;
}

int getWorldValueStats()
{
	int arraySize = sizeof(continents)/sizeof(continents[0]);

	int totalCountriesPerContinentCounter = 0;
	int totalCountriesPerContinent = 0;	

	int i;
	for (i = 0; i < arraySize; i++) {
		totalCountriesPerContinentCounter += countriesPerContinentCounter[i];
		totalCountriesPerContinent += countriesPerContinent[i];
	}

	int value = (int)((totalCountriesPerContinentCounter * 100) / totalCountriesPerContinent);

	return value;
}
