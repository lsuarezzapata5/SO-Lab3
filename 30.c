#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	pid_t pid_h2, pid_h3, pid_h4, pid_h5;
	pid_t pid_p;
	int h3,h4,h5,h2;
	int i = 0;
	printf("PID proceso 1: %d  \n PID padre h1:%d \n",getpid(),getppid());
	pid_h3 = fork();

	if(pid_h3 == 0) {
		printf("PID Hijo 3: %d  \n PID padre h3:%d \n",getpid(),getppid());
		pid_h4 = fork();
		if(pid_h4==0) {
			i++;
			printf("PID Hijo 4: %d  \n PID padre h4:%d \n",getpid(),getppid());
		}else{

			if(pid_h4==-1){
				printf("---ERROR---\n\n");
				return -1;
			}
			wait(h4);
			pid_h5=fork();
			if(pid_h5==0){
				i++;
			printf("PID Hijo 5: %d  \n PID padre h5:%d \n",getpid(),getppid());
			}else{
				if(pid_h5==-1){
					printf("---ERROR---\n\n");
					return -1;
				}
				wait(h5);
			}
		exit(0);
		}
	}else {
		wait(h3);
		if(pid_h3==-1){
			printf("---ERROR---\n\n");
			return -1;
		}
		pid_h2 = fork();
		if(pid_h2 == 0) {
			i++;
			printf("PID Hijo 2: %d  \n PID padre h2:%d \n",getpid(),getppid());
		}else{
			if(pid_h2==-1){
				printf("---ERROR---\n\n");
				return -1;
			}
			wait(h2);
		} 
	}
	//system("pstree");
	
	return 0;
}

