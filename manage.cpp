#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void insert_front(struct node** head,int data)
{
    node* new_node=new node();

    new_node->data=data;
    new_node->next=*head;
    *head=new_node;
}

void insert_after(struct node* node1,int n_data,int data)
{
    while(node1->data!=n_data)
    {
        node1=node1->next;

    }

    node* new_node=new node();
    new_node->data=data;
    new_node->next=node1->next;
    node1->next=new_node;
}

void insert_at_end(struct node* head,int data)
{
    node* new_node=new node();

    new_node->data=data;
    new_node->next=NULL;

    node* last=head;

    if(head==NULL)
    {
        head=new_node;
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=new_node;

}

void display(struct node* node)
{
    while(node!=NULL)
    {
        cout<<node->data<<"->";
        node=node->next;
    }
    cout<<"NULL \n";
}

void reverse(struct node** head)
{
    
    node* current=*head;
    node* prev=NULL;
    node* next=NULL;

    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;

    
}




int main()
{
    struct node* head=NULL;

while(1)
{
    int ch,ele;
    cout<<"1.Insert beggining "<<endl<<"2.Insert after "<<endl<<"3.Insert at the end "<<endl<<"4.display "<<endl<<"5.Reverse"<<endl<<"6.Delete"<<endl;
    cout<<"Enter choice: "<<endl;
    cin>>ch;


    switch(ch)
    {
        case 1:
        cout<<"Enter the element: "<<endl;
        cin>>ele;
        insert_front(&head,ele);
        break;

        case 2:
        int n_data;
        cout<<"Enter the node: "<<endl;
        cin>>n_data;
        cout<<"enter the element: "<<endl;
        cin>>ele;
        insert_after(head,n_data,ele);
        break;

        case 3:
        cout<<"inert the element: "<<endl;
        cin>>ele;
        insert_at_end(head,ele);
        break;

        case 4:
        display(head);
        break;

        case 5:
        reverse(&head);
        break;

    

        default: break;
        
    }
    

}

    return 0;
}