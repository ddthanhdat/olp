#include <iostream>
#include <math.h>
using namespace std;


int main(){
	freopen("test.INP","r",stdin);
	freopen("test.OUT","w",stdout);
	int n;
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
	//	cout << "dfasd";
		for(int i=0 ; i<n ; i++){
			cout << pn[i];
		}
		// M
		int m;
		cin >> m;
		int *pm= new int[m];
		for(int i=0; i<m;i++){
			cin >> pm[i];
			if(pm[i]<pn[0]) cout  << pn[0]+pn[1] << endl;
			else if(pm[i]>pn[n-1]+pn[n-2]) cout << pn[n-1]+pn[n-2] << endl;
			else {
			int min=pn[n-1]+pn[n-2];
			for(int j=0; j<n-1; j++)
				for(int k=j+1; k<n; k++)
						if(min>abs((pn[k]+pn[j])-pm[i])) min=abs((pn[k]+pn[j])-pm[i]);
			
			cout  << min+pm[i] << endl;
			}
		}
		
		
	}
}
