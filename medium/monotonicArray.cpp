using namespace std;

bool isMonotonic(vector<int> array) {
  if (array.size() <= 2)
    return true;
  auto left = array.begin();
  auto right = array.begin()+1;
  while (*left <= *right) {
    left++;
    right++;
    if (right == array.end())
      return true;
  }
  if (*left != *array.begin())
    return false;
  while (*left >= *right) {
    left++;
    right++;
    if (right == array.end())
      return true;
  }
  return false;
}
