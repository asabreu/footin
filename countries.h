enum continentType { Africa, Asia, Europe, North_America, South_America, Oceania, Antarctica };

static const char *continents[] = {"Africa", "Asia", "Europe", "North America", "South America", "Oceania", "Antarctica"};

struct country_st {
	char *codeAlpha2;
	char *codeAlpha3;
	char *name;
	const char *continentName;
	int continentIndex;
};

struct country_st *countries;
extern int numberOfCountries;

void initCountries();
struct country_st * findCountry(const char *code);
void printCountry(struct country_st * country);
