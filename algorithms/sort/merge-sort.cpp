#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int>& numbers);
void mergeSort(vector<int>& numbers, vector<int>& helper, int left, int right);
void merge(vector<int>& numbers, vector<int>& helper, int left, int mid, int right);
void print(vector<int>& numbers);

int main() {
  vector<int> numbers = {28, 24, 1, 4, 20, 4, 99, 10, 212};
  print(numbers);
  mergeSort(numbers);
  print(numbers);
}

void print(vector<int>& numbers) {
  for(int n : numbers) {
    cout << n << " ";
  }
  cout << endl;
}

void mergeSort(vector<int>& numbers) {
  int left = 0;
  int right = numbers.size() - 1;
  vector<int> helper(numbers.size());
  mergeSort(numbers, helper, left, right);
}

void mergeSort(vector<int>& numbers, vector<int>& helper, int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;

    mergeSort(numbers, helper, left, mid);
    mergeSort(numbers, helper, mid + 1, right);

    merge(numbers, helper, left, mid, right);
  }
}

void merge(vector<int>& numbers, vector<int>& helper, int left, int mid, int right) {
  for (int i = left; i <= right; ++i) {
    helper[i] = numbers[i];
  }

  int l = left;
  int r = mid + 1;
  int i = left;

  while (l <= mid && r <= right) {
    if (helper[l] <= helper[r]) {
      numbers[i++] = helper[l++];
    } else {
      numbers[i++] = helper[r++];
    }
  }

  // copy rest of the left side of the array into the target
  // the right side doesn't need to be copied because it's already there
  while (l <= mid) {
    numbers[i++] = helper[l++];
  }
}
