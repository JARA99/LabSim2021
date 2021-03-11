# !/bin/bash

# Author: Jorge Alejandro Rodriguez Aldana
# Type: Bash Script
# Exe: ./C_Generator.sh
# Resume: Automatic C script generator with name comments

# Welcome

echo '            ┏━━━┓━━━━━┏━┓━━┏┓━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┏┓━━━━━━━━
            ┃┏━┓┃━━━━━┃┏┛━━┃┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┏┛┗┓━━━━━━━
            ┃┃━┗┛━━━━┏┛┗┓┏┓┃┃━┏━━┓━━━━┏━━┓┏━━┓┏━┓━┏━━┓┏━┓┏━━┓━┗┓┏┛┏━━┓┏━┓
            ┃┃━┏┓━━━━┗┓┏┛┣┫┃┃━┃┏┓┃━━━━┃┏┓┃┃┏┓┃┃┏┓┓┃┏┓┃┃┏┛┗━┓┃━━┃┃━┃┏┓┃┃┏┛
            ┃┗━┛┃━━━━━┃┃━┃┃┃┗┓┃┃━┫━━━━┃┗┛┃┃┃━┫┃┃┃┃┃┃━┫┃┃━┃┗┛┗┓━┃┗┓┃┗┛┃┃┃━
            ┗━━━┛━━━━━┗┛━┗┛┗━┛┗━━┛━━━━┗━┓┃┗━━┛┗┛┗┛┗━━┛┗┛━┗━━━┛━┗━┛┗━━┛┗┛━
            ━━━━━━━━━━━━━━━━━━━━━━━━━━┏━┛┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
            ━━━━━━━━━━━━━━━━━━━━━━━━━━┗━━┛━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
'

# Get the file name

read -p 'File name: ' name
if [ -z $name ]; then
    echo 'Not a valid name'
    exit 2
fi
file_name=$name'.c'

if [ -e $file_name ]; then
    echo 'The name already exists'
    exit 2
fi

echo 'The file will be stored at: ' $file_name

# Get the author name

user=$(whoami)
host=$(uname -n)
author=$user'@'$host

# Get date

date=$(date)

# Get gcc version

version=$(gcc --version | head -n 1)

# Generating the file

echo '/*' >> ./$file_name
echo 'Author:       ' $author >> ./$file_name
echo 'Compiler:     ' $version >> ./$file_name
echo 'For compile:   gcc' $file_name ' -o ' $name >> ./$file_name
echo 'Date:         ' $date >> ./$file_name
echo 'Libraries:     stdio' >> ./$file_name
echo 'Abstract:     ' >> ./$file_name
echo 'Inputs:       ' >> ./$file_name
echo 'Outputs:      ' >> ./$file_name
echo '*/            ' >> ./$file_name

echo '' >> ./$file_name
echo '' >> ./$file_name

echo '///////////////////////////////////////////////////////////////////////' >> ./$file_name
echo '////////////////////////////// Libraries //////////////////////////////' >> ./$file_name
# echo '///////////////////////////////////////////////////////////////////////' >> ./$file_name

echo '' >> ./$file_name

echo '#include <stdio.h>' >> ./$file_name

echo '' >> ./$file_name
echo '' >> ./$file_name

echo '///////////////////////////////////////////////////////////////////////' >> ./$file_name
echo '/////////////////////////// Pseudocode steps //////////////////////////' >> ./$file_name
# echo '///////////////////////////////////////////////////////////////////////' >> ./$file_name

# Make it executable, and ignore the file in git

chmod +x $file_name
echo '/Bash/'$name >> ../.gitignore