#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include "sorter.h"


int main(void){
	Sorter_startSorting();
	sleep(2);
	Sorter_stopSorting();
	return 0;
}
