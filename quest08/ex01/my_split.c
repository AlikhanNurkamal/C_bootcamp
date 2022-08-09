#include "helper_functions.h"

#ifndef STRING_ARRAY
#define STRING_ARRAY

typedef struct
{
	int size;
	char** array;
} string_array;

#endif

string_array* my_split( char* str, char* sep )
{
	string_array* ptr = malloc( sizeof( string_array ) );

	int sz = 1;
	for ( int i = 0; str[i]; i++ )
	{
		if ( str[i] == *sep )
			sz++;
	}

	ptr -> size = sz;
	ptr -> array = malloc( sizeof( char* ) * ptr -> size );

	for ( int i = 0; i < ptr -> size; i++ )
	{
		ptr -> array[i] = malloc( sizeof( char ) * 128 );
		int pos = 0;
		while ( *str != *sep && *str )
		{
			ptr -> array[i][pos++] = *str;
			str++;
		}

		ptr -> array[i][pos] = '\0';

		if ( *str == *sep )
			str++;
	}

	return ptr;
}

void delete_string_array( string_array* ptr )
{
	for ( int i = 0; i < ptr -> size; i++ )
	{
		free( ptr -> array[i] );
	}

	ptr -> size = 0;
	free( ptr -> array );
	free( ptr );
}

// --------------------------------
// TEST CASES
// --------------------------------

/*
int main( int argc, char* argv[] )
{
	if ( argc == 1 )
	{
		putstr( "Neither string nor separator has been provided!\n" );
		return -1;
	}

	else if ( argc == 2 )
	{
		putstr( "Either string or separator has not been provided!\n" );
		return -1;
	}

	// string_array* arr = malloc( sizeof( string_array ) );
	string_array* arr = my_split( argv[1], argv[2] );
	for ( int i = 0; i < arr -> size; i++ )
	{
		putstr( arr -> array[i] );
		putchar( '\n' );
	}

	delete_string_array( arr );

	return 0;
}
*/

