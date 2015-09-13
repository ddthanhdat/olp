#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#define ll long long
using namespace std;
vector<ll> v; ll m;
bool cmp(ll a, ll b){
	if(a%m==b%m){
		if(a%2!=0 && b%2!=0) return a>b;
		if(a%2==0 && b%2==0) return a<b;
		else return abs(a%2)>abs(b%2);
	}
	else{
		return a%m<b%m;
	}
}
/*
bool cmp(long long a,long long b)
{
    if(a%m!=b%m) return a%m<b%m;
    else
    {
        if(abs(a)%2==0 && abs(b)%2==0) return a<b;
        else if(abs(a)%2==1 && abs(b)%2==1) return a>b;
        else return abs(a%2)>abs(b%2);
    }
}
*/
int main(){
	cout << -7%5;
//	freopen("ip.txt","r",stdin);
//	freopen("rs.txt","w",stdout);
	ll n;
	ll a;
	while(cin >> n>>m){
		if(!n && !m) {
			cout << "0 0" << endl;
			break;
		}
		for(ll i=0;i<n;i++){
			cin >> a;
			v.push_back(a);
		}
		sort(v.begin(),v.end(),cmp);
		
		cout << n << " " << m << endl;
		for(ll i=0;i<v.size();i++){
			cout << v[i] << endl;
		}
		v.clear();
	}
	return 0;

}
