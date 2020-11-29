#include "mylibs.h"
#include "cels_fahr_conv.h"
#include "clnt_utils.h"
#include "mysockets.h"

int main() {
  int is_continue = 1;
  double prev_temp;
  MYSOCK mysock;
  TEMP_D data;

  printf("Server start at port %d \n", PORT);

  printf("Setup UDP socket connection \n");
  temp_serv_setup(&mysock);

  while(is_continue) {
    temp_serv_recv(&mysock, &data);

    prev_temp = data.temp;
    switch(data.mode) {
      case CELS_TO_FAHR:
        cels_to_fahr(&data);
        printf("Convert %.0lf C to %.0lf F \n", prev_temp, data.temp);
        break;
      case FAHR_TO_CELS:
        fahr_to_cels(&data);
        printf("Convert %.0lf F to %.0lf C \n", prev_temp, data.temp);
        break;
      case QUIT_N_EXIT:
        is_continue = 0;
        break;
      default:
        perror("Invalid mode");
        exit(1);
    }

    temp_serv_send(&mysock, &data);
    printf("Send data to client \n");
  }

  temp_serv_close(&mysock);
  printf("Server terminated \n");

  return 0;
}

