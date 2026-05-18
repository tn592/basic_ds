/*
Question:
Create a singly linked list and print the middle element.
If there are multiple values in the middle, print both.


Sample Input:
2 4 6 8 10

Sample Output:
6


Sample Input:
1 2 3 4 5 6

Sample Output:
3 4
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
	Node* temp = head; int cnt = 0;
	while(temp != NULL){
		 cnt++; temp = temp->next;
	}
	temp = head;
	if(cnt%2 == 0){
		for(int i = 0; i < (cnt/2)-1; i++)
			temp = temp->next;
		cout << temp->value << " " << temp->next->value;
	}else{
		for(int i = 0; i < cnt/2; i++)
			temp = temp->next;
		cout << temp->value;
	}
	return 0;
}