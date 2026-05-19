#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
     int sockfd,readval,frame=0,totalframes,ack;
     struct sockaddr_in server;
     char str[100];

     sockfd=socket(AF_INET,SOCK_STREAM,0);
     if(sockfd<0)
     {
          printf("Socket creation failed\n");
          return 0;
     }

     printf("Socket created successfully\n");

     memset(&server,0,sizeof(server));

     server.sin_family=AF_INET;
     server.sin_port=htons(8080);
     inet_pton(AF_INET,"127.0.0.1",&server.sin_addr);

     if(connect(sockfd,(struct sockaddr *)&server,sizeof(server))<0)
     {
          printf("Connection failed\n");
          return 0;
     }

     printf("Connected to server\n");
     printf("Enter total number of frames: ");
     scanf("%d",&totalframes);

     while(frame<totalframes)
     {
          sprintf(str,"%d",frame);
          send(sockfd,str,strlen(str)+1,0);
          printf("Sent frame %d\n",frame);

          memset(str,0,sizeof(str));

          readval=read(sockfd,str,sizeof(str));

          if(readval>0)
          {
               str[readval]='\0';
               ack=atoi(str);
               printf("Received acknowledgment for frame %d\n",ack);
               frame++;
          }
          else
          {
          printf("Acknowledgment not received\n");
          }
     }

     printf("All frames sent successfully\n");

     close(sockfd);

     return 0;
}
