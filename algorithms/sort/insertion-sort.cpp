#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& numbers);
void insertionSort(vector<int>& numbers);

int main() {
  vector<int> numbers = {28, 24, 1, 4, 20, 4, 99, 10, 212};
  print(numbers);
  insertionSort(numbers);
  print(numbers);
}

void print(vector<int>& numbers) {
  for(int n : numbers) {
    cout << n << " ";
  }
  cout << endl;
}

void insertionSort(vector<int>& numbers) {
  for (int i = 1; i < numbers.size(); ++i) {
    int value = numbers[i];
    int j = i - 1;

    while (j >= 0 && value < numbers[j]) {
      numbers[j+1] = numbers[j];
      --j;
    }
    numbers[j+1] = value;
  }
}
