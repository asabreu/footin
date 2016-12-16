/* standard includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/* application includes */
#include "countries.h"

const char *iso_3166_table[][4] = {
{"1", "AF", "AFG", "Afghanistan, Islamic Republic of"},
{"2", "AL", "ALB", "Albania, Republic of"},
{"6", "AQ", "ATA", "Antarctica (the territory South of 60 deg S)"},
{"0", "DZ", "DZA", "Algeria, People's Democratic Republic of"},
{"5", "AS", "ASM", "American Samoa"},
{"2", "AD", "AND", "Andorra, Principality of"},
{"0", "AO", "AGO", "Angola, Republic of"},
{"3", "AG", "ATG", "Antigua and Barbuda"},
{"2", "AZ", "AZE", "Azerbaijan, Republic of"},
{"1", "AZ", "AZE", "Azerbaijan, Republic of"},
{"4", "AR", "ARG", "Argentina, Argentine Republic"},
{"5", "AU", "AUS", "Australia, Commonwealth of"},
{"2", "AT", "AUT", "Austria, Republic of"},
{"3", "BS", "BHS", "Bahamas, Commonwealth of the"},
{"1", "BH", "BHR", "Bahrain, Kingdom of"},
{"1", "BD", "BGD", "Bangladesh, People's Republic of"},
{"2", "AM", "ARM", "Armenia, Republic of"},
{"1", "AM", "ARM", "Armenia, Republic of"},
{"3", "BB", "BRB", "Barbados"},
{"2", "BE", "BEL", "Belgium, Kingdom of"},
{"3", "BM", "BMU", "Bermuda"},
{"1", "BT", "BTN", "Bhutan, Kingdom of"},
{"4", "BO", "BOL", "Bolivia, Republic of"},
{"2", "BA", "BIH", "Bosnia and Herzegovina"},
{"0", "BW", "BWA", "Botswana, Republic of"},
{"6", "BV", "BVT", "Bouvet Island (Bouvetoya)"},
{"4", "BR", "BRA", "Brazil, Federative Republic of"},
{"3", "BZ", "BLZ", "Belize"},
{"1", "IO", "IOT", "British Indian Ocean Territory (Chagos Archipelago)"},
{"5", "SB", "SLB", "Solomon Islands"},
{"3", "VG", "VGB", "British Virgin Islands"},
{"1", "BN", "BRN", "Brunei Darussalam"},
{"2", "BG", "BGR", "Bulgaria, Republic of"},
{"1", "MM", "MMR", "Myanmar, Union of"},
{"0", "BI", "BDI", "Burundi, Republic of"},
{"2", "BY", "BLR", "Belarus, Republic of"},
{"1", "KH", "KHM", "Cambodia, Kingdom of"},
{"0", "CM", "CMR", "Cameroon, Republic of"},
{"3", "CA", "CAN", "Canada"},
{"0", "CV", "CPV", "Cape Verde, Republic of"},
{"3", "KY", "CYM", "Cayman Islands"},
{"0", "CF", "CAF", "Central African Republic"},
{"1", "LK", "LKA", "Sri Lanka, Democratic Socialist Republic of"},
{"0", "TD", "TCD", "Chad, Republic of"},
{"4", "CL", "CHL", "Chile, Republic of"},
{"1", "CN", "CHN", "China, People's Republic of"},
{"1", "TW", "TWN", "Taiwan"},
{"1", "CX", "CXR", "Christmas Island"},
{"1", "CC", "CCK", "Cocos (Keeling) Islands"},
{"4", "CO", "COL", "Colombia, Republic of"},
{"0", "KM", "COM", "Comoros, Union of the"},
{"0", "YT", "MYT", "Mayotte"},
{"0", "CG", "COG", "Congo, Republic of the"},
{"0", "CD", "COD", "Congo, Democratic Republic of the"},
{"5", "CK", "COK", "Cook Islands"},
{"3", "CR", "CRI", "Costa Rica, Republic of"},
{"2", "HR", "HRV", "Croatia, Republic of"},
{"3", "CU", "CUB", "Cuba, Republic of"},
{"2", "CY", "CYP", "Cyprus, Republic of"},
{"1", "CY", "CYP", "Cyprus, Republic of"},
{"2", "CZ", "CZE", "Czech Republic"},
{"0", "BJ", "BEN", "Benin, Republic of"},
{"2", "DK", "DNK", "Denmark, Kingdom of"},
{"3", "DM", "DMA", "Dominica, Commonwealth of"},
{"3", "DO", "DOM", "Dominican Republic"},
{"4", "EC", "ECU", "Ecuador, Republic of"},
{"3", "SV", "SLV", "El Salvador, Republic of"},
{"0", "GQ", "GNQ", "Equatorial Guinea, Republic of"},
{"0", "ET", "ETH", "Ethiopia, Federal Democratic Republic of"},
{"0", "ER", "ERI", "Eritrea, State of"},
{"2", "EE", "EST", "Estonia, Republic of"},
{"2", "FO", "FRO", "Faroe Islands"},
{"4", "FK", "FLK", "Falkland Islands (Malvinas)"},
{"6", "GS", "SGS", "South Georgia and the South Sandwich Islands"},
{"5", "FJ", "FJI", "Fiji, Republic of the Fiji Islands"},
{"2", "FI", "FIN", "Finland, Republic of"},
{"2", "AX", "ALA", "Åland Islands"},
{"2", "FR", "FRA", "France, French Republic"},
{"4", "GF", "GUF", "French Guiana"},
{"5", "PF", "PYF", "French Polynesia"},
{"6", "TF", "ATF", "French Southern Territories"},
{"0", "DJ", "DJI", "Djibouti, Republic of"},
{"0", "GA", "GAB", "Gabon, Gabonese Republic"},
{"2", "GE", "GEO", "Georgia"},
{"1", "GE", "GEO", "Georgia"},
{"0", "GM", "GMB", "Gambia, Republic of the"},
{"1", "PS", "PSE", "Palestinian Territory, Occupied"},
{"2", "DE", "DEU", "Germany, Federal Republic of"},
{"0", "GH", "GHA", "Ghana, Republic of"},
{"2", "GI", "GIB", "Gibraltar"},
{"5", "KI", "KIR", "Kiribati, Republic of"},
{"2", "GR", "GRC", "Greece, Hellenic Republic"},
{"3", "GL", "GRL", "Greenland"},
{"3", "GD", "GRD", "Grenada"},
{"3", "GP", "GLP", "Guadeloupe"},
{"5", "GU", "GUM", "Guam"},
{"3", "GT", "GTM", "Guatemala, Republic of"},
{"0", "GN", "GIN", "Guinea, Republic of"},
{"4", "GY", "GUY", "Guyana, Co-operative Republic of"},
{"3", "HT", "HTI", "Haiti, Republic of"},
{"6", "HM", "HMD", "Heard Island and McDonald Islands"},
{"2", "VA", "VAT", "Holy See (Vatican City State)"},
{"3", "HN", "HND", "Honduras, Republic of"},
{"1", "HK", "HKG", "Hong Kong, Special Administrative Region of China"},
{"2", "HU", "HUN", "Hungary, Republic of"},
{"2", "IS", "ISL", "Iceland, Republic of"},
{"1", "IN", "IND", "India, Republic of"},
{"1", "ID", "IDN", "Indonesia, Republic of"},
{"1", "IR", "IRN", "Iran, Islamic Republic of"},
{"1", "IQ", "IRQ", "Iraq, Republic of"},
{"2", "IE", "IRL", "Ireland"},
{"1", "IL", "ISR", "Israel, State of"},
{"2", "IT", "ITA", "Italy, Italian Republic"},
{"0", "CI", "CIV", "Cote d'Ivoire, Republic of"},
{"3", "JM", "JAM", "Jamaica"},
{"1", "JP", "JPN", "Japan"},
{"2", "KZ", "KAZ", "Kazakhstan, Republic of"},
{"1", "KZ", "KAZ", "Kazakhstan, Republic of"},
{"1", "JO", "JOR", "Jordan, Hashemite Kingdom of"},
{"0", "KE", "KEN", "Kenya, Republic of"},
{"1", "KP", "PRK", "Korea, Democratic People's Republic of"},
{"1", "KR", "KOR", "Korea, Republic of"},
{"1", "KW", "KWT", "Kuwait, State of"},
{"1", "KG", "KGZ", "Kyrgyz Republic"},
{"1", "LA", "LAO", "Lao People's Democratic Republic"},
{"1", "LB", "LBN", "Lebanon, Lebanese Republic"},
{"0", "LS", "LSO", "Lesotho, Kingdom of"},
{"2", "LV", "LVA", "Latvia, Republic of"},
{"0", "LR", "LBR", "Liberia, Republic of"},
{"0", "LY", "LBY", "Libyan Arab Jamahiriya"},
{"2", "LI", "LIE", "Liechtenstein, Principality of"},
{"2", "LT", "LTU", "Lithuania, Republic of"},
{"2", "LU", "LUX", "Luxembourg, Grand Duchy of"},
{"1", "MO", "MAC", "Macao, Special Administrative Region of China"},
{"0", "MG", "MDG", "Madagascar, Republic of"},
{"0", "MW", "MWI", "Malawi, Republic of"},
{"1", "MY", "MYS", "Malaysia"},
{"1", "MV", "MDV", "Maldives, Republic of"},
{"0", "ML", "MLI", "Mali, Republic of"},
{"2", "MT", "MLT", "Malta, Republic of"},
{"3", "MQ", "MTQ", "Martinique"},
{"0", "MR", "MRT", "Mauritania, Islamic Republic of"},
{"0", "MU", "MUS", "Mauritius, Republic of"},
{"3", "MX", "MEX", "Mexico, United Mexican States"},
{"2", "MC", "MCO", "Monaco, Principality of"},
{"1", "MN", "MNG", "Mongolia"},
{"2", "MD", "MDA", "Moldova, Republic of"},
{"2", "ME", "MNE", "Montenegro, Republic of"},
{"3", "MS", "MSR", "Montserrat"},
{"0", "MA", "MAR", "Morocco, Kingdom of"},
{"0", "MZ", "MOZ", "Mozambique, Republic of"},
{"1", "OM", "OMN", "Oman, Sultanate of"},
{"0", "NA", "NAM", "Namibia, Republic of"},
{"5", "NR", "NRU", "Nauru, Republic of"},
{"1", "NP", "NPL", "Nepal, State of"},
{"2", "NL", "NLD", "Netherlands, Kingdom of the"},
{"3", "AN", "ANT", "Netherlands Antilles"},
{"3", "CW", "CUW", "Curaçao"},
{"3", "AW", "ABW", "Aruba"},
{"3", "SX", "SXM", "Sint Maarten (Netherlands)"},
{"3", "BQ", "BES", "Bonaire, Sint Eustatius and Saba"},
{"5", "NC", "NCL", "New Caledonia"},
{"5", "VU", "VUT", "Vanuatu, Republic of"},
{"5", "NZ", "NZL", "New Zealand"},
{"3", "NI", "NIC", "Nicaragua, Republic of"},
{"0", "NE", "NER", "Niger, Republic of"},
{"0", "NG", "NGA", "Nigeria, Federal Republic of"},
{"5", "NU", "NIU", "Niue"},
{"5", "NF", "NFK", "Norfolk Island"},
{"2", "NO", "NOR", "Norway, Kingdom of"},
{"5", "MP", "MNP", "Northern Mariana Islands, Commonwealth of the"},
{"5", "UM", "UMI", "United States Minor Outlying Islands"},
{"3", "UM", "UMI", "United States Minor Outlying Islands"},
{"5", "FM", "FSM", "Micronesia, Federated States of"},
{"5", "MH", "MHL", "Marshall Islands, Republic of the"},
{"5", "PW", "PLW", "Palau, Republic of"},
{"1", "PK", "PAK", "Pakistan, Islamic Republic of"},
{"3", "PA", "PAN", "Panama, Republic of"},
{"5", "PG", "PNG", "Papua New Guinea, Independent State of"},
{"4", "PY", "PRY", "Paraguay, Republic of"},
{"4", "PE", "PER", "Peru, Republic of"},
{"1", "PH", "PHL", "Philippines, Republic of the"},
{"5", "PN", "PCN", "Pitcairn Islands"},
{"2", "PL", "POL", "Poland, Republic of"},
{"2", "PT", "PRT", "Portugal, Portuguese Republic"},
{"0", "GW", "GNB", "Guinea-Bissau, Republic of"},
{"1", "TL", "TLS", "Timor-Leste, Democratic Republic of"},
{"3", "PR", "PRI", "Puerto Rico, Commonwealth of"},
{"1", "QA", "QAT", "Qatar, State of"},
{"0", "RE", "REU", "Reunion"},
{"2", "RO", "ROU", "Romania"},
{"2", "RU", "RUS", "Russian Federation"},
{"1", "RU", "RUS", "Russian Federation"},
{"0", "RW", "RWA", "Rwanda, Republic of"},
{"3", "BL", "BLM", "Saint Barthelemy"},
{"0", "SH", "SHN", "Saint Helena"},
{"3", "KN", "KNA", "Saint Kitts and Nevis, Federation of"},
{"3", "AI", "AIA", "Anguilla"},
{"3", "LC", "LCA", "Saint Lucia"},
{"3", "MF", "MAF", "Saint Martin"},
{"3", "PM", "SPM", "Saint Pierre and Miquelon"},
{"3", "VC", "VCT", "Saint Vincent and the Grenadines"},
{"2", "SM", "SMR", "San Marino, Republic of"},
{"0", "ST", "STP", "Sao Tome and Principe, Democratic Republic of"},
{"1", "SA", "SAU", "Saudi Arabia, Kingdom of"},
{"0", "SN", "SEN", "Senegal, Republic of"},
{"2", "RS", "SRB", "Serbia, Republic of"},
{"0", "SC", "SYC", "Seychelles, Republic of"},
{"0", "SL", "SLE", "Sierra Leone, Republic of"},
{"1", "SG", "SGP", "Singapore, Republic of"},
{"2", "SK", "SVK", "Slovakia (Slovak Republic)"},
{"1", "VN", "VNM", "Vietnam, Socialist Republic of"},
{"2", "SI", "SVN", "Slovenia, Republic of"},
{"0", "SO", "SOM", "Somalia, Somali Republic"},
{"0", "ZA", "ZAF", "South Africa, Republic of"},
{"0", "ZW", "ZWE", "Zimbabwe, Republic of"},
{"2", "ES", "ESP", "Spain, Kingdom of"},
{"0", "SS", "SSD", "South Sudan"},
{"0", "EH", "ESH", "Western Sahara"},
{"0", "SD", "SDN", "Sudan, Republic of"},
{"4", "SR", "SUR", "Suriname, Republic of"},
{"2", "SJ", "SJM", "Svalbard & Jan Mayen Islands"},
{"0", "SZ", "SWZ", "Swaziland, Kingdom of"},
{"2", "SE", "SWE", "Sweden, Kingdom of"},
{"2", "CH", "CHE", "Switzerland, Swiss Confederation"},
{"1", "SY", "SYR", "Syrian Arab Republic"},
{"1", "TJ", "TJK", "Tajikistan, Republic of"},
{"1", "TH", "THA", "Thailand, Kingdom of"},
{"0", "TG", "TGO", "Togo, Togolese Republic"},
{"5", "TK", "TKL", "Tokelau"},
{"5", "TO", "TON", "Tonga, Kingdom of"},
{"3", "TT", "TTO", "Trinidad and Tobago, Republic of"},
{"1", "AE", "ARE", "United Arab Emirates"},
{"0", "TN", "TUN", "Tunisia, Tunisian Republic"},
{"2", "TR", "TUR", "Turkey, Republic of"},
{"1", "TR", "TUR", "Turkey, Republic of"},
{"1", "TM", "TKM", "Turkmenistan"},
{"3", "TC", "TCA", "Turks and Caicos Islands"},
{"5", "TV", "TUV", "Tuvalu"},
{"0", "UG", "UGA", "Uganda, Republic of"},
{"2", "UA", "UKR", "Ukraine"},
{"2", "MK", "MKD", "Macedonia, The Former Yugoslav Republic of"},
{"0", "EG", "EGY", "Egypt, Arab Republic of"},
{"2", "GB", "GBR", "United Kingdom of Great Britain & Northern Ireland"},
{"2", "GG", "GGY", "Guernsey, Bailiwick of"},
{"2", "JE", "JEY", "Jersey, Bailiwick of"},
{"2", "IM", "IMN", "Isle of Man"},
{"0", "TZ", "TZA", "Tanzania, United Republic of"},
{"3", "US", "USA", "United States of America"},
{"3", "VI", "VIR", "United States Virgin Islands"},
{"0", "BF", "BFA", "Burkina Faso"},
{"4", "UY", "URY", "Uruguay, Eastern Republic of"},
{"1", "UZ", "UZB", "Uzbekistan, Republic of"},
{"4", "VE", "VEN", "Venezuela, Bolivarian Republic of"},
{"5", "WF", "WLF", "Wallis and Futuna"},
{"5", "WS", "WSM", "Samoa, Independent State of"},
{"1", "YE", "YEM", "Yemen"},
{"0", "ZM", "ZMB", "Zambia, Republic of"},
{"5", "XX", "null", "Disputed Territory"},
{"1", "XE", "null", "Iraq-Saudi Arabia Neutral Zone"},
{"1", "XD", "null", "United Nations Neutral Zone"},
{"1", "XS", "null", "Spratly Islands"}
};

