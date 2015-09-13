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
#define ifile(f) freopen(f,"r",stdin)
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
int n;
vector<int> adj[1000]; // tap hop cac vector
int step[1000];
map<int,int> note;
int bfs(int start, int ttl){
	// reset
	memset(step,-1,sizeof(step));
	queue<int> q;
	q.push(start);
	step[start]=0;
	int cnt=n;
	while(!q.empty()){
		
		// using
		int u=q.front();
	//	cout << u <<" note[u]= "<<note[u] << endl;
		if(step[u] > ttl  ||  adj[u].empty()) return cnt;
		cnt--;
		// truy cap
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i];
			if(step[v]==-1){
				
				step[v]=step[u]+1;
				q.push(v);
			}
		}
		
		// dele
		q.pop();
	}
	return cnt;
}


int main() {
	ifile("ip.txt");
//	freopen("ip.txt","r",stdin);
//	freopen("o.txt","w",stdout);
	int m;
	int dem=0;
	while(cin >> m && m){
		note.clear();
		for(int i=0;i<1000;i++) 
			adj[i].clear();
		int u,v;
		n=0;
		for(int i=0;i<m;i++){
			cin >> u >> v;
		//	cout << u << v << endl;
			if(!note.count(u)) note[u]=++n;
			if(!note.count(v)) note[v]=++n;
		//	cout << u<< " = "<<note[u] <<" "<<v <<" = "<< note[v] << endl;
			adj[note[u]].push_back(note[v]);
			adj[note[v]].push_back(note[u]);
		}
		int start, ttl;
		while(cin >> start >> ttl && start ){
			cout<< "Case "<<++dem<< ": "<< bfs(note[start], ttl)<<" nodes not reachable from node "<<start <<" with TTL = "<<ttl <<"."<< endl;;
		}
	}
    return 0;
}
