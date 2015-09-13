#include<cstdio>
#include <algorithm> 
#include <iostream>
#include<math.h>
#include <string.h>
#include <vector>
#include <map>
#include <utility>
#define Max 1000000000
#define ll long long
using namespace std;
bool mang[1000][1000];
int dx[10]={-1,1,0,0};
int dy[10]={0,0,-1,1};
int n, m;
void reset(){
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			mang[i][j]=0;
		}
	}
}
vector<string> v;
bool check(int x, int y){
	return 0<=x && x<v.size() && 0<=y && y<v[x].size();
}
int dem;
void DFS(int x, int y){
	int xx,yy;
	mang[x][y]=1;
	for(int i=0;i<=3;i++){
		xx=x+dx[i];
		yy=y+dy[i];
		
		if(check(xx,yy) && v[xx][yy]=='X'){
			
			v[x][y]='#';
		}
		if(check(xx,yy) && v[xx][yy]==' ' && !mang[xx][yy]) DFS(xx,yy);
		
		
	}
}




main(){
//	freopen("ip.txt","r",stdin);
	int n; cin >> n;
	string s;
	cin.ignore();
	for(int k=0;k<n;k++){
		
		while(getline(cin,s)){
			if(s[0]=='_') break;
			v.push_back(s);
		}
		int ln=2;
		for(int i=0;i<v.size();i++){
			if(ln<v[i].size()) ln=v[i].size();
		}
		ln+=2;
		for(int i=0;i<v.size();i++){
			while(v[i].size()!=ln) v[i]+=' ';
		}
		
		for(int i=0;i<v.size();i++){
			for(int j=0;j<v[i].size();j++){
				
				if(v[i][j]=='*') {
					reset();
					v[i][j]=' ';
					DFS(i,j);
					
				}
			}
		}
		for(int i=0;i<v.size();i++){
			while(v[i][v[i].size()-1]==' '&& v[i].size()>0) v[i].erase(v[i].size()-1);
		}
		for(int i=0;i<v.size();i++){
			cout << v[i] <<endl;
		}
		cout << s << endl;
		v.clear();
	}
}
