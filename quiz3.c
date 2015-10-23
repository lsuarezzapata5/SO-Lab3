/* programa que cree un hijo, el hijo llama a exec para compilar un programa*/
#include <unistd.h>
#include <stdio.h>
#include <string.h> 
#define NUMMAXCHAR 20
int main(int argc, char *argv[]) {
	int status;
	pid_t pid_h1;
	char programa [NUMMAXCHAR];
	char ejecutable [NUMMAXCHAR];

	strcpy(programa, argv[1]);
	strcpy(ejecutable,argv[2]);
	printf("PROG: %s EJEC: %s \n", programa, ejecutable);
	
	pid_h1 = fork();
	if(pid_h1 == 0) {
		execl("/usr/bin/gcc", "/usr/bin/gcc", programa, "-o", ejecutable);
				
	}else {
		wait(&status);
	}
	
	return 0;
}