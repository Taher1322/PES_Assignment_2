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
 *    Date  : 09/12/2021    
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

//Defining the Test function
int test_cbfifo();
int test_llfifo();

int main()
{
    //Calling Circular Buffer Test function -- Returns 1 for all test pass else 0
   int result = test_cbfifo();
   if (result == 1)
   {
       printf("Circular Buffer Test passed \n");
   }
   else 
       printf("Circular Buffer Test Failed \n");
    
   //Calling Linked List Test function -- Returns 1 for all test pass else 0 
   result = test_llfifo();
   if (result == 1)
   {
       printf("Linked List Test passed \n");
   }   
   else 
       printf("Linked List Test Failed \n");
   
}