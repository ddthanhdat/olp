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

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<string> v;
#define MOD 10000007
#define maxN 2001

int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int n,m;
int a[maxN][maxN];
char c[maxN][maxN];
bool check(int x, int y){
	return 0<=x && x<n && 0<=y && y<m;
}
int dfs(int x, int y) {
    int xx,yy;
    c[x][y]='.';
	int res=1;
    for (int h = 0; h < 8; h++) {
    	xx=x+dx[h];
    	yy=y+dy[h];
    	
    	if( check(xx,yy) && c[xx][yy]=='*' ){	
				res=0;
				dfs(xx,yy);
			}
	}
    return res;
}

int main() {
//    inpfile("ip.txt"); 

	
	
    
	while(cin >> n >> m){
		if(!n && !m) break;
		for(int i=0; i<n;i++)
			for(int j=0;j<m;j++)
				cin >> c[i][j];
		int tong=0;
		for(int i=0; i<n;i++)
			for(int j=0;j<m;j++){
				if(c[i][j]=='*'){
				//	memset(a,0,sizeof(a));
					tong+=dfs(i,j);
				}
			}
		cout << tong << endl;
		
		
	}
    return 0;
}
