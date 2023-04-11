#pragma once 
#include "Comms.h"
#include <arpa/inet.h>

class Client : public Comms {
public:
    Client();
    void ConnectSocket();
    string UserInput();
    string SendMessage();
    void RecieveMessage(char* buffer, int size);
    void BeginChat();
};