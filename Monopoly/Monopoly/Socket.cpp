#include <stdio.h>
#include <winsock2.h>
#pragma comment (lib, "ws2_32.lib")
#define PORT 3900
#define IP "127.0.0.1"
#define BACKLOG 10
class SockSet
{
	private:
		WSADATA wsaData;
		SOCKET sock;
		SOCKET newsock;
		SOCKADDR newAddr;
		sockaddr_in sockAddr;
	public:
		SockSet(){};
		SockSet(char ip[])
		{
			WSAStartup(MAKEWORD(2, 2), &wsaData);
			memset(&sockAddr, 0, sizeof(sockAddr));
			sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
			sockAddr.sin_family = PF_INET;
			sockAddr.sin_addr.s_addr = inet_addr(ip);
			sockAddr.sin_port = htons(PORT);
		};
		void Server()
		{
			bind(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
			listen(sock, 20);
			int nSize = sizeof(SOCKADDR);
			newsock = accept(sock, (SOCKADDR*)&newAddr, &nSize);
			
		}
		void Client()
		{
			connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
		}
		SOCKET GetSock(){return sock;}
		SOCKET GetClientSock(){ return newsock; }
		int Server_R()
		{
			int nbyte;
			char buffer[MAXBYTE];
			nbyte = recv(newsock, buffer, MAXBYTE, NULL);
			recv(newsock, buffer, MAXBYTE, NULL);
			return buffer[0] - '0';
		}

		int Client_R()
		{
			int nbyte;
			char buffer[MAXBYTE];
			nbyte = recv(sock, buffer, MAXBYTE, NULL);
			recv(sock, buffer, MAXBYTE, NULL);
			return buffer[0] - '0';
		}
		
};