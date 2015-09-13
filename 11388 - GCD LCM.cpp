#include <iostream>
#include <string.h>
using namespace std;
string add(char a[], char b[]){
	string res;
	int len;
	//xac dinh do dai lon nhat/
	if(strlen(a)>strlen(b)){
		len=strlen(a);
	}
	else len=strlen(b);
	// tinh toan
	int carry=0;
	while(len-->0 || carry!=0){
		int temp=0;
		if('0'<=a[strlen(a)-1]&&a[strlen(a)-1]<='9') temp+=a[strlen(a)-1]-'0';
		if('0'<=b[strlen(b)-1]&&b[strlen(b)-1]<='9') temp+=b[strlen(b)-1]-'0';
		b[strlen(b)-1]='\0';
		a[strlen(a)-1]='\0';
		temp+=carry;
		carry=temp/10;
		temp=temp%10;
		res=char(temp+'0')+res;
	}
	return res;
}
string mul(string a, string b)
{
    string res="";
    int n=a.length();
    int m=b.length();
    int len=n+m-1;
    int carry=0;
    for(int i=len;i>=0;i--)
    {
        int tmp=0;
        for(int j=n-1;j>=0;j--)
            if(i-j<=m && i-j>=1)
            {
                int a1=a[j]-48;
                int b1=b[i-j-1]-48;
                tmp+=a1*b1;
            }
            tmp+=carry;
            carry=tmp/10;
            res=(char)(tmp%10 + 48)+res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    return res;
}
int main(){
	string a,b;
	while(cin >> a>>b){
		cout << mul(a,b);
	}

}
