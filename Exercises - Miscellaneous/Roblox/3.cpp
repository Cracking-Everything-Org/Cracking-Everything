#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'deleteProducts' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ids
 *  2. INTEGER m
 */
struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

int deleteProducts(vector<int> ids, int m) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> minHeap;
    int count = 0;
    unordered_map<int, int> hm;

    for (int i = 0; i < ids.size(); i++) {
        if (hm.find(ids[i]) == hm.end()) {
            hm[ids[i]] = 1;
        } else {
            hm[ids[i]]++;
        }
    }

    for (auto entry : hm) {
        minHeap.push(make_pair(entry.first, entry.second));
    }

    int i = 0;
    while (i < m) {
        pair<int, int> top = minHeap.top();
        minHeap.pop();
        if (top.second - 1 > 0) {
            minHeap.push(make_pair(top.first, top.second - 1));
        }
        i++;
    }

    return minHeap.size();
}


int main()
