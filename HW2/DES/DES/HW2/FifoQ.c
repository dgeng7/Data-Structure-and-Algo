//
//  FifoQ.c

//
#include <stdio.h>
#include <stdlib.h>
#include "FifoQ.h"
#include "SimEng.h"



struct node
{
    void *E;
    double ts;
    struct node *next;
}*head,*temp3,*temp4,*temp5;

void create2(void *E, double ts)
{
    temp3 =(struct node *)malloc(1*sizeof(struct node));
    temp3->next = NULL;
    temp3->E = E;
    temp3->ts = ts;
}

void FIFOinsert(void *E, double ts)
{
    if (head == NULL) // Queue is empty
    {
        create2(E, ts);
        head = temp3;
    }
    else // Queue is not empty
    {
        temp4 = head;
        while (temp4 -> next != NULL) {
            temp4 = temp4 -> next;
        }
        create2(E, ts); // Create new node
        temp4 -> next = temp3;
        
    }
}


void * FIFOpop(){
    
    void *result;
    //special case
    if (head==NULL){
        return 0;
    }
    else{
        
        result = head -> E;
        
        temp5 = head;
        
        if (temp5->next == NULL)
        {
            free(temp5);
            temp5 = head = NULL;
            return result;
        }
        
        head = head->next;
        free(temp5);
        
        return result;//return the first in plane
        
    }
}
