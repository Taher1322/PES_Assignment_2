/*************************
 *
 *    
 *
 *    File name   : test.c
 *    Description : Test file to test different combinations of the functions and return 1 and 0 
 *    1 when all test are successful
 *    0 when any test fails
 *
 *    Author: TAHER S UJJAINWALA
 * 	  Tools : CODELITE IDE, GNU GCC 
 *    Date  : 09/14/2021    
 *    		 
 * 
 **************************/
//Including all .h header files
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "cbfifo.h"
#include "llfifo.h"

int test_llfifo()
{
    //Defining variables
    int actual_ret;
    int expected_ret;
    int status;
    
    //Creating new instance to create malloc
     llfifo_t *my_fifo = llfifo_create(25);
    //Enqueue data 10 in the list
    actual_ret = llfifo_enqueue(my_fifo, 10);
    expected_ret = 24; 
    if (actual_ret == expected_ret)   //Compare the value and increment the status value
        status++;
    
     //Enqueue data 200 in the list
    actual_ret = llfifo_enqueue(my_fifo, 200);
    expected_ret = 23; 
    if (actual_ret == expected_ret)    //Compare the value and increment the status value
        status++;
    
    //Enqueue data 56 in the list
    actual_ret = llfifo_enqueue(my_fifo, 56);
    expected_ret = 22;
    if (actual_ret == expected_ret)     //Compare the value and increment the status value
        status++;
        
    //Dequeue first element that is 10 from the list
    actual_ret = llfifo_dequeue(my_fifo);
    expected_ret = 21;
    if (actual_ret == expected_ret)
        status++;
    
    //Dequeue next element that is 200 from the list
    actual_ret = llfifo_dequeue(my_fifo);
    expected_ret = 20; 
    if (actual_ret == expected_ret)
        status++;
      
    //print all the list values
    printList(my_fifo);
    
    
    if (status == 5)
        return 1;
    else 
        return 0;
    printf("LLFIFO return value%d\n", actual_ret);
}
