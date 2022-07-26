using namespace std;

// getLightPeakLength(...)에서 index를 참조자 또는 포인터로 넘기면 아주 좀 더 효율적으로
// 작성할 수 있으나 (getRightPeakLength에서 반복문을 탈출하는 때의 index값을 이후 peak을
// 탐색하기 시작하는 인덱스로 하면 조금 더 효율적). getLeftPeakLength(...)와 함수 이름이 비슷한
// 역할이 추가되는 것이라 부자연스러워 고치진 않았다. 함수를 따로 만들지 않고 구현하면 위와 같은 처리에
// 대해 고민하지 않아도 됐을텐데... 시간이 될 때 다시 한번 풀어볼 것

static int getLeftPeakLength(vector<int>& array, int index) {
  int length = 0;
  while ((index > 0) && (array[index - 1] < array[index])) {
    length++;
    index--;
  }
  return length;
}

static int getRightPeakLength(vector<int>& array, int index) {
  int length = 0;
  while ((index < array.size() - 1) && (array[index] > array[index + 1])) {
    length++;
    index++;
  }
  return length;
}

int longestPeak(vector<int> array) {
  if (array.size() < 3) {
    return 0;
  }

  int potentialPeakLength = 0;
  int longtestPeakLength = 0;
  for (int i = 1; i < array.size() - 1; i++) {
    if (array[i - 1] < array[i] && array[i] > array[i + 1]) {
      potentialPeakLength = getLeftPeakLength(array, i) + \
                            getRightPeakLength(array, i) + 1;
      if (longtestPeakLength < potentialPeakLength) {
        longtestPeakLength = potentialPeakLength;
      }
    }
  }
  return longtestPeakLength;
}
