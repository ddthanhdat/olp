#include <iostream>
using namespace std;

long long dem(long long a){
	long long d=0;
	while(1){

		d++;
		if(a==1) break;
		if(a%2!=0) a=3*a+1;
		else a=a/2;
	}
	return d;
}


int main(){
//	freopen("test.INP","r",stdin);
//	freopen("test.OUT","w",stdout);
	long long max, i,j;
	long long d, a, b;
	
	while(cin>>i>>j){
		a=i;
		b=j;
		max=0;
		if(a>b){
			long long t=a;
			a=b;
			b=t;
		}
		for(long long k=a; k<=b; k++){
			d=dem(k);
			if(max<d) max=d;
		}
		cout <<i<<" " <<j<< " "<<max << endl;
	}
}
