#include <iostream>
#include <cstring>

using namespace std;


int main() {
  // 그룹단어가 아닌 경우: 이전에 이미 나왔는데, 동떨어진곳에 다시 등장
  // a, b, c... 배열을 두고,
  // 0이면 해당 문자가 끝날때까지 진행 후 마지막에 1로 체크
  // 1이면 이미 이전에 등장한 적이 있던 것

  ios::sync_with_stdio(0);
  cin.tie(NULL);

  int n;
  cin >> n;

  int arr[26];
  int ret = 0;

  for(int i = 0; i < n; i++) {
    memset(arr, 0, sizeof(arr));
    string s;
    cin >> s;
    char curr = s[0];
    bool isGrouped = true;
    
    for(char c : s) {
      if (isGrouped){
        if(arr[c - 'a'] == 0) {
          if(curr == c) continue;
          else {
            arr[curr - 'a'] = 1;
            curr = c;
          }
        } else {
          isGrouped = false;
          ret++;
          break;
        }
      }
    }
  }

  cout << n - ret << "\n";

  return 0;
}