#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
const int maxn=60000;
bool isPrime[maxn];
int mang[maxn]; int fn;
void Prime(){
	for(long long i=2;i<=maxn;i++){
		isPrime[i]=true;
	}
	for(long long i=2;i<=maxn;i++){
		if(isPrime[i])
			for(long long j=i;i*j<=maxn;j++)
				isPrime[i*j]=false;
	}
	fn=0;
	for(long long i=2;i<=maxn;i++){
		if(isPrime[i]) mang[fn++]=i;
	}
}
void factor(long long n){
	
	bool dem=0;
	if(n<1) {
			cout << "-1";
			n *= -1;
			dem = 1;
		}
	
	for(long long i=2;i<=n;i++){
		if(n%i==0){
			if(dem) cout << " x ";
			cout << i ;
			n=n/i;
			dem=1;
			i--;
		}
		if(i>sqrt(n)) {
			if(dem) cout << " x ";
			cout << n;
			break;
		}
	}
}
int main(){
	Prime();
	long long n;
	while(cin >> n){
		if(!n) break;
		cout << n << " = ";
		
		factor(n);
		cout << endl;
	}
	
}
