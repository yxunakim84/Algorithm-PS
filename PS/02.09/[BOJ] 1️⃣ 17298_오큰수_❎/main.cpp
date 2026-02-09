/**
 * 답 못 구했음
 * 다시 풀기!!
 */

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  /**
   * A=[3,5,2,7]
   * i: 1 2 3 4
   * Ai보다 오른쪽에 있으면서, Ai보다 큰 수들 중 가장 왼쪽에 위치한 수
   * 
   * 1. Ai의 오른쪽에 값이 존재하는지 > An만 없음 > N번째는 항상 -1
   * 2. 있다면, Ai보다 큰 값이 존재하는지
   * 3. 있다면, 가장 우선으로 나오는 값을 출력
   */

  int n;
  cin >> n;
  vector<int> v(n);
  stack<int> stk;


  for(int i = 0; i < n; i++) {
    int val;
    cin >> val; stk.push(val);
  }

  int max_val;
  vector<int> ret;
  for(int i = 0; i < n; i++) {
    if(i == 0) {
      // 맨 끝
      max_val = stk.top();
      stk.pop();
      ret.push_back(-1);

    }
    else {
      int val = stk.top();
      if(max(max_val, val) == val) {
        ret.push_back(-1);
      } else {
        
      }
      stk.pop();
    }
  }

  reverse(ret.begin(), ret.end());

  for(int v:ret) {
    cout << v << " ";
  }
  
  return 0;
}