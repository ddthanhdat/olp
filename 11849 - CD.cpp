#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#define ll long long
using namespace std;
map<ll,bool> ma;

int main(){
	freopen("ip.txt","r",stdin);
	freopen("rs.txt","w",stdout);
	ll n,m;
	while(cin >>n>>m){
		if(!n && !m) break;
		ll dem=0;
		ll a;
		for(ll i=0;i<n;i++){
			cin>> a;
			ma[a]=1;
		}
		for(ll i=0;i<m;i++){
			cin>> a;
			if(ma[a]==1) dem++;
		}
		cout << dem << endl;
		ma.clear();
	}

}
