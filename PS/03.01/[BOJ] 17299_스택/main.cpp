#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;
int arr[1000005];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> v(n);
  memset(arr, 0, sizeof(arr));

  for(int i = 0; i < n; i++) {
    int num;
    cin >> num;
    arr[num]++;
    v[i] = num;
  }

  stack<int> stk;
  stack<int> ret;
  for(int i = v.size()-1; i >= 0; i--) {
    if(stk.empty()) {
      stk.push(v[i]);
      ret.push(-1);
    }
    else {
      while(stk.size()) {
        int t = stk.top();
        // cout << "t: " << t <<" ";
        if(arr[v[i]] < arr[t]) {
          ret.push(t);
          stk.push(v[i]);
          break;
        } else {
          stk.pop();
        }
      }
      if(stk.empty()) {
        ret.push(-1);
        stk.push(v[i]);
      }
    }
  }

  while(ret.size()) {
    cout << ret.top() << " ";
    ret.pop();
  }
  cout << "\n";

  return 0;
}


/*
vector<int> v(n); 선언을 이렇게 했다면
- v[i] = num; 로 대입해줘야함
- push_back(num)을 하면? 이미 0으로 n만큼 초기화되어 있는데, 이 뒤에 값을 이어서 넣게 되는 것
*/