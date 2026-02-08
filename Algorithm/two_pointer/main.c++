#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 개념
  투포인터(Two Pointers) 알고리즘은 배열이나 리스트와 같은 선형 자료구조에서 두 개의 포인터를
  사용하여 정렬된 배열에서 특정 조건을 만족하는 부분 배열 또는 원하는 값을 찾는 등의 문제를 풀 때 
  주로 사용하는 알고리즘입니다.

  보통 **정렬된** 배열에서 두 수의 합 찾기, 연속된 부분배열의 합 찾기에 사용됩니다.

  - 왼쪽 포인터 (Left Pointer): 배열의 시작 지점에서 시작하여 오른쪽으로 이동합니다.
  - 오른쪽 포인터 (Right Pointer): 배열의 끝 지점에서 시작하여 왼쪽으로 이동합니다.

  1) 시작지점과 끝점 이렇게 2개로 이루어진 투포인터를 활용해서 문제를 풀 수도 있고
  2) 시작점에서 같이 시작하는 투포인터를 이용해 문제를 풀 수도 있습니다.
*/


/* 문제
  서로 다른 양의 정수로 이루어진 수열에서 특정 합을 이루는 숫자 쌍을 찾고자 합니다.
  만든 수열은 n개의 양의 정수로 이루어져 있으며 이 중에서 두 숫자의 합이 주어진 숫자 X가 되는 쌍의 개수를 구해야합니다.
*/

int main() {
  int n, x;
  cin >> n;
  vector<int> v(n);

  for(int i = 0; i < n; i++) cin >> v[i];
  cin >> x;

  sort(v.begin(), v.end());

  int l = 0, r = n - 1;
  int ret = 0;

  while(l < r) {
    if(v[l]+v[r] == x) {ret++; r--;}
    else if(v[l]+v[r] < x) l++;
    else if (v[l]+v[r] > x) r--;
  }

  cout << ret << "\n";

  return 0;
}