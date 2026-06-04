/*
Question:
Take a queue of size N as input. You need to copy
those elements into another queue in reverse order.

You may use a stack to solve this problem.
You should use STL to solve this problem.

After copying into the new queue, print its elements.


Sample Input:
5
10 20 30 40 50

Sample Output:
50 40 30 20 10
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
	queue<int> q;
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		q.push(x);
	}
	stack<int> s;
	while(!q.empty()){
		s.push(q.front());
		q.pop();
	}
	queue<int> q2;
	while(!s.empty()){
		q2.push(s.top());
		s.pop();
	}
	while(!q2.empty()){
		cout << q2.front() << " ";
		q2.pop();
	}
	return 0;
}