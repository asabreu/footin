/* standard includes */
#include <stdio.h>
#include <stdlib.h>

/* application includes */
#include "stats.h"

void init_stats()
{
	int array_size = sizeof(continents)/sizeof(continents[0]);

	countries_per_continent_counter = malloc(sizeof(int) * array_size);
	countries_per_continent = malloc(sizeof(int) * array_size);

	// initialize all containers to zero
	int i;
	for (i = 0; i < array_size; i++) {
		countries_per_continent_counter[i] = 0;
		countries_per_continent[i] = 0;
	}

	// count countries per continent
	for (i = 0; i < number_of_countries; i++) {
		struct country_st country = countries[i];
		int continent_index = country.continent_index;
		countries_per_continent[continent_index]++;
	}
}

void add_country_stats(struct country_st * country)
{
	int continent_index = country->continent_index;
	countries_per_continent_counter[continent_index]++;
}

void remove_country_stats(struct country_st * country)
{
	int continent_index = country->continent_index;
	countries_per_continent_counter[continent_index]--;
}

int get_world_value_stats()
{
	int array_size = sizeof(continents)/sizeof(continents[0]);

	int total_countries_per_continent_counter = 0;
	int total_countries_per_continent = 0;

	int i;
	for (i = 0; i < array_size; i++) {
		total_countries_per_continent_counter += countries_per_continent_counter[i];
		total_countries_per_continent += countries_per_continent[i];
	}

	int value = (int)((total_countries_per_continent_counter * 100) / total_countries_per_continent);

	return value;
}
