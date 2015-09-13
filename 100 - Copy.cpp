#include <iostream>
using namespace std;


int main(){
//	freopen("test.INP","r",stdin);
//	freopen("test.OUT","w",stdout);
	int n;
	while(cin >> n){
		// N
		int *pn = new int[n];
		
		for(int i=0;i<n;i++){
			cin >> pn[i];
		//	for(int j=i;j>0;j--){
	//			if(pn[j]<pn[j-1]) swap(pn[j],pn[j-1]);
	//		}
		}
		cout << "dfasd";
		for(int i=0 ; i<n ; i++){
			cout << pn[i];
		}
		//sap xep
//		for(int i=0; i<n-1 ; i++){
//			for(int j=i+1; j<n;j++)
//				if(a[i]>a[j]]) swap(a[i],a[j]);
//		}
		// M
		int m;
		cin >> m;
		int *pm= new int[m];
		for(int i=0; i<m;i++){
			cin >> pm[i];
		}
		
	}
}
