#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cctype>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <set>

using namespace std;

#define outfile(f) freopen(f,"w",stdout)
#define REP(i,n) for(int i=0;i<n;++i)
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define fill(a,val) memset(a,val,sizeof(a))
#define ll long long
#define ull unsigned long long
#define INF 500000000
#define bit(i) ((i)&(-i))
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define nL(note) note+note
#define nR(note) note+note+1
#define Max 100000
int r,c;


char mang[1000+4][1000+4];
vector <int> rs;
bool check(int x, int y){
	return 0<=x && x<r && 0<=y && y<c;
}
int dx[10]={0,0,-1,1,-1,1,-1, 1};
int dy[10]={-1,1,0,0,-1,1, 1,-1};
int dxZ[10]={-2,-2,-1,-1, 1,1,2,2};
int dyZ[10]={-1, 1,-2, 2,-2,2,-1,1};
map< pair<int,int> ,int> step;
int bfs(){
	queue< pair<int,int> > Z;
	queue< pair<int,int> > A;
	step.clear();
	pair<int,int> B;
	for(int i=0; i < r ;i++)
		for(int j=0 ; j < c ; j++){
			if(mang[i][j]=='Z') Z.push(make_pair(i,j));
			if(mang[i][j]=='A') A.push(make_pair(i,j));
			if(mang[i][j]=='B'){
				B.first=i;
				B.second=j;
			}
		}
		
	pair<int,int> u,v;
	// horse
	while(!Z.empty()){
		u=Z.front();
		Z.pop();
		for(int j=0;j<8;j++){
			v.first=u.first+dxZ[j];
			v.second=u.second +dyZ[j];
			if(check(v.first,v.second) && mang[v.first][v.second]=='.') {
				mang[v.first][v.second]='Z';
			}
		}
			
	}
	
	// king A moving
	while(!A.empty()){
		u=A.front();
		A.pop();
		for(int j=0;j<8;j++){
			v.first=u.first+dx[j];
			v.second=u.second +dy[j];
			if(check(v.first,v.second) && mang[v.first][v.second]!='Z'&& mang[v.first][v.second]!='A') {
				
				step[v]=step[u]+1;
				if(v==B) return step[v];
				mang[v.first][v.second]='A';
				A.push(v);
			}
		}
			
	}
		
	
	return -1;

}

int main() {
//	freopen("ip.txt","r",stdin);
//	freopen("o.txt","w",stdout);
	int n; cin >> n;
	for(int l=0;l<n;l++){
		cin >> r >> c;
		int x,y,u,v;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				 cin >> mang[i][j];
		}
		int res=bfs();
		if(res==-1){
			cout << "King Peter, you can't go now!" << endl;
		}else{
			cout << "Minimal possible length of a trip is " << res << endl;
		}
		
	}
	
    return 0;
}
