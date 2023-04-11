#include "Client.h"

Client:: Client() {
    serverAddress.sin_family = AF_INET; // Use the IPv4 Domain
    serverAddress.sin_port = htons(port); // uses port defined in the header file and converts the port mumber from host to network short 
    // string address = "127.0.0.1";
    // inet_pton(AF_INET, address.c_str(), &serverAddress.sin_addr);
    // char host[NI_MAXHOST];
	// char service[NI_MAXSERV];
}

void Client:: ConnectSocket() {
    try {
        int connection = connect(sock, (sockaddr*) &serverAddress, sizeof(serverAddress)); // try to connect and if not throw and error and then catch the error 
        if (connection == -1){
            throw ("Error trying to connect to socket");
        }

    }
    catch (exception &e){
        cout << "Error:" << e.what() << endl;
    }

    cout << "Sucessful connection via port number" << port << endl;
}

string Client:: UserInput() {
    string message; // creates a string variable 
    cout<< "Client:"; // allows client to enter in their message 
    getline(cin, message); // stores this in the input variable 
    return message; // returns input 
}

string Client:: SendMessage(){
    string message = UserInput(); //assigns the value returned from the function above to an input varaible 
    try {
        if (send(sock, message.c_str(), message.size()+1 , 0) == -1){ //if it equals the error code -1 then throw and error 
            throw ("Oh no there was an error sending the message");
        }
    }
    catch (exception &e){
    cout << "Error:" << e.what() << endl;
    }
    return message; // if not then return the message 
}

void Client:: RecieveMessage(char *buffer, int size){ // if the clients does not recieve the message then catch the error 
    try {
        if (recv(sock, buffer, size, 0) == -1){
          throw ("Oh no there was an error receiving the message"); 
        }
        else {
            cout<< "Server:";
        }
    }
    catch (exception &e) {
        cout << "Error:" << e.what() << endl;
    }

}

void Client:: BeginChat(){
    while (true){
        string message = SendMessage(); // calls the function above 
        char input_string[message.length() + 1]; // instantiate  the input string array, adding 1 to the length 
        if (Quit(input_string)){ // check if quit has been mentioned in the chat 
            cout << "The chat has ended" << endl; //this will print out the exit message to the chat
        };
        char buffer [bufferSize]; // instantiate buffer array to a size of 1024 
        RecieveMessage(buffer, bufferSize); // call recieve message function defined above with the message and size 
        cout<< buffer << endl;
        if (Quit(buffer)){ // check if the user has writeen quite and if so exit the chat 
            cout << "The chat has ended" << endl;
        }
    }
    CloseSocket(); 
}