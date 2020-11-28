#include "mysockets.h"

void temp_clnt(MYSOCK *mysock, TEMP_D *data) {
  mysock->sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if(mysock->sock == -1) {
    perror("Socket error");
    exit(1);
  }

  memset(&(mysock->serv_addr), 0, sizeof(mysock->serv_addr));
  (mysock->serv_addr).sin_family = AF_INET;
  (mysock->serv_addr).sin_addr.s_addr = inet_addr(LOCALHOST);
  (mysock->serv_addr).sin_port = htons(PORT);

  sendto(
    mysock->sock,
    (TEMP_D *)data,
    sizeof(*data), 
    0, 
    (struct sockaddr *)&(mysock->serv_addr), 
    sizeof(mysock->serv_addr)
  );

  mysock->clen = sizeof(mysock->clnt_addr);
  recvfrom(
    mysock->sock,
    (TEMP_D *)data,
    sizeof(*data),
    0,
    (struct sockaddr *)&(mysock->clnt_addr),
    &(mysock->clen)
  );

  close(mysock->sock);
}

void temp_serv_setup(MYSOCK *mysock) {
  mysock->sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if(mysock->sock == -1) {
    perror("Socket error");
    exit(1);
  }

  memset(&(mysock->serv_addr), 0, sizeof(mysock->serv_addr));
  (mysock->serv_addr).sin_family = AF_INET;
  (mysock->serv_addr).sin_addr.s_addr = htonl(INADDR_ANY);
  (mysock->serv_addr).sin_port = htons(PORT);

  if(bind(mysock->sock, 
      (struct sockaddr *)&(mysock->serv_addr), 
      sizeof(mysock->serv_addr)) == -1) {
    perror("Bind error");
    exit(1);
  }
}

void temp_serv_recv(MYSOCK *mysock, TEMP_D *data) {
  mysock->clen = sizeof(mysock->clnt_addr);
  recvfrom(
    mysock->sock,
    (TEMP_D *)data,
    sizeof(*data),
    0,
    (struct sockaddr *)&(mysock->clnt_addr),
    &(mysock->clen)
  );
}

void temp_serv_send(MYSOCK *mysock, TEMP_D *data) {
  sendto(
    mysock->sock,
    (TEMP_D *)data,
    sizeof(*data),
    0,
    (struct sockaddr *)&(mysock->clnt_addr),
    sizeof(mysock->clnt_addr)
  );
}

void temp_serv_close(MYSOCK *mysock) {
  close(mysock->sock);
}

