#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
const long long maxn=1000000+5;
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

int main(){
	freopen("bt.txt","r",stdin);
	freopen("rs.txt","w",stdout);
	long long n;
	Prime();
	while(cin>>n){
		if(n==0) break;
		long long a=0, b=0;
		for(long long i=2;i<=n;i++){
			if(isPrime[i]==true && isPrime[n-i]==true){
				a=i;
				b=n-i;
				break;
			
			}
		}
		if(a+b!=n) cout << n<<":\nNO WAY!" << endl;
		else {
		
			cout << n <<":\n"<<a<<"+" << b <<endl;
		}
	}
}
