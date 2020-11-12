#include "Server/HttpServer.h"


int main() {
    HttpServer server;
    server.startServer(5000);
    return 0;
}
