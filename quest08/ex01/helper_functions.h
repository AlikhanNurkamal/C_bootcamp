#include <stdlib.h>
#include <unistd.h>

int my_strlen( char* str )
{
	int len = 0;
	for ( int i = 0; str[i]; i++ )
		len++;

	return len;
}

int putchar( int ch )
{
        write( 1, &ch, 1 );
        return 0;
}

int putstr( char* str )
{
        while ( *str )
        {
                putchar( *str );
                str++;
        }

        return 0;
}

