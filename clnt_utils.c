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

void validate_mode_input(int *mode) {
  char input[MAX_INPUT];
  int i, isint;
  while(1) {
    printf("?> ");
    fgets(input, MAX_INPUT, stdin);
    input[strlen(input) - 1] = '\0';
    if(!strlen(input)) {
      printf("Please enter an integer \n");
      continue;
    }
    for(i = 0, isint = 1; i < strlen(input); i++) {
      if(!isdigit(input[i])) {
        isint = 0;
        break;
      }
    }
    if(!isint || strchr(input, '.'))
      printf("Please enter in integer only. \n");
    else {
      *mode = atoi(input);
      if(*mode < 1 || *mode > 3)
        printf("Please enter numbers from 1 to 3 only. \n");
      else break;
    }
  }
}

void validate_temp_input(double *temp) {
  char input[MAX_INPUT];
  int i, isnum;
  while(1) {
    printf("?> ");
    fgets(input, MAX_INPUT, stdin);
    input[strlen(input) - 1] = '\0';
    if(!strlen(input)){
      printf("Please enter a number \n");
      continue;
    }
    if(!isdigit(input[0]) || !isdigit(input[strlen(input) - 1]))
      isnum = 0;
    else {
      for(i = 0, isnum = 1; i < strlen(input); i++) {
        if(!isdigit(input[i]) && input[i] != '.') {
          isnum = 0;
          break;
        }
      }
    }
    if(!isnum)
      printf("Please enter in number only. \n");
    else break;
  }
  *temp = atof(input);
}

int input_mode() {
  int mode;
  printf("Select the mode: \n");
  printf("[1] Celsius to Fahrenheit \n");
  printf("[2] Fahrenheit to Celsius \n");
  printf("[3] Quit & Exit \n");
  validate_mode_input(&mode);
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
  validate_temp_input(&temp);
  return temp;
}

