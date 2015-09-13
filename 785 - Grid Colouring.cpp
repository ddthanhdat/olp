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
int mang[1000][1000];
int dx[10]={-1,1,0,0};
int dy[10]={0,0,-1,1};
int n, m;
vector<string> v;
void reset(){
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			mang[i][j]=0;
		}
	}
	
}

bool check(int x, int y){
	return 0<=x && x<v.size() && 0<=y && y<v[x].size();
}
int dem;
void DFS(int x, int y){
	int xx,yy;
	for(int i=0;i<=3;i++){
		xx=x+dx[i];
		yy=y+dy[i];
		if(check(xx,yy) && v[xx][yy]==' ') {
			v[xx][yy]=v[x][y];
			DFS(xx,yy);
		}
	}
//	mang[x][y]=0;
}




main(){
	freopen("ip.txt","r",stdin);
	string s;
	while(getline(cin,s)){
		if(s[0]=='_'){
			
			
			
		//	reset();
			// sau xu ly;
			for(int i=0;i<v.size();i++){
				for(int j=0; j< v[i].size(); j++){
					
					if(v[i][j]!='X' && v[i][j]!=' ') {
					//	cout << v[i][j] << endl;
						
						DFS(i,j);
						
						
					}
				}
				
			}
			//
			for(int i=0;i<v.size();i++){
					cout << v[i] << endl;
				
			}
			//
			cout << s << endl;
			v.clear();
		} else v.push_back(s);
	}
}
