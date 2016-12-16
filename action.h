#ifndef ACTION_H
#define ACTION_H

enum action_type { Display, Add, Remove, Detail, Wipe, Help }; 

enum action_type get_action_type(int argc, char *argv[]);

#endif
