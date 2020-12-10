FROM ubuntu
RUN apt update

RUN apt update && \
    apt upgrade -y


RUN apt install valgrind -y
RUN apt install gcovr -y
RUN apt install lcov -y
RUN apt install libboost-all-dev -y

RUN apt install -qq g++-9 -y
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 100

#ENV CMAKE_VERSION=3.17.0
#ENV CMAKE_VERSION_DIR=v3.17
#
#ENV CMAKE_OS=Linux-x86_64
#ENV CMAKE_TAR=cmake-$CMAKE_VERSION-$CMAKE_OS.tar.gz
#ENV CMAKE_URL=http://www.cmake.org/files/$CMAKE_VERSION_DIR/$CMAKE_TAR
#ENV CMAKE_DIR=$pwd/cmake-$CMAKE_VERSION

RUN apt install wget -y
#RUN wget $CMAKE_URL
#RUN mkdir -p $CMAKE_DIR
#RUN tar --strip-components=1 -xzf $CMAKE_TAR -C $CMAKE_DIR
#ENV PATH=$CMAKE_DIR/bin:$PATH


RUN apt install cmake -y
RUN apt install qt5-default -y

COPY . .
#CMD /bin/bash

RUN cmake -DCMAKE_BUILD_TYPE=Test ./

RUN make
CMD ./Application


#RUN apt-get -y install firefox
#
#CMD ["firefox"]
