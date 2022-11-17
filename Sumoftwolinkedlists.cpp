
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

void inserthead(Node **head, int newdata);
Node* addsamesizelist(Node *head1, Node *head2, int &carry);
Node* adddiffsizelist(Node *head1, Node *head2, int &carry, int cnt1, int cnt2);
void addcarry(Node *head, int &carry, Node *result);
int getsize(Node *n);

void inserthead(Node **head, int newdata)
{
   Node *newnode=new Node[(sizeof(Node))];
   newnode->data=newdata;

   newnode->next=*head;
   *head=newnode;
}

void insertend(Node **head, int newdata)
{
   Node *newnode=new Node[(sizeof(Node))];
   newnode->data=newdata;

   Node *last=*head;
   while(last->next!=NULL)
    last=last->next;
    
    last->next=newnode;
    return;
}

int getsize(Node *n)
{
    int size=0;
    while(n!=NULL)
    {
        n=n->next;
        size++;
    }
    return size;
    
}
void printlist(Node *n)
{
    cout<<"Printing list:"<<endl;
    while(n!=NULL)
    {
        cout<<n->data<<endl;
        n=n->next;
    }
}
Node* addsamesizelist(Node *head1, Node *head2, int &carry)
{
   //Node *result=NULL;
    
    Node *result=new Node[sizeof(Node)];
    int sum=0;
    if (head1 == NULL)
    return NULL;
    sum=head1->data+head2->data+ carry;
    
    carry=sum/10;
    sum=sum%10;
    result->data=sum;

    result->next=addsamesizelist(head1->next,head2->next,carry);
    return result;
    
}

Node* adddiffsizelist(Node *head1, Node *head2, int &carry, int cnt1, int cnt2)
{
    int diffcnt=cnt1-cnt2;

    Node *result=new Node[sizeof(Node)];
    int sum=0;
    if (((head1 == NULL) && head2) )
       addcarry(head2->next,carry,result);
    else if (head1 &&(head2==NULL))
        addcarry(head1->next,carry,result);
    else if((head1 == NULL) && (head2==NULL) )
    return NULL;
    else{
    sum=head1->data+head2->data+ carry;
    
    carry=sum/10;
    sum=sum%10;
    result->data=sum;
    result->next=adddiffsizelist(head1->next,head2->next,carry,cnt1,cnt2);}
    return result;
    
}

void addcarry(Node *head, int &carry, Node *result)
{
    int sum=0;
    result=new Node[sizeof(Node)];
    if(head==NULL)
    return;
    sum=head->data+ carry;
    
    carry=sum/10;
    sum=sum%10;
    result->data=sum;
    addcarry(head->next,carry,result->next);
    
}
void addlist(Node *head1, Node *head2, Node **result)
{
    int cnt1=0,cnt2=0;
 
    cnt1=getsize(head1);
    cnt2=getsize(head2);
    cout<<"Cnt1: "<<cnt1<<"Cnt2: "<<cnt2;
    int carry=0;
    
    if(cnt1==cnt2)
    {
        *result=addsamesizelist(head1,head2,carry);
    }
   else
       *result=adddiffsizelist(head1,head2,carry,cnt1,cnt2);
    
    if(carry)
    insertend(result,carry);
    
}
int main()
{
    Node*head1=NULL;
    Node *head2=NULL;
    Node *result=NULL;
    inserthead(&head1,5);
    inserthead(&head1,6);
    inserthead(&head1,2);
   // inserthead(&head2,8);
    inserthead(&head2,6);
    inserthead(&head2,5);
    printlist(head1);
    printlist(head2);
    cout<<"Head1data:"<<head1->data;
    cout<<"Head2data: "<<head2->data;
    addlist(head1,head2,&result);
    printlist(result);
    

    return 0;
}
