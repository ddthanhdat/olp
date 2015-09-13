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

vector<int> adj[3000];
int bin[3000];
int step[3000];
bool check[3000];
void bfs(int a){
	
	memset(step,0,sizeof(step));
	memset(check,0,sizeof(check));
	memset(bin,0,sizeof(bin));
	queue<int> q;
	q.push(a);
	step[a]=0;
	check[a]=1;
	int u, v;
	while(!q.empty()){
		u=q.front();
		q.pop();
		for(int i=0;i<adj[u].size();i++){
			v=adj[u][i];
			if(check[v]==0){
				
				
				step[v]=step[u]+1;
				bin[step[v]]++;
				q.push(v);
				check[v]=1;
				
			}
		}
		
	}
	int max=0;
	int savei=0;
	for(int i=0;i<3000;i++){
		if(bin[i]>max){
			max=bin[i];
			savei=i;
		}
	}
	if(max==0) cout << 0<< endl;
	else
		cout << max << " "<<savei << endl;

}

int main() {
//	freopen("ip.txt","r",stdin);
//	freopen("o.txt","w",stdout);
	int E,N,T;
	int tmp;
	cin >> E;
	for(int i=0;i<E;i++){
		cin >> N;
		for(int j=0;j<N;j++){
			cin >> tmp;
			
			adj[i].push_back(tmp);
		}
	}
	cin >> T;

	for(int i=0;i<T;i++){
		cin >> tmp;

		bfs(tmp);
		
	}
    return 0;
}
