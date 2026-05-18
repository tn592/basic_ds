#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int value; Node* next;
    Node(int value){
        this -> value = value; this -> next = NULL;
    }
};

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
    if(head!=NULL) cout << "The Linked List has been Created!";
    return 0;
}