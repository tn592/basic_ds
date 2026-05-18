/*
Question:
Create a singly linked list and check whether
the linked list is sorted in ascending order.


Sample Input:
1 5 6 8 9

Sample Output:
YES


Sample Input:
2 4 6 5 8 4

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

int main(){	
	Node* head = NULL; Node* tail = NULL;
	int value;
	while(true){
		cin >> value;
		if(value==-1) break;
		Node* newnode = new Node(value);
		if(head==NULL){
			head = newnode; tail = newnode;
		}else{
			tail->next = newnode; tail = newnode;
		}
	}
	Node* temp = head;
	bool f = true;
	while(temp != NULL && temp->next != NULL){
		if(temp->value > temp->next->value){
			f = false;
			break;
		}
		temp = temp->next;
	}
	cout << ((f) ? "YES\n" : "NO\n");
	return 0;
}