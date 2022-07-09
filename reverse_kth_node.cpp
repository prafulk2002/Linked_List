//Reverse kth Node.
/* for example: Node is: 1->2->3->4->5->6
k=2
output will be: 2->1->4->3->6->5
*/

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

node* reverse(node* &head, int k)
{
    node* prev=NULL;
    node* curr=head;
    node* next;
    int count=0;
    while(curr!=NULL && count<k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL)
    {
        head->next=reverse(next, k);
    }
    return prev;
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
    int k=2;
    node* newhead=reverse(head,k);
    display(newhead);
    return 0;
}
