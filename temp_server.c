#include "mylibs.h"
#include "cels_fahr_conv.h"
#include "clnt_utils.h"
#include "mysockets.h"

int main() {
  int is_continue = 1;
  MYSOCK mysock;
  TEMP_D data;

  temp_serv_setup(&mysock);

  while(is_continue) {
    temp_serv_recv(&mysock, &data);

    switch(data.mode) {
      case CELS_TO_FAHR:
        cels_to_fahr(&data);
        break;
      case FAHR_TO_CELS:
        fahr_to_cels(&data);
        break;
      case QUIT_N_EXIT:
        is_continue = 0;
        break;
      default:
        perror("Invalid mode");
        exit(1);
    }

    temp_serv_send(&mysock, &data);
  }

  temp_serv_close(&mysock);

  return 0;
}

