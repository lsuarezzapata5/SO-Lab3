#include<unistd.h>
#include<stdio.h>

int main(){
	printf("Ejecutable: \n");
	printf("Comando que no existe (mk): \n");
	execl("/bin/mk","/bin/mk","-m",".",NULL);
	printf("Comando (ls): \n");
	execl("/bin/ls","/bin/ls","-l",".",NULL);
	return 0;
}