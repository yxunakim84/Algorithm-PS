#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MIN -2e9
#define MAX 2e9
vector<long long> v;


int find(int target) {
  int l = 0;
  int r = v.size() - 1;
  
  while(l <= r) {
    // if(target > v[l]) l++;
    // else if(target < v[r]) r--;
    // else return 1;
    
    int m = (l+r) / 2;
    if(v[m] == target) return 1;
    else if(v[m] < target) l = m+1;
    else r = m-1;
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(NULL);
  cin.tie(NULL);

  int n, m;
  cin >> n;
  v.resize(n);

  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());

  cin >> m;

  for(int i = 0; i < m; i++) {
    int target;
    cin >> target;
    cout << find(target) << "\n";
  }

  return 0;
}