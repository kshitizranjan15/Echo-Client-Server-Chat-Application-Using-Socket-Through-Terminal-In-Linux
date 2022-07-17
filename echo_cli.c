/*Socket : Day Time Client*/
#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
#include<arpa/inet.h>
void str_cli(int sockfd);
int main(int argc, char *argv[])
{
int sockfd,n,conn,len;
char recvline[1024];
struct sockaddr_in servaddr;
len=sizeof(struct sockaddr_in);
sockfd=socket(AF_INET,SOCK_STREAM,0);
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr(argv[1]);//get ip from server
servaddr.sin_port=htons(atoi(argv[2])); // Get the port from the server
connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));

str_cli(sockfd);
exit(0);
}

void str_cli(int sockfd){

char sendline[1024], recvline[1024];
while(fgets(sendline,1024,stdin)!=NULL)
{
write(sockfd, sendline,strlen(sendline));
if(read(sockfd,recvline,1024)==0)
    perror("error");
    
    fputs(recvline, stdout);
    }
    
    }



