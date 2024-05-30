#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Suffix {
    int index;
    int rank[2];
};

bool compare(Suffix a, Suffix b) {
    return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1]) : (a.rank[0] < b.rank[0]);
}

vector<int> buildSuffixArray(string const& str) {
    int n = str.length();
    vector<Suffix> suffixes(n);

    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].rank[0] = str[i] - 'a';
        suffixes[i].rank[1] = (i + 1 < n) ? (str[i + 1] - 'a') : -1;
    }

    sort(suffixes.begin(), suffixes.end(), compare);

    vector<int> index(n);
    for (int k = 4; k < 2 * n; k <<= 1) {
        int rank = 0;
        int prevRank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        index[suffixes[0].index] = 0;

        for (int i = 1; i < n; i++) {
            if (suffixes[i].rank[0] == prevRank && suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
                prevRank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            } else {
                prevRank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            index[suffixes[i].index] = i;
        }

        for (int i = 0; i < n; i++) {
            int nextIndex = suffixes[i].index + k / 2;
            suffixes[i].rank[1] = (nextIndex < n) ? suffixes[index[nextIndex]].rank[0] : -1;
        }

        sort(suffixes.begin(), suffixes.end(), compare);
    }

    vector<int> suffixArray(n);
    for (int i = 0; i < n; i++) {
        suffixArray[i] = suffixes[i].index;
    }

    return suffixArray;
}

vector<int> kasaiLCP(string const& str, vector<int> const& suffixArray) {
    int n = str.length();
    vector<int> lcp(n, 0);
    vector<int> rank(n, 0);

    for (int i = 0; i < n; i++) {
        rank[suffixArray[i]] = i;
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = suffixArray[rank[i] + 1];
        while (i + k < n && j + k < n && str[i + k] == str[j + k]) {
            k++;
        }
        lcp[rank[i]] = k;
        if (k > 0) {
            k--;
        }
    }

    return lcp;
}

int main() {
    string str;
    cin >> str;

    int n = str.length();

    vector<int> suffixArray = buildSuffixArray(str);
    vector<int> lcpArray = kasaiLCP(str, suffixArray);

    long long totalDistinct = 0;
    for (int i = 0; i < n; i++) {
        totalDistinct += n - suffixArray[i] - lcpArray[i];
    }

    cout << totalDistinct << endl;

    return 0;
}
