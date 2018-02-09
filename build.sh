#!/bin/bash
gcc yapi/yapi.c -c
gcc yapi/yfifo.c -c
gcc yapi/yhash.c -c
gcc yapi/yjni.c -c
gcc yapi/yjson.c -c
gcc yapi/ykey.c -c
gcc yapi/ymemory.c -c
gcc yapi/ypkt_lin.c -c
gcc yapi/ypkt_osx.c -c
gcc yapi/ypkt_win.c -c
gcc yapi/yprog.c -c
gcc yapi/ystream.c -c
gcc yapi/ytcp.c -c
gcc yapi/ythread.c -c
g++ yocto_api.cpp -c
g++ yocto_relay.cpp -c
g++ yocto_temperature.cpp -c
g++ main.cpp yapi.o yfifo.o yhash.o yjni.o yjson.o ykey.o ymemory.o ypkt_lin.o ypkt_osx.o ypkt_win.o yprog.o ystream.o ytcp.o ythread.o yocto_api.o yocto_relay.o yocto_temperature.o  -lpthread -lusb-1.0