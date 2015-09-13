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
	s+='.';
	string tmp;
	for(ll i=0;i<s.size();i++){
		if('a'<=s[i] && s[i]<='z' || s[i]=='-') tmp+=s[i];
		else
		if('A'<=s[i]&& s[i]<='Z') tmp+=char(s[i]-'A'+'a');
		else {
			if(!tmp.empty()){
				
				chuoi+=tmp;
			}
			tmp.clear();
		}
	}
}

int main(){
	freopen("ip.txt","r",stdin);
	freopen("rs.txt","w",stdout);
	string s;
	while(getline(cin,s)){
		xuly(s);
	}
	
	map<string,bool>::iterator it;

	
	for(it=m.begin();it!=m.end();it++){
		cout << it->first << endl;
		
	}

}
