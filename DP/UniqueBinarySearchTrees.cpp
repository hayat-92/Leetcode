#include <iostream>
using namespace std;

int helper(int n, int *dp){

    if(n==1 || n==0){
        return 1;
    }

    int ans=0;
    for(int i=0; i<n; i++){
        ans+=helper(i, dp)*helper(n-i-1, dp);
    }

    dp[n]=ans;
    return ans;
}

int numTrees(int n)
{
    int *dp=new int[n+1];
    for(int i=0; i<=n; i++){
        dp[i]=0;
    }
    return helper(n, dp);
    delete [] dp;
}

int main()
{
    cout<<numTrees(3)<<endl;
    return 0;
}