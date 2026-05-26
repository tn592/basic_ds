/*
Question:
Take a doubly linked list as input and reverse it.
After that print the linked list.


Sample Input:
10 20 30 -1

Sample Output:
30 20 10


Sample Input:
10 20 30 40 -1

Sample Output:
40 30 20 10
*/


#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int value; Node *next, *pr;
	Node(int value){
		this -> value = value;
		this -> next = NULL; this -> pr = NULL;
	}
};

void insert_list(Node* &head, Node* &tail, int value){
	Node* newnode = new Node(value);
	if(head==NULL){
		head = newnode; tail = newnode;
		return;
	}
	tail->next = newnode;
	newnode->pr = tail;
	tail = newnode;
}

void reverse_list(Node* head, Node* tail){
	for(Node* i = head, *j = tail; i != j && i->pr != j; i=i->next,j=j->pr)
		swap(i->value,j->value);
}

void print_list(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout << temp->value << " ";
		temp = temp->next;
	}
}

int main(){	
	Node* head = NULL; Node* tail = NULL;
	int value;
	while(true && cin >> value){
		if(value==-1) break;
		insert_list(head,tail,value);
	}
	reverse_list(head,tail);
	print_list(head);
	return 0;
}