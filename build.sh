#!/bin/bash

g++ -fpic --shared $(python3-config --includes) geometry.cpp geometrymodule.cpp -o geometry.abi3.so
