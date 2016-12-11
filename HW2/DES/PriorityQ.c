//
//  PriorityQ.c

//

#include <stdio.h>
#include <stdlib.h>
#include "PriorityQ.h"

//define structure for future use
struct node
{
    void *E;
    double ts;
    struct node *prev;
    struct node *next;
}*h,*temp,*temp1,*temp2;

//create a queue if queue is empty
void create(void *E, double ts)
{
    temp =(struct node *)malloc(1*sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    temp->E = E;
    temp->ts = ts;
}

void PQinsert(void *E, double ts)
{
    if (h == NULL) // Queue is empty
    {
        create(E, ts);
        h = temp;
    }
    else // Queue is not empty
    {
        create(E, ts); // Create new node
        temp1 = h;
        
        if (temp1 -> ts > temp -> ts)
        {
            temp1 -> prev = temp;
            temp -> next = temp1;
            h = temp;
        }
        else
        {
            while (temp1-> ts < temp-> ts)
            {
                
                if (temp1 -> next == NULL) // temp1 is the Last element in the queue
                {
                    temp1->next = temp;
                    temp -> prev = temp1;
                    break;
                }
                
                else if (temp1 -> next -> ts > temp -> ts)
                {
                    temp -> prev = temp1;
                    temp -> next = temp1 -> next;
                    temp1 -> next = temp;
                    temp1 -> next -> prev = temp;
                    break;
                }
                
                else
                {
                    temp1 = temp1 -> next;
                }
            }
        }
        
    }
}


void* PQpop(){
    
    void *result;
    //capture the special case
    if (h==NULL){
        return NULL;
    }
    else{
        
        result = h -> E;
        
        temp2 = h;
        //pop out the first one in the left hand side of the queue
        if (temp2->next == NULL)
        {
            free(temp2);
            temp2 = h = NULL;
            return result;
        }
        
        h = h->next;
        free(temp2);
        
        return result;
        
    }
}
