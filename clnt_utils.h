#ifndef _CLNT_UTILS_H
#define _CLNT_UTILS_H

#define CELS_TO_FAHR 1
#define FAHR_TO_CELS 2
#define QUIT_N_EXIT 3

#define MAX_INPUT 64

void welcome_banner();
void validate_mode_input(int*);
void validate_temp_input(double*);
int input_mode();
double input_temp(int);

#endif

