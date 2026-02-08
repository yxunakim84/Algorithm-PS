#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 투포인터 사용
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  int N, M;
  cin >> N >> M;

  vector<int> v1(N), v2(M);
  for(int i = 0; i < N; i++) cin >> v1[i];
  for(int j = 0; j < M; j++) cin >> v2[j];

  int p1 = 0, p2 = 0;

  // 두 포인터가 모두 범위 내에 있을 때
  while(p1 < v1.size() && p2 < v2.size()) {
    if(v1[p1] <= v2[p2]) cout << v1[p1++] << " ";
    else if(v1[p1] > v2[p2]) cout << v2[p2++] << " ";
  }
  
  while(p1 < v1.size()) cout << v1[p1++] << " ";
  while(p2 < v2.size()) cout << v2[p2++] << " ";

  cout << "\n";
  
  return 0;
}

/**
 * 1. 결과값으르 굳이 따로 저장하고 다시 출력하지 말고, 결정 났을 때 바로 출력
 * 2. || 조건으로 해서 처리 복잡하게 하지 말고, && 조건으로 하고 남은 조건들 처리하는 것이 더 간단
 * 3. 같은 경우를 굳이 따로 빼지 않아도 됨.. > 잘 생각해보기
 */
/*
vector<int> ret;

while(p1 < v1.size() || p2 < v2.size()) {

  if(p1 >= v1.size() && p2 >= v2.size()) {
    break;
  }

  if(p1 >= v1.size()) {
    // p2만 넣어줌
    for(int i = p2; i < v2.size(); i++) {
      ret.push_back(v2[i]);
    }
    break;
  }
  if(p2 >= v2.size()) {
    // p1만 넣어줌
    for(int i = p1; i < v1.size(); i++) {
      ret.push_back(v1[i]);
    }
    break;
  }


  if(v1[p1] == v2[p2]) {
    ret.push_back(v1[p1++]); ret.push_back(v2[p2++]);
  }
  else if(v1[p1] < v2[p2]) {
    ret.push_back(v1[p1++]);
  }
  else if(v1[p1] > v2[p2]) {
    ret.push_back(v2[p2++]);
  }
}

for(auto it: ret) cout << it << " ";
*/


// Merge를 사용하는 방법
/*
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin>>N>>M;

    vector<int> v1(N),v2(M);
    for(auto &i : v1) cin>>i;
    for(auto &i : v2) cin>>i;

    vector<int> v3(N+M);
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    
    for(auto i: v3) cout<<i<<' ';
}
 */