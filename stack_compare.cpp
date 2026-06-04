/*
Question:
Take two stacks of size N and M as input and
check whether both of them are the same or not.

Do not use STL stack to solve this problem.


Sample Input:
5
10 20 30 40 50
5
10 20 30 40 50

Sample Output:
YES


Sample Input:
5
10 20 30 40 50
4
10 20 30 40

Sample Output:
NO


Sample Input:
5
10 20 30 40 50
5
50 40 30 20 10

Sample Output:
NO
*/



#include <bits/stdc++.h>
using namespace std;

class myStack{
public:
	list<int> l;

	void push(int v){
		l.push_back(v);
	}

	void pop(){
		l.pop_back();
	}

	int top(){
		return l.back();
	}

	int size(){
		return l.size();
	}

	bool empty(){
		return l.empty();
	}
};

int main(){
	myStack st1, st2;
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		st1.push(x);
	}
	int m; cin >> m;
	for(int i = 0; i < m; i++){
		int x; cin >> x;
		st2.push(x);
	}
	bool f = 1;
	if(n!=m) cout << "NO";
	else{
		while(!st1.empty() && !st2.empty()){
			if(st1.top() != st2.top()){
				f = 0; break;
			}
			st1.pop(); st2.pop();
		}
		cout << ((f) ? "YES" : "NO");
	}
	return 0;
}