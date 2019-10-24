    vector<vector<vector<int>>> dp(countOfApp+1,vector<vector<int>>(disk+1,vector<int>(mem+1,-1)));
    dp[0][0][0]=0;
    for(int i =1;i<=countOfApp;i++){
        for(int j=0;j<=disk;j++){
            for(int k=0;k<=mem;k++){
                dp[i][j][k]=dp[i-1][j][k];
                if(j>=disks[i-1] && k>=mems[i-1]){
                    if(dp[i-1][j-disks[i-1]][k-mems[i-1]]!=-1){
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-disks[i-1]][k-mems[i-1]]+users[i-1]);
                    }
                }
            }
        }
    }
    
    for(int i=0;i<=disk;i++){
        for(int j=0;j<=mem;j++){
            if(dp[countOfApp][i][j]!=-1){
                res=max(res,dp[countOfApp][i][j]);
            }
        }
    }