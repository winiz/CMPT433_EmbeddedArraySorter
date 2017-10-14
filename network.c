#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>


#define BUFSIZE 1024
#define PORTNUM 12345

void error(char *msg) {
  perror(msg);
  exit(1);
}

void Network_Listening(void) {
	int the_socket, n;
	socklen_t serverlen;
	socklen_t clientlen;
	struct sockaddr_in serveraddr;
	struct sockaddr_in clientaddr;
	char buf[BUFSIZE];

	printf("checkpoint 1");
	the_socket = socket(AF_INET, SOCK_DGRAM, 0);
	if (the_socket < 0) {
		error("Opening socket");
	}
	serverlen = sizeof(serveraddr);
	memset(&serveraddr, 0, serverlen);
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	serveraddr.sin_port = htons(PORTNUM);

	if (bind(the_socket, (struct sockaddr *) &serveraddr, serverlen) < 0) {
		error("bind");
	}
	clientlen = sizeof(struct sockaddr_in);
	printf("checkpoint 2");

	while (1) {
		printf("Waiting for data...");
		n = recvfrom(the_socket, buf, BUFSIZE, 0,
				(struct sockaddr *) &clientaddr, &clientlen);

		if (n < 0) {
			error("recvfrom");
		}

		printf("received a datagram: %s\n", buf);
	}
}
