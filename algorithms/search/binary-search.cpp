#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& numbers, int item) {
  int low = 0;
  int high = numbers.size() - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (item > numbers[mid]) {
      low = mid + 1;
    } else if (item < numbers[mid]) {
      high = mid - 1;
    } else {
      return mid;
    }
  }

  return -1;
}

int main() {
  vector<int> numbers = {1, 2, 4, 5, 6, 7, 8, 12, 48};
  cout << binarySearch(numbers, 12) << endl;
  cout << binarySearch(numbers, 9) << endl;
  vector<int> empty;
  cout << binarySearch(empty, 6) << endl;
  return 0;
}
