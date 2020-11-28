#ifndef _MYSOCKETS_H
#define _MYSOCKETS_H

#include "mylibs.h"

#define LOCALHOST "127.0.0.1"
#define PORT 5252

typedef struct mysocket_info {
  int sock;
  int clen;
  struct sockaddr_in serv_addr;
  struct sockaddr_in clnt_addr;
} MYSOCK;

typedef struct temp_data {
  int mode;
  double temp;
} TEMP_D;

void temp_clnt(MYSOCK*, TEMP_D*);
void temp_serv_setup(MYSOCK*);
void temp_serv_recv(MYSOCK*, TEMP_D*);
void temp_serv_send(MYSOCK*, TEMP_D*);
void temp_serv_close(MYSOCK*);

#endif

