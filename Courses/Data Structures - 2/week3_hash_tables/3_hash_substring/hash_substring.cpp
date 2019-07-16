#include <iostream>
#include <string>
#include <vector>

using std::string;
typedef unsigned long long ull;

struct Data {
  string pattern, text;
};

Data read_input() {
  Data data;
  std::cin >> data.pattern >> data.text;
  return data;
}

void print_occurrences(const std::vector<int> &output) {
  for (size_t i = 0; i < output.size(); ++i)
    std::cout << output[i] << " ";
  std::cout << "\n";
}
unsigned long long hash_func(const string &s, const int &prime,
                             const int &multiplier) { 
  unsigned long long hash = 0;
  for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i)
    hash = (hash * multiplier + s[i]) % prime;
  return hash;
}

std::vector<long long> PrecomputeHashes(const string &T, const size_t &lenP,
                                        const int &p, const int &x) {
  size_t lenT = T.size();
  std::vector<long long> H(lenT - lenP + 1);
  string S = T.substr(lenT - lenP);
  H[lenT - lenP] = hash_func(S, p, x);
  long long y = 1;
  for (size_t i = 1; i <= lenP; i++)
    y = (y * x) % p;
  for (int i = lenT - lenP - 1; i >= 0; --i)
    H[i] =
        ((x * H[i + 1] + T[i] - y * T[i + lenP]) % p + p) %
        p; 
  return H;
}
bool AreEqual(const string &T, const string &P, const size_t &start) {
  for (size_t i = start; i <= start + P.size() - 1; ++i) {
    if (T[i] != P[i - start]) {
      return false;
    }
  }
  return true;
}

std::vector<int> RabinKarp(const Data &input) {
  const string &T = input.text;
  const string &P = input.pattern;
  int p = int(1e9) + 7;         
  int x = rand() % (p - 1) + 1; 
  std::vector<int> result;
  unsigned long long pHash = hash_func(P, p, x);
  std::vector<long long> H = PrecomputeHashes(T, P.size(), p, x);
  for (size_t i = 0; i <= T.size() - P.size(); ++i) {
    if (pHash != H[i])
      continue;
    if (AreEqual(T, P, i))
      result.push_back(i);
  }
  return result;
}
std::vector<int> get_occurrences(const Data &input) {
  const string &s = input.pattern, t = input.text;
  std::vector<int> ans;
  for (size_t i = 0; i + s.size() <= t.size(); ++i)
    if (t.substr(i, s.size()) == s)
      ans.push_back(i);
  return ans;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  print_occurrences(RabinKarp(read_input()));
  return 0;
}