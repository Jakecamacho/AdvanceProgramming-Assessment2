#pragma once 
#include "Comms.h"
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstdlib>
#include <cstring>
#include <netdb.h> 
#include <arpa/inet.h>

class Server : public Comms {
protected:
    int server;
public:
    Server();
    void BindSocket();
    void ListenSocket();
    void AcceptSocket();
    void RecieveMessage(char * buffer, int size);
    void BeginChat();    
    string UserInput();
    string SendMessage();
};