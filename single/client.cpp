#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>

#include "util.h"

#define NANS_MAX_MESSAGE_LENGTH 10

int main()
{
	int sockfd;
	struct sockaddr_in clientaddr;
	bool isConnected;
	int clientlen = sizeof(clientaddr);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	clientaddr.sin_family = AF_INET;
	clientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	clientaddr.sin_port = htons(PORT);

	if (!(isConnected = (connect(sockfd, (struct sockaddr *)&clientaddr, clientlen) >= 0)))
	{
		std::cout<<"Connection Error"<<std::endl;
	}

	/* XXX: Fix below box for client part */
	{
		int i;
		for (i=0;i<10; i++)
		{
			struct data databuf = {};

			/* is there is a data */
			if (i % 2 == 0)
			{
				databuf.isSteeringAngle = true;
				databuf.steeringAngle = 30.1 + i;
			} else
			{
				databuf.isMotorSpeed = true;
				databuf.motorSpeed = i;
			}
			std::cout<<"Created Message"<<std::endl;
			if (isConnected)
				send(sockfd, &databuf, sizeof(databuf), 0);
		}
	}
	/* XXX: Fix above box for client part */



	if (isConnected)
			close(sockfd);
	return 0;
}
