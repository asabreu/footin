#ifndef STATS_H
#define STATS_H

/* application includes */
#include "countries.h"

int * countriesPerContinentCounter; 
int * countriesPerContinent;

void initStats();
void addCountryStats(struct country_st * country);
void removeCountryStats(struct country_st * country);
int getWorldValueStats();

#endif
