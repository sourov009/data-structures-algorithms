#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& numbers, int item) {
  int low = 0;
  int high = numbers.size() - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (numbers[mid] > item) {
      low = mid + 1;
    } else if (numbers[mid] < item) {
      high = mid - 1;
    } else {
      return mid;
    }
  }

  return -1;
}

int main() {
  vector<int> numbers = {1, 2, 4, 5, 6, 7, 8, 12, 48};
  cout << binarySearch(numbers, 6) << endl;
  cout << binarySearch(numbers, 9) << endl;
  vector<int> empty;
  cout << binarySearch(empty, 6) << endl;
  return 0;
}
