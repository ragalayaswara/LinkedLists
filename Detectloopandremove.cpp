// A C++ recursive program to add two linked lists
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

void detectloopremove(Node *head)
{
    Node *cur=head;
    Node *prev=head;
    bool loopdetected=false;
    
    unordered_set<Node *>h;
    while(cur!=NULL)
    {
        if(h.find(cur) != h.end())
        {
           loopdetected=true; 
        }
        else{
        h.insert(cur);
        prev=cur;
        cur=cur->next;
        }
        
        if(loopdetected==true)
        {
            prev->next=NULL;
            loopdetected=false;
            return;
        }
     
    }
}

int main()
{
    Node *head=NULL;
    inserthead(&head,1);
    inserthead(&head,2);
    inserthead(&head,3);
    inserthead(&head,4);
    inserthead(&head,5);

    head->next->next->next->next->next=head;
    detectloopremove(head);
    printlist(head);
    
}