int number_of_countries = 0;

/* forward declaration */
struct country_st create_country(char *code_alpha_2, char *code_alpha_3, char *name, enum continent_type type);

void init_countries()
{
	number_of_countries = sizeof(iso_3166_table)/sizeof(iso_3166_table[0]);
	
	countries = (struct country_st *)malloc(sizeof(struct country_st) * number_of_countries);
   
	int i = 0;
	for (i = 0; i < number_of_countries; i++) {
		const char *code_alpha_2 = iso_3166_table[i][1];
		const char *code_alpha_3 = iso_3166_table[i][2];
		const char *name = iso_3166_table[i][3];
		int continent =  atoi(iso_3166_table[i][0]);
    
		countries[i] = create_country((char *)code_alpha_2, (char *)code_alpha_3, (char *)name, continent);
	}
}

struct country_st * find_country(const char *code) {
	int i = 0;
	if (code == NULL || (strlen(code) != 2 && strlen(code) != 3)) {
		return NULL;
	}

	for (i = 0; i < number_of_countries; i++) {
		struct country_st country = countries[i];
        if (strlen(code) == 2) {
			if (!strncasecmp(country.code_alpha_2, code, 3)) {
				return &countries[i];
         	}

		} else {
			if (!strncasecmp(country.code_alpha_3, code, 3)) {
				return &countries[i];
			}
		}
     }
  
	return NULL;
}

void print_country(struct country_st * country)
{
	printf("code_alpha_2: %s\n", country->code_alpha_2);
	printf("code_alpha_3: %s\n", country->code_alpha_3);
	printf("name: %s\n", country->name);
	printf("continent: %s\n", country->continent_name);
}

/* private methods */

struct country_st create_country(char *code_alpha_2, char *code_alpha_3, char *name, enum continent_type type)
{   
	struct country_st country;
	country.code_alpha_2 = (char*)malloc(strlen(code_alpha_2) * sizeof(char) + 1);
	country.code_alpha_3 = (char*)malloc(strlen(code_alpha_3) * sizeof(char) + 1);
	country.name = (char*)malloc(strlen(name) * sizeof(char) + 1);
  
	strcpy(country.code_alpha_2, code_alpha_2);
	strcpy(country.code_alpha_3, code_alpha_3);
	strcpy(country.name, name);

	country.continent_name = continents[(int)type];
	country.continent_index = (int)type;    

	return country;
}

