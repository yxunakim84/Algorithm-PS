#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& arr, int target) {
  int left = 0;
  int right = arr.size() - 1;

  while(left <= right) {
    int mid = (left + right) / 2;
    if(arr[mid] == target) return mid;
    else if(target < arr[mid]) right = mid - 1;
    else if(target > arr[mid]) left = mid + 1;
  }

  return -1; // target 값을 찾지 못했을 때
}


int main() {

  vector<int> a {1, 2, 3, 3, 3, 4};

  /**
   * 1. 원하는 요소 자리 찾기
   */
  // iterator를 반환하므로, 배열 시작지점 주소를 빼줘야함
  cout << lower_bound(a.begin(), a.end(), 3) - a.begin() << "\n";
  // 2
  cout << upper_bound(a.begin(), a.end(), 3) - a.begin() << "\n";
  // 5

  /**
   * 2. 원하는 요소 출력하기
   */
  cout << *lower_bound(a.begin(), a.end(), 3) << "\n";
  // 3

  /**
   * 3. 원하는 숫자가 몇 개 들어있는지
   */
  cout << upper_bound(a.begin(), a.end(), 3) - lower_bound(a.begin(), a.end(), 3) << "\n";
  // 3


  return 0;
}

