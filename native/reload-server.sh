#!/bin/bash

echo "restaring runner.exe"

killall runner.exe 
./_build/default/runner.exe &

