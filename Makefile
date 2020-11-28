TARGETS = temp_server temp_client
SERV_OBJS = temp_server.o cels_fahr_conv.o clnt_utils.o mysockets.o
CLNT_OBJS = temp_client.o clnt_utils.o mysockets.o

ALL: $(TARGETS) cleanobj

temp_server: $(SERV_OBJS)
	gcc -o $@ $^

temp_client: $(CLNT_OBJS)
	gcc -o $@ $^

cleanobj:
	rm *.o

cleanexe:
	rm $(TARGETS)

clean:
	rm *.o $(TARGETS)

