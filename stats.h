#ifndef STATS_H
#define STATS_H

/* application includes */
#include "countries.h"

int * countries_per_continent_counter; 
int * countries_per_continent;

void init_stats();
void add_country_stats(struct country_st * country);
void remove_country_stats(struct country_st * country);
int get_world_value_stats();

#endif
