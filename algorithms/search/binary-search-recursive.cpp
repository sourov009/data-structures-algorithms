#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& numbers, int item);
int binarySearch(vector<int>& numbers, int item, int low, int high);

int main() {
  vector<int> numbers = {1, 2, 4, 5, 6, 7, 8, 12, 48};
  cout << binarySearch(numbers, 12) << endl;
  cout << binarySearch(numbers, 9) << endl;
  vector<int> empty;
  cout << binarySearch(empty, 6) << endl;
  return 0;
}

int binarySearch(vector<int>& numbers, int item) {
  int low = 0;
  int high = numbers.size() - 1;
  return binarySearch(numbers, item, low, high);
}

int binarySearch(vector<int>& numbers, int item, int low, int high) {
  if (low <= high) {
    int mid = (low + high) / 2;

    if (item > numbers[mid]) {
      return binarySearch(numbers, item, mid + 1, high);
    } else if (item < numbers[mid]) {
      return binarySearch(numbers, item, mid, mid - 1);
    } else {
      return mid;
    }
  }

  return -1;
}
