/*
Question:
Create a singly linked list and check whether
the linked list contains any duplicate value.

You can assume that the maximum value will be 100.


Sample Input:
5 4 8 6 2 1

Sample Output:
NO


Sample Input:
2 4 5 6 7 4

Sample Output:
YES
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
	int fr[105] = {0};
	Node* temp = head;
	while(temp != NULL){
		fr[temp->value]++; 
		temp = temp->next;
	}
	bool f = false;
	for(int i = 0; i < 105; i++){
		if(fr[i] > 1){
			f = true; 
			break;
		}
	}
	cout << ((f) ? "YES\n" : "NO\n");
	return 0;
}