#include <iostream>
#include <string.h>
using namespace std;
int GCD(int a, int b){
	if(a%b==0) return b;
	return GCD(b,a%b);
}
int mang[1000]; int slm;
void cut(char chuoi[]){
	int sodem=0;
	slm=0;
	for(int i=0;i<strlen(chuoi);i++){
		if('0'<=chuoi[i] && chuoi[i]<='9') sodem=sodem*10+(chuoi[i]-'0');
		if(chuoi[i]==' ' || i==strlen(chuoi)-1) {
			mang[slm]=sodem;
			sodem=0;
			slm++;
		}
	}
	
	
}
int main(){
	
	int n;
	char m[1000000];
	cin >> n;
	cin.ignore();
	for(int k=0;k<n;k++){
		
		
		
		gets(m);
		cut(m);
		int maxg=0;
		for(int i=0;i<slm-1;i++){
			for(int j=i+1;j<slm;j++){
				int temp=GCD(mang[i],mang[j]);
				if(maxg<temp) maxg=temp;
			}
		}
			
		cout << maxg;
		cout << endl;
		
		
	}
	
}
