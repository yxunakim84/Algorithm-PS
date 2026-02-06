/**
 * dfs 진입처리 시점
 */

#include <iostream>
#include <vector>
#include <cstring> 

using namespace std;

vector<int> map[2005];
int visited[2005] = {false};
bool isExist = 0;

void dfs(int startP, vector<int> ret) {

  if(ret.size() == 5) {
    isExist = 1;
    return;
  }

  for(auto it: map[startP]) {
    if(visited[it]) continue;

    ret.push_back(it);
    visited[it] = true;

    dfs(it, ret);
    
    ret.pop_back();
    visited[it] = false;
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    map[a].push_back(b);
    map[b].push_back(a);
  }

  vector<int> ret;

  // map[1] -> 2, 4
  for(int i = 0; i < N; i++) {
    memset(visited, false, sizeof(visited));
    ret.clear();

    ret.push_back(i);
    visited[i] = true;
    dfs(i, ret);

    if(isExist) break;
  }

  cout << isExist << "\n";
  
  return 0;
}