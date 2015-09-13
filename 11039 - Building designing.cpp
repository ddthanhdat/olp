#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#define ll long long
using namespace std;
vector<ll> v;
vector<ll> rs;
bool cmp(ll a, ll b){
	return abs(a)>abs(b);
}

int main(){
//	freopen("ip.txt","r",stdin);
	ll N;
	cin >> N;
	for(ll Ni=0;Ni<N;Ni++){
		ll M; cin >> M;
		ll n;
		for(ll Mi=0;Mi<M;Mi++){
			cin >> n;
			v.push_back(n);
		}
		//sort giam dan`
		sort(v.begin(),v.end(),cmp);
		// so dau tien
		int carry;
		if(v[0]>0) carry=-1;
		else carry=1;
		rs.push_back(v[0]);
		
		// loc so ra
		for(ll i=1;i<v.size();i++){
			if(carry==-1 && v[i]<0){
				rs.push_back(v[i]);
				carry=1;
			}
			if(carry==1 && v[i]>0){
				rs.push_back(v[i]);
				carry=-1;
			}
		}
		
		
		cout << rs.size() ; 
		
		
		cout << endl;
		v.clear();
		rs.clear();
		
	}
	
	
}
