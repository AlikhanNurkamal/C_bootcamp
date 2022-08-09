#include "helper_functions.h"

char* my_strip( char* str )
{
	if ( !*str )
		return "";

	int len = my_strlen( str );
	char* res = ( char* ) malloc( sizeof( char ) * len + 1 );

	while ( *str == ' ' )
		str++;

	int pos = 0;
	while ( *str )
	{
		res[pos++] = *str++;

		if ( *str == ' ' )
		{
			while ( *str == ' ' )
				str++;
			if ( *str )
				res[pos++] = ' ';
		}
	}

	res[pos] = '\0';

	return res;
}

// --------------------------------
// TEST CASES
// --------------------------------

/*
int main( int argc, char* argv[] )
{
	if ( argc == 1 )
	{
		putstr( "No string has been provided!\n" );
		return -1;
	}

	for ( int i = 1; i < argc; i++ )
	{
		char* final_string = my_strip( argv[i] );
		putstr( final_string );
		putchar( '\n' );
		free( final_string );
	}

	return 0;
}
*/

