//
// Created by rituparn on 24.12.23.
//
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <cstdint>

const uint64_t INF = 1e18;

struct Edge {
    uint64_t to;
    uint64_t weight;

    Edge(uint64_t to, uint64_t weight) : to(to), weight(weight) {}
};

uint64_t UniversetypeA(uint64_t Universes, uint64_t vertex) {
    return (Universes + 1) % vertex;
}

uint64_t UniversetypeB(uint64_t Universes, uint64_t vertex) {
    return (Universes * Universes + 1) % vertex;
}

void AddEdge(std::vector<std::vector<Edge>>& adjacency_matrix, uint64_t in_vertex, uint64_t weight1, uint64_t weight2, uint64_t number_of_nodes) {
    uint64_t out_vertex1 = UniversetypeA(in_vertex, number_of_nodes);
    uint64_t out_vertex2 = UniversetypeB(in_vertex, number_of_nodes);
    adjacency_matrix[in_vertex].emplace_back(out_vertex1, weight1);
    adjacency_matrix[in_vertex].emplace_back(out_vertex2, weight2);
}

std::vector<uint64_t> Dijkstra(std::vector<std::vector<Edge>>& adjacency_matrix, uint64_t start_node) {
    uint64_t number_of_nodes = adjacency_matrix.size();
    std::vector<uint64_t> Distance(number_of_nodes, INF);
    std::priority_queue<std::pair<uint64_t, uint64_t>, std::vector<std::pair<uint64_t, uint64_t>>, std::greater<>> Queue;
    Distance[start_node] = 0;
    Queue.emplace(0, start_node);


    while (!Queue.empty()) {
        std::pair<uint64_t, uint64_t> node = Queue.top();
        Queue.pop();

        for (const auto& edge : adjacency_matrix[node.second]) {
            uint64_t new_dist = node.first + edge.weight;
            if (new_dist < Distance[edge.to]) {
                Distance[edge.to] = new_dist;
                Queue.emplace(new_dist, edge.to);
            }
        }
    }

    return Distance;
}

int main() {
    uint64_t BottlesA, BottleB, NumberofUniverse, StartingUniverse, EndingUniverse;
    std::cin >> BottlesA >> BottleB >> NumberofUniverse >> StartingUniverse >> EndingUniverse;

    std::vector<std::vector<Edge>> Matrix(NumberofUniverse);
    for (uint64_t i = 0; i < NumberofUniverse; i++) {
        AddEdge(Matrix, i, BottlesA, BottleB, NumberofUniverse);
    }

    std::vector<uint64_t> NumofBottles = Dijkstra(Matrix, StartingUniverse);
    std::cout <<NumofBottles.at(EndingUniverse) << '\n';
    return 0;
}
