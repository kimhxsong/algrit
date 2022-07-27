#include <vector>

using namespace std;

// O(n)으로 풀긴 했지만... 중첩된 분기가 너무 많다.
vector<int> arrayOfProducts(vector<int> array) {
  if (array.size() < 2)
    return {};

  int indexOfZeroValue = -1;
  double productsOfTotalElems = 0;
  for (int i = 0; i < array.size(); i++) {
    if (array[i] == 0) {
      if (indexOfZeroValue != -1)
          return vector<int>(array.size(), 0);
      indexOfZeroValue = i;
    } else {
      if (productsOfTotalElems != 0) {
        productsOfTotalElems *= array[i];
      } else {
        productsOfTotalElems = array[i];
      }
    }
  }

  vector<int> result(array.size(), 0);
  if (indexOfZeroValue != -1) {
    result[indexOfZeroValue] = productsOfTotalElems;
  } else {
    for (int i = 0; i < array.size(); i++) {
      result[i] = productsOfTotalElems / array[i];
    }
  }
  return result;
}
