#include <iostream>
#include <math.h>
using namespace std;


int main(){
//	freopen("test.INP","r",stdin);
//	freopen("test.OUT","w",stdout);
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int h;
		cin >> h;
		int m=h;
		int a=0, b=0, c=0;
		int found=-1;
		
		while(m>=c*c) c++;
		c--;
	//	cout << c;
		int cc=c;
		while(1){
			// reset khi cc--
			m=h;
			m=m-cc*cc-a*a;
			
			// tim b
			while(m>=b*b) b++;
			b--;
			//
			if(a*a+b*b+cc*cc==h) {
				found=1;
				break;
			}
			//
			
			if(cc<0) {
				a++;
				cc=c;
				b=0;
			}
			else cc--;
			
			if(a>=sqrt(h)) break;
		}
		
		
		if(found==1)
		cout << a << " " << b <<" "<< cc ;
		else cout << found ;
	
		if(i!=n-1) cout << endl;
		
	}
	
}
