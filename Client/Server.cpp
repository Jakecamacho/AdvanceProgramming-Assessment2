#include "Server.h"

Server::Server(){
    serverAddress.sin_family = AF_INET; // domain address (IPv4)
    serverAddress.sin_port = htons(port); // Host Address
    serverAddress.sin_addr.s_addr = htons(INADDR_ANY); // uses port defined in the header file and converts the port mumber from host to network short 
//     string address = "127.0.0.1";
//     inet_pton(AF_INET, address.c_str(), &serverAddress.sin_addr);
//     char host[NI_MAXHOST];
// 	char service[NI_MAXSERV];
}

void Server:: BindSocket(){
    try {
        if (::bind(sock,(sockaddr *) &serverAddress, sizeof(serverAddress)) == -1){ // if there is a problem binding then throw the below error 
            throw ("Oh no there was an error with the connection binding"); 
        }
    }
    catch (exception &e) {
        cout << "Error:" << e.what() << endl;
    }
    cout << "Socket bound" << endl;
}

void Server :: ListenSocket(){
    try {
        if (listen(sock, SOMAXCONN) == -1){ // if their is a problem listening then throw the below error 
            throw ("Error listening to the port");
        }
    }
    catch (exception &e){
        cout << "Error:" << e.what() << endl;
    }
    cout << "Server listening on port"<< port << endl;
}

void Server :: AcceptSocket(){
    sockaddr_in sockAddress; // instantiate structure for having the clients IP address 
    socklen_t client_socket_length = sizeof(sockAddress); // hold the socket length 
    try {
        int server = accept(sock, (sockaddr*) &sockAddress, &client_socket_length); // try to establish a connection with the client and if unable throw an error;
        if (server == -1){
            throw ("Oh no there was an error with accepting the connection");
        }
    }
    catch (exception &e){
        cout << "Error:" << e.what() << endl;
    }
    
}

string Server:: UserInput() {
    string message;
    cout<< "Server:";
    getline(cin, message);
    return message;
}

string Server:: SendMessage(){
    string message = UserInput(); // assign value returned from the getinput function to string
    try {
        if (send(server, message.c_str(), message.size()+1 , 0) == -1){ // if this fails then return the error 
            throw ("Oh no there was an error sending the message");
        }
    }
    catch (exception &e){
        cout << "Error:" << e.what() << endl;
    }
    return message;
};

void Server:: RecieveMessage(char *buffer, int size){
    cout<< "yo yo "<< endl;
    int recieved =recv(server, buffer, size, 0);
    cout << strerror(errno) << endl;
    cout<< recieved << endl;
    try {
        if (recieved == -1){ // if the server fails to recieve the message then throw an error 
          throw ("Oh no there was an error receiving the message"); 
        }
        else {
            cout<< "Client:";
        }
    }
    catch (exception &e) {
        cout << "Error:" << e.what() << endl;
    }

}

void Server:: BeginChat() {
    while(true) {
        cout<< "hey" << endl;
        char buffer [bufferSize] ; // instantiate buffer array to a size of 1024 
        cout<< "y" << endl;
        RecieveMessage(buffer, bufferSize); // call recieve message function defined above with the message and size 
        cout<< buffer << endl;
        if (Quit(buffer)) { // check if the user has writeen quite and if so exit the chat 
           cout << "The chat has ended" << endl;
        }
        string message = SendMessage(); // calls the function above
        char input_string[message.length() + 1]; // instantiate  the input string array, adding 1 to the length 
        strcpy(input_string, message.c_str());
        if (Quit(input_string)){ // check if quit has been mentioned in the chat 
            cout << "The chat has ended" << endl;
        };
        
    }
    CloseSocket();
}