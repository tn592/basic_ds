/*
Question:
Take a singly linked list as input and print
the maximum value from the linked list.


Sample Input:
2 4 1 3 5 4 2 5 -1

Sample Output:
5


Sample Input:
5 4 1 2 5 6 8 4 1 3 -1

Sample Output:
8
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

int get_mx(Node* head){
	Node* temp = head;
	int mx = INT_MIN;
	while(temp != NULL){
		mx = max(temp->value, mx);
		temp = temp->next;
	}
	return mx;
}

int main(){	
	Node* head = NULL; Node* tail = NULL;
	int value;
	while(true){
		cin >> value;
		if(value==-1) break;
		insert_list(head,tail,value);
	}
	cout << get_mx(head);
	return 0;
}