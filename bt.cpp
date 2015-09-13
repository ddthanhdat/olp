#include <iostream>

using namespace std;
int main(){
//	freopen("test.INP","r",stdin);
//	freopen("test.OUT","w",stdout);
	int muon;
	int n;
	while(cin>>n){
		
		int s=n;
		while(1){
			if(n%3!=0){
				muon=3-n%3;
				n=n+muon;
			}
			else muon=0;
			
			if(n/3>=muon){
				s+=n/3;
				n=n/3-muon;
				
			}
			else {
			break;
			}
			if(n<=0) break;
			
		}
		cout << s << endl;
		
		
		
	}
}
