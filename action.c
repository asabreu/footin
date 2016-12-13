/* standard includes */
#include <string.h>

/* application includes */
#include "action.h"

enum actionType getActionType(int argc, char *argv[]) {
	enum actionType result = Help; // defaults to Help

	if (argc == 1) {
		return Display;

	} else {
		char *cmd = argv[1];
	
		if (argc == 2) {
			if (strncmp("-d", cmd, strlen(cmd)) == 0) {
				return Detail;
			} else if (strncmp("-w", cmd, strlen(cmd)) == 0) {
				return Wipe;
			}
	
		} else if (argc == 3) {
			if (strncmp("-a", cmd, strlen(cmd)) == 0) {
				return Add;
			} else if (strncmp("-r", cmd, strlen(cmd)) == 0) {
				return Remove;
			}
		}
	}

	return result;
}
