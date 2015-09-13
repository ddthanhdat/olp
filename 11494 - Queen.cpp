#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <map>
#define ll long long
using namespace std;
bool row[20];
bool col[20];
bool cheo1[20]; //top- right -> bottom - left
bool cheo2[20];
int main(){
//	freopen("ip.txt","r",stdin);
	int x1,x2,y1,y2;
	while(cin >> x1>> y1>> x2>>y2){
		if(!x1 && !x2 && !y1 && !y2) break;
		//
		row[x1]=1; col[y1]=1; cheo1[x1+y1]=1 ; cheo2[x1-y1+8]=1;
		//
		if(x1==x2 && y1==y2) cout << 0 << endl;
		else if(row[x2]==1 || col[y2]==1 || cheo1[x2+y2]==1 || cheo2[x2-y2+8]==1){
			cout << 1 << endl;
		}
		else cout << 2 << endl;
		row[x1]=col[y1]=cheo1[x1+y1]=cheo2[x1-y1+8]=0;
	}
	
	
}
