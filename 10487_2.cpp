#include <iostream>
#include <math.h>
using namespace std;


int main(){
//	freopen("test.INP","r",stdin);
//	freopen("test.OUT","w",stdout);
	int n;
	int d=1;
	while(cin >> n){
		// N
		if(n==0) break;
		int *pn = new int[n];
		
		for(int i=0;i<n;i++){
			cin >> pn[i];
			for(int j=i;j>0;j--){
				if(pn[j]<pn[j-1]) swap(pn[j],pn[j-1]);
			}
		}
		// M
		int m;
		cin >> m;
		int *pm= new int[m];
		cout << "Case "<< d << ":" << endl;
		d++;
		for(int i=0; i<m;i++){
			int a, b;
			cin >> pm[i];
			if(pm[i]<pn[0]) {a=pn[0];b=pn[1]; }
			else if(pm[i]>pn[n-1]+pn[n-2]) {a=pn[n-1];b=pn[n-2]; }
			else {
				
			int min=pn[n-1]+pn[n-2];
			for(int j=0; j<n-1; j++)
				for(int k=j+1; k<n; k++)
					if(min>abs((pn[k]+pn[j])-pm[i])) {
						min=abs((pn[k]+pn[j])-pm[i]);
						a=pn[k];
						b=pn[j];
					}
			
			}
			cout  << "Closest sum to "<<pm[i] << " is "<<a+b <<"."<< endl;
		}
		
		
	}
}
