#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
const int maxn =100+5;
int isPrime[maxn];
void Prime(){
	for(int i=2;i<=maxn;i++){
		isPrime[i]=-1;
	}
	for(int i=2;i<=maxn;i++){
		if(isPrime[i]==-1) 
		for(int j=i;j*i<=maxn;j++){
			isPrime[j*i]=i;
		}
	}
}
int bangma[101][101];
int factor(int i,int n){
	
	if(isPrime[n]==-1) {
		bangma[i][n]++;
	return 1;
	}
	else{
		bangma[i][isPrime[n]]++;
		factor(i,n/isPrime[n]);
	}
}

void tinhtoan(){
	Prime();
	for(int i=2;i<=100;i++){
		for(int j=2;j<=i;j++){
			bangma[i][j]=0;
		}
	}
	// tinh gia tri moi con so
	bangma[2][2]++;
	for(int i=3;i<=100;i++){
		for(int j=2;j<=i;j++){
			bangma[i][j]=bangma[i-1][j];
		}
		if(isPrime[i]==-1) bangma[i][i]++;
		else {
			factor(i,i);
		}
	}
}
int main(){
//	freopen("ip.txt","r",stdin);
//	freopen("rs.txt","w",stdout);
	tinhtoan();
	int n;
	while(cin>> n){
		if(n==0) break;
		int dem=0;
		printf("%3d! =",n);
		for(int i=2;i<=n;i++){
			if(dem==15 && isPrime[i]==-1) {
				cout << endl;
				printf("      ");
				dem=0;
			}
			if(isPrime[i]==-1){
				printf("%3d",bangma[n][i]);	
				++dem;
			}
			
		}
		
	cout << endl;
	}
	
	
}
