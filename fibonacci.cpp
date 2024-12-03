#include <iostream>
#include <vector>

using namespace std;

int fib_dp(int n){
    vector<int> dp(n+1,0);
    dp[1]=1;
    for (int i=2;i<n+1;++i){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int fib_recursion(int n){
    if (n==0) return 0;
    if (n==1) return 1;
    return fib_recursion(n-1)+fib_recursion(n-2);
}

int main(){

    cout<<fib_dp(20)<<endl;
    cout<<fib_recursion(20)<<endl;
}