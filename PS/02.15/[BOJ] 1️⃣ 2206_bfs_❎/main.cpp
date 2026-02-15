#include <cstdio>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int map[1005][1005];
int visited[1005][1005][2];
int n, m;


int dr[] = {1, 0, -1, 0};
int dc[] = {0, -1, 0, 1};

void bfs(int r, int c) {
  
  queue<tuple<int, int, int>> q;
  q.push({r, c, 0});
  visited[r][c][0] = 1;

  while(!q.empty()) {
    int curr_r, curr_c, broken;
    tie(curr_r, curr_c, broken) = q.front();
    q.pop();

    for(int i = 0; i < 4; i++) {
      int next_r = curr_r + dr[i];
      int next_c = curr_c + dc[i];

      // if(map[next_c][next_r] == 1) continue; // 벽을 깰 수도 있으니 이걸 기준으로 거르면 안됨
      if(visited[next_r][next_c][broken] >= 1) continue;
      if(next_r < 0 || next_c < 0 || next_r >= n || next_c >= m) continue;

      // 1. 벽이 아닌 경우 (이미 이전에 벽을 깬 상태일 수도 있음, 그렇든 그렇지 않든 일단 다음이 이동 가능하므로)
      if(map[next_r][next_c] == 0) {
        visited[next_r][next_c][broken] = visited[curr_r][curr_c][broken] + 1;
        q.push({next_r, next_c, broken});
      }
      // 2. 벽인 경우 
      else if(map[next_r][next_c] == 1 && broken == 0) { // 이전에 벽을 깬 적이 없어야됨
        visited[next_r][next_c][1] = visited[curr_r][curr_c][broken] + 1;
        q.push({next_r, next_c, 1}); // 벽을 한 번 깼으므로, 앞으로 broken은 1
      }
    }
  }
}

int main() {

  cin >> n >> m;
  // n: 행 m: 열

  
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < m; j++) {
      map[i][j] = s[j] - '0';
      // i: 행 j: 열
    }
  }
  
  bfs(0, 0);
  //n-1, m-1까지

  int not_broken = visited[n-1][m-1][0];
  int broken = visited[n-1][m-1][1];

  if(not_broken > 0 && broken > 0) cout << min(not_broken, broken);
  else if((not_broken + broken) == 0) cout << "-1" << "\n";
  else cout << max(not_broken, broken) << "\n";

  return 0;
}