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
// code//
vector<string> v;
vector<string> chuoi; // vector chua chuoi
void xuly(string s, int left){
	if(left==s.size()){
		for(int i=0;i<v.size();i++){
			cout << v[i];
		}
		cout << endl;
		return ;
	}
	if(s[left]=='#'){
		for(int i=0;i<chuoi.size();i++){
			v.push_back(chuoi[i]);
			xuly(s,left+1);
			//xoa
			v.pop_back();
		}
	}
	if(s[left]=='0'){
		for(int i=0;i<10;i++){
			string a;
			a+=(char)(i+'0');
			v.push_back(a);
			a.clear();
			xuly(s,left+1);
			// xoa
			v.pop_back();
		}
	}
}
int main(){
//	freopen("ip.txt","r",stdin);
	
	int n;
	while(cin >> n){
		cout << "--\n";
		string s;
		for(int i=0;i<n;i++){
			cin >> s;
			chuoi.push_back(s);
		}
		int N; // xo luong rule;
		cin >> N;
		string rule;
		for(int i=0;i<N;i++){
			cin >> rule;
			xuly(rule,0);
		}
		chuoi.clear();
		
	}
	
}
