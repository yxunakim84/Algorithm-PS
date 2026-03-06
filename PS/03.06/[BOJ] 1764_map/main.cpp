#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  map<string, int> name_not_heard;
  map<string, int> name_not_seen;
  vector<string> name_not_heard_and_seen;

  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    name_not_heard[s] = 1;
  }
  for(int i = 0; i < m; i++) {
    string s;
    cin >> s;
    name_not_seen[s] = 1;
    if(name_not_heard[s] == 1) {
      name_not_heard_and_seen.push_back(s);
    }
  }

  sort(name_not_heard_and_seen.begin(), name_not_heard_and_seen.end());

  cout << name_not_heard_and_seen.size() << "\n";
  for(string it: name_not_heard_and_seen) {
    cout << it << "\n";
  }

  return 0;
}