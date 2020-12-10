#include "Viewer.h"

Viewer::Viewer() {
    loginWidget = std::make_shared<LoginWidget>();
    mainWidget = std::make_shared<MainWidget>();
    connect(loginWidget.get(), SIGNAL(openMainWidget()),
            mainWidget.get(), SLOT(after_login()));
}

void Viewer::runApp() {
    auto controller = Controller::getInstance();
    controller->runClient("127.0.0.1", "5555", [](int error) {
        std::cout << "Client error: " << error << std::endl;
    });

    loginWidget->show();
}
