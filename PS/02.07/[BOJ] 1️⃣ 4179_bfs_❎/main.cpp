#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int R, C;
char map[1005][1005];
int f_dist[1005][1005];
int j_dist[1005][1005];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int total_time = 0;

void f_bfs(queue<pair<int, int>> qF) {
  while(!qF.empty()) {
    pair<int, int> curr = qF.front();
    qF.pop();
    
    for(int i = 0; i < 4; i++) {
      int nx = curr.first + dx[i];
      int ny = curr.second + dy[i];
      if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
      if(f_dist[nx][ny] >= 0 || map[nx][ny] == '#') continue;

      f_dist[nx][ny] = f_dist[curr.first][curr.second] + 1;
      qF.push({nx, ny});
    }
  }
}

void bfs(queue<pair<int, int>> qJ) {
  while(!qJ.empty()) {
    pair<int, int> curr = qJ.front();
    qJ.pop();
    
    for(int i = 0; i < 4; i++) {
      int nx = curr.first + dx[i];
      int ny = curr.second + dy[i];
      if(nx < 0 || ny < 0 || nx >= R || ny >= C) {
        total_time = j_dist[curr.first][curr.second] + 1;
        return;
      }
      if(j_dist[nx][ny] != -1 || (map[nx][ny] == '#')) continue;
      if(f_dist[nx][ny] != -1 && f_dist[nx][ny] <= j_dist[curr.first][curr.second] + 1) continue;

      j_dist[nx][ny] = j_dist[curr.first][curr.second] + 1;
      qJ.push({nx, ny});
    }
  }

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  
  cin >> R >> C;
  pair<int, int> startP;
  queue<pair<int, int>> qF;
  queue<pair<int, int>> qJ;

  memset(f_dist, -1, sizeof(f_dist));
  memset(j_dist, -1, sizeof(j_dist));

  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      cin >> map[i][j];
      if(map[i][j] == 'J') {
        qJ.push({i, j});
        j_dist[i][j] = 0;
      } else if(map[i][j] == 'F') {
        qF.push({i, j});
        f_dist[i][j] = 0;
      }
    }
  }
  
  f_bfs(qF);

  bfs(qJ);

  if(total_time > 0) cout << total_time << "\n";
  else cout << "IMPOSSIBLE" << "\n";
  
  return 0;
}

// void bfs(pair<int, int> start) {
//   visited[start.first][start.second] += 1; // visited가 필요한가?
//   queue<pair<int, int>> q;
//   q.push(start);

//   while(!q.empty()) {
//     pair<int, int> curr = q.front();
//     q.pop();
//     // 불
//     for(auto it: fire) {
//       for(int i = 0; i < 4; i++) {
//         int nextX = it.first + dx[i];
//         int nextY = it.second + dy[i];
//         if(map[nextX][nextY] == '#' || map[nextX][nextY] == 'J') continue;
//         if(nextX < 0 || nextY < 0 || nextX >= R || nextY >= C) continue;
//         map[nextX][nextY] = 'F';
//         fire.push_back({nextX, nextY});
//       }
//     }

//     // 지훈
//     for(int i = 0; i < 4; i++) {
//       int nextX = curr.first + dx[i];
//       int nextY = curr.second + dy[i];
//       if(nextX < 0 || nextY < 0 || nextX >= R || nextY >= C) {
//         total_time = visited[curr.first][curr.second];
//         return;
//       }
//       if(map[nextX][nextY] == '#' || map[nextX][nextY] == 'F') continue;
//       if(visited[nextX][nextY] != 0) continue;

//       visited[nextX][nextY] = visited[curr.first][curr.second] + 1;
//     } 
//   }

// }

// int main() {
//   cin >> R >> C;
//   pair<int, int> startP;

//   for(int i = 0; i < R; i++) {
//     for(int j = 0; j < C; j++) {
//       cin >> map[i][j];
//       if(map[i][j] == 'J') { //문자열, 문자 비교?
//         startP = tie(i, j);
//       } else if(map[i][j] = 'F') {
//         fire.push_back({i, j});
//       }
//     }
//   }

//   bfs(startP);

//   if(total_time) cout << total_time << "\n";
//   else cout << "IMPOSSIBLE" << "\n";

//   return 0;
// }