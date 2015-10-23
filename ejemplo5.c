#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>
int main(int argc, char *argv[]){
	pid_t pid_hijo, pid_padre;
	int estado;

	printf("El pid del programa principal es: %d\n", (int)getpid());
	switch(pid_hijo=fork()){
		case -1: 
		printf("Error al crear el proceso\n");
		return -1;

		case 0:
		printf("PROCESO HIJO\n");
		printf("PID del proceso: %d\n",(int) pid_hijo);
		printf("PID del padre: %d\n",(int) getppid());
		exit(0);
		printf("Esta instrucción nunca se ejecutara en el proceso hijo.\n");
		break;

		default:
		wait(&estado);
		printf("PROCESO PADRE: Proceso hijo con PID %d creado\n", (int)pid_hijo );
		printf("PID del proceso hijo: %d\n",(int) pid_hijo);
		printf("PID del padre: %d\n",(int) getppid());
	}
	return 0;
}