#include <iostream>
#include <string.h>
using namespace std;

int ktm(char a){
	char s[100];
	char s1[100];
	int found=0;
	strcpy(s,"AE3HIJLZMOS2TUVWXY518");
	strcpy(s1,"ae3hijlzmos2tuvwxy518");
	for(int i=0; i<strlen(s); i++){
		if(s[i]==a) found=1;
	}
	for(int i=0; i<strlen(s1); i++){
		if(s1[i]==a) found=1;
	}
	return found;
}
int chuyenma(char a)
	{
		char s[100];
		strcpy(s,"E,S,J,5,Z,L,2,3");
		char s1[100];
		strcpy(s1,"e,s,j,5,z,l,2,3");
		int i=1;
		for(int j=0; j<strlen(s); j++){
			if(s[j]==',') i++;
			if(s[j]==a) return i;
		}
		i=1;
		for(int j=0; j<strlen(s1); j++){
			if(s1[j]==',') i++;
			if(s1[j]==a) return i;
		}
		return -1;
	}
int main(){
	char s[10000];
	int p,m;
	int sl;
	while(gets(s)){
	
	p=1;
	m=1;
	sl=strlen(s);
	for(int i=0; i<=sl/2; i++){
		if(s[i]!=s[sl-i-1]) {
			p=0;
			break;
		}
		
	}
	for(int i=0; i<sl; i++){
		if(ktm(s[i])==0){
			m=0;
			break;
		} 
	}
	if(strlen(s)%2==0) sl=strlen(s)/2-1;
	else sl=strlen(s)/2;
	//cout << sl;
	if(m==1)
	for(int i=0;i<=sl; i++){
		if(s[i]!=s[strlen(s)-i-1] || chuyenma(s[i])!=-1 ){
			if((chuyenma(s[i])+chuyenma(s[strlen(s)-i-1]))!=9){
				//cout << chuyenma(s[i])+chuyenma(s[sl-i-1]) ;
				m=0;
				break;
			}
		}
	}
	cout << s;
	if(p==1){
		if(m==1) cout << " -- is a mirrored palindrome.";
		else cout << " -- is a regular palindrome.";
	}
	else {
		if(m==0) cout << " -- is not a palindrome.";
		else  cout << " -- is a mirrored string.";
	}
	cout << endl;
}
	return 0;
	
}
