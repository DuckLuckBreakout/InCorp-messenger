FROM ubuntu

RUN apt update && \
    apt upgrade -y && \
    apt install valgrind -y && \
    apt install gcovr -y && \
    apt install lcov -y && \
#    apt install libboost-all-dev -y && \
    apt install -qq g++-9 -y && \
    update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 100

#ENV CMAKE_VERSION=3.17.0
#ENV CMAKE_VERSION_DIR=v3.17
#ENV CMAKE_OS=Linux-x86_64
#ENV CMAKE_TAR=cmake-$CMAKE_VERSION-$CMAKE_OS.tar.gz
#ENV CMAKE_URL=http://www.cmake.org/files/$CMAKE_VERSION_DIR/$CMAKE_TAR
#ENV CMAKE_DIR=$pwd/cmake-$CMAKE_VERSION

#RUN apt install wget -y
#RUN wget $CMAKE_URL
#RUN mkdir -p $CMAKE_DIR
#RUN tar --strip-components=1 -xzf $CMAKE_TAR -C $CMAKE_DIR
#ENV PATH=$CMAKE_DIR/bin:$PATH


RUN apt install cmake -y
RUN apt install curl -y
#RUN curl -OL https://github.com/mongodb/mongo-cxx-driver/releases/download/r3.6.2/mongo-cxx-driver-r3.6.2.tar.gz
#RUN tar -xzf mongo-cxx-driver-r3.6.2.tar.gz
#WORKDIR mongo-cxx-driver-r3.6.2/build
#RUN apt install -y mongodb
RUN apt-get install -y \
    openssh-server \
    g++ \
    cmake \
    git

RUN apt install libboost-all-dev -y
#installing the mongoc dependencies and driver
RUN apt-get install -y \
    pkg-config \
    libssl-dev \
    libsasl2-dev


##installing mongocxx driver - connects c++ to mongo
#RUN cd ~ \
#    && wget https://github.com/mongodb/mongo-cxx-driver/archive/r3.6.2.tar.gz \
#    && tar -xzf r3.6.2.tar.gz \
#    && cd mongo-cxx-driver-r3.6.2/build \
#    && cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local .. \
#    && make EP_mnmlstc_core \
#    && make \
#    && make install \
#    && cd ~ \
#    && rm r3.6.2.tar.gz \
#    && rm -rf mongo-cxx-driver-r3.6.2
# RUN apt install libmongoc-1.0-0 -y
# RUN apt install libbson-1.0-0 -y
#
# RUN wget https://github.com/mongodb/mongo-c-driver/releases/download/1.17.3/mongo-c-driver-1.17.3.tar.gz \
#     && tar xzf mongo-c-driver-1.17.3.tar.gz \
#     && cd mongo-c-driver-1.17.3 \
#     && mkdir cmake-build \
#     && cd cmake-build \
#     && cmake -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF .. \
#     && cmake --build . \
#     && cmake --build . --target install
#
#
# RUN curl -OL https://github.com/mongodb/mongo-cxx-driver/releases/download/r3.6.2/mongo-cxx-driver-r3.6.2.tar.gz \
#     && tar -xzf mongo-cxx-driver-r3.6.2.tar.gz \
#     && cd mongo-cxx-driver-r3.6.2/build \
#     && cmake ..                                \
#            -DCMAKE_BUILD_TYPE=Release          \
#            -DCMAKE_INSTALL_PREFIX=/usr/local \
#     && cmake ..                                            \
#            -DCMAKE_BUILD_TYPE=Release                      \
#            -DCMAKE_PREFIX_PATH=/opt/mongo-c-driver         \
#            -DCMAKE_INSTALL_PREFIX=/opt/mongo-cxx-driver \
#     && cmake --build . \
#     && cmake --build . --target install

COPY . .
#CMD /bin/bash
# RUN apt install gnupg -y
# RUN wget -qO - https://www.mongodb.org/static/pgp/server-4.4.asc | apt-key add -
# RUN wget -qO - https://www.mongodb.org/static/pgp/server-4.4.asc | apt-key add -
# RUN echo "deb [ arch=amd64,arm64 ] https://repo.mongodb.org/apt/ubuntu focal/mongodb-org/4.4 multiverse" | tee /etc/apt/sources.list.d/mongodb-org-4.4.list
# RUN apt update
# RUN apt install -y mongodb-org
# RUN mongo

RUN cmake -DCMAKE_BUILD_TYPE=Test ./

RUN make || make
# RUN make
CMD ./test_mongocxx
# CMD /bin/bash

#RUN apt-get -y install firefox
#
#CMD ["firefox"]