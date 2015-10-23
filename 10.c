#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
	pid_t pid_h1 = 0, pid_h2 = 0;
	pid_t pid_n1 = 0, pid_n2 = 0;
	int status_h1, status_h2, status_n1, status_n2;
	pid_h1 = fork();
	
	if(pid_h1 == 0) {
		pid_n1= fork();
		if(pid_n1) {
			printf("PID del nieto 1: %d\n",(int)pid_n1);
		}
		else {
			wait(status_n1);
			printf("PID del padre del nieto 1: %d\n", (int)getppid());
			exit(2);
		}
	}
	else{
		wait(status_h1);
		printf("PID del hijo 1: %d\n", (int)pid_h1);	
		printf("PID del padre del hijo 1: %d\n", (int)getppid());
	
		pid_h2 = fork();
		if(pid_h2 == 0) {
			pid_n2= fork();
			if(pid_n2) {
				printf("PID del nieto 2: %d\n",(int)pid_n2);
			}
			else {
				wait(status_n2);
				printf("PID del padre del nieto 2: %d\n", (int)getppid());
				exit(4);
			}
		}
		else{
			wait(status_h2);
			printf("PID del hijo 2: %d\n", (int)pid_h2);	
			printf("PID del padre del hijo 2: %d\n", (int)getppid());
		}
		wait(status_n1);
		wait(status_n2);
		wait(status_h1);
		wait(status_h2);
	}
}