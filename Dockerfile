FROM ubuntu

RUN apt update && \
    apt upgrade -y && \
    apt install valgrind -y && \
    apt install gcovr -y && \
    apt install lcov -y && \
    apt install -qq g++-9 -y && \
    update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 100


RUN apt update

RUN apt update && \
    apt upgrade -y


RUN apt install valgrind -y
RUN apt install gcovr -y
RUN apt install lcov -y
RUN apt install libboost-all-dev -y

RUN apt install -qq g++-9 -y
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 100

RUN apt install wget -y


RUN apt install cmake -y
RUN apt install curl -y

RUN apt-get install -y \
    openssh-server \
    g++ \
    cmake \
    git

RUN apt install libboost-all-dev -y
RUN apt-get install -y \
    pkg-config \
    libssl-dev \
    libsasl2-dev


COPY . .

RUN cmake -DCMAKE_BUILD_TYPE=TestServer ./

RUN make || make
RUN ./Application || true


RUN cd CMakeFiles/Application.dir \ &&
    lcov --directory . --capture --output-file coverage.info \ &&
    lcov --remove coverage.info '/usr/*' "${HOME}"'/.cache/*' --output-file coverage.info \ &&
    lcov --list coverage.info \ &&
    bash "<(curl -s https://codecov.io/bash)" -f coverage.info \ &&
    cd .. \ &&
    cd ..

RUN apt install qt5-default -y

RUN cmake -DCMAKE_BUILD_TYPE=TestClient ./

RUN make
CMD ./Application

RUN cd CMakeFiles/Application.dir \ &&
    lcov --directory . --capture --output-file coverage.info \ &&
    lcov --remove coverage.info '/usr/*' "${HOME}"'/.cache/*' --output-file coverage.info \ &&
    lcov --list coverage.info \ &&
    bash "<(curl -s https://codecov.io/bash)" -f coverage.info
