#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int sock, listener;
    struct sockaddr_in addr;
    char buf[1024];
    int bytes_read;
    char mes[1024] = {"11"};

 printf("SLAVE PROCESS: a^2 \n");

    listener = socket(AF_INET, SOCK_STREAM, 0);
    if(listener < 0)
    {
        perror("socket");
        exit(1);
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        exit(2);
    }

    listen(listener, 1);
    
    while(1)
    {
        sock = accept(listener, NULL, NULL);
        if(sock < 0)
        {
            perror("accept");
            exit(3);
        }
        while(1)
        {
           bytes_read = recv(sock, buf, 1024, 0);
            if(bytes_read <= 0) break;
		sleep(1);
		float kat = atof(buf);
		if (kat < 0) {			
		  close(sock);
		  printf("Finish!\n");
		  exit(1);
		}
		printf("\nPolucheno chislo: %6.2f",kat);
		kat = kat*kat;
               	printf("\nPosilka rezultata: %6.2f \n",kat);
		sprintf(mes,"%f",kat);
		mes[strlen(mes)] = '\n';		
		fflush(stdout);
		send(sock, mes, strlen(mes), 0);
        }
    
        close(sock);
    }
    
    return 0;
}
