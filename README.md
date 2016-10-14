
****************************************
Simple example of calling shared library
****************************************

Guilty parties
--------------
Ian Bell, 2016

To build
--------

First:

    git clone --recursive https://github.com/CoolProp/CoolProp
    cd CoolProp
    mkdir build
    cd build
    cmake .. -DCOOLPROP_SHARED_LIBRARY=ON
    cmake --build . --config Release

Then in that directory with libCoolProp.dylib (or libCoolProp.so on unix):

    g++ main.cpp -I../../include -L. -lCoolProp && ./a.out