#include "Server/HttpServer.h"


int main() {
    HttpServer server;
    server.startServer(5555);
    return 0;
}
