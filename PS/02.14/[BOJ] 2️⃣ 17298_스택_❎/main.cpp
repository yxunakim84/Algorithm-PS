#include <cstdio>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

/**
 * TODO: 코드 최적화 해보기
 */

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> v(n);
  stack<int> ret;
  stack<int> stk;

  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }

  for(int i = n-1; i >= 0; i--) {
    stack<int> temp;
    bool found = false;
    while(stk.size()) {
      int top = stk.top();
      if(top > v[i]) {ret.push(top); found = true; break;}
      else {
        temp.push(top);
        stk.pop();
      }
    }
    if(!found) {
      ret.push(-1);
    }
    /**
     * 다시 넣어주는 부분이 필요 없음
     */
    // while(temp.size()) {
    //   stk.push(temp.top());
    //   temp.pop();
    // }
    stk.push(v[i]);
  }

  while(ret.size()) {
    cout << ret.top() << " ";
    ret.pop();
  }

  cout << "\n";
  return 0;
}