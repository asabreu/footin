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
void print_continent_and_value(char * continent_name, int value);
void display_country_info(struct country_st * country, const char * info);
char *left_align_string(char * str, int width);
char *right_align_string(char * str, int width);
char *repeat_string(char * str, size_t count);

void display_usage()
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

void display_stats_with_detail(bool detail)
{
	// if with detail get the stored countries key list
	int count = 0;
	char ** keys = NULL;
	if (detail == true) {
		count = db_count();
		keys = db_all_keys(count);
	}

	// world value
	printf("\n");
 	print_continent_and_value("World", get_world_value_stats());
	printf("\n");

	// each continent
	int array_size = sizeof(continents)/sizeof(continents[0]);
	for (int i = 0; i < array_size; i++) {
		int value = (int)((countries_per_continent_counter[i] * 100) / countries_per_continent[i]);

		if (detail == true) {
			char name[KNAMEWIDTH];
			sprintf(name, "%s (%d from %d)", continents[i], countries_per_continent_counter[i], countries_per_continent[i]);
			print_continent_and_value((char *)name, value);

			if (keys != NULL) {
				bool country_found = false;
				for (int c = 0; c < count; c++) {
				 	// find country by code
					struct country_st * country = find_country(keys[c]);
					if (country != NULL) {
						if (country->continent_index == i) {
							country_found = true;
							printf("\t");
							display_country_info(country, "");
						}
					}
				}

				if (country_found == true) printf("\n");
			}

		} else {
			print_continent_and_value((char *)continents[i], value);
		}
	}

 	printf("\n");
}

void display_country_not_found_with_code(char * code)
{
	printf("Country with ISO 3166-%lu code '%s' not found!\n", strlen(code), code);
}

void display_country_added(struct country_st * country)
{
	display_country_info(country, "added");
}

void display_country_removed(struct country_st * country)
{
	display_country_info(country, "removed");
}

void display_country_not_added(struct country_st * country)
{
	display_country_info(country, "not added, record already exist!");
}

void display_country_not_removed(struct country_st * country)
{
	display_country_info(country, "not removed, record not found!");
}

/* private methods */

void print_continent_and_value(char * continent_name, int value)
{
	char *str = left_align_string(continent_name, KNAMEWIDTH);

	char value_str[5];
	sprintf(value_str, "%d", value);
	strcat(value_str, "%");

	printf(KBROWN "%s" KRESET, str);
	printf("\t");
	printf(KCYAN "%s" KRESET, right_align_string((char *)value_str, KVALUEWIDTH));

	printf("\n");
}

void display_country_info(struct country_st * country, const char * info)
{
	char * code_alpha_3 = country->code_alpha_3;
	if (code_alpha_3 == NULL) {
		printf("%s (%s) %s\n", country->name, country->code_alpha_3, info);
	} else {
		printf("%s (%s, %s) %s\n", country->name, country->code_alpha_2, code_alpha_3, info);
	}
}

char * left_align_string(char * str, int width)
{
	int str_length = strlen(str);
	int right_padding = width - str_length;
	if (right_padding < 0) {
		right_padding = 0;
	}

	char * right_string = repeat_string(" ", right_padding);
	char * final = (char *) malloc(1 + width);
	strcat(final, str);
	strcat(final, right_string);

	return final;
}

char * right_align_string(char * str, int width)
{
	int str_length = strlen(str);
	int left_padding = width - str_length;
	if (left_padding < 0) {
		left_padding = 0;
	}

	char * left_string = repeat_string(" ", left_padding);
	char * final = (char *) malloc(1 + width);
	strcat(final, left_string);
	strcat(final, str);

	return final;
}

char * repeat_string(char * str, size_t count)
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
