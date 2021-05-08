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

if [ -e $name/$file_name ]; then
    echo 'The name already exists'
    exit 2
fi

echo 'The file will be stored at: ' $name '/' $file_name

# Get the author name

user=$(whoami)
host=$(uname -n)
author=$user'@'$host

# Get date

date=$(date)

# Get gcc version

version=$(gcc --version | head -n 1)

# Generating the file

mkdir $name
echo '/*' >> ./$name/$file_name
echo 'Author:       ' $author >> ./$name/$file_name
echo 'Compiler:     ' $version >> ./$name/$file_name
echo 'For compile:   gcc' $file_name ' -lm -o ' $name ' && ./'$name >> ./$name/$file_name
echo 'Date:         ' $date >> ./$name/$file_name
echo 'Libraries:     stdio' >> ./$name/$file_name
echo 'Abstract:     ' >> ./$name/$file_name
echo 'Inputs:       ' >> ./$name/$file_name
echo 'Outputs:      ' >> ./$name/$file_name
echo '*/            ' >> ./$name/$file_name

echo '' >> ./$name/$file_name
echo '' >> ./$name/$file_name

echo '///////////////////////////////////////////////////////////////////////' >> ./$name/$file_name
echo '////////////////////////////// Libraries //////////////////////////////' >> ./$name/$file_name
# echo '///////////////////////////////////////////////////////////////////////' >> ./$name/$file_name

echo '' >> ./$name/$file_name

echo '#include <stdio.h>' >> ./$name/$file_name

echo '' >> ./$name/$file_name
echo '' >> ./$name/$file_name

echo '///////////////////////////////////////////////////////////////////////' >> ./$name/$file_name
echo '/////////////////////////////// Constants /////////////////////////////' >> ./$name/$file_name
# echo '///////////////////////////////////////////////////////////////////////' >> ./$name/$file_name

echo '' >> ./$name/$file_name
echo '' >> ./$name/$file_name

echo '///////////////////////////////////////////////////////////////////////' >> ./$name/$file_name
echo '/////////////////////////////// Variables /////////////////////////////' >> ./$name/$file_name
# echo '///////////////////////////////////////////////////////////////////////' >> ./$name/$file_name

echo '' >> ./$name/$file_name
echo '' >> ./$name/$file_name

echo '///////////////////////////////////////////////////////////////////////' >> ./$name/$file_name
echo '/////////////////////////////// Functions /////////////////////////////' >> ./$name/$file_name
# echo '///////////////////////////////////////////////////////////////////////' >> ./$name/$file_name

echo '' >> ./$name/$file_name
echo '' >> ./$name/$file_name

echo '///////////////////////////////////////////////////////////////////////' >> ./$name/$file_name
echo '///////////////////////////////   Code    /////////////////////////////' >> ./$name/$file_name
# echo '///////////////////////////////////////////////////////////////////////' >> ./$name/$file_name

echo '' >> ./$name/$file_name
echo '' >> ./$name/$file_name

# Make it executable, and ignore the file in git

chmod +x $name/$file_name
echo $name >> ./$name/.gitignore

# Create a readme

echo '#    ' $name >> ./$name/README.md
echo '' >> ./$name/README.md
echo '' >> ./$name/README.md
echo '' >> ./$name/README.md

echo '##    Documentación para el usuario'  >> ./$name/README.md
echo '' >> ./$name/README.md
echo '' >> ./$name/README.md
echo '' >> ./$name/README.md

echo '##    Método'  >> ./$name/README.md
echo '' >> ./$name/README.md
echo '' >> ./$name/README.md
echo '' >> ./$name/README.md

echo '##    Variables'  >> ./$name/README.md
echo '' >> ./$name/README.md

echo '###   Entrada'  >> ./$name/README.md
echo '' >> ./$name/README.md
echo '' >> ./$name/README.md
echo '' >> ./$name/README.md

echo '###   Salida'  >> ./$name/README.md
echo '' >> ./$name/README.md
echo '' >> ./$name/README.md
echo '' >> ./$name/README.md

echo '###   Otras variables'  >> ./$name/README.md
echo '' >> ./$name/README.md
echo '' >> ./$name/README.md
echo '' >> ./$name/README.md

echo '##    Pseudocódigo'  >> ./$name/README.md
echo '' >> ./$name/README.md
echo '' >> ./$name/README.md
echo '' >> ./$name/README.md

echo '##    [Código]('$file_name')'  >> ./$name/README.md