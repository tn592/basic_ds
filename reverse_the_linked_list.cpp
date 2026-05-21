/*
Question:
Take a singly linked list as input and print
the reverse of the linked list.


Sample Input:
5 4 8 6 2 1 -1

Sample Output:
1 2 6 8 4 5


Sample Input:
1 2 3 4 -1

Sample Output:
4 3 2 1
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int value; Node* next;
	Node(int value){
		this -> value = value; this -> next = NULL;
	}
};

void insert_list(Node* &head, Node* &tail, int value){
	Node* newnode = new Node(value);
	if(head==NULL){
		head = newnode; tail = newnode;
		return;
	}
	tail->next = newnode;
	tail = newnode;
}

void reverse_list(Node* temp){
	if(temp==NULL) return;
	reverse_list(temp->next);
	cout << temp->value << " ";
}

int main(){
	Node* head = NULL; Node* tail = NULL;
	int value;
	while(true){
		cin >> value;
		if(value==-1) break;
		insert_list(head, tail, value);
	}
	reverse_list(head);
	return 0;
}