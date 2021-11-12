#include <bits/stdc++.h>
#include <cinttypes>
using namespace std;
class Node
{
    public: int data;
    Node* xnode;
};
Node* Xor(Node* x, Node* y)
{
    return reinterpret_cast<Node*>(reinterpret_cast<uintptr_t>(x)^reinterpret_cast<uintptr_t>(y));
}
void insert(Node** head_ref, int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->xnode = *head_ref;
    if(*head_ref != NULL)
    {
        (*head_ref)->xnode = Xor(new_node, (*head_ref)->xnode);
    }
    *head_ref = new_node;
}
void printList(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next;
    cout<<"THe nodes of LinkedList are:\n";
    while(curr!=NULL)
    {
        cout<<curr->data<<"->";
        next = Xor(prev, curr->xnode);
        prev = curr;
        curr = next;
    }
    cout<<"\n";
}
Node* delEnd(Node** head)
{
    if (*head == NULL)
        printf("List is empty");
    else {
  
        
        Node* curr = *head;
        Node* prev = NULL;
  
        Node* next;
  
        while (Xor(curr->xnode, prev) != NULL) {
  
            next = Xor(prev, curr->xnode);
            prev = curr;
            curr = next;
        }
        if (prev != NULL)
            prev->xnode = Xor(Xor(prev->xnode, curr), NULL);
        else
            *head = NULL;
        free(curr);
    }
  
    return *head;
}

int main()
{
    Node* head = NULL;
    int n, val, ch=1;
    while(true)
    {
       cout<<"\nEnter \n1. Insertion.\n2. Deletion.\n3. Print List.\n4. Exit. "<<endl;
       cin>>ch;
       switch(ch)
       {
           case 1: cout<<"\nEnter the value: ";
                   cin>>val;
                   insert(&head, val);
                   break;
           case 2: head = delEnd(&head);

                    break;
            case 3: printList(head);
                    break;
            case 4: exit(0);
            default: break;                    
       }
    }
    return 0;
}