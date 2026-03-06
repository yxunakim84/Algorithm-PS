#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    vector<int> graph[300001];
    int n, m, k, x;
    cin >> n >> m >> k >> x;

    for(int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
    }

    // bfs
    queue<int> q;
    q.push(x);
    // int visited[300001];
    // memset(visited, -1, sizeof(visited));
    vector<int> visited(300001, -1);
    visited[x] = 0;
    vector<int> ret;

    while(!q.empty()) {
      int now = q.front();
      q.pop();

      for(int it: graph[now]) {
        if(visited[it] == -1) {
          q.push(it);
          visited[it] = visited[now] + 1;

          if(visited[it] == k) {
            ret.push_back(it);
          }
        }
      }
    }

    if(ret.size() == 0) {
      cout << -1 << "\n";
    } else {
      sort(ret.begin(), ret.end());
      for(int it: ret) {
        cout << it << "\n";
      }
    }

  return 0;
}