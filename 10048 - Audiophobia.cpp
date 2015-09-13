#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
using namespace std;
#define ff first
#define ss second

#define REP(i,a,b) for(int i=a;i<b;i++)
#define INF 2000000
typedef pair<int,int> ii;
typedef pair<int,ii > iii;
vector<iii> g;
int lab[105];
int findSet(int i) { return (lab[i] == i) ? i : (lab[i] = findSet(lab[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
vector<ii> adj[105];
bool check [105];
void kruskal(){
	for(int i=0;i<105;i++){
		lab[i]=i;
		adj[i].clear();
		check[i]=0;
	}
	
	sort(g.begin(),g.end());
	//
	ii u;
	int w;
	for(int i=0;i<g.size();i++){
		u=g[i].ss;
		
		w=g[i].ff;
		int a=u.ff;
		int b=u.ss;
		int x=findSet(a);
		int y=findSet(b);
		if(x!=y){
			lab[x] = y ;
			adj[a].push_back(make_pair(b,w));
			adj[b].push_back(make_pair(a,w));
		}
		
	}
}
int Max;
int dfs(int u, int e, int MAX){
	check[u]=1;
	for(int i=0;i<adj[u].size();i++){
		int v= adj[u][i].ff;
	//	cout << v << endl;
		int w= adj[u][i].ss;
		if(check[v]==0){
		//	cout << v << endl;
		//	cout << w << endl;
			
			if(MAX<w) MAX=w;
			check[v]=1;
			if(v==e) {
			//	cout << "max "<<MAX << endl;
				Max=MAX;
				return MAX;
				
				
			}
			dfs(v,e,MAX);
			check[v]=0;
		}
	}
	return -99999;
}
int main(){
	

	freopen("i.txt","r",stdin);
	int C, S ,Q;
	int kt=0;
	while(cin >> C >> S >> Q && C){
		if(kt>0) cout << endl;
		kt++;
		int a, b, d;
		g.clear();
		for(int i=0;i<S;i++){
			cin >> a >> b >> d;
			g.push_back(make_pair(d,make_pair(a,b)));
			
		}
		kruskal();
		cout << "Case #" << kt << endl;
		for(int i=0;i<Q;i++){
			cin >> a >> b;
			for(int i=0;i<105;i++){
				check[i]=0;
			}
			Max=-1;
			dfs(a,b,-1000);
			if(Max==-1) cout <<"no path" << endl;
			else cout << Max << endl;
		
		}
		
	}
		
	
}



