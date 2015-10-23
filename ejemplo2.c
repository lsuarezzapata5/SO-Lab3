#include <unistd.h>
#include <stdio.h>


int main(int argc, char *argv[]){
	pid_t pid_hijo;
	printf("Ejemplo fork. Este proceso va a crear otro proceso\n\n");
	printf("El pid del programa principar es: %d\n",(int)getpid());

	switch(pid_hijo=fork()){
		case -1: 
		printf("Error al crear el proceso\n");
		return -1;

		case 0:
		printf("PROCESO HIJO\n");
		printf("PID del hijo: %d\n",(int) pid_hijo);
		break;

		default:
		printf("PROCESO PADRE: Proceso hijo con PID %d creado\n", (int)pid_hijo );

	}
	printf("Fin del proceso cuyo hijo tiene un PID de %d \n",(int) pid_hijo );
	return 0;
}