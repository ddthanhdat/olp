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
int dem;
void dfs(int x, int y) {
	//
//	cout << c[x][y] << " ";
	// khoang tri
	a[x][y]=dem;
	dem++;
	
    // di chuyen
    int xx=x;
    int yy=y;
    if(c[x][y]=='N') {
    	xx+=-1;
	}
	if(c[x][y]=='S') { 
		xx+=1;
	}
	if(c[x][y]=='W') { 
		yy+=-1;
	}
	if(c[x][y]=='E') { 
		yy+=1;
	}
	// xy lu
	if(!check(xx,yy)){
    	
    	cout << a[x][y] << " step(s) to exit" << endl;
    	return;
	}
	if(a[xx][yy]!=0){
		int c=a[xx][yy]-1;
		int d=a[x][y] - c;
		cout << c<<" step(s) before a loop of "<<d<<" step(s)"<<endl;
		return;
	}
	dfs(xx,yy);
}

int main() {
//    inpfile("ip.txt"); 

	
	
    int x;
	while(cin >> n >> m >> x){
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin >> c[i][j];
		if(!n && !m && !x) break;
		memset(a,0,sizeof(a));
		dem=1;
		dfs(0,x-1);
		
		
	}
    return 0;
}
