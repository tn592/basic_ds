/*
Question:
Take a stack of size N and a queue of size M as input.
Then check whether both of them are the same or not
in the order of removing elements.

You should use STL to solve this problem.


Sample Input:
5
10 20 30 40 50
5
10 20 30 40 50

Sample Output:
NO


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
YES
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
	stack<int> s;
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x; 
		s.push(x);
	}
	queue<int> q;
	int m; cin >> m;
	for(int i = 0; i < m; i++){
		int x; cin >> x;
		q.push(x);
	}
	if(n!=m) cout << "NO";
	else{
		bool f = 1;
		while(!s.empty() && !q.empty()){
			if(s.top() != q.front()){
				f = 0; break;
			}
			s.pop(); q.pop();
		}
		cout << ((f) ? "YES" : "NO");
	}
	return 0;
}