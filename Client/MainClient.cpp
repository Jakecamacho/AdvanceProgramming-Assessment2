#include "Client.h"
#include <iostream>

using namespace std;


int main() {

    cout<< "The chat will now begin with the Server"<< endl;
    auto *client = new Client(); // Instantiate new Server class object
    client->OpenSocket(); // call open socket function 
    client->ConnectSocket(); // calls connect socket function 
    client->BeginChat(); // calls begin chat function 

}