#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;

    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void insertathead(node* &head, int val)
{
    node* n=new node(val);
    n->next=head;
    head=n;

}

void insertattail(node* &head, int val)
{
    node* n=new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}

void makecycle(node* head, int pos)
{
    node* temp=head;
    node* startnode;
    int count=1;
    while(temp->next!=NULL)
    {
        if(count=pos)
        {
            startnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}

bool detect(node* &head)
{
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
        {
            return true;
        }
    }
    return false;
}

void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node* head=NULL;
    insertattail(head ,1);
    insertattail(head ,2);
    insertattail(head ,3);
    insertattail(head ,4);
    insertattail(head ,5);
    insertathead(head ,6);
    insertathead(head ,7);
    insertathead(head ,8);
    makecycle(head, 3);
    cout<<detect(head)<<endl;
    return 0;
}
