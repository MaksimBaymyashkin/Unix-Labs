#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char buf[1024];


int main()
{
 float kat1 = 0;
 float kat2 = 0;

 float kat1v2 = 0;
 float kat2v2 = 0;
 float kat_sum = 0;
 float gip = 0;

char mes[1024] = {"main"};
char mes2[1024] = {"main"};

 
printf("MAIN PROCESS\n");

while (kat1<=0){
 printf("Katet 1 = ");
 scanf("%s",&mes);
 kat1= atof(mes);
}

while (kat2<=0){
 printf("Katet 2 = ");
 scanf("%s",&mes2);
 kat2= atof(mes2);
}

mes[strlen(mes)] = '\n';
mes2[strlen(mes2)] = '\n';

//A^2
    int sock;
    struct sockaddr_in addr;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket");
        exit(1);
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("connect");
        printf("Zapustite slave process a^2!!\n");
        exit(2);
    }
    
    send(sock, mes, strlen(mes), 0);   
    recv(sock, buf, 1024, 0);
    kat1v2 = atof(buf);
    printf("\nPoluchen rezultat a^2 : %6.2f \n",kat1v2); 

    sleep(1);

    send(sock, mes2, strlen(mes2), 0);   
    recv(sock, buf, 1024, 0);
    kat2v2 = atof(buf);
    printf("\nPoluchen rezultat b^2 : %6.2f \n",kat2v2);
    
    send(sock, "-1\n", 2, 0);
    close(sock);
    sleep(2);

//A+B
    sprintf(mes,"%f",kat1v2);
    sprintf(mes2,"%f",kat2v2);
    int sock2;
    struct sockaddr_in addr2;
    sock2 = socket(AF_INET, SOCK_STREAM, 0);
    if(sock2 < 0)
    {
        perror("socket");
        exit(1);
    }
    addr2.sin_family = AF_INET;
    addr2.sin_port = htons(3426);
    addr2.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if(connect(sock2, (struct sockaddr *)&addr2, sizeof(addr2)) < 0)
    {
        perror("connect");
        printf("Zapustite slave process a+b!!\n");
        exit(2);
    }
    
    send(sock2, mes, strlen(mes), 0); 
    recv(sock2, buf, 1024, 0);
    send(sock2, mes2, strlen(mes2), 0);  	
    recv(sock2, buf, 1024, 0);
    kat_sum = atof(buf);
    printf("\nPoluchen rezultat a^2+b^2 : %6.2f \n",kat_sum);     
    close(sock2);
    sleep(2);

//SQRT
    sprintf(mes,"%f",kat_sum);
    int sock3;
    struct sockaddr_in addr3;
    sock3 = socket(AF_INET, SOCK_STREAM, 0);
    if(sock3 < 0)
    {
        perror("socket");
        exit(1);
    }
    addr3.sin_family = AF_INET;
    addr3.sin_port = htons(3427);
    addr3.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if(connect(sock3, (struct sockaddr *)&addr3, sizeof(addr3)) < 0)
    {
        perror("connect");
        printf("Zapustite slave process SQRT!!\n");
        exit(2);
    }
    
    send(sock3, mes, strlen(mes), 0);   
    recv(sock3, buf, 1024, 0);
    gip = atof(buf);
    printf("\nPoluchen rezultat sqrt(a^2+b^2) : %6.2f \n",gip); 
    close(sock3);

    printf("\nGipotenuza =  %6.2f \n",gip); 


    printf("\nFinish!\n");
    return 0;
}
