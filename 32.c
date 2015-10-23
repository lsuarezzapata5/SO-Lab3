#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define longitud 50

int main(){
	char programa[longitud];
	pid_t pid;
	pid_t status;
	printf("____________________________________________\n");
	printf("  INGRESE EL NOMBRE DEL PROGRAMA A EJECUTAR\n");
	printf("____________________________________________\n");
	scanf("%s",programa);
	pid = fork();
	if(pid == 0){
		execl(programa, programa, NULL);
	}else{
		wait(status);
		printf("____________________________________________\n");
		printf("   PROGRAMA EJECUTADO SATISFACTORIAMENTE\n");
		printf("____________________________________________\n");
	}
	return 0;
}