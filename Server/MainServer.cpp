#include "Server.h"
#include <iostream>

using namespace std;


int main() {
    cout<< "The chat will now begin with the client"<< endl;
    auto *server = new Server(); // Instantiate new Server class object
    server->OpenSocket(); // calls opensocket function 
    server->BindSocket(); // calls bind socket function 
    server->ListenSocket(); // calls listen socket function 
    server->AcceptSocket(); // calls accept socket function 
    server->BeginChat(); // calls begin chat function 

}