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
vector<ll> v;
ll Max;
ll chiadoan(ll mid){
	ll tong=0;
	ll count=0;
	for(ll i=0;i<v.size();i++){
		tong+=v[i];
		if(tong>mid){
			
			count++;
			tong=v[i];
		}
	}
	count++;
	return count;
}
ll tinhtong(ll x){
	ll tong=0;
	ll ln=0;
	for(ll i=0;i<v.size();i++){
		tong+=v[i];
		if(tong>x){
			if(tong-v[i]>ln) ln=tong-v[i];
			tong=v[i];
			
		}
	}
	if(tong>ln) ln=tong;
	return ln;
}
ll binarysearch(ll m){
	ll left=0, right=1000000000+5;
	ll mid;
	ll sodoan;
	ll rs;
	while(left<=right){
		mid=(left+right)/2;
		sodoan=chiadoan(mid);
		if(sodoan<m) right=mid-1;
		else if(sodoan==m) {
			rs=mid;
			right=mid-1;
			
			
		}
		else left=mid+1;
	}
	return rs;
}

int main(){
//	freopen("ip.txt","r",stdin);
	ll n,m,c;
	while(cin >> n >> m){
		for(ll i=0;i<n;i++){
			cin >> c;
			v.push_back(c);
		}
		ll a=binarysearch(m);
		
		cout <<tinhtong(a)<< endl;
		v.clear();
	}
}
