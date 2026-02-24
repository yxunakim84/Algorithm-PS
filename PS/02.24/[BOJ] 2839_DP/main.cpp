#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int dp[5005];
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    dp[3] = 1;
    dp[5] = 1;
    for(int i = 6; i <= n; i++) {
        if(dp[i-5] != -1) {
            dp[i] = dp[i-5] + 1;
        } else if(dp[i-3] != -1) {
            dp[i] = dp[i-3] + 1;
        } else dp[i] = -1;        
    }

    cout << dp[n] << "\n";

}