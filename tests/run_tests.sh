#!/bin/bash
for file in /home/$USER/Desktop/minirt_gh/tests/*.rt; do
    echo "Testing $file"
    /home/$USER/Desktop/minirt_gh/miniRT "$file" >> output.log 2>&1
	sleep 0.5
    cat output.log
done
