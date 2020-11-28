#include "mylibs.h"
#include "clnt_utils.h"
#include "mysockets.h"

int main() {
  MYSOCK mysock;
  TEMP_D data;
  double prev_temp;

  int ssock;
  struct sockaddr_in clnt_addr, server_addr;

  welcome_banner();
  
  while(1) {
    data.mode = input_mode();
    if(data.mode == QUIT_N_EXIT) {
      data.temp = 0;
      temp_clnt(&mysock, &data);
      printf("\nBye-BYEE \n");
      break;
    }

    prev_temp = data.temp = input_temp(data.mode);

    temp_clnt(&mysock, &data);

    if(data.mode == CELS_TO_FAHR) {
      printf("%.0lf C = %.0lf F \n", prev_temp, data.temp);
    } else if(data.mode == FAHR_TO_CELS) {
      printf("%.0lf F = %.0lf C \n", prev_temp, data.temp);
    }
    
    putchar('\n');
  }

  return 0;
}

