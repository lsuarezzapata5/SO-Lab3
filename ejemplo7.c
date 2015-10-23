#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
int main(int argc, char *argv[]){
	printf("El ID del proceso es: %d\n", (int) getpid() );
	printf("El ID del proceso padre es: %d\n", (int) getppid() );
	for(;;){
		pause();
	}
	return 0;
}