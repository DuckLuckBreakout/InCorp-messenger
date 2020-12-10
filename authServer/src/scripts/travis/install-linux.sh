
sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
sudo apt update -qq

sudo apt install -qq g++-9
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 100

CMAKE_VERSION=3.17.0
CMAKE_VERSION_DIR=v3.17

CMAKE_OS=Linux-x86_64
CMAKE_TAR=cmake-$CMAKE_VERSION-$CMAKE_OS.tar.gz
CMAKE_URL=http://www.cmake.org/files/$CMAKE_VERSION_DIR/$CMAKE_TAR
CMAKE_DIR=$(pwd)/cmake-$CMAKE_VERSION

wget --quiet $CMAKE_URL
mkdir -p $CMAKE_DIR
tar --strip-components=1 -xzf $CMAKE_TAR -C $CMAKE_DIR
export PATH=$CMAKE_DIR/bin:$PATH

sudo apt install curl -y
sudo apt install valgrind
sudo apt install gcovr
sudo apt install lcov
sudo apt install libboost-all-dev
sudo apt install -y mongodb
sudo apt install -y \
    openssh-server \
    g++ \
    cmake \
    git

sudo apt install libmongoc-1.0-0 -y
sudo apt install libbson-1.0-0 -y

sudo wget https://github.com/mongodb/mongo-c-driver/releases/download/1.17.3/mongo-c-driver-1.17.3.tar.gz \
     && tar xzf mongo-c-driver-1.17.3.tar.gz \
     && cd mongo-c-driver-1.17.3 \
     && mkdir cmake-build \
     && cd cmake-build \
     && cmake -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF .. \
     && cmake --build . \
     && cmake --build . --target install


sudo curl -OL https://github.com/mongodb/mongo-cxx-driver/releases/download/r3.6.2/mongo-cxx-driver-r3.6.2.tar.gz \
     && tar -xzf mongo-cxx-driver-r3.6.2.tar.gz \
     && cd mongo-cxx-driver-r3.6.2/build \
     && cmake ..                                \
           -DCMAKE_BUILD_TYPE=Release          \
           -DCMAKE_INSTALL_PREFIX=/usr/local \
     && cmake ..                                            \
           -DCMAKE_BUILD_TYPE=Release                      \
           -DCMAKE_PREFIX_PATH=/opt/mongo-c-driver         \
           -DCMAKE_INSTALL_PREFIX=/opt/mongo-cxx-driver \
     && cmake --build . \
     && cmake --build . --target install