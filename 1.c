#include <syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main(void){
	long ID1, ID2;
	//Llamada indirecta 
	ID1=syscall(SYS_getpid);
	printf("syscall(SYS_getpid)= %ld\n", ID1);

	//llamada con la funcion propiamente reservada
	ID2=getpid();
	printf("getpid()= %ld\n", ID2);

	return 0;

}
