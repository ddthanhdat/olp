#include <iostream>
#include <string.h>
using namespace std;
int GCD(int a, int b){
	if(a%b==0) return b;
	return GCD(b,a%b);
}

int main(){
	int n;
	while(cin >> n){
		if (n==0) break;
		int g=0;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++){
			g+=GCD(i,j);
			}
		
		
		cout << g << endl;
	}
	
}
