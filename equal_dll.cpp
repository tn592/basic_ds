/*
Question:
Take two doubly linked lists as input and check
whether they are the same or not.


Sample Input:
10 20 30 40 50 -1
10 20 30 40 50 -1

Sample Output:
YES


Sample Input:
10 20 30 40 50 -1
10 20 30 40 -1

Sample Output:
NO


Sample Input:
10 20 30 40 -1
10 20 30 40 50 -1

Sample Output:
NO
*/


#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int value;
	Node* next; Node* pr;
	Node(int value){
		this -> value = value;
		this -> next = NULL; this->pr = NULL;
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

int sz(Node* &head){
	Node* temp = head;
	int cnt = 0;
	while(temp != NULL){
		cnt++; temp = temp->next;
	}
	return cnt;
}

void same_or_not(Node* &head1, Node* &head2){
	int sz1 = sz(head1), sz2 = sz(head2);
	Node* temp1 = head1; Node* temp2 = head2;
	int f = 1;
	if(sz1==sz2){
		while(temp1 != NULL && temp2 != NULL){
			if(temp1->value != temp2->value){
				f = 0; break;
			}
			temp1 = temp1->next; temp2 = temp2->next;
		}
		cout << ((!f) ? "NO" : "YES");
	}else cout << "NO";
}

int main(){
	Node* head1 = NULL; Node* tail1 = NULL;
	Node* head2 = NULL; Node* tail2 = NULL;
	int value;
	while(true && cin >> value){
		if(value==-1) break;
		insert_list(head1,tail1,value);
	}
	while(true && cin >> value){
		if(value==-1) break;
		insert_list(head2,tail2,value);
	}
	same_or_not(head1,head2);
	return 0;
}