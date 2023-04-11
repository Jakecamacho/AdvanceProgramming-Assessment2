#include "Comms.h"

void Comms :: OpenSocket() {
    sock = socket(AF_INET, SOCK_STREAM, 0); // socket takes the address domain (IPv4), socket type TCP  and protocol

    try {
        if (sock == -1) { // if there is an error with creatiing the socet then throw an error 
            throw ("Error establishing socket");
        }
    }
    catch(exception &e){
        cout << "Error:" << e.what() << endl;
            
    }
}

void Comms :: CloseSocket() const { // closed client file descriptior 
    close(sock);
} 

bool Comms :: Quit(char* message) {  // checks if the user has entered quit and if they have then the chat will be terminated 
    return strcmp(message, "Quit") ==0;
    cout<< "Goodbye!" << endl;
}

