#include<iostream>

using namespace std;
class Node
{
public:
    int data;
    Node* next;
};
main()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    //memory allocation
    head = new Node();
    second = new Node();
    third= new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;



}
