#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

long long a[310000],b[310000];
int main(){
    int n,m;
	while (scanf("%d %d", &n, &m) != EOF) {
		for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        sort(a,a+n);
        for(int i=0;i<m;i++){
            scanf("%lld",&b[i]);
        }
        sort(b,b+m);
        long long ans = max(a[1]*b[0],a[n-2]*b[m-1]);
        if(ans <= 0){
            long long tmp=1e9;
            int flag=-1;
            for(int i=0;i<n;i++){
                if(abs(a[i])<tmp){
                    tmp=abs(a[i]);
                    flag=i;
                }
            }
            tmp=1e9;
            for(int i=0;i<n;i++){
                if(i!=flag && abs(a[i])<tmp){
                    tmp=abs(a[i]);
                    flag=i;
                }
            }
            for(int i=0;i<m;i++){
                ans = max(ans, a[flag]*b[i]);
            }

            
        }
        printf("%d\n",ans);
	}

	return 0;
}
/*
2 2 
20 18
2 14
5 3
-1 0 1 2 3
-1 0 1
2 2
-1 -2
1 2
 */
