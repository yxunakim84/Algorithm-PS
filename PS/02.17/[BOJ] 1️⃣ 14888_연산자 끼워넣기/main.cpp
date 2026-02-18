#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> v;
long long max_sum = -2e9;
long long min_sum = 2e9;

void operate(vector<char> &op_v) {
  long long sum = v[0];
  for(int i = 0; i < op_v.size(); i++) {
    switch (op_v[i])
    {
    case '+':
      sum = sum + v[i+1];
      break;
    case '-':
      sum = sum - v[i+1];
      break;
    case 'x':
      sum = sum * v[i+1];
      break;
    case '/':
      sum = sum / v[i+1];
      break;
    default:
      break;
    }
  }

  max_sum = max(sum, max_sum);
  min_sum = min(sum, min_sum);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  int n;
  cin >> n;
  v.resize(n);

  char op[10] = {'+', '-', 'x', '/'};
  vector<char> op_v;

  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }

  for(int i = 0; i < 4; i++) {
    int cnt;
    cin >> cnt;
    for(int j = 0; j < cnt; j++) {
      op_v.push_back(op[i]);
    }
  }

  sort(op_v.begin(), op_v.end());
  do{
    operate(op_v);
  }
  while(next_permutation(op_v.begin(), op_v.end()));
  
  cout << max_sum << "\n" << min_sum << "\n";
  return 0;
}