#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
	pid_t child_pid;

	if(child_pid>0){
		//Este es elproceso padre el cual duerme por 20 segundos
		sleep(20);
	}else{
		//este es el proceso hijo el cual termina inmediatamente
		exit(0);
	}
	
	return 0;
}