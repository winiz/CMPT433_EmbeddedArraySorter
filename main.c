#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include "sorter.h"
#include "network.h"


int main(void){
	Sorter_startSorting();
	sleep(2);
	Sorter_stopSorting();
	Network_Listening();
	return 0;
}
