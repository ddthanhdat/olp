#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;


int main(){
//	freopen("ip.txt","r",stdin);
//	freopen("rs.txt","w",stdout);
	int i=0;
	char chuoi[200][200];
	while(gets(chuoi[i])){
		if(chuoi[i][0]=='0') break;
		i++;
	}
	int maxlen=0;
	for(int j=0;j<i;j++){
		if(maxlen<strlen(chuoi[j])-1) maxlen =strlen(chuoi[j])-1;
	}
	int temp=0;
	int mang[200]; int csmang=0;
	for(int m=maxlen+4;m>=0;m--){
		for(int n=0;n<i;n++){
			int len=strlen(chuoi[n])-1;
			if('0'<=chuoi[n][len] && chuoi[n][len]<='9') temp+=chuoi[n][len]-'0';
			chuoi[n][len]='\0';
		}
		mang[csmang++]=temp%10;
		temp=temp/10;		
	}
	while(mang[csmang-1]==0) csmang--;
	if(csmang<0) cout << 0;
	for(int m=csmang-1;m>=0;m--){
		cout << mang[m];
	}
	cout << endl;
}
