#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

main(){
	int fd;
	pid_t pid;
	int num;
	if((pid=fork())<0){
		perror("fork fallo");
		exit(-1);
	}else if (pid==0){
		for(num=0; num<20; num++){
			printf("Hijo: %d \n", num);
			sleep(1);
		}
	}else{
		for(num=0; num<20; num+=3){
			printf("Padre: %d\n",num );
			sleep(1);
		}
	}
}