#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <map>
#define ll long long
using namespace std;
// vector ip trong ham main
vector<int> ip;
// value N
int N;
// vector trong ham backtrack
vector<int> solution;
// map de tranh trung nhau
map< vector<int>,bool > m;
//
 vector<int> tmp;
void backtrack(int left, int tong){
	if(left==ip.size() || tong >=N ){
		if(tong==N && m[solution]==0){
			bool dem=0;
			for(int j=0;j<solution.size();j++){
				if(dem) cout << "+";
				cout << solution[j];
				dem=1;
			}
			cout << endl;
			m[solution]=1;
		}
		return;
	}
	for(int i=left;i<ip.size();i++){
		solution.push_back(ip[i]);
		backtrack(1+i,tong+ip[i]);
		
		// xoa tai cho
		solution.pop_back();
	}
}
int main(){
//	freopen("ip.txt","r",stdin);
//	freopen("rs.txt","w",stdout);
	while(cin >> N){
		if(!N) break;
		int n; cin >> n;
		int a;
		for(int i=0;i<n;i++){
			cin >> a;
			ip.push_back(a);
		}
		//
		cout << "Sums of "<<N <<":"<<endl;
		
		backtrack(0,0);
		// in output
		if(m.size()==0) cout << "NONE"<<endl;
		
		//reset
		ip.clear();
		m.clear();
	}
	
	
}
