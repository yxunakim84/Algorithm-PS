#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int map[1005][1005];
int visited[1005][1005];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int m, n;

int max_day = 0;

void bfs(queue<pair<int, int>> &q) {
  while (!q.empty()) {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      int next_cost = visited[cy][cx] + 1;
      if(ny >= n || ny < 0 || nx >= m || nx < 0) continue; //범위 벗어남
      if(map[ny][nx] == -1) continue;
      if(visited[ny][nx] >= 0 && next_cost >= visited[ny][nx]) continue;

      visited[ny][nx] = next_cost;
      max_day = max(max_day, next_cost);
      q.push({ny, nx});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> m >> n;

  // memset(visited, -2, sizeof(visited));
  /**
   * memset은 0이나 -1로만 초기화 해야됨
   * memset은 '정수' 단위가 아니라 '바이트(Byte, 8bit)' 단위로 값을 채우기 때문
   */
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        visited[i][j] = -2;
    }
  }

  queue<pair<int, int>> tomato;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> map[i][j];
      if(map[i][j] == 1) { //토마토
        tomato.push({i, j});
        visited[i][j] = 0;
      } else if(map[i][j] == -1) { //벽
        visited[i][j] = -1;
        /**
         * visited에서 벽도 처리해줘야함. 그렇지 않으면 -2로 초기화되므로 벽인데 익지 못한 토마토로 체크될 수 있음
         */
      }
    }
  }
  
  bfs(tomato);
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(visited[i][j] == -2) {
        cout << "-1" << "\n";
        return 0;
      }
    }
  }

  cout << max_day << "\n";

  return 0;
}