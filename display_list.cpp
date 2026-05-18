#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int value; Node* next;
    Node(int value){
        this -> value = value; this -> next = NULL;
    }
};

void display_list(Node* &head){
    Node* temp = head; int cnt = 0;
    cout << "The list: ";
    while(temp != NULL){
        cout << temp->value << " ";
        temp = temp->next;
        cnt++;
    }
    cout << '\n' << "Size of the list: " << cnt;
}

int main(){
    Node* head = NULL; Node* tail = NULL;
    int value;
    cout << "Enter values (-1 to stop): ";
    while(true){
        cin >> value;
        if(value==-1) break;
        Node* newnode = new Node(value);
        if(head==NULL){
            head = newnode; 
            tail = newnode;
        }else{
            tail->next = newnode; 
            tail = newnode;
        }
    }
    if(head!=NULL) cout << "The Linked List has been Created!" << '\n';
    display_list(head);
    return 0;
}