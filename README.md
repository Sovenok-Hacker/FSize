# FSize
A little C program to get size of any file
![File Size Icon](/file.png)

# Installation
```
make build
sudo make install
```

# Usage
```
fsize LICENSE # output: 35 KB
fsize . # output: . is not a regular file or does not exist.
fsize /dev/null # output: /dev/null is not a regular file or does not exist.
```
