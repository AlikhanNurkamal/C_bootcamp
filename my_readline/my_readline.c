#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int READLINE_READ_SIZE = 8;
char* line;

int my_getc( int fd )
{
    int ch;
    int bytes = read( fd, &ch, 1 );
    if ( bytes == 0 )
        return -1;
    return ch;
}

int my_putchar( int ch )
{
    write( 1, &ch, 1 );
    return 0;
}

int my_putstr( char* str )
{
    while ( *str )
    {
        my_putchar( *str );
        str++;
    }

    return 0;
}

void init_my_readline( )
{
    line = NULL;
    line = malloc( sizeof( char ) * READLINE_READ_SIZE );
}

char* my_readline( int fd )
{
    if ( fd < 0 )
        return NULL;

    char ch = my_getc( fd );

    if ( ch == -1 )
        return NULL;

    init_my_readline( );
    int pos = 0;
    
    while ( ch != '\n' && ch != -1 && pos < READLINE_READ_SIZE - 1 )
    {
        line[pos++] = ch;
        ch = my_getc( fd );
    }

    line[pos] = '\0';

    return line;
}

int main( int argc, char* argv[] )
{
    int fd = 0;

    if ( argc == 1 )
    {
        my_putstr( "Please enter a line to be read:\n" );
        line = my_readline( 0 );
        my_putstr( line );
        my_putchar( '\n' );
        free( line );

        return 0;
    }

    line = my_readline( -1 );

    for ( int i = 1; i < argc; i++ )
    {
        fd = open( argv[i], O_RDONLY );
        line = my_readline( fd );
        my_putstr( line );
        my_putchar( '\n' );
        free( line );

	    // while ( ( line = my_readline( fd ) ) )
	    // {
	    //     my_putstr( line );
        //     my_putchar( '\n' );
        //     free( line );
	    // }

	    close( fd );
    }

    return 0;
}

