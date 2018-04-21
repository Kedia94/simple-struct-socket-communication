all: client server client1

client: client.cpp
	g++ -o client client.cpp

client1: client1.cpp
	g++ -o client1 client1.cpp

server: server.cpp
	g++ -o server server.cpp -lpthread

clean:
	rm -rf client client1 server
