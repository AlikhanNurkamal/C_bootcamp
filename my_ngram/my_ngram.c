#include <stdlib.h>
#include <unistd.h>

int my_putchar( int ch )
{
	write( 1, &ch, 1 );	// write( 1, ... ) means writing to the stdout
				// 0 - stdin, 1 - stdout, 2 - stderr
	return 0;
}

int my_putint( int num )
{
	num = num + '0';	// converting int number to a char type
	write( 1, &num, 1 );
	return 0;
}

void my_putstr( char* str )
{
	while ( *str )
	{
		my_putchar( *str );
		str++;
	}
}

int main( int argc, char* argv[] )
{
	if ( argc == 1 )
	{
		my_putstr( "Strings have not been provided!\n" );
		return 0;
	}

	int ascii[128] = { 0 };		// initializing an array of zeros
					// to count the number of occurrences
					// of each character

	for ( int i = 1; i < argc; i++ )
	{
		for ( int j = 0; argv[i][j]; j++ )
			ascii[( int ) argv[i][j]]++;
	}

	for ( int i = 0; i < 128; i++ )
	{
		if ( ascii[i] > 0 )
		{
			my_putchar( ( char ) i );
			my_putchar( ':' );
			my_putchar( ' ' );
			my_putint( ( int ) ascii[i] );
			my_putchar( '\n' );
		}
	}

	return 0;
}

