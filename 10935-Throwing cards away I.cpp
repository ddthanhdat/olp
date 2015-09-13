#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#define ll long long
using namespace std;
queue<int> q;



int main(){
//	freopen("ip.txt","r",stdin);
//	freopen("rs.txt","w",stdout);
	int n;
	while(cin >> n){
		if(!n) break;
		int i=1;
		bool dem=0;
		//discar
		if(n==1) cout << "Discarded cards:";
		else cout << "Discarded cards: ";
		while(i<=n){
			
			q.push(i); i++;
		}
		
		while(q.size()!=1){
			if(dem) cout << ", ";
			cout << q.front();
			q.pop();
			q.push(q.front());
			q.pop();
			dem=1;
		}
		cout << endl;
		cout << "Remaining card: " << q.front() << endl;
		q.pop();
	//	q.clear();
	}
	
}
