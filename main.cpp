#include "src/server/lib/Server/Server/HttpServer.h"

int main() {
    HttpServer server = HttpServer();
    server.startServer(5556);
    return 0;
}
