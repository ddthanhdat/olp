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
int row,col;
int a[maxN][maxN];
char c[maxN][maxN];
bool check(int x, int y){
	return 0<=x && x<row && 0<=y && y<col;
}
int dem;
void dfs(int x, int y) {
//	cout << c[x][y] << " ";
	c[x][y]='q';
	int xx, yy;
	for(int i=0;i<4;i++){
		xx=x+dx[i];
		yy=y+dy[i];
		if(check(xx,yy) && (c[xx][yy]=='T')){
			return ;
		}
	}
	for(int i=0;i<4;i++){
		xx=x+dx[i];
		yy=y+dy[i];
		if(check(xx,yy) && c[xx][yy]=='G'){
			dem++;
			c[xx][yy]='.';
		}
		if(check(xx,yy) && c[xx][yy]=='.'){
			dfs(xx,yy);
		}
	}
}

int main() {
//    inpfile("ip.txt"); 
    
    while(cin >> col >> row){
    	for(int i=0;i<row;i++)
    		for(int j=0;j<col;j++)
    			cin >> c[i][j];
    			
    	for(int i=0;i<row;i++)
    		for(int j=0;j<col;j++)
    			if(c[i][j]=='P'){
    				dem=0;
    				dfs(i,j);
    				break;
				}
		cout << dem << endl;
	}
	
    return 0;
}
