#include <cstdio>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  deque<pair<int, int>> dq;
  
  for(int i = 1; i <= n; i++) {
    int _move;
    cin >> _move;
    dq.push_back({i, _move}); //풍선 번호, 이동 정보
  }
  
  while (!dq.empty()) {
    int move = dq.front().second;
    cout << dq.front().first << " ";
    dq.pop_front();

    if(dq.empty()) break;

    if(move > 0) {
      for(int i = 0; i < move - 1; i++) {
        dq.push_back(dq.front());
        dq.pop_front();
      }
    } else {
      for(int i = 0; i < abs(move); i++) {
        dq.push_front(dq.back());
        dq.pop_back();
      }
    }
  }
  cout << "\n";
  
  return 0;
}