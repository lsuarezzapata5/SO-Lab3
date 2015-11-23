#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	pid_t pid_h1, pid_h2, pid_h3;
	pid_t pid_p;

	int f,h3,h1,h2;
	int i = 0;
	
	pid_h1 = fork();


	if(pid_h1 == 0) {
		f=0;
		for (i=1; i<11;i++){
			f=factorial(i);
			printf("Hijo 1:  Fact(%d): %d\n",i,f );
		}
		

	}else {
		pid_h2 = fork();
		if(pid_h2 == 0) {
			f=0;
			for (i=1; i<11;i++){
				f=factorial(i);
				printf("Hijo 2:  Fact(%d): %d\n",i,f );
			}
		}else {
			pid_h3 = fork();
			if(pid_h3 == 0) {
					f=0;
				for (i=1; i<11;i++){
					f=factorial(i);
					printf("Hijo 3:  Fact(%d): %d\n",i,f );
				}
				
			exit(0);	
			}

			
			exit(0);
		
		}
	
		
	exit(0);
	}

	wait(h1);
	wait(h2);
	wait(h3);
	return 0;
}

int factorial(int n) { 
	int r; 
	if (n==1) { 
		return 1; 
	} 
	r=n*factorial(n-1); 
	return (r) ; 
} 

