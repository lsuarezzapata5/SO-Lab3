#include <stdio.h>
#include <unistd.h>

main() {
	pid_t pid_hijo, pid_n;
	int status_1, status_2;
	
	pid_hijo = fork();
	if(pid_hijo == 0){
		
		wait(status_1);
		pid_n = fork();
		if(pid_n){
			wait(status_2);
			
			printf("!\n");		
		}else{
			printf("Mundo ");
		}
	}else{
		printf("Hola ");
	}
	return 0;
}