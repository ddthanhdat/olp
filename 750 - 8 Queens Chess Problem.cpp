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
// code//
vector<int> solution;
vector< vector<int> > rs;
bool row[20];
bool cheo1[20]; // top-left -> botum- right
bool cheo2[20]; // 
void backtrack(int col){
	if(col ==9 ){
		rs.push_back(solution);
		return ;
	}
	for(int i=1;i<=8;i++){
		int c1=i-col+10;
		int c2=i+col;
		if(row[i]==0 && cheo1[c1]==0 && cheo2[c2]==0){
			solution.push_back(i);
			row[i]=cheo1[c1]=cheo2[c2]=1;
			backtrack(col+1);
			// xoa
			solution.pop_back();
			row[i]=cheo1[c1]=cheo2[c2]=0;
		}
	}
	
}
int main(){
	backtrack(1);
	cout << rs.size();
	
	
}
