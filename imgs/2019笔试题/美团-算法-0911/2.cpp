
#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
#include<string.h>
using namespace std;
#define inf 1e7
int a[105],b[105];
int dp[10005][105];

/*
4
3 3 4 3
4 7 6 5
*/


int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int sum = 0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        for(int i=0;i<n;i++)scanf("%d",&b[i]);

        for(int i=0;i<=10000;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=-1;
            }
            
        }
        dp[0][0] = 0;
        int min_k = 1000;
        for(int i=0;i<n;i++){

            for(int j=sum+105;j>=b[i];j--){
                for(int k=n;k>0;k--)
                if(dp[j-b[i]][k-1]!=-1){
                    dp[j][k] = max(dp[j][k], dp[j-b[i]][k-1]+a[i]);
                    if (j>=sum)
                        min_k = min(min_k, k);
                }
            }
        }

        int min_c = 0;
        for(int j=sum;j<=sum+105;j++){
            if(dp[j][min_k]!=-1){
                min_c = max(min_c, dp[j][min_k]);
            }
        }
        printf("%d %d\n", min_k, sum-min_c);
    }

    return 0;
} 
