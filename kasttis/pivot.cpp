#include <iostream>
#include <cstdio>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define ll long long
int a[100006];
bool check[100006];

int n ,k; 
int MIN [100006];
int MAX [100006];

int main(){
//  freopen("i.txt","r",stdin);
    cin >> n;
    
    k=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    int maxx=a[0];
    MAX[0]=a[0];
    for(int i=1;i<n;i++){
        if(maxx<a[i]){
            maxx=a[i];
        }
        MAX[i]=maxx;
    }
    int minn=a[n-1];
    MIN[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        if(minn>a[i]){
            minn=a[i];
        }
        MIN[i]=minn;
    }
    for(int i=0 ; i<n ;i++){
        if(a[i]==MAX[i]&&a[i]==MIN[i])
                k++;
    }
    cout<<k<<endl;
    
}