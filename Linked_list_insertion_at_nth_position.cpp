#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node* next;
};

class List
{

    node* head;
public:
    List()
    {
        head = NULL;

    }
   void CreateList();
   void InsertNum();
};
void List:: CreateList()
{

    cout<<"Enter the number to enter into the created list: ";
    int num; cin>>num;
    node* temp = new node();
    temp->data = num;
    temp->next = NULL;
    if(head==NULL)
    {
       head = temp;
       temp = NULL;
    }
    node *p = head;

    cout<<"Created List Contains: "<<endl;
     while(p!=NULL)
    {
         cout<<p->data<<"->"<<"NULL\n";
        p = p->next;
    }
    cout<<endl;
}
void List:: InsertNum()
{
    while(true){
    int c;
    cout<<"\n\tPlease enter the type of insertion that has to be performed:\n\n";
    cout<<"\t\t1.At the beginning.\n\t\t2.After particular number(if exists).\n\t\t3.At the end.\n\t\t4.exit\n";
    cout<<"Please Enter your choice: ";
    cin>>c;
    if(c==1)
    {
        if(head!=NULL||head!=0)
        {
            node* newNum = new node();
            cout<<"Enter the number: ";
            int newx;  cin>>newx;
            newNum->data= newx;
            newNum->next = head;
            head = newNum;

            node*q = head;
            cout<<"\n\t::::NEW LIST::::\n\n";
            while(q!=NULL)
            {
                cout<<q->data<<" ";
                q=q->next;
            }
            cout<<endl;
        }
        else
        {
            cout<<"List do not exists. Please create the list...\n";
        }
    }
    else if(c==2)
        {
            if(head!=NULL)
            {
                cout<<"\n\tPlease enter the number after which new number has to be added: ";
                int num;  cin>>num;
                node* p = head;
                while(p!=NULL)
                {
                    if(p->data==num)
                    {
                        cout<<"\t\tEntered Number found.\n";
                        cout<<"\t\tPlease enter the new Number: ";
                        int numx; cin>>numx;
                        node* nextP = p->next;
                        node* newNum = new node();
                        newNum->data = numx;
                        newNum->next = nextP;
                        p->next = newNum;
                    }
                    p = p->next;
                }
                 node* q = head;
                 cout<<"\n\t::::NEW LIST::::\n\n";
                    while(q!=NULL)
                    {
                        cout<<q->data<<"  ";
                        q = q->next;
                    }
                    cout<<endl;
            }
            else
            {
                cout<<"List do not exists. Please create the List.\n";
            }
        }
        else if(c==3)
        {
                if(head!=NULL)
                {
                    cout<<"Please enter the number to be inserted at the end: ";
                    int numx; cin>>numx;
                    node *p = head, *q2 = p->next;
                    while(q2!=NULL)
                    {
                        p=q2;
                        q2 = q2->next;
                    }
                    node* newNum = new node();
                    newNum->data = numx;
                    newNum->next = NULL;
                    p->next = newNum;
                    node* q = head;

                    cout<<"\n\t::::NEW LIST::::\n\n\t";
                    while(q!=NULL)
                    {
                        cout<<q->data<<"  ";
                        q = q->next;
                    }
                    cout<<endl;
                }
                else
                {
                    cout<<"\tList do not exists. Please create the List.\n\n";
                }
        }
        else if(c==4)
        {
            cout<<"Exiting insertion.\n";
            break;
        }
        else
        {
            cout<<"Invalid Choice.\n";
        }
    }
}
main()
{
    List obj;

    while(true)
    {
        cout<<"\nPlease enter your choice:\n";
        cout<<"1. Create a liked list.\n2. Enter a number in the Linked list.\n3. Exit.\n\n";
        int choice; cout<<"The Choice is:  "; cin>>choice;
        switch(choice)
        {
            case 1:obj.CreateList();
                    break;
            case 2: obj.InsertNum();
                    break;
            case 3: exit(0);
            default: cout<<"Invalid choice.";
        }
    }

}
