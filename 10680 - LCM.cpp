#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
long long GCD(long long a, long long b){
	if(a<b){
		long long t=a;
		a=b;
		b=t;
	}
	if (a%b==0) return b;
	
	return GCD(b,a%b);
}
long long LCM(long long a,long long b){
	return a*b/GCD(a,b);
}
long long mang[1000005];
void tinhtoan (){
	mang[1]=1;
	mang[2]=2;
	for(long long i=3;i<=1000000;i++){
		mang[i]=LCM(mang[i-1],i);
		
	}
	for(long long i=2;i<=1000000;i++){
		while(mang[i]%10==0){
			mang[i]=mang[i]/10;
		}
		mang[i]=mang[i]%10;
	}
}

int main(){
	tinhtoan();
	
	long long n;
	while(cin >> n){
		if (n==0) break;
		long long temp=2;
		for(long long i=3;i<=n;i++){
			temp=LCM(temp,i);
			cout << temp << " ";
		}
	}
	
	
}
