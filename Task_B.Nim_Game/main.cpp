#include <iostream>
#include <vector>

int sprague_grundy(int heap_size, const std::vector<int>& moves,
                   std::vector<int>& grundy) {
    if (grundy[heap_size] != -1) return grundy[heap_size];

    std::vector<bool> mex(heap_size + 1, false);

    for (int move : moves) {
        if (move <= heap_size) {
            int next_grundy = sprague_grundy(heap_size - move, moves, grundy);
            mex[next_grundy] = true;
        }
    }

    for (int index = 0; index <= heap_size + 1; ++index) {
        if (!mex[index]) {
            grundy[heap_size] = index;
            break;
        }
    }

    return grundy[heap_size];
}
std::vector<int> grundyArray(std::vector<int>& Moves) {
    const int MAX = 10001;
    std::vector<int> grundy(MAX, -1);
    for (int index = 0; index < MAX; ++index) {
        sprague_grundy(index, Moves, grundy);
    }
    return grundy;
}
bool isWinningPosition(const std::vector<int>& heaps,
                       std::vector<int>& grundy) {
    int NUM = 0;
    for (auto element : heaps) {
        NUM ^= grundy[element];
    }
    return NUM;
}

int main() {
    int numberofmoves;
    std::cin >> numberofmoves;
    std::vector<int> Moves(numberofmoves);
    for (int index = 0; index < numberofmoves; ++index) {
        std::cin >> Moves[index];
    }
    std::vector<int> grundy = grundyArray(Moves);
    int numberOfPositions;
    std::cin >> numberOfPositions;
    while (numberOfPositions--) {
        int numberofheapes;
        std::cin >> numberofheapes;
        std::vector<int> heaps(numberofheapes);
        for (int index = 0; index < numberofheapes; ++index) {
            std::cin >> heaps[index];
        }
        std::cout << (isWinningPosition(heaps, grundy) ? "W" : "L");
    }
    return 0;
}
