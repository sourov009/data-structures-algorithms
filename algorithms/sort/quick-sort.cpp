#include <iostream>
#include <vector>

using namespace std;

void swap(int* x, int* y);
void print(vector<int>& numbers);
void quickSort(vector<int>& numbers);
void quickSort(vector<int>& numbers, int left, int right);
int partition(vector<int>& numbers, int left, int right);

int main() {
  vector<int> numbers = {28, 24, 1, 4, 3, 5, 14,99, 10, 212, 7};
  print(numbers);
  quickSort(numbers);
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

void quickSort(vector<int>& numbers) {
  int left = 0;
  int right = numbers.size() - 1;
  quickSort(numbers, left, right);
}

void quickSort(vector<int>& numbers, int left, int right) {
  if (left < right) {
    int index = partition(numbers, left, right);

    quickSort(numbers, left, index - 1);
    quickSort(numbers, index + 1, right);
  }
}

int partition(vector<int>& numbers, int left, int right) {
  int pivot = numbers[right];

  for (int i = left; i < right; ++i) {
    if (numbers[i] <= pivot) {
      swap(&numbers[i], &numbers[left++]);
    }
  }
  swap(&numbers[left], &numbers[right]);

  return left;
}
