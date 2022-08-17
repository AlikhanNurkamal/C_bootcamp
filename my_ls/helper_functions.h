#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
int my_putchar( char ch );

int my_putstr( char* str );

int my_strlen( const char* str );

int my_strcmp( char* str1, char* str2 );

void my_strcpy( char* dest, const char* source );

void my_strcat( char* dest, const char* source );