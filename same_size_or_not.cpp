/*
Question:
Take two singly linked lists as input and check
whether their sizes are the same or not.


Sample Input:
2 1 5 3 4 9 -1
1 2 3 4 5 6 -1

Sample Output:
YES


Sample Input:
5 1 4 5 -1
5 1 4 -1

Sample Output:
NO
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

int size(Node* head){
	int sz = 0;
	Node* temp = head;
	while(temp != NULL){
		sz++; temp = temp->next;
	}
	return sz;
}

int main(){	
	Node* head1 = NULL; Node* tail1 = NULL;
	Node* head2 = NULL; Node* tail2 = NULL;
	int value;
	while(true){
		cin >> value;
		if(value==-1) break;
		insert_list(head1, tail1, value);
	}
	while(true){
		cin >> value;
		if(value==-1) break;
		insert_list(head2, tail2, value);
	}
	int sz1 = size(head1);
	int sz2 = size(head2);
	cout << ((sz1==sz2) ? "YES\n" : "NO\n");
	return 0;
}