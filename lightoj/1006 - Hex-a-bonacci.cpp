#include <iostream>
#include <cstdio>
using namespace std;

long long F[10009];
int main() {
//	freopen("i.txt","r",stdin);
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &F[0], &F[1], &F[2], &F[3], &F[4], &F[5], &n);
        for(int i=6;i<=n;i++){
        	F[i]=F[i-1]% 10000007 +  F[i-2]% 10000007 + F[i -3]% 10000007 + F[i-4]% 10000007  +F[i-5]% 10000007+ F[i-6]% 10000007;
		}
        printf("Case %d: %d\n", ++caseno, F[n] % 10000007);
    }
    return 0;
}
