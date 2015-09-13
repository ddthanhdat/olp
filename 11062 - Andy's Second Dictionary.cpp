#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#define ll long long
using namespace std;
map<string,bool> m;
string chuoi; bool add=0;
void xuly(string s){
	if(s[s.size()-1]=='-'){
		string t;
		for(ll i=0;i<s.size();i++){
			if('a'<=s[i] && s[i]<='z') t+=s[i];
			else
			if('A'<=s[i]&& s[i]<='Z') t+=char(s[i]-'A'+'a');
		}
			s.erase(s.size()-1);
			add=1;
			chuoi+=t;
			t.clear();
		
	}
	else{
		s+='.';
		string tmp;
		for(ll i=0;i<s.size();i++){
			if('a'<=s[i] && s[i]<='z' || s[i]=='-') tmp+=s[i];
			else
			if('A'<=s[i]&& s[i]<='Z') tmp+=char(s[i]-'A'+'a');
			else {
				if(!tmp.empty()){
				
					if(add) {
						chuoi+=tmp;
						m[chuoi]=1;
						add=0;
						chuoi.clear();
					}
					else {
						m[tmp]=1;
					}
				}
				tmp.clear();
			}
		}
	}
}

int main(){
//	freopen("ip.txt","r",stdin);
//	freopen("rs.txt","w",stdout);
	string s;
	while(cin >> s){
		xuly(s);
	}
	
	map<string,bool>::iterator it;

	
	for(it=m.begin();it!=m.end();it++){
		cout << it->first << endl;
		
	}

}
