#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  sort(arrayOne.begin(), arrayOne.end());
  sort(arrayTwo.begin(), arrayTwo.end());

  int indexOne = 0;
  int indexTwo = 0;

  vector<int> smallestPair(2);
  unsigned int smallestDifference = numeric_limits<int>::max();

  while (indexOne != arrayOne.size() &&
         indexTwo != arrayTwo.size()) {
    unsigned int currentDifference = abs(arrayOne[indexOne] - arrayTwo[indexTwo]);
    if (currentDifference < smallestDifference) {
      smallestDifference = currentDifference;
      smallestPair[0] = arrayOne[indexOne];
      smallestPair[1] = arrayTwo[indexTwo];
    }
    if (arrayOne[indexOne] == arrayTwo[indexTwo]) {
      break;
    } else if (arrayOne[indexOne] < arrayTwo[indexTwo]) {
      indexOne++;
    } else {
      indexTwo++;
    }
  }
  return smallestPair;
}
