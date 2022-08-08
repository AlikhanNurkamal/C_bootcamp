#include "template.h"

listnode* reverse_linked_list( listnode* head )
{
	listnode* curr = head;
	listnode* next = head;
	listnode* prev = NULL;

	while ( curr )
	{
		next = next -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
	}

	head = prev;

	return head;
}

int main( )
{
	listnode* head = NULL;

	head = create_list( 20 );

	print_list( head );

	head = reverse_linked_list( head );
	print_list( head );

	delete_list( head );

	return 0;
}

