//
// Created by rituparn on 24.12.23.
//

#include <cstdint>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

void AddEdge(std::vector<std::vector<std::pair<std::int64_t, std::int64_t>>>& adjacency_list, std::int64_t in_vertex, std::int64_t out_vertex, std::int64_t weight) {
    adjacency_list[in_vertex].push_back(std::make_pair(weight, out_vertex));
}

std::int64_t FindCheapestPrice(std::vector<std::vector<std::pair<std::int64_t, std::int64_t>>>& adjacency_list, std::int64_t start_node, std::int64_t end_node, std::int64_t number_of_flights) {
    std::priority_queue<std::pair<std::int64_t, std::int64_t>, std::vector<std::pair<std::int64_t, std::int64_t>>, std::greater<std::pair<std::int64_t, std::int64_t>>> traversal_queue;
    traversal_queue.push({0, start_node});
    std::vector<std::int64_t> min_cost(adjacency_list.size(), std::numeric_limits<std::int64_t>::max());
    min_cost[start_node] = 0;
    std::int64_t stops = 0;
    while (!traversal_queue.empty() && stops < number_of_flights) {
        std::size_t size = traversal_queue.size();
        while (size-- != 0) {
            auto [cost, current_node] = traversal_queue.top();
            traversal_queue.pop();
            for (auto& [price, neighbour] : adjacency_list[current_node]) {
                if (price + cost < min_cost[neighbour]) {
                    min_cost[neighbour] = price + cost;
                    traversal_queue.push(std::make_pair(min_cost[neighbour], neighbour));
                }
            }
        }
        stops++;
    }
    if (stops - 1 >= number_of_flights) {
        return -1;
    }
    if (min_cost[end_node] >= std::numeric_limits<std::int64_t>::max()) {
        return -1;
    }
    return min_cost[end_node];
}

int main() {
    std::int64_t Universes, TeleportationDevices, Flights, EarthC137, CitadelofRicks;
    std::cin >> Universes>> TeleportationDevices>> Flights>> EarthC137>> CitadelofRicks;
    std::vector<std::vector<std::pair<std::int64_t, std::int64_t>>> adjacency_list(Universes + 1);

    for (int i = 0; i < TeleportationDevices; i++) {
        std::int64_t Invertex, Outvertex, cost;
        std::cin >> Invertex>> Outvertex>> cost;
        AddEdge(adjacency_list, Invertex, Outvertex, cost);
    }
    std::cout << FindCheapestPrice(adjacency_list, EarthC137, CitadelofRicks, Flights) << '\n';
    return 0;
}