#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// 그리디로 하기에는 일관성이 없음
// 선택하거나 선택하지 않거나 > dp
// 가능한 모든 경로 탐색 > dfs

int n;
vector<pair<int, int>> v;
int max_val = 0;

void dfs(int day, int sum) {
  
  if(day > n) {
    max_val = max(max_val, sum);
    return;
  }

  int duration = v[day].first;
  int value = v[day].second;

  if(day + duration <= n+1) {
    dfs(day + duration, sum + value);
  }
  if(day + 1 <= n+1) {
    dfs(day + 1, sum);
  }

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> n;
  v.resize(n+1);

  for(int i = 1; i <= n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  dfs(1, 0);

  cout << max_val << "\n";  
  return 0;
}
