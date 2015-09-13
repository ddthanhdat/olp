// Note: largest possible integer which can be made by appending all the N integers
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#define ll long long
using namespace std;
bool cmp(string a, string b){
	return a+b>b+a;
}

vector<string> v;
int main(){
	
//	freopen("ip.txt","r",stdin);
	
	ll n;
	while(cin >> n){
		if(!n) break;
		string m;
		for(ll i=0;i<n;i++){
			cin >> m;
			v.push_back(m);
		}
		sort(v.begin(),v.end(),cmp);
		for(ll i=0;i<n;i++){
			cout << v[i];
		}
		
		cout << endl;
		v.clear();
	}
	
	
}
