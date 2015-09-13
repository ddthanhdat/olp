#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cstring>
#include <set>
using namespace std;
#define ff first
#define ss second

#define REP(i,a,b) for(int i=a;i<b;i++)
#define INF -2000000
typedef pair<int,int> ii;
typedef pair<int,ii > iii;
long long h[10000000+5];

int l[230];
int r[230];
int F0[230][230];
int F1[230][230];
int F2[230][230];

int main(){
	freopen("i.txt","r",stdin);
	int n, k;
	cin >> n >> k;
	int sum=0;
	for(int i=1; i<=n;i++){
		cin >> l[i] >> r[i];
		sum+=l[i];
		sum+=r[i];
		
	}
	
	for(int i =0 ; i < 230; i++){
		F0[0][i]=INF;
		F1[0][i]=INF;
		F2[0][i]=INF;
		
	}
	F0[0][0]=sum;
	for(int i=1 ; i<=n; i++){
		F0[i][0] = F0[i-1][0]; F1[i][0] = F2[i][0] = INF;
		for(int j=1;j<=k;j++){
			
			F0[i][j]=max(max(F0[i-1][j],F1[i-1][j]),F2[i-1][j]);
			
			F1[i][j]=max(F0[i-1][j-1],F1[i-1][j-1]) - l[i];
		
			F2[i][j]=max(F0[i-1][j-1],F2[i-1][j-1]) - r[i];
			printf("(%d, %d, %d)    ",F0[i][j], F1[i][j], F2[i][j]); 
			
		}
		cout << endl;
		cout << endl;

	}
	
	cout << max(max(F0[n][k],F1[n][k]),F2[n][k]) << endl;
}



