#!/bin/bash
for file in tests/*.rt; do
    echo "Testing $file"
    /home/afoth/Desktop/MiniRT/miniRT $file > output.log 2>&1
    cat output.log
done
#./run_tests.sh
