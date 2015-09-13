#include <iostream>

using namespace std;

int main(){
	long long a, b, c ,L;
	long long d;
	while(cin >> a >> b>> c>> d >> L){
		
		if(a==0 && b==0 && c==0 && d==0 && L==0) break;
		int dem=0;
		
		for(long long i=0; i<=L; i++){
			if((a*i*i+b*i+c)%d==0) dem++;
		}
		
		cout << dem << endl;
		
	}
	
	
	
	
}
