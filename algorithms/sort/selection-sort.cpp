#include <iostream>
#include <vector>

using namespace std;

void swap(int* x, int* y);
void print(vector<int>& numbers);
void selectionSort(vector<int>& numbers);

int main() {
  vector<int> numbers = {28, 24, 1, 4, 20, 4, 99, 10, 212};
  print(numbers);
  selectionSort(numbers);
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

void selectionSort(vector<int>& numbers) {
  for (int i = 0; i < numbers.size(); ++i) {
    int minIndex = i;
    for (int j = i+1; j < numbers.size(); ++j) {
      if (numbers[j] < numbers[minIndex]) {
        minIndex = j;
      }
    }
    swap(&numbers[i], &numbers[minIndex]);
  }
}
