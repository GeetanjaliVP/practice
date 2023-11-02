#include <bits/stdc++.h>
using namespace std;

template<typename t>

class node {
public:
    t data;
    node* next;

    // A constructor is called here
    node(t value)
    {

        data = value;

        next = NULL;
    }
};

void insert_at_head(struct node** head,t data)
{
    node* n=new node(data);

    n->next=*head;
    *head=n;
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
    struct node* head=NULL;

while(1)
{

    
    insert_at_head(&head,num);
        

}

}