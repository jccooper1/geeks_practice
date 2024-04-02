#include<iostream>
#include<cstdio>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
            data = x;
            next = NULL;
    }
};

class Solution
{
        public:
        Node *sortedInsert(Node* head, int data)
        {
             Node* newNode = new Node(data);
             if(head == NULL){
                     newNode->next = newNode;
                     head = newNode;
                     return head;
             }
                else if(data <= head->data){
                        Node* temp = head;
                        while(temp->next != head){
                                temp = temp->next;
                        }
                        temp->next = newNode;
                        newNode->next = head;
                        return newNode;
                }
                else{
                        Node* temp = head;
                        while(temp->next != head && data > temp->next->data){
                                temp = temp->next;
                        }
                        newNode->next = temp->next;
                        temp->next = newNode;
                        return head;
                }
        }
};

void printList(struct Node *start)
{
    struct Node *temp;

    if(start != NULL)
    {
        temp = start;
        do { printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != start);
        printf("\n");
    }
}

int main()
{
int t,n,x;
scanf("%d",&t);
int arr;
    while(t--){
    scanf("%d",&n);
    int list_size, i;
    
    struct Node *start = NULL;
    struct Node *temp,*r;
    
        if(n>0){
            scanf("%d",&arr);
        
        temp = new Node(arr);
        start=temp;
        r=start;
        }
        for (i = 0; i<n-1; i++)
        {
                scanf("%d",&arr);
                temp = new Node(arr);
                r->next=temp;
                r=r->next;
        }
        
        if(n>0)
        temp->next=start;
 
        scanf("%d",&x);
        Solution ob;
        start = ob.sortedInsert(start,x);
        printList(start);
        r=start;
        while(r!=start->next)
        {

            temp=start;
            start=start->next;
            free(temp);
        }
        free(start);
}
    return 0;
}