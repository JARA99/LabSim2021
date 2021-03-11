# !/bin/bash

# Author: Jorge Alejandro Rodriguez Aldana
# Type: Bash Script
# Exe: ./WeatherReport.sh
# Resume: Prints the weather report


# Get the information
curl wttr.in/Guatemala -o data.dat # This thing by itself looks amazingly good by the way

## Just for better looking
echo ''
echo ''
echo ''
echo ''

# Read the first 7 lines
head -7 data.dat 

## Again, just for better looking
echo ''
echo ''

# Delete the data archive
rm data.dat
