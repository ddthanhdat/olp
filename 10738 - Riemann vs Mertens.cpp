#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
const long long maxn=1000000+5;
long long isPrime[maxn];
void Prime(){
	for(long long i=2;i<=maxn;i++){
		isPrime[i]=-1;
	}
	for(long long i=2;i<=maxn;i++){
		if(isPrime[i]==-1) 
			for(long long j=i;j*i<=maxn;j++){
				isPrime[j*i]=i;
			}
	}
	
}
long long factor[1000];
void recrusive_factor(long long n,long long &fn){
    if(isPrime[n]==-1){
        factor[fn]=n;
        fn++;
    }else{
        recrusive_factor(n/isPrime[n],fn);
        factor[fn]=isPrime[n];
        ++fn;
        
    }
    
}

int isfactor(long long n){
    long long fn=0;
    recrusive_factor(n,fn);
    
    for(long long i=0;i<fn-1;i++){
    	for(long long j=i+1;j<fn;j++){
    		if(factor[i]==factor[j]) return 0;
    		
		}
		
	}
	if(fn%2==0) return 1;
	return -1;
}
long long mang[maxn][2];
void m(){
	// set 1
	mang[1][0]=1;
	mang[1][1]=1;
	
	for(long long i=2;i<=maxn;i++){
		int m=isfactor(i);
		mang[i][0]=m;
		mang[i][1]=mang[i][0]+mang[i-1][1];
		
	}
}

int main(){
//	freopen("ip.txt","r",stdin);
//	freopen("rs.txt","w",stdout);
	Prime();
	m();
	long long n=1;
	while(cin>>n){
		if(n==0) break;
		printf("%8d%8d%8d\n",n,mang[n][0],mang[n][1]);
	//	cout << n <<"        " <<mang[n][0] <<"        "<< mang[n][1] << endl;
	}	
}
