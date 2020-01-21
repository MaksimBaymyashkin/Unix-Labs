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
    int ab = 0; 
    float a,b,rez;
    char mes[1024] = {"22"};

 printf("SLAVE PROCESS: a+b \n");

    listener = socket(AF_INET, SOCK_STREAM, 0);
    if(listener < 0)
    {
        perror("socket");
        exit(1);
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3426);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        exit(2);
    }

    listen(listener, 1);
    ab = 0; 

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
		float val = atof(buf);
		ab++;
		if (ab<=1){
		  printf("\nPolucheno chislo A: %6.2f",val);
		  ab=1;	
		  a = val;	
		  sprintf(mes,"%f",a);
		  mes[strlen(mes)] = '\n';		
		  fflush(stdout);
		  send(sock, mes, strlen(mes), 0);
		}
		else {
		  printf("\nPolucheno chislo B: %6.2f",val);
		  b = val;
		  rez = a+b;
               	  printf("\nPosilka rezultata: %6.2f \n",rez);
		  sprintf(mes,"%f",rez);
		  mes[strlen(mes)] = '\n';		
		  fflush(stdout);
		  send(sock, mes, strlen(mes), 0);
		  sleep(1);
		  close(sock);
		  printf("Finish!\n");
		  exit(1);
		}
        }
    
        close(sock);
    }
    
    return 0;
}
