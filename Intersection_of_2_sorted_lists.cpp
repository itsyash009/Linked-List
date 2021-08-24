#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    Node* head=NULL;
    Node* tail=NULL;
    Node* t1=head1;
    Node* t2=head2;
    while(t1!=NULL&&t2!=NULL)
    {
        if(t1->data==t2->data)
        {
            if(head==NULL)
                head = tail = new Node(t1->data);
                
            else
            {
                // appending new node at the end
                tail->next = new Node(t1->data);
                tail = tail->next;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        else if(( t1->data)>(t2->data))
        t2=t2->next;
        else 
        t1=t1->next;
    }
    tail->next=NULL;
    return(head);
}
