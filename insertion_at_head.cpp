#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int value; Node* next;
    Node(int value){
        this -> value = value; this -> next = NULL;
    }
};

void insert_at_head(Node* &head, int value){
    Node* newnode = new Node(value);
    if(head==NULL){
        head = newnode; return;
    }
    newnode->next = head; head = newnode;
}

void display_list(Node* &head){
    Node* temp = head; 
    cout << "Linked List: ";
    while(temp != NULL){
        cout << temp->value << " ";
        temp = temp->next;
    }
}

int main(){
    Node* head = NULL;
    int value;
    cout << "Enter values (-1 to stop): ";
    while(true){
        cin >> value;
        if(value==-1) break;
        insert_at_head(head, value);
    }
    display_list(head);
    return 0;
}