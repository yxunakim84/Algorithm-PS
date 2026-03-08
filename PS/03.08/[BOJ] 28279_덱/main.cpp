#include <cstdio>
#include <iostream>
#include <deque>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  
  int n;
  cin >> n;

  deque<int> deq;

  for(int i = 0; i < n; i++) {
    int command;
    cin >> command;
    if(command == 1) {
      int x;
      cin >> x;
      deq.push_front(x);
    } else if(command == 2) {
      int x;
      cin >> x;
      deq.push_back(x);
    } else if(command == 3) {
      if(deq.size()) {
        int f = deq.front();
        deq.pop_front();
        cout << f << "\n";
      } else {
        cout << "-1" << "\n";
      }
    } else if(command == 4) {
      if(deq.size()) {
        int b = deq.back();
        deq.pop_back();
        cout << b << "\n";
      } else {
        cout << "-1" << "\n";
      }
    } else if(command == 5) {
      cout << deq.size() << "\n";
    } else if(command == 6) {
      if(deq.size()) cout << "0" << "\n";
      else cout << "1" << "\n";
    } else if(command == 7) {
      if(deq.size()) {
        int f = deq.front();
        cout << f << "\n";
      } else {
        cout << "-1" << "\n";
      }
    } else if(command == 8) {
      if(deq.size()) {
        int b = deq.back();
        cout << b << "\n";
      } else {
        cout << "-1" << "\n";
      }
    }
  }

  return 0;
}