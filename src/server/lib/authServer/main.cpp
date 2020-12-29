#include "src/server/lib/authServer/Server/Server/Server.h"

int main() {
    Server server = Server();
    server.startServer(5555);
    return 0;
}
