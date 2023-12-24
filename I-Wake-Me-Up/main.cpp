//
// Created by rituparn on 24.12.23.
//
#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>



void AddEdge(std::vector<std::vector<std::pair<double, uint64_t>>>& adjacency_list, uint64_t in_vertex, uint64_t out_vertex, double weight) {
    adjacency_list[in_vertex].push_back(std::make_pair(weight, out_vertex));
    adjacency_list[out_vertex].push_back(std::make_pair(weight, in_vertex));
}
double Dijkstra(uint64_t number_of_nodes, std::vector<std::vector<std::pair<double, uint64_t>>>& adjacency_list, uint64_t start_node, uint64_t end_node) {
    std::priority_queue<std::pair<double, uint64_t>, std::vector<std::pair<double, uint64_t>>, std::greater<>> traversal_queue;
    std::vector<double> cost(number_of_nodes + 1, std::numeric_limits<double>::max());
    cost[start_node] = 0;
    traversal_queue.push({0, start_node});

    while (!traversal_queue.empty()) {
        auto [current_cost, current_node] = traversal_queue.top();
        traversal_queue.pop();

        if (current_cost > cost[current_node]) {
            continue;
        }

        for (const auto& [neighbor_price, neighbor_node] : adjacency_list[current_node]) {
            double discounted_price = neighbor_price - cost[current_node] * neighbor_price;
            double new_cost = cost[current_node] + discounted_price;
            if (new_cost < cost[neighbor_node]) {
                cost[neighbor_node] = new_cost;
                traversal_queue.push({new_cost, neighbor_node});
            }
        }
    }

    return cost[end_node];
}


int main() {
    uint64_t Universes, Teleportation, StartingUniverse, FinalUniverse;
    std::cin >> Universes>> Teleportation>> StartingUniverse>> FinalUniverse;
    std::vector<std::vector<std::pair<double, uint64_t>>> adjacency_list(Universes + 1);
    for (uint64_t i = 0; i < Teleportation; i++) {
        double cost;
        uint64_t Invertex, Outvertex;
        std::cin >> Invertex >> Outvertex >> cost;
        AddEdge(adjacency_list, Invertex, Outvertex, cost / 100);
    }

    std::cout << std::setprecision(2);
    std::cout << std::noshowpoint << Dijkstra(Universes, adjacency_list, StartingUniverse, FinalUniverse);

    return 0;
}