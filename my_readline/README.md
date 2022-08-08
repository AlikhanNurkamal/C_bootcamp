# Welcome to My Readline

## Task
The main task of this exercise is to re-build the readline( ) function in C. The function is supposed to read one line at a time from a specified file (either file in the current directory or STDIN).

## Description
The problem has been easily solved using the basic understanding of open( ), read( ), write( ) functions. What is more, in this task the use of pointers is crucial.

## Installation
In order to install the program, you just need to enter the following line of code to the console:
```
gcc -o my_readline my_readline.c
```
This will compile the project and save the executable file as `my_readline`.

## Usage
After the project is installed, you can run it using:
```
./my_readline
```
OR
```
./ my_readline arg1 arg2 ...
```

The first usage runs with STDIN, so the program reads a line from the console input. Whereas the second version opens files, whose names are given as arg1, arg2, etc., and reads lines from them.

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar Silicon Valley</a></i></span>
<span><img alt='Qwasar Silicon Valley Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
