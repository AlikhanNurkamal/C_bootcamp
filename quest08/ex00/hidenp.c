#include <stdio.h>

int my_hidenp( char* str1, char* str2 )
{
	if ( *str1 == '\0' )
		return 1;

	if ( *str1 != '\0' && *str2 == '\0' )
		return 0;

	while ( *str1 )
	{
		if ( *str1 != *str2 )
			str2++;
		else
		{
			str1++;
			str2++;
		}

		if ( *str1 != '\0' && *str2 == '\0' )
			return 0;
	}

	return 1;
}

// --------------------------------
// TEST CASES
// --------------------------------

/*
int main( )
{
	char* str1 = "fg.aw;'oeh";
	char* str2 = "ewiufsng;;.;apo[w,';'ooacheshnm";
	int hiden = my_hidenp( str1, str2 );
	printf( "%d\n", hiden );

	return 0;
}
*/

