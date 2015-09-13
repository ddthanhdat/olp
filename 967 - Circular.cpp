#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ff first
#define ss second
#define MAX 1000000
#define REP(i,a,b) for(int i=a;i<b;i++)
bool isPrime[MAX+100];
typedef pair<int,int> ii;
typedef pair<int,ii > iii;
vector <iii> g;
int Prime [MAX+5];
void eratosthenes(){
	REP(i,2,MAX+1)
		isPrime[i]=1;
	for(long long i=2;i<MAX;i++)
		if(isPrime[i]==1)
			for(long long j=i; j*i<MAX;j++)
				isPrime[i*j]=0;
	
}
int bangchuyen[10]={0,1,10,100,1000,10000,100000};
int leftmost(int n){
	int N;
	int nn=n;
	int dem=0;
	while(nn>0){
		nn=nn/10;
		dem++;
	}
	int t;
	for(int i=0;i<dem;i++){
		t=n%10;
		n=n/10;
		n+=t*bangchuyen[dem];
	//	cout << n << endl;
		if(isPrime[n]==0) return 0;
	}
	return 1;
}
void quyhoachdong(){
	Prime[2]=1;
	int res;
	for(int i=3;i<MAX;i++){
		res = isPrime[i]==0 ? 0: leftmost(i);
	//	cout << "i= " << i << " res= " << res << endl;
		Prime[i]= Prime[i-1] + res;
	}
}
int main(){
//	freopen("i.txt","r",stdin);
	eratosthenes();
	quyhoachdong();
	int a, b;
	while(cin >> a >> b){
		if(a == -1)  break;
		int res= Prime[b]-Prime[a-1];
		if(res==0) cout << "No Circular Primes." << endl;
		else if(res==1) cout << "1 Circular Prime." << endl;
		else cout << res << " Circular Primes." << endl;
	}
	
}



