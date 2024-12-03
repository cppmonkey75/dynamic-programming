//https://quick-bench.com/q/ya8Qv306mJNep9bhBf0hvtxFJQw

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

static void fib_dp_fn(benchmark::State& state) {
  // Code inside this loop is measured repeatedly
  for (auto _ : state) {
    int n=fib_dp(20);
  }
}
// Register the function as a benchmark
BENCHMARK(fib_dp_fn);

static void fib_recursion_fn(benchmark::State& state) {
  // Code before the loop is not measured

  for (auto _ : state) {
    int n=fib_recursion(20);
  }
}
BENCHMARK(fib_recursion_fn);