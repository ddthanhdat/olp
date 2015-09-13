#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
const long long maxn=32770;
bool isPrime[maxn];
void Prime(){
	for(long long i=2;i<=maxn;i++){
		isPrime[i]=true;
	}
	for(long long i=2;i<=maxn;i++){
		if(isPrime[i]) 
			for(long long j=i;j*i<=maxn;j++){
				isPrime[j*i]=false;
			}
	}
}
long long socapngto(long long n){
	long long dem=0;
	if(isPrime[n-2]==true) dem++;
	for(long long i=3;i<=n/2;i+=2){
		if(isPrime[i]==true&& isPrime[n-i]==true) {
		dem++;
		}
	}
	return dem;
}

int main(){
//	freopen("test.INP","r",stdin);
//	freopen("test.OUT","w",stdout);
	long long n;
	Prime();
	while(cin>>n){
		if(n==0) break;
		cout << socapngto(n) << endl;
		
		
	}
}
