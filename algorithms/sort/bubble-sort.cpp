#include <iostream>
#include <vector>

using namespace std;

void swap(int* x, int* y);
void print(vector<int>& numbers);
void bubbleSort(vector<int>& numbers);

int main() {
  vector<int> numbers = {28, 24, 1, 4, 20, 4, 99, 10, 212, 7};
  print(numbers);
  bubbleSort(numbers);
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

void bubbleSort(vector<int>& numbers) {
  int n = numbers.size();
  for (int i = 0; i < n-1; ++i) {
    for (int j = 0; j < n-i-1; ++j) {
      if (numbers[j] > numbers[j+1]) {
        swap(&numbers[j], &numbers[j+1]);
      }
    }
  }
}
