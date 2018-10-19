#include <iostream>
#include <vector>

using namespace std;

int linearSearch(vector<int>& numbers, int item) {
  for (int i = 0; i < numbers.size(); ++i) {
    if (numbers[i] == item) {
      return i;
    }
  }

  return -1;
}

int main() {
  vector<int> numbers = {1, 3, 4, 12, 39, 93, 5, 9, 2};
  cout << linearSearch(numbers, 39)  << endl;
  cout << linearSearch(numbers, 100) << endl;
  vector<int> empty;
  cout << linearSearch(empty, 12) << endl;
  return 0;
}
