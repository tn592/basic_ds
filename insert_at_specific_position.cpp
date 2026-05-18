#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int value; Node* next;
    Node(int value){
        this -> value = value; this -> next = NULL;
    }
};

void insert_at_specific_pos(Node* &head, int idx, int value){
    Node* newnode = new Node(value);
    Node* temp = head;
    for(int i = 1; i < idx; i++)
        temp = temp->next;
    newnode->next = temp->next;
    temp->next = newnode;
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
    Node* head = new Node(10); Node* a = new Node(20); Node* b = new Node(30);
    head->next = a; a->next = b;
    cout << "Enter the value and index: ";
    int value, idx;
    cin >> value >> idx;
    insert_at_specific_pos(head, idx, value);
    display_list(head);
    return 0;
}