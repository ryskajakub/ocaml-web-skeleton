#!/bin/bash

echo "change"

killall hello_world.exe 
./_build/default/hello_world.exe &

