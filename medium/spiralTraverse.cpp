using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array) {
  if (array.empty())
    return {};

  vector<int> result = {};
  int rowStartIndex = 0;
  int rowEndIndex = array.size() - 1;
  int colStartIndex = 0;
  int colEndIndex = array[0].size() - 1;
  
  while (rowStartIndex <= rowEndIndex &&
         colStartIndex <= colEndIndex) {
    int col = colStartIndex;
    while (col <= colEndIndex) {
      result.push_back(array[rowStartIndex][col]);
      col++;
    }
    int row = rowStartIndex + 1;
    while (row <= rowEndIndex) {
      result.push_back(array[row][colEndIndex]);
      row++;
    }
    col = colEndIndex - 1;
    while (col >= colStartIndex) {
      if (rowStartIndex == rowEndIndex)
        break;
      result.push_back(array[rowEndIndex][col]);
      col--;
    }
    row = rowEndIndex - 1;
    while (row > rowStartIndex) {
      if (colStartIndex == colEndIndex)
        break;
      result.push_back(array[row][colStartIndex]);
      row--;
    }
    rowStartIndex++;
    rowEndIndex--;
    colStartIndex++;
    colEndIndex--;
  }
  return result;
}
