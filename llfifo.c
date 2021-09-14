/*************************
 *
 *    
 *
 *    File name   : main.c
 *    Description : Linked List and Circular Buffer
 * 
 *
 *    Author: TAHER S UJJAINWALA
 * 	  Tools : CODELITE IDE, GNU GCC 
 *    References: https://prepinsta.com/c-program/implementation-of-queues-using-linked-list/
 *    https://www.programiz.com/dsa/linked-list-operations
 *    Code snippets used by Howdy Pierce
 *    Help and discussion with Gaurang Rane
 *    Date  : 09/12/2021    
 *    		 
 * 
 **************************/

//Including all .h header files
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "llfifo.h"


typedef struct node{
    void* data;
    struct node* next;
}node_t;

typedef struct llfifo_s{
    node_t* head;
    node_t* tail;  
    int malloc_ptr;
    int available;
    int length;
}llfifo_t;
 
   
/*
 * Creates and initializes the FIFO
 *
 * Parameters:
 *   capacity  the initial size of the fifo, in number of elements
 * 
 * Returns: A pointer to a newly-created llfifo_t instance, or NULL in
 *   case of an error.
 */
 
llfifo_t *llfifo_create(int capacity)
{
    llfifo_t* new_node = (llfifo_t*)malloc(sizeof(llfifo_t));
    if (new_node == NULL)
        return NULL;
    new_node->head = (node_t*)malloc(sizeof(node_t));
    if(new_node->head == NULL)
        return NULL;
    new_node->available = 1;
    new_node->malloc_ptr = 1;
    new_node->head->next = NULL;
    node_t *test, *new_node1;
    test = new_node->head;
    
    for (int i =0; i< capacity -1; i++)
    {
        new_node1 = (node_t*)malloc(sizeof(node_t));
        if(new_node1 == NULL)
            return NULL;
        test->next = new_node1;
        new_node1->next = NULL;
        test = test->next;
        (new_node->available)++;
        (new_node->malloc_ptr)++;
    }
    
    new_node->tail = new_node->head;
    return new_node;
    
    
    
}

/*
 * Enqueues an element onto the FIFO, growing the FIFO by adding
 * additional elements, if necessary
 *
 * Parameters:
 *   fifo    The fifo in question
 *   element The element to enqueue, which cannot be NULL
 * 
 * Returns:
 *   The new length of the FIFO on success, -1 on failure. It is an error to attempt 
 * to enqueue the NULL pointer.
 */

int llfifo_enqueue(llfifo_t *fifo, void *element)
{
    if (fifo->head == NULL)
        return -1;
    
    if((fifo->available) >0)
    {
        (fifo->length)++;
        fifo->tail->data = element;
        if((fifo->available) >0)
            fifo->tail = fifo->tail->next;
        (fifo->available)--;
    }
    else 
    {
        (fifo->length)++;
        node_t *new_node1 = (node_t*)malloc(sizeof(node_t));
        new_node1->data = element;
        new_node1->next = NULL;
        fifo->tail->next = new_node1;
        fifo->tail = new_node1;
        (fifo->malloc_ptr)++;
    }
    
    return fifo->available;
}   

/*
 * Removes ("dequeues") an element from the FIFO, and returns it
 *
 * Parameters:
 *   fifo  The fifo in question
 * 
 * Returns:
 *   The dequeued element, or NULL if the FIFO was empty
 */
void *llfifo_dequeue(llfifo_t *fifo)
{
    node_t* temp;
	if((fifo->head == NULL)&&(fifo->tail == NULL)){
		return NULL;
	}
	else{
            fifo->length--;
            fifo->head = fifo->head->next;
            //fifo->tail = NULL;
            (fifo->available)--;
            return fifo->available;
            free(temp);
		}
        
}


void printList(llfifo_t* fifo) {
    node_t *p = fifo->head;
    for (int i=0; i< ((fifo->malloc_ptr) - (fifo->available)); i++)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

/*
 * Teardown function: Frees all dynamically allocated
 * memory. After calling this function, the fifo should not be used
 * again!
 *
 * Parameters:
 *   fifo  The fifo in question
 * 
 * Returns: none
 */
void llfifo_destroy(llfifo_t* fifo)
{
  while (fifo) {
    llfifo_t *this = fifo;
    fifo = fifo->tail;
    free(this);
  }
}

/*
 * Returns the number of elements currently on the FIFO. 
 *
 * Parameters:
 *   fifo  The fifo in question
 * 
 * Returns:
 *   The number of elements currently on the FIFO
 */
int llfifo_length(llfifo_t *fifo)
{
    return fifo->length;
}

/*
 * Returns the FIFO's current capacity
 *
 * Parameters:
 *   fifo  The fifo in question
 * 
 * Returns:
 *   The current capacity, in number of elements, for the FIFO
 */
int llfifo_capacity(llfifo_t *fifo)
{
    return fifo->available;
}