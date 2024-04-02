//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    Node* remove_zeros(Node*head){
        while(head!=NULL&&head->data==0){
            head=head->next;
        }
        return head;
    }
    
    int len(Node*head){
        int count=0;
        while(head!=NULL){
            count++;
            head=head->next;
        }
        return count;
    }
    
    bool bigger(Node*head1,Node*head2){
        if(len(head1)>len(head2)){
            return true;
        }
        if(len(head1)<len(head2)){
            return false;
        }
        while(head1!=NULL&&head2!=NULL){
            if(head1->data>head2->data){
                return true;
            }
            if(head1->data<head2->data){
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
        return false;
    }
    Node* reverse(Node*head){
        Node*curr=head;
        Node*prev=nullptr;
        Node*next=nullptr;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        head1=remove_zeros(head1);
        head2=remove_zeros(head2);
        int val1,val2;
        int len1=len(head1);
        int len2=len(head2);
        bool carry=false;
        if(bigger(head2,head1)){
            swap(head1,head2);
        }
        head1=reverse(head1);
        head2=reverse(head2);
        Node*temp=new Node(-1);
        Node*curr=temp;
        while(head1||head2){
            val1 = (head1 != NULL) ? head1->data : 0;
            val2 = (head2 != NULL) ? head2->data : 0;
            if(head1){
                val1=head1->data;
                head1=head1->next;
            }
            if(head2){
                val2=head2->data;
                head2=head2->next;
            }
            if(carry){
                carry=false;
                val1--;
            }
            int val=val1-val2;
            if(val<0){
                val+=10;
                carry=true;
            }
            Node*newnode=new Node(val);
            curr->next=newnode;
            curr=curr->next;
        }
        Node*ans=temp->next;
        ans=reverse(ans);
        ans=remove_zeros(ans);
        if(ans==NULL){
            return new Node(0);
        }
        return ans;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends