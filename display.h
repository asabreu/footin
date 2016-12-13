#ifndef DISPLAY_H
#define DISPLAY_H

/* application includes */
#include "stats.h"

typedef enum { false, true } bool;

void displayUsage();
void displayStatsWithDetail(bool detail);
void displayCountryNotFoundWithCode(char *code);
void displayCountryAdded(struct country_st * country);
void displayCountryRemoved(struct country_st * country);

void displayCountryNotAdded(struct country_st * country);
void displayCountryNotRemoved(struct country_st * country);

#endif
