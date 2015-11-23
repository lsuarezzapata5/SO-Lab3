#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

struct str_addr{
    char network[15];
    int host;
};

//declaracion funciones
int exec_ping();

int main(int argc, char* argv[])
{
	//pid_t pid;
	int status, i,j, responden=0, porcentaje=0;
	int ans;
	int init_host, quantity;
	char *pch;
	struct str_addr addr;
		
	if(argc != 3){
		printf("error arguments\n");
		printf("./a.out <network> <quantity> \n");
		printf("%s 192.168.0.10 5\n", argv[0]);
		exit(1);
	}
	
	pch=strrchr(argv[1],'.');		//Busca el ultimo punto y  
	*pch = '\0';						//lo reemplaza por el caracter nulo
	init_host = atoi(pch+1);
	strcpy(addr.network, argv[1]);
	quantity = atoi(argv[2]);
	
	printf("network %s\n", addr.network);
	printf("host %d\n\n", init_host);
	
	for(i=0; i<quantity; i++){
		if(fork()==0){
			printf("running host %d\n", init_host+i);
			addr.host = init_host+i;
			ans = exec_ping(&addr);
			exit(ans);
		}
					
	}

	for(j=0; j<quantity; j++){
		wait(&status);
		if(status==0){
			responden++;
		}

	}
	porcentaje=(responden*100)/quantity;
	printf("Responden: %d       Porcentaje: %d %c\n", responden,porcentaje, '%' );
	printf("No responden: %d    Porcentaje: %d %c\n", quantity-responden, 100-porcentaje, '%');
}

/**
Esta función concatena cadenas para poder formar el comando con que se va a realizar el ping a una maquina,
ademas ejecuta el comando para realizar el ping y lee la respuesta (si el host respondio o no), 
si el host responde retorna 0 de lo contrario responde con la dirección del host respectiva.

*sprintf(char *str, const char *format): Método para escribir datos formateados en una cadena de caracteres, 
en vez de imprimir almacena el contenido  de format en donde apunta el str.

*popen(const char *command, const char *type): Permite abrir otro ejecutable para ejecutarlo 
y leer su salida o enviarle datos de entrada. 

*strstr(const char *haystack, const char *needle): encuentra la primera ocurrencia de la subcadena needle en la cadena haystack,
devuelve un puntero a la primera ocurrencia en el haystack de cualquiera de toda la secuencia de caracteres de needle.


**/
int exec_ping(struct str_addr *_addr){

	FILE *ping_response;
	char ping_comand[100];
	char buffer[100];
	char no_response[] = "0 received";

	sprintf(ping_comand,"ping -w 2 %s.%d",_addr->network,_addr->host); //format es: "ping -w 2 %s.%d",_addr->network,_addr->host,
	// format es lo que se va a llevar a ping_comand, que es una cadena de caracteres (char ping_comand[100]).

	ping_response = popen(ping_comand, "r"); //Se ejecuta el comando que esta en ping_comand, en modo lectura y lo que retorna lo lleva a ping_response.

	
	while (!feof(ping_response)) { //Mientras no sea el final de ping_response
	  fgets(buffer, 100, ping_response); //Lee la linea 100 de ping_response y lo almacena en buffer
	  if (strstr(buffer, no_response)) { //encuentra la primera ocurrencia de no_response en buffer, y devuelve un puntero a esa primera ocurrencia.
	  		printf("Host %s.%d no response\n\n",_addr->network,_addr->host);
	  		return _addr->host;
	  }
	}
	printf("Host %s.%d response\n\n",_addr->network,_addr->host);
	pclose(ping_response);//Espera que el proceso termine para poder retornar el estado del exit
	return 0;
}