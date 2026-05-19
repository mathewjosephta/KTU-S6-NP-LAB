#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
int sockfd,readval;
struct sockaddr_in server;
char str[100];

sockfd=socket(AF_INET,SOCK_STREAM,0);

if(sockfd<0)
{
printf("Socket creation failed\n");
return 0;
}

memset(&server,0,sizeof(server));

server.sin_family=AF_INET;
server.sin_port=htons(8086);

inet_pton(AF_INET,"127.0.0.1",&server.sin_addr);

if(connect(sockfd,(struct sockaddr *)&server,sizeof(server))<0)
{
printf("Connection failed\n");
return 0;
}

printf("Connected\n");

printf("Enter string: ");

scanf("%s",str);

send(sockfd,str,strlen(str)+1,0);

readval=read(sockfd,str,sizeof(str));

if(readval>0)
{
str[readval]='\0';
}

printf("Server says: %s\n",str);

close(sockfd);

return 0;
}
