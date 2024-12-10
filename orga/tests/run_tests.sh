#!/bin/bash
for file in /home/$USER/Desktop/MiniRT/orga/tests/*.rt; do
    echo "Testing $file"
    /home/$USER/Desktop/MiniRT/miniRT "$file" >> output.log 2>&1
    cat output.log
done
