#include <iostream>
using namespace std;

void per(int a){
	long s=0;
	for(int i=1; i<a; i++){
		if(a%i==0) s+=i;
	}
	if(a<10) cout << "    " << a;
	if (a<100 && a > 9) cout << "   " << a;
	if(a<1000 && a >99) cout << "  " << a;
	if(a<10000 && a > 999) cout << " " << a;
	if(a>=10000) cout << a;
	if(s==a) cout << "  PERFECT";
	if(s<a) cout << "  DEFICIENT";
	if(s>a) cout << "  ABUNDANT";
	
}

int main(){
	
	int a[100];
	int n=0;
	while(1){
		cin >> a[n];
		if(a[n]==0) break;
		n++;
	}
	cout << "PERFECTION OUTPUT\n";
	for(int i=0; i<n; i++){
		
		per(a[i]);
		cout << endl;
	}
	cout << "END OF OUTPUT\n";
}
