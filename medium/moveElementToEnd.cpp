#include <vector>

using namespace std;

// 변수를 하나 줄여서 풀어볼 것
vector<int> moveElementToEnd(vector<int> array, int toMove) {
  vector<int>::iterator cursor1 = array.begin();
  vector<int>::iterator cursor2 = array.begin();
  vector<int>::iterator last = array.end();
  while (1) {
    while (cursor1 != array.end() && *cursor1 != toMove)
      cursor1++;
    cursor2 = cursor1;
    while (cursor2 != array.end() && *cursor2 == toMove)
      cursor2++;
    if (cursor2 == last)
      break;
    swap(*cursor1, *cursor2);
    cursor1++;
  }
  return array;
}
