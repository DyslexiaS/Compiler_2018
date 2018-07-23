#!/bin/bash
make
./myparser < $1
java -jar jasmin.jar Computer.j
java main
