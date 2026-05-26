/*
Question:
Take a doubly linked list as input and check
whether it forms a palindrome or not.


Sample Input:
10 20 30 20 10 -1

Sample Output:
YES


Sample Input:
10 20 30 30 20 10 -1

Sample Output:
YES


Sample Input:
10 20 30 20 40 -1

Sample Output:
NO
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

void p(Node* head, Node* tail){
	int f = 1;
	for(Node* i=head, *j=tail; i!=j && i->pr!=j; i=i->next,j=j->pr){
		if(i->value != j->value){
			f = 0; break;
		}
	}
	cout << ((f) ? "YES" : "NO");
}

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

int main(){
	Node* head = NULL; Node* tail = NULL;
	int value;
	while(true && cin >> value){
		if(value==-1) break;
		insert_list(head,tail,value);
	}
	p(head,tail);
	return 0;
}