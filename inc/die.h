#ifndef DIE_H
#define DIE_H

void die(char *error_msg, int exit_code);
int or_die(int succeeded, char *error_msg, int exit_code);

#endif /* DIE_H */
