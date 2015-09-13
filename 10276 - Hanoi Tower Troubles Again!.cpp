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
bool kt(ll a){
	for(ll i=0;i<a;i++)
	if(i*i==a) return 1;
	return 0;
}
ll rs[51];
vector<ll> tmp(51,0);


void backtrack(int left, ll i, int peg){
	if(peg>50) return;
	if(left>peg){
		rs[peg]=i-1;
		backtrack(left=1,i,peg+1);
	}else{
		if(tmp[left]==0){
			tmp[left]=i;
			backtrack(left=1,i+1,peg);
		}
		else if(kt(tmp[left]+i)==1) {
					tmp[left]=i;
					backtrack(left=1,i+1,peg);
		} else backtrack(left+1,i,peg);
			
	}
}

int main(){
//	freopen("ip.txt","r",stdin);
	backtrack(1,1,1);
	ll n;
	cin >> n;
	ll a;
	for(int i=0;i<n;i++){
		cin >> a;
		cout << rs[a] << endl;
	}
	
}
