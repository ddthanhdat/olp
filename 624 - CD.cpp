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
// value 
int N;
int Max;
// vector trong ham backtrack
vector<int> solution;
vector< vector<int> > rs; // vector chua cac dap an

// vector tam de cho vao rs
 vector<int> tmp;
void backtrack(int left, int tong){
	if(left==ip.size() || tong >N ){
		if(tong>N){ // do tong>N phai bo con so cuoi cung
			int s=0;
			for(int j=0;j<solution.size()-1;j++){ //j<solution.size()-1 ; khong lay so cuoi cung
				s+=solution[j];
				tmp.push_back(solution[j]);
			}
			if(Max<s) Max=s;
			rs.push_back(tmp);
			tmp.clear();
			return;
		}
		int s=0;
		for(int j=0;j<solution.size();j++){
			s+=solution[j];
		}
		if(Max<s) Max=s;
		rs.push_back(solution);
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
		Max=0;
		int n; cin >> n;
		int a;
		for(int i=0;i<n;i++){
			cin >> a;
			ip.push_back(a);
		}
		// chay de quy
		backtrack(0,0);
		// in output
		for(int i=0;i<rs.size();i++){
			int ss=0;
			for(int j=0;j<rs[i].size();j++){
				ss+=rs[i][j];
			}
			if(ss==Max){
				for(int j=0;j<rs[i].size();j++)
					cout << rs[i][j]<< " ";
				break;
			}
		}
		cout << "sum:" << Max << endl;
		//reset
		ip.clear();
		rs.clear();
		
	}
	
	
}
