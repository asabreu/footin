#ifndef DISPLAY_H
#define DISPLAY_H

/* application includes */
#include "stats.h"

typedef enum { false, true } bool;

void display_usage();
void display_stats_with_detail(bool detail);
void display_country_not_found_with_code(char * code);
void display_country_added(struct country_st * country);
void display_country_removed(struct country_st * country);

void display_country_not_added(struct country_st * country);
void display_country_not_removed(struct country_st * country);

#endif
