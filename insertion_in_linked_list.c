#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};

struct node * find_node(struct node *head, int val)
{
    struct node *tmp = head;

    while(tmp)
    {
        if (tmp->val == val) return tmp; /*Found*/

        tmp = tmp->next;
    }

    return NULL; /*Not found*/
}

void print_list(struct node *head)
{
    printf("H->");

    while(head)
    {
        printf("%d->", head->val);
        head = head->next;
    }

    printf("|||\n\n");
}

void insert_front(struct node **head, int value)
{
    struct node * new_node = NULL;

    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Failed to insert element. Out of memory");
    }

    new_node->val = value;
    new_node->next = *head;

    *head = new_node;
}

void insert_end(struct node **head, int value)
{
    struct node * new_node = NULL;
    struct node * last = NULL;

    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Failed to insert element. Out of memory");
    }

    new_node->val = value;
    new_node->next = NULL;

    if( *head == NULL)
    {
        *head = new_node;
        return;
    }

    last = *head;
    while(last->next) last = last->next;

    last->next = new_node;
}

void insert_after(struct node *pos, int value)
{
    struct node * new_node = NULL;

    if (pos == NULL) return;

    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Failed to insert element. Out of memory");
    }

    new_node->val = value;
    new_node->next = pos->next;
    pos->next = new_node;
}

void insert_before(struct node **head, struct node *pos, int value)
{
    struct node * new_node = NULL;
    struct node * tmp_node = NULL;

    if (pos == NULL) return;

    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Failed to insert element. Out of memory");
    }

    new_node->val = value;

    if(*head == pos)
    {
        new_node->next = pos;
        *head = new_node;
        return;
    }

    tmp_node = *head;

    while(tmp_node->next != pos)
    {
        tmp_node = tmp_node->next;

        if(tmp_node == NULL) return; /*Not found*/
    }

    new_node->next = tmp_node->next;
    tmp_node->next = new_node;
}

void main()
{
    int count = 0, i, val, pos;
    struct node * head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &count);

    for (i = 0; i < count; i++)
    {
        printf("Enter %dth element: ", i);
        scanf("%d", &val);
        insert_front(&head, val);
    }

    printf("Initial List: ");
    print_list(head);

    printf("Enter a value to enter at the front of the list: ");
    scanf("%d", &val);
    insert_front(&head, val);

    printf("List after insertion: ");
    print_list(head);

    printf("Enter a value to enter at the end of the list: ");
    scanf("%d", &val);
    insert_end(&head, val);

    printf("List after insertion: ");
    print_list(head);

    printf("Enter a value to insert in the list: ");
    scanf("%d", &val);

    printf("Insert after: ");
    scanf("%d", &pos);

    insert_after(find_node(head, pos), val);

    printf("List after insertion: ");
    print_list(head);

    printf("Enter a value to insert in the list: ");
    scanf("%d", &val);

    printf("Insert before: ");
    scanf("%d", &pos);

    insert_before(&head, find_node(head, pos), val);

    printf("List after insertion: ");
    print_list(head);
}

