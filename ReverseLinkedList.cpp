
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
// A linked List Node
class Node {
public:
    int data;
    Node* next;
};
 
void inserthead(Node **head, int newdata)
{
    Node *newnode= new Node[sizeof(Node)];
    newnode->data=newdata;
    
    newnode->next=*head;
    *head=newnode;
}

void printlist(Node *n)
{
    cout << "Printing list : "<<endl;
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
}

Node *reverselist(Node *head)
{
    Node *cur=head;
    Node *prev=NULL;
    Node *nex=NULL;
    while(cur!=NULL)
    {
        nex=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nex;
    }
    head=prev;
    return head;
}

int main()
{
    Node *head=NULL;
    inserthead(&head,1);
    inserthead(&head,2);
    inserthead(&head,3);
    inserthead(&head,4);
    inserthead(&head,5);

    printlist(head);
    head=reverselist(head);
    printlist(head);
    
}
