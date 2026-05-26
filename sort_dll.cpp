/*
Question:
Take a doubly linked list as input and sort it
in ascending order. Then print the list.


Sample Input:
1 4 5 2 7 -1

Sample Output:
1 2 4 5 7


Sample Input:
20 40 30 10 50 60 -1

Sample Output:
10 20 30 40 50 60
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
	list<int> dll;
	int v;
	while(true && cin >> v){
		if(v==-1) break;
		dll.push_back(v);
	}
	dll.sort();
	for(int i : dll)
		cout << i << " ";
	return 0;
}