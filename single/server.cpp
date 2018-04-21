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
	struct sockaddr_in serveraddr, clientaddr;
	socklen_t clientlen = sizeof(clientaddr);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	serveraddr.sin_port = htons(PORT);

	if (bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
	{
		std::cout<<"Binding Error"<<std::endl;
		return -1;
	}

	listen(sockfd, 5);
	int newsockfd = accept(sockfd, (struct sockaddr *)&clientaddr, &clientlen);

	/* XXX: Fix below box for server part */
	{
		struct data databuf;
		while(recv(newsockfd, &databuf, sizeof(databuf), 0) > 0)
		{
			std::cout<<"New Message"<<std::endl;
			if (databuf.isSteeringAngle)
				std::cout << "angle: "<<databuf.steeringAngle<<std::endl;
			if (databuf.isMotorSpeed)
				std::cout <<"speed: "<<databuf.motorSpeed<<std::endl;
			std::cout<<std::endl;
		}
	}
	/* XXX: Fix above box for server part */
	
	close(newsockfd);
	close(sockfd);
	return 0;
}
