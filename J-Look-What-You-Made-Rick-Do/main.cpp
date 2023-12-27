//
// Created by rituparn on 25.12.23.
//
#include <iostream>
#include <vector>

void Algorithm(std::vector<std::vector<int>>& adjacencyMatrix, int numUniverses) {
    for (int i = 0; i < numUniverses; ++i) {
        for (int j = 0; j < numUniverses; ++j) {
            char isConnected;
            std::cin >> isConnected;
            if (isConnected == '1') {
                adjacencyMatrix[i][j] = 1;
            }
        }
    }
    for (int k = 0; k < numUniverses; ++k) {
        for (int i = 0; i < numUniverses; ++i) {
            for (int j = 0; j < numUniverses; ++j) {
                adjacencyMatrix[i][j] |= (adjacencyMatrix[i][k] & adjacencyMatrix[k][j]);
            }
        }
    }
}

int main() {
    int Universes;
    std::cin >> Universes;

    std::vector<std::vector<int>> adjacencyMatrix(Universes, std::vector<int>(Universes, 0));
    Algorithm(adjacencyMatrix, Universes);
    for (const auto& row : adjacencyMatrix) {
        for (int val : row) {
            std::cout << val;
        }
        std::cout << std::endl;
    }
    return 0;
}
