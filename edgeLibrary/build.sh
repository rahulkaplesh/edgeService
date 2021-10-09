if [ ! -d "bin" ]; then
    mkdir bin
fi

if [ ! -d "googletest" ]; then
    git clone https://github.com/google/googletest/
fi

cd bin
cmake -DCMAKE_BUILD_TYPE=Debug ../ 
make