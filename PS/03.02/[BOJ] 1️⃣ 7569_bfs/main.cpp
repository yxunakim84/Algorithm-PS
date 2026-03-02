#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

int m, n, h;

int map[105][105][105];

int dy[] = {0, 0, 1, 0, -1, 0};
int dx[] = {0, 0, 0, 1, 0, -1};
int dh[] = {1, -1, 0, 0, 0, 0};

int max_day = 0;

void bfs(queue<tuple<int, int, int>> &q) {
  while(!q.empty()) {
    int ch, cy, cx;
    tie(ch, cy, cx) = q.front();
    q.pop();

    // for(int i = 0; i < 2; i++) {
    //   int nh = ch + dh[i];
    //   int next_cost = map[ch][cy][cx] + 1;
    //   if(nh >= h || nh < 0) continue;
    //   if(map[nh][cy][cx] == -1) continue;
    //   if(map[nh][cy][cx] > 0 && next_cost >= map[nh][cy][cx]) continue;

    //   map[nh][cy][cx] = next_cost;
    //   max_day = max(max_day, next_cost);
    //   q.push({nh, cy, cx});
    // }
    for(int i = 0; i < 6; i++) {
      int nh = ch + dh[i];
      int ny = cy + dy[i];
      int nx = cx + dx[i];

      int next_cost = map[ch][cy][cx] + 1;
      // 1. 범위 체크
      if(nh >= h || nh < 0 || ny >= n || ny < 0 || nx >= m || nx < 0) continue; //범위 벗어남
      
      if(map[nh][ny][nx] == -1) continue;
      if(map[nh][ny][nx] > 0 && next_cost >= map[nh][ny][nx]) continue;

      map[nh][ny][nx] = next_cost;
      max_day = max(max_day, next_cost);
      q.push({nh, ny, nx});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> m >> n >> h;
  queue<tuple<int, int, int>> tomato;
  
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < m; k++) {
        cin >> map[i][j][k];
        if(map[i][j][k] == 1) {
          tomato.push({i, j, k});
        }
      }
    }
  }
  
  bfs(tomato);
  
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < m; k++) {
        if(map[i][j][k] == 0) {
          cout << "-1" << "\n";
          return 0;
        }
      }
    }
  }
  
  cout << (max_day == 0 ? 0 : max_day - 1) << "\n";
  // 가장 처음 익어 있는 토마토가 1인 상태로 저장되어 있었으므로 1을 빼준다.
  // 단, 만약 처음부터 모든 토마토가 익어 있어 max_day가 0인 상황이면 -1이 출력되므로 이 부분 처리를 따로 해줘야됨.

  return 0;
}