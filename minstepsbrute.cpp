#include<bits/stdc++.h>
using namespace std;

int helper(int n, int *ans){
    if(n<=1){
        return 0;
    }

    if(ans[n]!= -1){
        return ans[n];
    }

    int x=helper(n-1,ans);
    int y,z;
    y=z=INT_MAX;
    if(n%2==0){
        y=helper(n/2, ans);
    }
    if(n%3==0){
        z=helper(n/3, ans);
    }

    int output = min(x,min(y,z))+1;
    ans[n]=output;
    return output;
}
//DP recursive
int minsteps2(int n){
    int *ans = new int[n+1];
    // memset(ans,-1,n+1);
    for(int i=0;i<=n;i++){
        ans[i] = -1;
    }
    return helper(n,ans);
}

//DP iterative
int minsteps3(int n){
    int *dp = new int[n+1];
    dp[0]=0;
    dp[1]=0;

    for(int i=2;i<=n;i++){
        int x=dp[i-1];
        int y,z;
        y=z=INT_MAX;

        if(i%2==0){
            y=dp[i/2];
        }

        if(i%3==0){
            z=dp[i/3];
        }
        dp[i]=min(x,min(y,z))+1;
    }
    int output = dp[n];
    delete []dp;
    return output;
}



int minsteps(int n){
    if(n<=1){
        return 0;
    }

    int x=minsteps(n-1);
    int y,z;
    y=z=INT_MAX;
    if(n%2==0){
        y=minsteps(n/2);
    }
    if(n%3==0){
        z=minsteps(n/3);
    }

    int ans = min(x,min(y,z))+1;
    return ans;
}


int main(){
    int n;
    cin>>n;

    cout<<minsteps(n)<<endl;
    cout<<minsteps2(n)<<endl;
    cout<<minsteps3(n)<<endl;
}