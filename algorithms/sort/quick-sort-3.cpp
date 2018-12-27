#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void swap(int* x, int* y);
void print(vector<int>& numbers);
void quickSort3(vector<int>& numbers);
void quickSort3(vector<int>& numbers, int left, int right);
pair<int, int> partition(vector<int>& numbers, int left, int right);

int main() {
  // vector<int> numbers = {28, 24, 1, 4, 3, 5, 14,99, 10, 212, 7};
  vector<int> numbers = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4};
  print(numbers);
  quickSort3(numbers);
  print(numbers);
}

void swap(int* x, int* y) {
  int t = *x;
  *x = *y;
  *y = t;
}

void print(vector<int>& numbers) {
  for(int n : numbers) {
    cout << n << " ";
  }
  cout << endl;
}

void quickSort3(vector<int>& numbers) {
  int left = 0;
  int right = numbers.size() - 1;
  quickSort3(numbers, left, right);
}

void quickSort3(vector<int>& numbers, int left, int right) {
  if (left < right) {
    pair<int, int> pt = partition(numbers, left, right);

    quickSort3(numbers, left, pt.first);
    quickSort3(numbers, pt.second, right);
  }
}

pair<int, int> partition(vector<int>& numbers, int left, int right) {
  // only 2 elements
  if (right - left <= 1) {
    if (numbers[right] < numbers[left]) {
      swap(&numbers[left], &numbers[right]);
      return make_pair(left, right);
    }
  }

  int pivot = numbers[right];
  int i = left;

  while (i <= right) {
    if (numbers[i] < pivot) {
      swap(&numbers[i++], &numbers[left++]);
    } else if (numbers[i] > pivot) {
      swap(&numbers[i], &numbers[right--]);
    } else {
      ++i;
    }
  }

  return make_pair(left-1, right+1);
}
