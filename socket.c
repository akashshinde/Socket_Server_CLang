#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(){

  int socketfd,new_socket;
  struct sockaddr_in server_addr,client_addr;
  printf("Creating socket now");
  socketfd =socket(AF_INET, SOCK_STREAM, 0); 
  
  printf("Binding socket to port");
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(3000);
  bind(socketfd,(struct sockaddr *)&server_addr,sizeof(server_addr));
  listen(socketfd,5);
  new_socket = accept(socketfd,(struct sockaddr *) &client_addr,sizeof(client_addr));
  printf("Programm listening on port 3000");
  return 0;
  }
