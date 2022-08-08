#include "template.h"

listnode* remove_nth_node_from_end( listnode* head, int n )
{
        int len = listlen( head );

        listnode* temp = head;

        if ( len - n == 0 )
        {
                head = head -> next;
                temp -> next = NULL;
                free( temp );
                return head;
        }

        for ( int i = 0; i < len - n - 1; i++ )
        {
                temp = temp -> next;
        }

        listnode* to_delete = temp -> next;
        temp -> next = to_delete -> next;
        to_delete -> next = NULL;
        free( to_delete );

        return head;
}

int main( )
{
	listnode* head = NULL;

	head = create_list( 10 );

	print_list( head );

	head = remove_nth_node_from_end( head, 3 );
	print_list( head );

	head = remove_nth_node_from_end( head, 5 );
	print_list( head );

	delete_list( head );

	return 0;
}
