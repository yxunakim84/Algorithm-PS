#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n, m;
pair<int, int> map[505][505];
int visited[505][505];
/**
 * 0: 방문했는데 탈출 x
 * 1: 방문했는데 탈출 o
 * -1: 아직 방문 전
 */
int dp[505][505];

int dfs(int r, int c) {

  if(r >= n || r < 0 || c >= m || c < 0) return 1;

  if(visited[r][c] != -1) return visited[r][c];

  visited[r][c] = 0;
  
  int ny = r + map[r][c].first;
  int nx = c + map[r][c].second;
  return visited[r][c] = dfs(ny, nx);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      char keyword;
      cin >> keyword;
      visited[i][j] = -1;
      if(keyword == 'U') map[i][j] = {-1, 0};
      else if(keyword == 'R') map[i][j] = {0, 1};
      else if(keyword == 'D') map[i][j] = {1, 0};
      else if(keyword == 'L') map[i][j] = {0, -1};
    }
  }
  
  // memset(visited, -1, sizeof(visited));
  int ret = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      ret += dfs(i, j);
    }
  }

  cout << ret << "\n";

  return 0;
}


/*
#include <cstdio>
#include <iostream>

using namespace std;

int n, m;
pair<int, int> map[105][105];
int visited[105][105];

int ret = 0;

void dfs(int r, int c) {
  visited[r][c] = 1;
  int dy = map[r][c].first;
  int dx = map[r][c].second;
  int ny = r + dy;
  int nx = c + dx;

  if(visited[ny][nx] == 1) return; // 탈출 못함
  if(ny >= n || ny < 0 || nx >= m || nx < 0) { //경계
    ret++;
    return;
  }
  dfs(ny, nx);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      char keyword;
      cin >> keyword;
      switch (keyword)
      {
      case 'U':
        map[i][j] = {-1, 0};
        break;
      case 'R':
        map[i][j] = {0, 1};
        break;
      case 'D':
        map[i][j] = {1, 0};
        break;
      case 'L':
        map[i][j] = {0, -1};
        break;
      default:
        break;
      }
    }
  }
  
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      memset(visited, 0, sizeof(visited));
      dfs(i, j);
    }
  }

  cout << ret << "\n";

  return 0;
}
*/