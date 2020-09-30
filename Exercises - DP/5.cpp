/*
Binomial coefficient / Combinations
(n k)  n choose k, denote number of ways to choose k items from n items where sequence does not matter.
*/

/* RECURSIVE */
int combinations(int n, int k) {
  if (k == n || k == 0) {
    return 1;
  }
  return combinations(n - 1, k - 1) + combinations(n - 1, k);
}

/* TOP-DOWN */
int combinations(int n, int k) {
  vector<vector<int>> cache(n, vector<int>(k, 0));
  return binomialCoefficient(n, k, cache);
}

int binomialCoefficient(int n, int k, vector<vector<int>>& cache) {
  if (k == n || k == 0) {
    return 1;
  }
  if (cache[n][k] != 0) {
    return cache[n][k];
  }
  int res = binomialCoefficient(n - 1, k - 1, cache) + binomialCoefficient(n - 1, k, cache);
  cache[n][k] = res;
  return cache[n][k];
}

/* BOTTOM-UP */
int combinations(int n, int k) {
  vector<vector<int>> cache(n + 1, vector<int>(k + 1, 0));
  for (int i = 0; i <= n; i++) {
    cache[i][0] = 1;
    if (i <= k) {
      cache[i][i] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      cache[i][k] = cache[i - 1][j - 1] + cache[i - 1][j];
    }
  }
  return cache[n][k];
}
