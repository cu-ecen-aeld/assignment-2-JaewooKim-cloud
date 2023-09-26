#!/bin/bash



writefile="$1"
writestr="$2"

if [ $# -ne 2 ]; then
    echo "Error: Two arguments are required."
    exit 1
fi


# Extract the directory path from the file path
directory_path="$(dirname "$writefile")"

# Create the directory path, including any necessary parent directories
mkdir -p "$directory_path"


# Ensure the file exists (create it if it doesn't)
touch "$writefile"


# Use echo to write or overwrite the file
echo "$writestr" > "$writefile"

# Check if the file was created or overwritten successfully
if [ -e "$writefile" ]; then
    echo "File created or overwritten successfully at: $writefile"
else
    echo "Failed to create or overwrite the file at: $writefile"
    exit 1
fi
