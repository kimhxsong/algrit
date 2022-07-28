#include <vector>
#include <unordered_set>

using namespace std;

// 메모리 공간을 상수 공간으로 쓰는 다른 풀이 방법에 대해서 고민해볼 필요.
int firstDuplicateValue(vector<int> array) {
  unordered_set<int> values;
  for (int i = 0; i < array.size(); i++) {
    if (values.insert(array[i]).second == false) {
      return array[i];
    }
  }
  
  return -1;
}
