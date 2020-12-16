#include "src/server/lib/authServer/Server/Server/HttpServer.h"

int main() {
    HttpServer server = HttpServer();
    server.startServer(5555);
    return 0;
}
