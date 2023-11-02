#include <bits/stdc++.h>
using namespace std;


class node {
public:
    int data;
    node* next;

    // A constructor is called here
    node(int value)
    {
         cout<<"In constructor....";
        data = value;

        next = NULL;
    }
};

void insert_at_head(struct node** head,int data)
{
    node* n=new node(data);

    n->next=*head;
    *head=n;
}

void insert_in_middle(struct node** head,int val,int data)
{
    node* n=new node(data);
    node* temp=*head;

    while(temp->data!=val)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            cout<<"Node is not present in the list..."<<endl;
            return;
        }
    }
    
    
    n->next=temp->next;
    temp->next=n;

}

void insert_at_position(struct node** head,int val,int data)
{
    int count=1;
    node* n=new node(data);
    node* temp=*head;
    node* prev=NULL;
    if(val==1)
    {
        n->next=*head;
        *head=n;
        return;
    }
    while(count!=val-1 && temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;

}

void insert_at_end(struct node** head,int data)
{
    node* n=new node(data);
    node* temp=*head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=NULL;
}

void deletion(struct node** head,int data)
{
    node* temp=*head;
    node* pre=NULL;

    while(temp->data!=data)
    {
        pre=temp;
        temp=temp->next;
    }
    pre->next=temp->next;
    delete temp;
}

void reversal(struct node** head)
{
    node* prev=NULL;
    node* next=NULL;
    node* temp=*head;

    while(temp!=NULL)
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
        *head=prev;
    }
}

void display(struct node** head)
{
    node* temp=*head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    int ch,num;
    node* head=NULL;

while(1)
{

    cout<<"1.Insert at front "<<endl<<"2.Insert by value "<<endl<<"3.Insert at position "<<endl<<"4.Insert at end "<<endl<<"5.Delete "<<endl<<"6.Reverse"<<endl<<"7.display "<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1:cout<<"Enter the value: ";
               cin>>num;
               insert_at_head(&head,num);
               break;

        case 2:int pos;
               cout<<"Enter the position element: ";
               cin>>pos;
               cout<<"Enter the value: ";
               cin>>num;
               insert_in_middle(&head,pos,num);
               break;

        case 3:int pos1;
               cout<<"Enter the position: ";
               cin>> pos1;
               cout<<"Enter the value: ";
               cin>>num;
               insert_at_position(&head,pos1,num);
               break;

        case 4:cout<<"Enter the value: ";
               cin>>num;
               insert_at_end(&head,num);
               break;

        case 5:cout<<"Enter the value: ";
               cin>>num;
               deletion(&head,num);
               break;

        case 6:reversal(&head);
               break;

        case 7:display(&head);
               break;

        default: break;
    }

}

}