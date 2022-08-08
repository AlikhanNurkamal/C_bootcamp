#include "template.h"

listnode* remove_duplicates( listnode* head )
{
	listnode* temp = head;

	while ( temp )
	{
		int move = 1;

		if ( !temp -> next )
			return head;

		if ( temp -> val == temp -> next -> val )
		{
			listnode* to_delete = temp -> next;
			temp -> next = to_delete -> next;
			to_delete -> next = NULL;
			free( to_delete );

			move = 0;
		}

		if ( move )
			temp = temp -> next;
	}

	return head;
}

int main( )
{
	listnode* head = NULL;
	// head = create_list( 15 );

	listnode* one = malloc( sizeof( listnode ) );
	one -> val = 1;
	
	listnode* two = malloc( sizeof( listnode ) );
	two -> val = 2;
	one -> next = two;

	listnode* three = malloc( sizeof( listnode ) );
	three -> val = 2;
	two -> next = three;

	listnode* four = malloc( sizeof( listnode ) );
	four -> val = 2;
	three -> next = four;

	listnode* five = malloc( sizeof( listnode ) );
	five -> val = 3;
	four -> next = five;
	five -> next = NULL;

	head = one;
	print_list( head );

	head = remove_duplicates( head );
	print_list( head );

	delete_list( head );

	return 0;
}
