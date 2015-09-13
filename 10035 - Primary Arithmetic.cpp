#include <iostream>
using namespace std;
int main(){
	
	long long a,b;
	while(cin>>a>>b){
		
		if(a==0 && b == 0 ) break;
		int carry =0;
		int dem=0;
		do{
		
			int soduA=a%10;
			int soduB=b%10;
			if(soduA+soduB+dem>9){
				dem =1;;
				carry++;
			}
			else dem=0;
			a=a/10;
			b=b/10;
		}
		while(a!=0 || b!=0);
		if(carry==0) cout << "No carry operation.";
		else if(carry==1)cout << carry << " carry operation.";
		else cout << carry << " carry operations.";
		cout << endl;
	}
}
