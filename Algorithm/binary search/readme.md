### 이분탐색 (이진탐색)

- 이분탐색은 정렬된 배열에서 탐색 범위를 절반씩 줄여나가는 방식으로 특정 값을 찾는 알고리즘
- 시간복잡도는 O(long N)
- 문제에서 주어진 **배열의 크기가 너무나도 큰 상태에서** **어떤 값을 찾아야하는 로직이 있을 때** 사용
- 반드시 **배열이 정렬**되어 있어야 함

### 동작 원리

1. 초기 설정: 배열의 가장 왼쪽 인덱스 left, 오른쪽 인덱스 right 설정
2. 중간값 계산: 현재 배열의 중간 인덱스 mid 계산 (left+right) / 2
3. 비교

- 3-1. target == mid 이면 return mid
- 3-2. target < mid 이면 right = mid - 1
- 3-3. target > mid 이면 left = mid + 1

4. 위 과정을 left <= right 일때까지 반복

### lower_bound()와 upper_bound()

- 배열에서 원하는 값을 쉽게 찾을 수 있는 함수
- lower_bound(): 어떤 값이 나오는 첫번째 지점의 위치
- upper_bound(): 어떤 값이 초과하는 지점의 위치
- **반드시 정렬된 배열에서만 써야함**

```
lower_bound(a.begin(), a.end(), 3) - a.begin()
upper_bound(a.begin(), a.end(), 3) - a.begin()
```

- 이터레이터를 반환하므로 주소값을 빼줘야함
- 이터레이터를 반환하므로 \*를 통해 값에 접근이 가능함
