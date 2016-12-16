#ifndef COUNTRIES_H
#define COUNTRIES_H

enum continent_type { Africa, Asia, Europe, North_America, South_America, Oceania, Antarctica };

static const char *continents[] = {"Africa", "Asia", "Europe", "North America", "South America", "Oceania", "Antarctica"};

struct country_st {
	char *code_alpha_2;
	char *code_alpha_3;
	char *name;
	const char *continent_name;
	int continent_index;
};

struct country_st *countries;
extern int number_of_countries;

void init_countries();
struct country_st * find_country(const char * code);
void print_country(struct country_st * country);

#endif
