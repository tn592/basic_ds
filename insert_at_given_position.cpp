/*
Question:
Take a singly linked list as input, then take q queries.
In each query you will be given an index and value.
You need to insert the value at the given index
and print the linked list.

If the index is invalid, print "Invalid".


Sample Input:
10 20 30 -1
7
1 40
5 50
4 50
0 100
7 40
1 110
7 40


Sample Output:
10 40 20 30
Invalid
10 40 20 30 50
100 10 40 20 30 50
Invalid
100 110 10 40 20 30 50
100 110 10 40 20 30 50 40
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

void insert_at_head(Node* &head, Node* &tail, int value){
	Node* newnode = new Node(value);
	if(head==NULL){
		head = newnode; tail = newnode; 
		return;
	}
	newnode->next = head;
	head = newnode;
}

void insert_at_tail(Node* &head, Node* &tail, int value){
	Node* newnode = new Node(value);
	if(head==NULL){
		head = newnode; tail = newnode;
		return;
	}
	tail->next = newnode;
	tail = newnode;
}

void insert_at_gv_pos(Node* &head, int idx, int value){
	Node* newnode = new Node(value);
	Node* temp = head;
	for(int i = 0; i < idx-1; i++)
		temp = temp->next;
	newnode->next = temp->next;
	temp->next = newnode;
}

int size(Node* head){
	int sz = 0;
	Node* temp = head;
	while(temp != NULL){
		sz++; temp = temp->next;
	}
	return sz;
}

void print_list(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << '\n';
}

int main(){
	Node* head = NULL; Node* tail = NULL;
	int value;
	while(true){
		cin >> value;
		if(value==-1) break;
		insert_at_tail(head, tail, value);
	}
	int q;
	cin >> q;
	while(q--){
		int idx, value;
		cin >> idx >> value;
		int sz = size(head);
		if(idx > sz)
			cout << "Invalid\n";
		else if(idx == 0){
			insert_at_head(head,tail,value);
			print_list(head);
		}else if(idx == sz){
			insert_at_tail(head,tail,value);
			print_list(head);
		}else{
			insert_at_gv_pos(head,idx,value);
			print_list(head);
		}
	}
	return 0;
}