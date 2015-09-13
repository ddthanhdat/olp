#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
const long long maxn=11000+5;
bool isPrime[maxn]; int slPrime=0;
int mangPrime[maxn];
void Prime(){
	for(long long i=2; i<=maxn; i++)
		isPrime[i]=true;
	for(long long i=2; i<=maxn; i++){
		if(isPrime[i])
			for(long long j=i;j*i<=maxn;j++)
				isPrime[j*i]=false;
	}
	// tao mang chu so nguyen to
	for(long long i=2; i<=maxn; i++){
		if(isPrime[i]){
			mangPrime[slPrime]=i;
			slPrime++;
		}
	}
}
// xet co phai so nguyento?
int song(long long n){
	int dem=0;
	while(mangPrime[dem]<= sqrt(n)){
		if(n%mangPrime[dem]==0) return 0;
		dem++;
	}
	return 1;
}
// tinh toan
int a[10001];
void tinhtoan(){
	a[0]=song(41);
	for(int i=1;i<=10000;i++){
		a[i]=a[i-1]+song(i*i+i+41);
	}
}

int main(){
//	freopen("ip.txt","r",stdin);
//	freopen("rs.txt","w",stdout);
	Prime();
	tinhtoan();
	int n, m;
	while(scanf("%d %d",&n,&m)!=EOF){
		if(n>m){
			int t=n;
			n=m;
			m=t;
		}
		double ans=double(a[m]-a[n-1])/double(m-n+1);
        printf("%.2lf\n",ans*100.00+1e-6);
	
	}
}
