#include <iostream>
using namespace std;
int main(){
	int n;
	int s[10];
	cin >> n;
	for(int i=0;i<n;i++){
		int m;
		cin >> m;
		for(int j=0; j<10; j++){
			s[j]=0;
		}
		for(int j=1; j<=m; j++){
			int d=j;
			do{
				s[d%10]++;
				d=d/10;
			}
			while(d>0);
		}
		for(int j=0; j<10; j++){
			cout << s[j] ;
			if(j<9) cout << " ";
		}
		cout << endl;
	}
}
