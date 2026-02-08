#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  string s, target;
  cin >> s >> target;

  stack<char> stk;

  for(char it: s) {
    stk.push(it);
    
    if(stk.size() >= target.size() && it == target[target.size()-1]) {
      string temp = "";
      for(int i = target.size()-1; i>=0; i--) {
        if(stk.top() == target[i]) temp+=stk.top(), stk.pop();
        else break;
      }
      reverse(temp.begin(), temp.end());
      if(temp != target) {
        for(char a:temp) {
          stk.push(a);
        }
      }
    }
  }

  string ret;
  if(stk.empty()) cout << "FRULA\n";
  else {
    /*
    // stk가 점점 줄어드는데, 이 사이즈를 기준으로 for문 범위를 설정하게 되면 원하는 값이 안 나옴
    for(int i = 0; i < stk.size(); i++) {
      ret += stk.top();
      stk.pop();
    }
    */
    while(stk.size()) {
      ret += stk.top(); stk.pop();
    }
    reverse(ret.begin(), ret.end());
    cout << ret << "\n";
    }

  return 0;
}