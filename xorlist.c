/**
 * File: xorlist.c
 *
 * Summary: 
 * 	Useless, memory efficient linked list implementation.
 *
 * Details:
 * 	This linked list implementation uses only one field for
 * 	both the previous and the next pointer data.
 *
 * 	This field is actually the xor of the previous and the
 * 	next nodes' addresses.
 *
 * 	You can traverse the list both ways if you keep the addresses
 * 	of the first and the last element of this list.
 *
 * 	However, you can't go neither forwords nor backwards at any
 * 	given node if:
 * 	- You don't know the address of the previous node (to go forwards)
 * 	- You don't know the address of the next node (to go backwards) 
 * 	
 * 	Therefore, you can always move forwards from the first node and
 * 	backwards from the last node as the opposite way nodes do not exist
 * 	so their addresses are 0.
 *	
 *	This program is my solution to the following interview problem (from Google)
 *	
 *		An XOR linked list is a more memory efficient double linked list.
 *		Instead of each node holding <next> and <prev> fields, it holds a
 *		field named <both>, which is an XOR of the next and the
 *		previous node. Implement an XOR linked list; it has an
 *		add(element) which adds the element to the end, and a
 *		get(index) which returns the node at index.
 *
 * Author:
 * 	nicktheway, ngkatomer@auth.gr
 *
 * Date:
 * 	May 20, 2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

typedef struct node
{
	uintptr_t both;
	int data;	
} node;


uintptr_t nodeXOR(node const* const a,  uintptr_t const b);
node* getNode(node const* head, int const id);
void add(node** end, int data);

int main(void)
{
	// Start and End references.
	node* S = (node *) 0;
	node* E = (node *) 0;

	add(&E, 0);
	S = E; // Store the start of the list.
	assert(getNode(S, 0)->data == 0);


	add(&E, 1);
	assert(getNode(S, 1)->data == 1);
	add(&E, 2);
	assert(getNode(S, 2)->data == 2);
	add(&E, 3);
	assert(getNode(S, 3)->data == 3);
	add(&E, 4);
	assert(getNode(S, 4)->data == 4);
	

	return EXIT_SUCCESS;
}


uintptr_t nodeXOR(node const* const a,  uintptr_t const b)
{
	return (uintptr_t) a ^ b;
}

node* getNode(node const* head, int const id)
{
	node const* p = head;
	node const* pr = 0;

	for (int i = 0; i < id; i++)
	{
		node const* temp = p;
		p = (node *) nodeXOR(pr, p->both);
		pr = temp;
	}

	return (node*) p;
}

void add(node** end, int data)
{
	node* newNode = malloc(sizeof *newNode);
	newNode->data = data;
	
	if (*end)
	{
		(*end)->both = nodeXOR(newNode, (*end)->both ^ 0);
	}

	newNode->both = nodeXOR(*end, 0);
	*end = newNode;
}
