#include <signal.h>
void my_handler (int sig);

int main(void){
	//Part I: Catch SIGINT
	signal(SIGINT, my_handler);
	printf("Catching SIGINT \n");
	sleep(3);
	printf("No SIGINT within 3 seconds \n");


	//Part II: Ignore SIGINT
	signal(SIGINT, SIG_IGN);
	printf("Ignoring SIGINT \n");
	sleep(3);
	printf("No SIGINT within 3 seconds \n");

	//Part III: DEfault action for SIGINT
	signal(SIGINT, SIG_DFL);
	printf("Default ation for SIGINT \n");
	sleep(3);
	printf("No SIGINT within 3 seconds \n");


}

void my_handler (int sig){
	printf("I got SIGINT, number %d \n", sig );
	exit(0);
}