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

#define inpfile(f) freopen(f,"r",stdin)
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



vector<string> v;
#define MOD 10000007
#define maxN 2001

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int n;
int a[maxN][maxN];
char c[maxN][maxN];
bool check(int x, int y){
	return 0<=x && x<n && 0<=y && y<n;
}
int dem;
void dfs(int x, int y) {
//	cout << c[x][y] << " ";
	c[x][y]='.';
	int xx, yy;
	for(int i=0;i<4;i++){
		xx=x+dx[i];
		yy=y+dy[i];
		if(check(xx,yy) && (c[xx][yy]=='x' || c[xx][yy]=='@')){
			dfs(xx,yy);
		}
	}
}

int main() {
//    inpfile("ip.txt"); 
    int T; cin >> T;
	for(int t=1;t<=T;t++){
		cin >> n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				cin >> c[i][j];
			}
		//
		int dem=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				if(c[i][j]=='x'){
					dem++;
					dfs(i,j);
				}
			}
		cout << "Case "<<t<<": "<<dem << endl;
	}
    return 0;
}
