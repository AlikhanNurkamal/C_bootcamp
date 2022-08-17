#include "helper_functions.h"
int my_putchar( char ch )
{
    write( 1, &ch, 1 );
    return 0;
}

int my_putstr( char* str )
{
    while ( *str )
        my_putchar( *str++ );

    return 0;
}

int my_strlen( const char* str )
{
    int len = 0;
    for ( int i = 0; str[i]; i++ )
        len++;

    return len;
}

int my_strcmp( char* str1, char* str2 )
{
    int i = 0;
    while ( str1[i] && str2[i] && str1[i] == str2[i] )
        i++;

    return str1[i] - str2[i];
}

void my_strcpy( char* dest, const char* source )
{
    int pos = 0;
    while ( source[pos] )
    {
        dest[pos] = source[pos];
        pos++;
    }

    dest[pos] = '\0';
}

void my_strcat( char* dest, const char* source )
{
    int i = 0;
    while ( dest[i] )
        i++;

    int pos = 0;
    while ( source[pos] )
        dest[i++] = source[pos++];

    dest[i] = '\0';
}