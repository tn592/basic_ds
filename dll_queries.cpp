/*
Question:
You have a doubly linked list which is empty initially.
You need to take a value Q which refers to queries.

For each query you will be given X and V.
You will insert the value V at the Xth index
of the doubly linked list and print the list
from left to right and right to left.

If the index is invalid then print "Invalid".


Sample Input:
6
0 10
1 20
4 30
0 30
1 40
5 50


Sample Output:
10
10
10 20
20 10
Invalid
30 10 20
20 10 30
30 40 10 20
20 10 40 30
Invalid
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

void insert_at_head(Node* &head, Node* &tail, int value){
	Node* newnode = new Node(value);
	if(head==NULL){
		head = newnode; tail = newnode;
		return;
	}
	newnode->next = head;
	head->pr = newnode;
	head = newnode;
}

void insert_at_tail(Node* &head, Node* &tail, int value){
	Node* newnode = new Node(value);
	if(head==NULL){
		head = newnode; tail = newnode;
		return;
	}
	tail->next = newnode;
	newnode->pr = tail;
	tail = newnode;
}

void insert_at_idx(Node* &head, int idx, int value){
	Node* newnode = new Node(value);
	Node* temp = head;
	for(int i = 0; i < idx-1; i++)
		temp = temp->next;
	newnode->next = temp->next;
	temp->next->pr = newnode;
	temp->next = newnode;
	newnode->pr = temp;
}

int list_size(Node* &head){
	Node* temp = head;
	int sz = 0;
	while(temp != NULL){
		sz++; temp = temp->next;
	}
	return sz;
}

void print_forward(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout << temp->value << " ";
		temp = temp->next;
	}
}

void print_backward(Node* tail){
	Node* temp = tail;
	while(temp != NULL){
		cout << temp->value << " ";
		temp = temp->pr;
	}
}

int main(){
	Node* head = NULL; Node* tail = NULL;
	int q;
	cin >> q;
	while(q--){
		int x, v;
		cin >> x >> v;
		int sz = list_size(head);
		if(x==0){
			insert_at_head(head,tail,v);
			print_forward(head);
			cout << '\n';
			print_backward(tail);
			cout << '\n';
		}else if(x==sz){
			insert_at_tail(head,tail,v);
			print_forward(head);
			cout << '\n';
			print_backward(tail);
			cout << '\n';
		}else if(x<sz){
			insert_at_idx(head,x,v);
			print_forward(head);
			cout << '\n';
			print_backward(tail);
			cout << '\n';
		}else cout << "Invalid\n";
	}
	return 0;
}