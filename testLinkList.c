#include <stdio.h>
#include <malloc.h>

typedef struct node {
    int data;
    struct node* next;

} Node;

void print(Node* head) 
{
    while(head) 
    {
       printf ("%d ",head->data);
       head = head->next;
    }
    printf("\n");
}

void insertData(Node** head, const int data)
{

    Node *temp,  *curr;


    temp = (Node *) malloc(sizeof(Node));
    temp->next = NULL;
    temp->data = data;
    
    if(*head == NULL)
    {
       *head = temp; 
       return;
    }

    curr = *head;

    while(curr->next)
    {
        curr = curr->next;

    }

    curr->next = temp;

}

void deleteData(Node** head, const int data)
{
     
     Node *curr = *head, *prev = *head;


     while(curr && curr->data != data)
     {
         
         prev = curr;
         curr = curr->next;
     }       

     if (curr == NULL)
         return;

     if (*head == curr)
     {
          *head = curr->next;
          free(curr);
          return;
     }

     prev->next = curr->next;
     free(curr);

}

void swapFIRSTnLAST(Node **head)
{

    Node *cur = *head, *prev = *head;


    if(!cur)
        return;

    if(!(cur->next))
         return;

    while(cur->next)
    {
        prev = cur;
        cur = cur->next;
    }

    //check if only 2 nodes are there
    if(*head == prev)
    {
        cur->next = prev;
        cur->next->next = NULL;
        *head = cur;
        return;
    }

    //for more than 2 nodees
    cur->next = (*head)->next;
    prev->next = *head;
    prev->next->next = NULL;
    *head = cur;
    
}


int main()
{
    Node* link_list = NULL;
    
    
    insertData(&link_list, 1);
    insertData(&link_list, 3);
    insertData(&link_list, 2);
    insertData(&link_list, 5);
    insertData(&link_list, 4);

    print(link_list);

    deleteData(&link_list, 2);
    print(link_list);
    deleteData(&link_list, 2);
    print(link_list);
    deleteData(&link_list, 1);
    print(link_list);
    deleteData(&link_list, 3);
    print(link_list);
    deleteData(&link_list, 5);
    print(link_list);
    deleteData(&link_list, 4);
    print(link_list);
    deleteData(&link_list, 2);

    print(link_list);

    insertData(&link_list, 1);
    insertData(&link_list, 3);

    print(link_list);

    swapFIRSTnLAST(&link_list);
    print(link_list);

    insertData(&link_list, 2);
    insertData(&link_list, 5);
    insertData(&link_list, 4);

    print(link_list);
    swapFIRSTnLAST(&link_list);
    print(link_list);
    return 0;
}
