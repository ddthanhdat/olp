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
int dx[10]={0,0,-1,1};
int dy[10]={-1,1,0,0};
map< pair<int,int> ,int> step;
int bfs(){
	step.clear();
	// creat two queue to using save position J and F
	queue< pair<int,int> > F;
	queue< pair<int,int> > J;
	// sreach J and F in gib
	for(int i=0; i < r ;i++)
		for(int j=0 ; j < c ; j++){
			if(mang[i][j]=='J') J.push(make_pair(i,j));
			if(mang[i][j]=='F') F.push(make_pair(i,j));
		}
		
	pair<int,int> u,v;
	int nF,nJ;
	
	while(!J.empty()){
		nJ=J.size(); // numbers a pair int queue before;
		for(int i=0;i<nJ;i++){ // front numbers-> one lan
			u=J.front();
			J.pop();
			
			
			if(mang[u.first][u.second]=='J')
				for(int j=0;j<4;j++){ // move position up, down,left, right
					v.first=u.first+dx[j];
					v.second=u.second +dy[j];
					if(check(v.first,v.second)==0) return step[u]+1; // escape the maze
					else
					if(mang[v.first][v.second]=='.'){
					//	cout << mang[v.first][v.second];
						mang[v.first][v.second]='J'; // visited pair v;
						step[v]=step[u]+1; // check in step
						J.push(v);
					}
				}
		}

		nF=F.size();
		for(int i=0;i<nF;i++){
			u=F.front();
			F.pop();
			
			//di chuyen
			if(mang[u.first][u.second]=='F')
				for(int j=0;j<4;j++){
					v.first=u.first+dx[j];
					v.second=u.second +dy[j];
					if(check(v.first,v.second) && mang[v.first][v.second]!='#' && mang[v.first][v.second]!='F'){
						mang[v.first][v.second]='F';

						F.push(v);
					}
				}
		}
		
		
		
		
	}
	return -1; // not escape the maze return -1;

}

int main() {
//	freopen("ip.txt","r",stdin);
//	freopen("o.txt","w",stdout);
	int number; cin >> number;
	for(int nb=0;nb<number;nb++){
	//	cout <<  "case " <<nb+1 << " = ";
		cin >> r >> c;
		for(int i=0;i<r;i++){
			for(int j=0; j < c; j++){
				cin >> mang[i][j];
			}
		}
		int res=bfs();
		if(res==-1){
			cout <<"IMPOSSIBLE" ;
		}else{
			cout << res ;
		}
		cout << endl;
			
			
	}
	
    return 0;
}
