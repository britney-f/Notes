#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
#include<string.h>
#include<cmath>
#include<queue>
using namespace std;
#define maxn 310000

int a[maxn];
int main(){
    int n;
	while (scanf("%d", &n) != EOF) {
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            a[i]=abs(a[i]);
        }

        sort(a,a+n);
        long long ans=0;
        for(int i=0;i<n-1;i++){
            if(a[i+1]>a[i]*2)continue;

            int l=i+1,r=n-1;
            while(l!=r){
                int mid = (l+r+1)/2;
                if(a[mid]<=a[i]*2)l=mid;
                else r=mid-1;
            }
            ans+=(r-i);
        }
        printf("%lld\n",ans);
    }

	return 0;
}
/*
2
1 5
3
1 -2 2

 */

 
 