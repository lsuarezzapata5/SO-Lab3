#include <signal.h>
void my_handler (int sig);

int main(void){
	struct sigaction my_action;
	//Part I: Catch SIGINT
	my_action.sa_handller=my_handler;
	my_action-sa_flags=SA_RESTART;
	sigaction(SIGINT, &my_action, NULL);
	printf("Catching SIGINT \n");
	sleep(3);
	printf("No SIGINT within 3 seconds \n");


	//Part II: Ignore SIGINT
	my_action.sa_handller=SIG_IN;
	my_action-sa_flags=SA_RESTART;
	sigaction(SIGINT, &my_action, NULL);
	printf("Ignoring SIGINT \n");
	sleep(3);
	printf("No SIGINT within 3 seconds \n");

	//Part III: DEfault action for SIGINT
	my_action.sa_handller=SIG_IN;
	my_action-sa_flags=SA_RESTART;
	sigaction(SIGINT, &my_action, NULL);
	printf("Default ation for SIGINT \n");
	sleep(3);
	printf("No SIGINT within 3 seconds \n");


}

void my_handler (int sig){
	printf("I got SIGINT, number %d \n", sig );
	exit(0);
}