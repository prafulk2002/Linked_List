//Recursive Method

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

node* reverseRecursive(node* &head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    
    node* newhead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
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
    display(head);
    node* newhead=reverseRecursive(head);
    display(newhead);
    return 0;
}
