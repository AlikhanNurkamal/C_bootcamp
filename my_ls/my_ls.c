#include <stdio.h>
#include "helper_functions.h"
// Defining a struct to store both names of the files in the current directory and their modification times.
typedef struct
{
    long int* times;
    char** dir_names;
} files_info;

void sort_lexicographically( files_info* info, int files_count, int pos )
{
    char temp[100];
    for ( int i = pos; i < files_count - 1; i++ )
    {
        for ( int j = i + 1; j < files_count; j++ )
        {
            if ( my_strcmp( info -> dir_names[i], info -> dir_names[j] ) > 0 )
            {
                my_strcpy( temp, info -> dir_names[i] );
                my_strcpy( info -> dir_names[i], info -> dir_names[j] );
                my_strcpy( info -> dir_names[j], temp );
            }
        }
    }
}

// This function will sort the files in the given directory by their modification date.
// last updated - first - and vice versa.
void sort_files_by_time( files_info* info, int files_count )
{
    int iteration = 0, index = 0;
    long int temp_int = 0;
    
    while ( iteration < files_count )
    {
        int max_found = 0;
        char temp_str[100];
        long int max = info -> times[iteration];

        // Seeking for the largest modification time ( the greater -> more recent )
        for ( int i = iteration + 1; i < files_count; i++ )
        {
            if ( info -> times[i] > max )
            {
                max = info -> times[i];
                index = i;
                max_found = 1;
            }
        }
        
        if ( !max_found )
        {
            sort_lexicographically( info, files_count, iteration );
            iteration++;
            continue;
        }

        my_strcpy( temp_str, info -> dir_names[iteration] );
        my_strcpy( info -> dir_names[iteration], info -> dir_names[index] );
        my_strcpy( info -> dir_names[index], temp_str );

        temp_int = info -> times[iteration];
        info -> times[iteration] = info -> times[index];
        info -> times[index] = temp_int;

        iteration++;
    }
}

void my_ls( const char* directory, int a, int t )
{
    DIR* dir = opendir( directory );
    struct dirent* dp;

    if ( !dir )
    {
        // If the directory is not found
		if ( errno == ENOENT )
			my_putstr( "Directory doesn't exist" );

        // If the directory is not readable, throw error and exit
		else
			my_putstr( "Unable to read directory" );

		return;
    }

    int files_count = 0;
    while ( ( dp = readdir( dir ) ) )
    {
        if ( !a && dp -> d_name[0] == '.' )
            continue;

        files_count++;
    }
    closedir( dir );

    dir = opendir( directory );

    files_info* info = malloc( sizeof( files_info ) );
    info -> times = malloc( sizeof( long int ) * files_count );
    info -> dir_names = malloc( sizeof( char* ) * files_count );

    if ( t )
    {
        int pos = 0;
        while ( ( dp = readdir( dir ) ) )
        {
            if ( !a && dp -> d_name[0] == '.' )
                continue;

            info -> dir_names[pos] = dp -> d_name;
            info -> times[pos] = 0;

            struct stat filestat;
            lstat( dp -> d_name, &filestat );
            printf( "%s ", info -> dir_names[pos] );
            printf( "%ld\n", filestat.st_mtime );
            // info -> times[pos] = filestat.st_mtime;
            // info -> times[pos] += filestat.st_mtim.tv_sec;
            // info -> times[pos] += filestat.st_mtim.tv_nsec;
            
            pos++;
        }

        sort_files_by_time( info, files_count );
    }
    else
    {
        int pos = 0;
        while ( ( dp = readdir( dir ) ) )
        {
            if ( !a && dp -> d_name[0] == '.' )
                continue;

            info -> dir_names[pos] = dp -> d_name;
            pos++;
        }

        sort_lexicographically( info, files_count, 0 );
    }

    for ( int i = 0; i < files_count; i++ )
    {
        my_putstr( info -> dir_names[i] );
        my_putchar( '\n' );
    }

    free( info -> times );
    free( info -> dir_names );
    free( info );

    closedir( dir );
}

int main( int argc, char* argv[] )
{
    int a = 0, t = 0;
    char* dir = ".";

    if ( argc == 1 )
    {
        my_ls( dir, a, t );
        return 0;
    }

    for ( int i = 1; i < argc; i++ )
    {
        if ( my_strcmp( argv[i], "-a" ) == 0 )
            a = 1;
        else if ( my_strcmp( argv[i], "-t" ) == 0 )
            t = 1;
        else if ( my_strcmp( argv[i], "-at" ) == 0 && argv[i+1] )
        {
            dir = argv[i+1];
            i++;
        }
        else
        {
            my_putstr( "Invalid argument!\n" );
            return -1;
        }
    }

    my_ls( dir, a, t );

    return 0;
}