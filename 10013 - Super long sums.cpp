#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
	freopen("ip.txt","r",stdin);
	freopen("rs.txt","w",stdout);
	long long m;
	long long *a=new long long[1000000+1],*b=new long long[1000000+1];
	long long *mang=new long long[1000000+1];
	cin >> m;
	for(long long j=0;j<m;j++){
	
		long long n;
		cin>> n;
		
		for(long long i=0;i<n;i++){
			cin >> a[i] >> b[i];
		}
	
		long long carry=0;
		long long mn=0;
		for(long long i=n-1;i>=0;i--){
			long long tmp=carry +a[i]+b[i];
			carry=tmp/10;
			tmp=tmp%10;
			mang[mn++]=tmp;
		
		}
		if(carry>0)cout <<carry;
		for(long long i=mn-1;i>=0;i--){
			cout << mang[i];
		}
		cout << endl;
		if(j!=m-1) cout << endl;
		
	}
	delete [] a;
		delete [] b;
		delete [] mang;
}
