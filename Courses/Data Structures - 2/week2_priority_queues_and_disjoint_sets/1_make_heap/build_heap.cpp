#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
private:
  vector<int> data_;
  vector<pair<int, int>> swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for (int i = 0; i < n; ++i)
      cin >> data_[i];
  }
  void SiftUp(int i) {
    while (i > 0 && data_[(i - 1) >> 1] > data_[i]) {
      swap(data_[(i - 1) >> 1], data_[i]);
      swaps_.push_back(make_pair((i - 1) >> 1, i));
      i = (i - 1) >> 1;
    }
  }
  void SiftDown(int i) {
    int minIndex = i;
    int l = 2 * i + 1, r = 2 * i + 2; 
    if (l < data_.size() && data_[l] < data_[minIndex])
      minIndex = l;
    if (r < data_.size() && data_[r] < data_[minIndex])
      minIndex = r;
    if (minIndex != i) { 
      swap(data_[i], data_[minIndex]);
      swaps_.push_back(make_pair(i, minIndex));
      ShiftDown(minIndex); 
    }
  }
  void GenerateSwaps() {
    swaps_.clear();
    for (int i = (data_.size() - 2) >> 1; i >= 0; i--) 
      SiftDown(i);
  }

public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}