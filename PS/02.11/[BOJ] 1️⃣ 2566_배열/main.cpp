#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[9][9];
int max_val = -1;
pair<int, int> pos = {-1, -1};

int main() {
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      cin >> arr[i][j];
      int temp_max_val = max(max_val, arr[i][j]);
      if(temp_max_val != max_val) {
        max_val = max(max_val, arr[i][j]);
        pos = {i, j};
      }
    }
  }

  cout << max_val << "\n";
  cout << pos.first + 1 << " " << pos.second + 1 << "\n";

  return 0;
}