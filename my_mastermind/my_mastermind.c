#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct
{
        _Bool c;
        _Bool t;
        char* code;
        int attempts;
        char* randcode;
} Options;

int my_strlen( char* str );
int my_strcmp( char* str1, char* str2 );
int number_attempts( Options *options );


// ---------------------------------
// USEFUL FUNCTIONS
// ---------------------------------

void random_code( char* code )
{
	// code = ( char* ) malloc( sizeof( char ) * 5 );
	srand( time( NULL ) );
	code[0] = ( char ) ( '0' + rand( ) % 7 + 1 );

	for ( int i = 1; i < 4; i++ )
		code[i] = ( char ) ( '0' + rand( ) % 8 );

	code[4] = '\0';
}

_Bool is_num( char *str )
{
	int i = 0;
	while ( str[i] )
	{
		if ( str[i] < '0' || str[i] > '7' )
			return 0;

		i++;
	}

	return 1;
}

_Bool valid( char *str )
{
	if ( my_strlen( str ) != 4 )
		return 0;
	
	if ( !is_num( str ) )
		return 0;

	return 1;
}

_Bool is_num_input( char* str )
{
	int i = 0;
	while ( str[i] != '\n' )
	{
                if ( str[i] < '0' || str[i] > '7' )
                        return 0;

                i++;
	}

	return 1;
}

_Bool valid_input( char *str )
{
	if ( my_strlen( str ) != 5 )
		return 0;

	if ( !is_num_input( str ) )
		return 0;

	return 1;
}

int initialize( int argc, char** argv, Options *options )
{
	options -> c = 0;
	options -> t = 0;
	options -> code = ( char* ) malloc( sizeof( char ) * 5 );
	options -> attempts = 10;
	random_code( options -> randcode );

	// options -> randcode = random_code( );

	if ( argc > 5 )
		return -1;

	for ( int i = 1; i < argc; i++ )
	{
		if ( my_strcmp( argv[i], "-c" ) == 0 && argv[i+1] != NULL )
		{
			options -> c = 1;
			if ( valid( argv[i+1] ) )
				options -> code = argv[i+1];
			else
				return -1;
		}

		if ( my_strcmp( argv[i], "-t" ) == 0 && argv[i+1] != NULL )
		{
			options -> t = 1;
			if ( atoi( argv[i+1] ) > 0 )
				options -> attempts = atoi( argv[i+1] );
			else
				return -1;
		}
			
		if ( ( my_strcmp( argv[i], "-c" ) == 0 && argv[i+1] == NULL ) || ( my_strcmp( argv[i], "-t" ) == 0 && argv[i+1] == NULL ) )
			return -1;
	}

	return 0;
}

int check_code( char* code, Options *options )
{
	int misplaced_pieces = 0;
    	int wellplaced_pieces = 0;
    	int i = 0;
    	int j = 0;
    	char* secret_code = ( char* ) malloc( sizeof( char ) * 5 );

    	if ( options -> c )
        	secret_code = options -> code;

    	else
        	snprintf( secret_code, 5, "%s", options -> randcode );

    	while ( code[i] != '\n' )
    	{
        	if ( code[i] == secret_code[i] )
            		wellplaced_pieces++;

        	j = 0;

        	while ( secret_code[j] != '\0' )
        	{
            		if ( i != j && code[i] == secret_code[j] )
                		misplaced_pieces++;

            		j++;                    
        	}

        	i++;
    	}

    	if ( wellplaced_pieces == 4 )
    	{
        	printf( "Congratz! You did it!\n" );
        	return EXIT_SUCCESS;
    	}

    	else
    	{
        	printf( "Well placed pieces: %d\n", wellplaced_pieces );
        	printf( "Misplaced pieces: %d\n", misplaced_pieces );
        	return EXIT_FAILURE;
    	}
}

// ---------------------------------
// HELPER FUNCTIONS
// ---------------------------------

int my_strlen( char* str )
{
	int count = 0;
	while ( str[count] )
	{
		count++;
	}

	return count;
}

int my_strcmp( char* str1, char* str2 )
{
	int i = 0;
	while( str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i] )
	{
		i++;
	}

	return ( str1[i] - str2[i] );
}

int number_attempts( Options *options )
{
	if ( options -> t )
		return options -> attempts;

	return 10;
}

// ---------------------------------
// MAIN
// ---------------------------------

int main( int argc, char** argv )
{
	Options options;
	int valid_options = initialize( argc, argv, &options );
	int round = 0;
	char code[128];

	if ( valid_options != 0 )
		return -1;

	int attempts = number_attempts( &options );
	printf( "Will you find the secret code?\n" );
	printf( "Please enter a valid guess\n" );

	// printf( "Code is: %s\n", options.code );
	// printf( "Attempts: %d\n", options.attempts );
	// printf( "Random code is: %s\n", options.randcode );

	printf( "---\nRound %d\n", round );

	while( 1 )
	{
		read( 0, code, sizeof( code ) );
		round++;
		if ( valid_input( code ) )
		{
			if ( check_code( code, &options ) == EXIT_SUCCESS )
				return EXIT_SUCCESS;
		}
		else
			printf( "Wrong input!\n" );

		if ( round >= attempts )
		{
			printf( "You lost!\n" );
			if ( options.c )
				printf( "Code is: %s\n", options.code );
			else
				printf( "Code is: %s\n", options.randcode );
			return EXIT_FAILURE;
		}

		printf( "---\nRound %d\n", round );
	}

	return EXIT_SUCCESS;
}

