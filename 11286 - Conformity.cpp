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
map< vector<ll>,int > m;


int main(){
//	freopen("ip.txt","r",stdin);
	ll N;
	ll n;
	while(cin >> N){
		if(!N) break;
		ll Max=0;
		for(ll i=0;i<N;i++){
			// nhap moi frosh
			for(int j=0;j<5;j++){
				cin >> n;
				v.push_back(n);
			}
			// sort vector de cho vao map
			sort(v.begin(),v.end());
			// ++ 1gt vao map tai vector
			m[v]++;
			if(m[v]>Max) Max=m[v];
			// reset vector
			v.clear();
		}
		map< vector<ll>,int >:: iterator it;
		ll tong=0;
		for(it=m.begin();it!=m.end();it++){
			if((*it).second==Max) tong+=(*it).second;
		}
		cout << tong << endl;
		m.clear();
	}
	
	
}
