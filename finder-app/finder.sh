#!/bin/bash



filesdir="$1"
searchstr="$2"

if [ $# -ne 2 ]; then
    echo "Error: Two arguments are required."
    exit 1
fi



# Check if the 'filesdir' variable is set and matches the expected value
if [ ! -d "$filesdir" ]; then
    echo "Error: The 'filesdir' directory '$filesdir' does not exist or is not valid."
    exit 1
fi



# Count the number of files
num_files=$(find "$filesdir" -type f | wc -l)

# Count the number of subdirectories (excluding the root directory)
num_subdirectories=$(find "$filesdir" -type d -mindepth 1 | wc -l)

X=$((num_files + num_subdirectories))
Y=$(grep -r "$searchstr" "$filesdir" | wc -l)

echo "The number of files are $X and the number of matching lines are $Y"
