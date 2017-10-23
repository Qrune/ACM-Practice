send(sock, "GET\n",4,0);
while (len = recv(sock,buf,99,0)){
	buf[len] = '\0';
	printf("%s",buf)
	//print message
}
close(sock);
#include <sys/socket.h>
#include <arpa/inet.h>
void main()
{
	 int client_sock;
	 int listen_sock;
	 struct sockaddr_in client_addr;
	 struct sockaddr_in listen_addr;
	 int status = 0;
	 listen_sock = socket(AF_INET,SOCK_STREAM,0);
	 if (listen_sock < 0){
	 	printf("Socket error\n");
	 	return;
	 }
	 listen_addr.sin_family = AF_INET;
	 listen_addr.sin_port = htons(7000);
	 listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	 status = bind(listen_sock, (struct sockaddr*) &listen_addr, sizeof(listen_addr));
	 if (status == -1){
	 	printf("bind error");
	 }
	 unsigned int client_addr_size = sizeof(client_addr);
	 {
	 	client_sock = accept(listen_sock, (struct sockaddr*)&client_addr, &client_addr_size);
	 	send(client_sock,"Hello\n",6,0);
	 	char buf[100];
	 	int len = recv(client_sock, buf,99,0);
	 	
	 	shutdown(client_sock,SHUT)
	 }
}