#include "Comms.h"

void Comms :: OpenSocket() {
    sock = socket(AF_INET, SOCK_STREAM, 0);

    try {
        if (sock == -1) {
            throw ("Error establishing socket");
        }
    }
    catch(exception &e){
        cout << "Error:" << e.what() << endl;
            
    }
}

void Comms :: CloseSocket() const {
    close(sock);
} 

bool Comms :: Quit(char* message) {
    return strcmp(message, "Quit") ==0;
}

