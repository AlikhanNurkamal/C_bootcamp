#include <stdlib.h>
#include <stdio.h>

#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE

typedef struct s_listnode
{
        int val;
        struct s_listnode* next;
} listnode;

#endif

int listlen( listnode* head )
{
        int count = 0;
        listnode* temp = head;

        while ( temp )
        {
                count++;
                temp = temp -> next;
        }

        return count;
}

void print_list( listnode* head )
{
        listnode* temp = head;
        while ( temp )
        {
                printf( "%d", temp -> val );
                if ( temp -> next )
                        printf( " -> " );
                temp = temp -> next;
        }

        printf( "\n" );
}

void delete_list( listnode* head )
{
        while ( head )
        {
                listnode* temp = head -> next;
                head -> next = NULL;
                free( head );
                head = temp;
        }
}

listnode* create_list( int number )
{
        listnode* head = NULL;

        for ( int i = 0; i < number; i++ )
        {
                listnode* node = malloc( sizeof( listnode ) );
                node -> val = i;
                node -> next = NULL;

                if ( !head )
                {
                        head = node;
                }
                else
                {
                        node -> next = head;
                        head = node;
                }
        }

	return head;
}

