#include <cstdio>
#include <iostream>

using namespace std;
#define MAX 15

long long dp[MAX][MAX]; //층 호수

void solve() {
  //0층 기초값 설정
  for(int i = 1; i < MAX; i++) {
    dp[0][i] = i;
  }

  for(int k = 1; k < MAX; k++) {
    for(int j = 1; j < MAX; j++) {
      dp[k][j] = dp[k][j-1] + dp[k-1][j];
    }
  }
}

int main() {

  int T, k, n;
  cin >> T;

  solve();

  for(int i = 0; i < T; i++) {
    cin >> k >> n; //k층 n호
    cout << dp[k][n] << "\n";
  }
  

  return 0;
}