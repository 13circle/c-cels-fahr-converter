#include "mylibs.h"
#include "clnt_utils.h"

void welcome_banner() {
  printf("-------------------------------- \n");
  printf("  Celsius-Fahrenheit Converter \n");
  printf("-------------------------------- \n");
  putchar('\n');
  printf("Documentation at: \n");
  printf("https://github.com/13circle/c-cels-fahr-converter/blob/main/README.md \n");
  putchar('\n');
}

void validate_mode_input(int chk, int *mode) {
  while(1) {
    if(chk != 1)
      printf("Please enter in integer only. \n");
    else if(*mode < 1 || *mode > 3)
      printf("Please enter numbers from 1 to 3 only. \n");
    else break;
    printf("?> ");
    chk = scanf("%d", mode);
  }
}

void validate_temp_input(int chk, double *temp) {
  while(1) {
    if(chk != 1)
      printf("Please enter in number only. \n");
    else break;
    printf("?> ");
    chk = scanf("%lf", temp);
  }
}

int input_mode() {
  int mode;
  printf("Select the mode: \n");
  printf("[1] Celsius to Fahrenheit \n");
  printf("[2] Fahrenheit to Celsius \n");
  printf("[3] Quit & Exit \n");
  printf("?> ");
  validate_mode_input(scanf("%d", &mode), &mode);
  return mode;
}

double input_temp(int mode) {
  char mode_str[11];
  double temp;
  if(mode == CELS_TO_FAHR)
    strcpy(mode_str, "Celsius");
  else if(mode == FAHR_TO_CELS)
    strcpy(mode_str, "fahrenheit");
  else {
    perror("Invalid mode number");
    exit(1);
  }
  printf("Enter a temperature (in %s): \n", mode_str);
  printf("?> ");
  validate_temp_input(scanf("%lf", &temp), &temp);
  return temp;
}

