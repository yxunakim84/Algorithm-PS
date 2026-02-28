// #include <cstdio>
// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// int map[55][55]; //0:청소안됨, 1:벽, 2:청소완료
// //  북  동  남  서
// int dy[] = {-1, 0, 1, 0};
// int dx[] = {0, 1, 0, -1};
// int n, m;
// int cnt = 0;

// void dfs(int row, int column, queue<int> q) {

//   // 기저조건은 백스텝 했는데 벽일때

//   if(map[row][column] == 0) { // 1. 현재 칸 청소
//     cnt++;
//     map[row][column] = 2;
//   }
//   int cd = q.front();
//   q.pop();
//   q.push(cd);
  
//   bool is_all_cleaned = true;
//   for(int i = 0; i < 4; i++) {
//     int d = q.front();
    
//     if(map[row+dy[d]][column+dx[d]] == 0) { // 2. 90도 돌았는데 청소 안 한 방
//       is_all_cleaned = false;
//       q.pop();
//       q.push(d);
//       dfs(row+dy[d], column+dx[d], q);
//       return; //!!!!
//     } else { // 청소 한 방
//       q.pop();
//       q.push(d);
//     }
//   }
//   if(is_all_cleaned) {
//     for(int i = 0; i < 3; i++) {
//       q.push(q.front());
//       q.pop();
//     }

//     // 3. 한칸 후진
//     int nd;
//     if(cd > 1) {
//       nd = cd - 2;
//     } else {
//       nd = cd + 2;
//     }
    
//     int br = row + dy[nd];
//     int bc = column + dx[nd];

//    if(br >= 0 && br < n && bc >= 0 && bc < m && map[br][bc] != 1) {
//       dfs(br, bc, q); // 방향 유지하며 후진
//     } else {
//       cout << cnt << "\n";
//       exit(0);
//     }
//   }
  
  
  
// }

// int main() {
//   cin >> n >> m;
//   int r, c, d;
//   cin >> r >> c >> d;

//   for(int i = 0; i < n; i++) { // 열
//     for(int j = 0; j < m; j++) { // 행
//       cin >> map[i][j];
//     }
//   }
//   queue<int> q;
//   if(d == 0) { q.push(0); q.push(3); q.push(2); q.push(1); }
//   else if(d == 1) { q.push(1); q.push(0); q.push(3); q.push(2); }
//   else if(d == 2) { q.push(2); q.push(1); q.push(0); q.push(3); }
//   else if(d == 3) { q.push(3); q.push(2); q.push(1); q.push(0); }
//   // 0 3 2 1
//   // 3 2 1 0
//   // 2 1 0 3
//   // 1 0 3 2
//   dfs(r, c, q); // 시작지점과 방향
  

//   return 0;
// }

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[55][55]; 
// 북(0), 동(1), 남(2), 서(3)
int dy[] = {-1, 0, 1, 0}; 
int dx[] = {0, 1, 0, -1};
int n, m;
int cnt = 0;

void dfs(int row, int column, queue<int> q) {
    // 1. 현재 칸 청소
    if (map[row][column] == 0) {
        cnt++;
        map[row][column] = 2;
    }

    int cd = q.front(); // 현재 로봇이 바라보는 방향 (원본)
    
    // 주변 4칸 중 청소되지 않은 빈 칸이 있는지 확인
    bool has_uncleaned = false;
    for (int i = 0; i < 4; i++) {
        int nr = row + dy[i];
        int nc = column + dx[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
            if (map[nr][nc] == 0) has_uncleaned = true;
        }
    }

    if (has_uncleaned) {
        // 2. 청소되지 않은 빈 칸이 있는 경우
        for (int i = 0; i < 4; i++) {
            // 반시계 방향으로 90도 회전 (큐의 다음 원소가 왼쪽 방향)
            q.push(q.front());
            q.pop();
            
            int d = q.front(); 
            int nr = row + dy[d];
            int nc = column + dx[d];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && map[nr][nc] == 0) {
                dfs(nr, nc, q);
                return;
            }
        }
    } else {
        // 3. 청소되지 않은 빈 칸이 없는 경우 (후진)
        int nd = (cd + 2) % 4; // 현재 방향 기준 뒤쪽
        int br = row + dy[nd];
        int bc = column + dx[nd];

        if (br >= 0 && br < n && bc >= 0 && bc < m && map[br][bc] != 1) {
            // 바라보는 방향(원본 q)을 유지한 채 후진
            // 후진할 때 넘겨줄 큐는 현재 cd가 맨 앞인 상태여야 함
            queue<int> next_q;
            if(cd == 0) { next_q.push(0); next_q.push(3); next_q.push(2); next_q.push(1); }
            else if(cd == 1) { next_q.push(1); next_q.push(0); next_q.push(3); next_q.push(2); }
            else if(cd == 2) { next_q.push(2); next_q.push(1); next_q.push(0); next_q.push(3); }
            else if(cd == 3) { next_q.push(3); next_q.push(2); next_q.push(1); next_q.push(0); }
            
            dfs(br, bc, next_q);
        } else {
            // 후진 불가능하면 종료
            cout << cnt << "\n";
            exit(0);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (!(cin >> n >> m)) return 0;
    int r, c, d;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    queue<int> q;
    if (d == 0) { q.push(0); q.push(3); q.push(2); q.push(1); }
    else if (d == 1) { q.push(1); q.push(0); q.push(3); q.push(2); }
    else if (d == 2) { q.push(2); q.push(1); q.push(0); q.push(3); }
    else if (d == 3) { q.push(3); q.push(2); q.push(1); q.push(0); }

    dfs(r, c, q);

    return 0;
}