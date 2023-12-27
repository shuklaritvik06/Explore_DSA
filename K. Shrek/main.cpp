//
// Created by rituparn on 24.12.23.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
std::vector<std::vector<std::pair<int, int>>> buildTable(std::vector<int>& Sequence) {
    int N = Sequence.size();
    int DEPTH = static_cast<int>(log2(N)) + 1;
    std::vector<std::vector<std::pair<int, int>>> Sparsetable(N, std::vector<std::pair<int, int>>(DEPTH, {0, 0}));

    for (int i = 0; i < N; ++i) {
        Sparsetable[i][0] = {Sequence.at(i), i};
    }

    for (int j = 1; (1 << j) <= N; ++j) {
        for (int i = 0; i + (1 << j) - 1 < N; ++i) {
            std::pair<int,int> left = Sparsetable[i][j - 1];
            std::pair<int,int> right= Sparsetable[i + (1 << (j - 1))][j - 1];
            Sparsetable[i][j] = min(left, right);
        }
    }

    return Sparsetable;
}

std::pair<int, int> Checking(std::vector<std::vector<std::pair<int, int>>>& Sparsetable, int left, int right) {
    int j = static_cast<int>(log2(right - left + 1));
    std::pair<int,int> leftCheck = Sparsetable[left][j];
    std::pair<int,int> rightCheck= Sparsetable[right - (1 << j) + 1][j];
    return min(leftCheck, rightCheck);
}

int SecondMin(std::vector<int>& Sequence, std::vector<std::vector<std::pair<int, int>>>& Sparsetable, int left, int right) {
    std::pair<int,int> MinPart= Checking(Sparsetable, left - 1, right - 1);
    int minIndex = MinPart.second;
    int  secondSmallest = INT_MAX;

    if (left - 1 <= minIndex - 1) {
        secondSmallest = std::min(secondSmallest, Sequence[Checking(Sparsetable, left - 1, minIndex - 1).second]);
    }

    if (minIndex + 1 <= right - 1) {
        secondSmallest = std::min(secondSmallest, Sequence[Checking(Sparsetable, minIndex + 1, right - 1).second]);
    }

    return secondSmallest;
}

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> sequence(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> sequence[i];
    }

    std::vector< std::vector< std::pair<int, int>>> sparsetable = buildTable(sequence);

    for (int i = 0; i < M; ++i) {
        int left, right;
        std::cin >> left >> right;
        std::cout << SecondMin(sequence, sparsetable, left, right) << '\n';
    }

    return 0;
}
