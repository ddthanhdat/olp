#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#define ll long long
using namespace std;
map<string,ll> m;



int main(){
//	freopen("ip.txt","r",stdin);
//	freopen("rs.txt","w",stdout);
	ll n;
	cin >> n;
	cin.ignore();
	cin.ignore();
	for(ll i=0;i<n;i++){
		ll dem=0;
		string s;
		while(getline(cin,s)){
			if(s=="") break;
			m[s]++;
			dem++;
		}
		// cout ten + %
		map<string,ll>::iterator it;
		for(it=m.begin();it!=m.end();it++){
			cout << (*it).first << " ";
			printf("%.4f\n",(float)(*it).second*100.0000/dem);
		}
		// xuong dong
		if(i!=n-1) cout << endl;
		// reset
		m.clear();
		
	}
	
}
