#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  
  vector<int> v(28);
  
  for(auto &i:v) {
    cin >> i;
  }
  sort(v.begin(), v.end());

  int index = 0;
  for(int i = 1; i <= 30; i++) {
    if(i != v[index]) cout << i << "\n";
    else index++;
  }

  return 0;
}