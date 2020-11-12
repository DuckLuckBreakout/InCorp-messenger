#include "Server/Server/HttpServer.h"

int main() {
    HttpServer server = HttpServer();
    server.startServer(5000);
    return 0;
}
