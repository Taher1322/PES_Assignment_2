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

//Defining Data to Enqueue in character array - Integers, characters (caps and small)
unsigned int dataset1[32] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220};
unsigned char dataset2[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
unsigned char dataset3[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

//Defining variables to read and check the outcomes
int status;
int expected_ret;
int actual_ret;
unsigned int val[32];
unsigned char val1[26];


int test_cbfifo()
{
    //Test case 1 - Null condition check for Enqueue operation 
    actual_ret = cbfifo_enqueue(NULL, sizeof(NULL));
    //printf("Actual return value from Null Enqueue is %d\n", actual_ret);
    expected_ret = -1;
    if (actual_ret == expected_ret)         //IF both the values are same we increment the status counter
        status++;
    
    
    //Test case 2 - Enqueqe first dataset which includes 32 integers that makes it 128 bytes of data to be written in buffer
    actual_ret = cbfifo_enqueue(&dataset1,  sizeof(dataset1));
    expected_ret = cbfifo_capacity();           //Using the API to get the Size of Buffer 
    if(actual_ret == expected_ret)              //Compare if both values are same and increment the status counter
        status++;
        

    //Test case 3 - Dequeue 64 bytes that makes it 16 integers to be dequeued and stored in val (data type defined as  unsigned integer)
    actual_ret = cbfifo_dequeue(val, 64);
    expected_ret = 64;
    //Printing first 64 bytes(16 integers) from buffer and updating the buffer length
    for (int  i=0; i< 16; i++)
    {
        printf("%d", val[i]);
    }
    printf("\n");
    if (actual_ret == expected_ret)             //Compare if both values are same and increment the status counter
        status++;
        

    //Test case 4 - Enqueue second dataset which includes 26 characters in lower case 
    actual_ret = cbfifo_enqueue(&dataset2, sizeof(dataset2));
    expected_ret = 90;                         //Adding 64 + 26 = 90 characters currently present in the buffer
    if (actual_ret == expected_ret)
        status++;                              //Compare if both values are same and increment the status counter
    //printf("Actual return value from Enqueu is %d\n", status);
    

    //Test case 5 - Dequeue 32 bytes that makes it 8 integers to be dequeued and stored in val array
    actual_ret = cbfifo_dequeue(val, 32);
    expected_ret = 58;                         //Removing 90(currently filled) - 32(dequeued) = 58(new buffer capacity) 
    //Printing first 32 bytes(8 integers) from buffer and updating the buffer length
    for (int  i=0; i< 8; i++)
    {
        printf("%d", val[i]);
    }
    printf("\n");
    if (actual_ret == expected_ret)          //Compare if both values are same and increment the status counter
        status++;
        

    //Test case 6 - Dequeue 32 bytes that makes it 8 integers to be dequeued and stored in val array
    actual_ret = cbfifo_dequeue(val, 32);
    expected_ret = 26;                        //Removing 58(currently filled) - 32(dequeued) = 26(new buffer capacity) 
    //Printing first 32 bytes(8 integers) from buffer and updating the buffer length
    for (int  i=0; i< 8; i++)
    {
        printf("%d", val[i]);
    }
    printf("\n");
    if (actual_ret == expected_ret)         //Compare if both values are same and increment the status counter
        status++;
        

    //Test case 7 - Dequeue more elements than currently present in the buffer (Currently present = 26)
    actual_ret = cbfifo_dequeue(val1, 32);    //Dequeued and stored in val1 array
    //printf("Actual return value from Enqueu is %d\n", actual_ret);
    expected_ret = 0;
    //Printing remaining 26 bytes characters from buffer and updating the buffer length
    for (int  i=0; i< 26; i++)
    {
        printf("%c", val1[i]);
    }
    printf("\n");
    if (actual_ret == expected_ret)        //Compare if both values are same and increment the status counter
        status++;
     
    //Buffer is empty at this point of time 
    

    //Test case 8 - Enqueue dataset3 which contains all upper case characters 
    actual_ret = cbfifo_enqueue(&dataset3, sizeof(dataset3));
    //printf("Actual return value from Enqueu is %d\n", actual_ret);
    expected_ret = 26;
    if (actual_ret == expected_ret)        //Compare if both values are same and increment the status counter
        status++;
    

    //Test case 9 - Enqueue dataset2 which contains all lower case characters
    actual_ret = cbfifo_enqueue(&dataset2, sizeof(dataset2));
    //printf("Actual return value from Enqueu is %d\n", actual_ret);
    expected_ret = 52;                      //Current size of buffer will be 26+26 = 52
    if (actual_ret == expected_ret)        //Compare if both values are same and increment the status counter
        status++;
    

    //Test case 10 - Enqueue dataset1 which includes 32 integers that si 128 bytes of data (so only the empty space will be filled)
    actual_ret = cbfifo_enqueue(&dataset1, sizeof(dataset1));   
    //printf("Actual return value from Enqueu is %d\n", actual_ret);
    expected_ret = cbfifo_length();       //Only 74 bytes will be stores from dataset1 (19 integers)
    if (actual_ret == expected_ret)       //Compare if both values are same and increment the status counter
        status++;
    

    //Test case 11 - Null condition check for Dequeue 
    actual_ret = cbfifo_dequeue(NULL, 1);           //Error boundary check for Dequeue
    //printf("Actual return value from Enqueu is %d\n", actual_ret);
    expected_ret = -1;
    if (actual_ret == expected_ret)      //Compare if both values are same and increment the status counter
        status++;
        

    //Test case 12 - Dequeue 26 bytes of characters that will be nothing but upper case characters 
    actual_ret = cbfifo_dequeue(val1, 26);
    expected_ret = 102;                 //Current size of buffer will be 128 - 26 = 102 bytes
    //Printing 26 bytes characters from buffer and updating the buffer length
    for (int  i=0; i< 26; i++)
    {
        printf("%c", val1[i]);
    }
    printf("\n");
    
    if (actual_ret == expected_ret)     //Compare if both values are same and increment the status counter
        status++;
    

    //Test case 13 - Checking the buffer size
    actual_ret = cbfifo_capacity();
    expected_ret = 128;
    if (actual_ret == expected_ret)
        status++;
   
    

    //Test case 14 - Dequeue 26 bytes of characters that will be nothing but lower case characters 
    actual_ret = cbfifo_dequeue(val1, 26);
    expected_ret = 76;                 //Current size of buffer will be 102 - 26 = 76s bytes
    //Printing 26 bytes characters from buffer and updating the buffer length
    for (int  i=0; i< 26; i++)
    {
        printf("%c", val1[i]);
    }
    printf("\n");
    
    if (actual_ret == expected_ret)         //Compare if both values are same and increment the status counter
        status++;
     

    //Test case 15 - Dequeue  more bytes than actually present in the buffer case
    actual_ret = cbfifo_dequeue(val, 128);
    expected_ret = 0;
    //Printing all remaining bytes characters from buffer and updating the buffer length
    for (int  i=0; i< 32; i++)
    {
        printf("%d", val[i]);
    }
    printf("\n");
    
    if (actual_ret == expected_ret)        //Compare if both values are same and increment the status counter
        status++;
        

    //Test case 16 - Enqueue dataset1 which have 32 integers that means all 128 bytes are filled
    actual_ret = cbfifo_enqueue(&dataset1, sizeof(dataset1));
    expected_ret = cbfifo_capacity();  
    if (actual_ret == expected_ret)    //Compare if both values are same and increment the status counter
        status++;
        

    //Test case 17 - Dequeue checking with nbytes as 0 
    actual_ret = cbfifo_dequeue(val, 0);
    expected_ret = 0;
    if (actual_ret == expected_ret)    //Compare if both values are same and increment the status counter
        status++;
    

    //Debugging messages for developer
    printf("Actual return value from Enqueu is %d\n", actual_ret);
    printf("Status value is %d\n", status);
    
    if (status == 17)
        return 1;
    else 
        return 0;
}
