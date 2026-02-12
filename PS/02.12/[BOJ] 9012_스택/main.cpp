#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

int main() {
  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    stack<char> stk;
    string s;
    cin >> s;
    for(auto c:s) {
      if(stk.size()) {
       char stk_top = stk.top();
       if(stk_top == '(' && c == ')') {
        stk.pop();
       } else {
        stk.push(c);
       }
      } else {
        stk.push(c);
      }
    }
    if(stk.empty()) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }


  return 0;
}