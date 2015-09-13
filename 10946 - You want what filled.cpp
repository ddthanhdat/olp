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
char mang[100][100];
int dx[10]={-1,1,0,0};
int dy[10]={0,0,-1,1};
int n, m;

bool check(int x, int y){
	return 0<=x && x<n&& 0<=y && y<m;
}
int dem;
void DFS(int x, int y,char c){
	
	mang[x][y]='.';
	dem++;
	int xx,yy;
	for(int i=0;i<=3;i++){
		xx=x+dx[i];
		yy=y+dy[i];
		if(check(xx,yy)&&mang[xx][yy]==c){
			DFS(xx,yy,c);
		}
	}
}
bool cmp(pair<char,int> a, pair<char,int> b){
	if(a.second==b.second) return a.first<b.first;
	else return a.second > b.second;
}

vector< pair<char,int> > v;
main(){
//	freopen("ip.txt","r",stdin);
	int k=1;
	while(cin >> n>>m){
		if(!n && !m) break;
		//ip
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> mang[i][j];
			}
		}
		//chay DFS
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(mang[i][j]!='.'){
					dem=0;
					char t=mang[i][j];
					DFS(i,j,mang[i][j]);
					v.push_back(make_pair(t,dem));
				}
			}
		}
		// sap xep
		sort(v.begin(),v.end(),cmp);
		
		cout << "Problem "<< k++ << ":" << endl;
		for(int i=0;i<v.size();i++){
			cout << v[i].first << " "<< v[i].second << endl;
		}
		v.clear();
	}
}
