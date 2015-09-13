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
#define maxN 1001

int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int T;
int n, m;
int x, y, res;
char s[maxN];
int a[maxN][maxN];
bool check(int x, int y){
	return 0<=x && x<v.size() && 0<=y && y<v[x].size();
}
int dfs(int x, int y) {
    int res = 0;
    int xx,yy;
    a[x][y]+=1;
    res+=1;
    for (int h = 0; h < 8; h++) {
    	xx=x+dx[h];
    	yy=y+dy[h];
    	
    	if( check(xx,yy)&&v[xx][yy]=='W'   && !a[xx][yy]){	
				res += dfs(xx, yy);
			}
	}
    return res;
}

int main() {
 //   inpfile("ip.txt"); 

	
	
    scanf("%d\n\n", &T);
	char s[1000];
    for(int k=0;k<T;k++){
		while(gets(s) && strlen(s) ){
			if(s[0]=='L'||s[0]=='W'){
				string s1=s;
				
				v.push_back(s1);
			//	for(int i=0;i<s.size();i++) if()a[v.size()-1][i]=1;
			}
			else{
				int i,j;
				
				sscanf(s,"%d %d",&i,&j);
				memset(a,0,sizeof(a));
				i--;
				j--;
				
				res= (v[i][j]=='L') ? 0 : dfs(i,j);
				
				cout << res << endl;
			}
			
		}
		if(k!=T-1)cout << endl;
		v.clear();
	}
    return 0;
}
