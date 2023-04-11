#pragma once
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstdlib>
#include <cstring>
#include <netdb.h> 
#include <arpa/inet.h>

using namespace std;

class Comms {
protected: 
    int port = 54000;
    int bufferSize = 4096;
    int sock;
    sockaddr_in serverAddress;
public: 
    Comms() = default;
    void OpenSocket();
    void CloseSocket() const;
    bool Quit(char* message);
};