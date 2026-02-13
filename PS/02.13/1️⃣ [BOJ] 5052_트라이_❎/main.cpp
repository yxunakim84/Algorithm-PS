#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 나이브한 아이디어:
 * 길이 짧은 번호부터 오름차순 정렬하여 짧은 번호가 긴 번호에 포함되는게 있는지 > 이중 for문을 써야됨..
 * 
 * -> 문자열을 오름차순 정렬하면, 비슷한 단어끼리 인접하여 정렬됨
 * 
 */
// int sort_by_len(string a, string b) {
//   if(a.size() != b.size()) {
//     return a.size() < b.size();
//   }

//   return a < b;
// }

int main() {

  int testcase;
  cin >> testcase;
  for(int i = 0; i < testcase; i++) {
    int n;
    cin >> n;
    vector<string> v(n);
    for(int j = 0; j < n; j++) {
      cin >> v[j];
    }
    sort(v.begin(), v.end());
    bool is_prefix = false;
    for(int j = 0; j < n-1; j++) {
      if(v[j+1].substr(0, v[j].size()) == v[j]) {
        is_prefix = true;
        cout << "NO" << "\n";
        break;
      }
    }
    if(!is_prefix) {
      cout << "YES" << "\n";
    }
  }
  return 0;
}