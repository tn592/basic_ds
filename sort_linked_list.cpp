/*
Question:
Take a singly linked list as input and sort it
in descending order. Then print the linked list.


Sample Input:
1 4 5 2 7 -1

Sample Output:
7 5 4 2 1


Sample Input:
20 40 30 10 50 60 -1

Sample Output:
60 50 40 30 20 10
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

void sort_list(Node* &head){
	for(Node* i = head; i->next != NULL; i = i->next){
		for(Node* j = i->next; j != NULL; j = j->next){
			if(i->value < j->value)
				swap(i->value, j->value);
		}
	}
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
	while(true){
		cin >> value;
		if(value==-1) break;
		insert_list(head, tail, value);
	}
	sort_list(head);
	print_list(head);
	return 0;
}