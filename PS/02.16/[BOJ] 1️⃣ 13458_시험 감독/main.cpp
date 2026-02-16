#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  long long ret = 0;

  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int main, sub;
  cin >> main >> sub;
  // 총감독 무조건 있어야

  for(int it: v) {
    int left = it - main;
    ret += 1;
    if(left > 0) {
      int a = left / sub;
      if(left % sub > 0) ret += 1;
      ret += a;
    }
  }

  cout << ret << "\n";


  return 0;
}