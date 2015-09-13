#include <iostream>
#include <math.h>
using namespace std;


int main(){
	freopen("test.INP","r",stdin);
	freopen("test.OUT","w",stdout);
	int n;
	int d=1;
	while(cin >> n){
		int p=1;
		int kt=-1;
		int *pn=new int[n];
		for(int i=0; i<n;i++){
			cin >> pn[i];
		}
		for(int i=0; i<n;i++){
			if(pn[i]>0) {
				p*=pn[i];
				kt=1;
			}
		}
		if(kt==-1) p=0;
		cout << "Case #"<< d <<": The maximum product is "<< p <<"."<< endl;
		d++;
	}
}
