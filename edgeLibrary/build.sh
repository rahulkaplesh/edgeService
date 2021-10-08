if [ ! -d "bin" ]; then
    mkdir bin
fi

cd bin
cmake -DCMAKE_BUILD_TYPE=Debug ../ 
make