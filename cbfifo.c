/*************************
 *
 *    
 *
 *    File name   : cbfifo.c
 *    Description : Implementation of Circular Buffer - Enqueue, Dequeue, length, capacity API are developed
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


#define	SIZE_OF_BUFFER 128	    // Maximum size of buffer

uint32_t buffer_length;         //Total no of elements current in the array
uint32_t write_index = 0;       //Write index to track Enqueue operation
uint32_t read_index = 0;        //Read index to track Dequeue Operation
unsigned char buffer[SIZE_OF_BUFFER];       //Character array to store the data when Enqueued


/*
* Enqueues data onto the FIFO, up to the limit of the available FIFO
* capacity.
*
 * Parameters:
 *   buf      Pointer to the data
 *   nbyte    Max number of bytes to enqueue
 * 
 * Returns:
 *   The number of bytes actually enqueued, which could be 0. In case
 * of an error, returns -1.
 */
 
size_t cbfifo_enqueue(void *buf, size_t nbyte)          
{
    if(buf == NULL)                                                     //Checking if the data to store is not a Null value
        return -1;                                                      //Returning -1 if the buf is NULL 
    else
    {   
        if(buffer_length >= SIZE_OF_BUFFER)                             //Checking if current element is equal to greater than total size 
            return 0;                                                   //Returning 0 if it is equal of greater as per circular buffer concept
        else 
        {
            if (nbyte > (SIZE_OF_BUFFER - buffer_length))              //Check if data to Enqueue is greater than number of characters left in buffer
                nbyte = SIZE_OF_BUFFER - buffer_length;                //If greater store only the space left in the char array
        }
            
        for(int i =0; i<= nbyte-1; i++)                                //Loop to store characters one by one
           
            {
                buffer[write_index] = *(uint8_t*)buf;                  //Type cast the buf value to Enqueue and store it in buffer with write index
                write_index++;                                         //Increment to keep a location track
                buffer_length++;                                       //Number to elements currently filled in char array
                buf =  (uint8_t*)buf +1;                               //Incrementing the location to point the next byte to store
                if(write_index == SIZE_OF_BUFFER)                      //Checks if all 128 bytes data is filled - if yes reset the write index to 0
                    {
                        write_index =0;
                    }
            }          
            
        return buffer_length;                                          //Returns the number of elements stored in char array
       
    }

}   


/*
 * Attempts to remove ("dequeue") up to nbyte bytes of data from the
 * FIFO. Removed data will be copied into the buffer pointed to by buf.
 *
 * Parameters:
 *   buf      Destination for the dequeued data
 *   nbyte    Bytes of data requested
 * 
 * Returns:
 *   The number of bytes actually copied, which will be between 0 and
 * nbyte. 
 * 
 * To further explain the behavior: If the FIFO's current length is 24
 * bytes, and the caller requests 30 bytes, cbfifo_dequeue should
 * return the 24 bytes it has, and the new FIFO length will be 0. If
 * the FIFO is empty (current length is 0 bytes), a request to dequeue
 * any number of bytes will result in a return of 0 from
 * cbfifo_dequeue.
 */
 
size_t cbfifo_dequeue(void *buf, size_t nbyte)
{
    if(buf == NULL)                                                 //Checking the storing array if is NULL or not
        return -1;                                                  //Returning -1 if return array is not defined
    else
    {
        if(buffer_length == 0 || nbyte ==0)                         //Checking if dequeue operation can be perfomed and there is some data in the char array
            return 0;                                               //Returning 0 for any of the above true operations
        else 
        {
            if (nbyte > buffer_length)                              //If more number of bytes are dequeue than total elements currently present then dequeue only the elements present in array
                nbyte = buffer_length;                              //Initialize the new nbyte
        }
            
       for (int i =0; i<= nbyte-1; i++)                             //Loop to dequeue characters one by one
           
            {
                *(uint8_t*)buf = buffer[read_index];               //Reading the buffer stored input to buf pointer and type casting it to unsgined int
                read_index++;                                      //Incrementing read index to know the exact data read
                buffer_length--;                                   //Decrementing to keep a track of updated number of elements present in the char array
                buf =  (uint8_t*)buf +1;                           //Incrementing the pointer to read the next character
                if(read_index == SIZE_OF_BUFFER)                   //Checking if all 128 bytes are read - if yes reset the read index
                    {
                        read_index =0;                          
                    }
            }          
            
        return buffer_length;                                      //Returning the updates number of elements present in the char array
    }
   
}   

/*
 * Returns the number of bytes currently on the FIFO. 
 *
 * Parameters:
 *   none
 * 
 * Returns:
 *   Number of bytes currently available to be dequeued from the FIFO
 */

size_t cbfifo_length()
{
    return buffer_length;                               //Returning the number of bytes currently present in an character araay of 128 bytes
}

/*
 * Returns the FIFO's capacity
 *
 * Parameters:
 *   none
 * 
 * Returns:
 *   The capacity, in bytes, for the FIFO
 */
 
size_t cbfifo_capacity()
{
    return SIZE_OF_BUFFER;                              //Returning the total capacity of character array in this case 128 bytes
}