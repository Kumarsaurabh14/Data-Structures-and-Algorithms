#include <stdio.h>
#include <stdlib.h>

/* Structure of a node */
struct node {
    int data;          // Data
    struct node *next; // Address
}*head;


/*
 * Functions to create and display result
 */
void createList(int n);
void searchList(int itm);


int main()
{
    int n, item;
    printf("Taking input for creating List\n");
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("Enter number to be searched: ");
    scanf("%d",&item);



    searchList(item);

    return 0;
}

/*
 * Create a list of n nodes
 */
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    // Terminate if memory not allocated
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }


    // Input data of node from the user
    printf("Enter the data of node 1: ");
    scanf("%d", &data);

    head->data = data; // Link data field with data
    head->next = NULL; // Link address field to NULL


    // Create n - 1 nodes and add to list
    temp = head;
    for(i=2; i<=n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        /* If memory is not allocated for newNode */
        if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data; // Link data field of newNode
        newNode->next = NULL; // Make sure new node points to NULL

        temp->next = newNode; // Link previous node with newNode
        temp = temp->next;    // Make current node as previous node
    }
}


/*
 * search in entire list
 */
void searchList(int itm)
{
    struct node *temp, *loc=NULL;

    // Return if list is empty
    if(head == NULL)
    {
        printf("List is empty.");
        return;
    }

    temp = head;
    while(temp != NULL)
    {
        if(itm==temp->data){
            loc = temp;
            break;
        }
        else{
                    temp = temp->next;                 // Move to next node
        }
    }
    if(loc!=NULL)
    printf("data found at: %d",loc);
    else
        printf("Data not found.");
}


