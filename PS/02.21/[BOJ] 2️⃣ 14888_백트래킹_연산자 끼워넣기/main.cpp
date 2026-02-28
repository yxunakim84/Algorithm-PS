#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int num_arr[15];
vector<int> op_arr;
int n;
long long max_sum = -2e9;
long long min_sum = 2e9;

int operate(int a, int b, int op_idx) {
  if(op_idx == 0) return a + b;
  else if(op_idx == 1) return a - b;
  else if(op_idx == 2) return a * b;
  else return a / b;
}

void dfs(int idx, long long sum) {
  // 기저조건
  if(idx == n) {
    max_sum = max(max_sum, sum);
    min_sum = min(min_sum, sum);
    return;
  }
  
  // 네가지 방향
  for(int i = 0; i < 4; i++) {
    if(op_arr[i] == 0) continue;
    int ret = operate(sum, num_arr[idx], i);
    op_arr[i]--;
    dfs(idx+1, ret);
    op_arr[i]++;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> num_arr[i];
  }
  op_arr.resize(4);
  for(int i = 0; i < 4; i++) {
    cin >> op_arr[i];
  }
  long long sum = num_arr[0];
  dfs(1, sum);
  
  cout << max_sum << "\n" << min_sum << "\n";
  
  return 0;
}