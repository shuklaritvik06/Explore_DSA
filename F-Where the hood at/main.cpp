//
// Created by rituparn on 25.12.23.
//
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

void AddEdge(std::vector<std::vector<int>>& adjacency, int Source, int Destination) {
    adjacency[Source].push_back(Destination);
}

void DFS(std::vector<std::vector<int>>& adjacency, int vertex,
         std::vector<bool>& visited, std::stack<int>& traversal_stack) {
    visited[vertex] = true;
    for (int neighbor : adjacency[vertex]) {
        if (!visited[neighbor]) {
            DFS(adjacency, neighbor, visited, traversal_stack);
        }
    }
    traversal_stack.push(vertex);
}

void ReverseDFS(std::vector<std::vector<int>>& reversed_adjacency, int vertex,
                std::vector<bool>& visited, std::vector<int>& component) {
    visited[vertex] = true;
    component.push_back(vertex);
    for (int neighbor : reversed_adjacency[vertex]) {
        if (!visited[neighbor]) {
            ReverseDFS(reversed_adjacency, neighbor, visited, component);
        }
    }
}

std::vector<std::vector<int>> IdentifyStronglyConnected(
        std::vector<std::vector<int>>& adjacency,
        std::vector<std::vector<int>>& reversed_adjacency, int Vertices) {
    std::stack<int> traversal_stack;
    std::vector<bool> visited(Vertices, false);

    for (int i = 0; i < Vertices; ++i) {
        if (!visited[i]) {
            DFS(adjacency, i, visited, traversal_stack);
        }
    }
    visited.assign(Vertices, false);
    std::vector<std::vector<int>> strongly_connected_component;
    while (!traversal_stack.empty()) {
        int list = traversal_stack.top();
        traversal_stack.pop();
        if (!visited[list]) {
            std::vector<int> connected_component;
            ReverseDFS(reversed_adjacency, list, visited, connected_component);
            strongly_connected_component.push_back(connected_component);
        }
    }
    return strongly_connected_component;
}

std::pair<int, int> Degree(std::vector<std::vector<int>>& adjacency, int Vertices) {
    std::vector<int> OutDegree(Vertices, 0), InDegree(Vertices, 0);
    for (int i = 0; i < Vertices; ++i) {
        for (int neighbor : adjacency[i]) {
            OutDegree[i]++;
            InDegree[neighbor]++;
        }
    }

    int total_degrees_in = std::count(InDegree.begin(), InDegree.end(), 0);
    int total_degrees_out = std::count(OutDegree.begin(), OutDegree.end(), 0);

    return {total_degrees_in, total_degrees_out};
}

int main() {
    int Vertices, Edges;
    std::cin >> Vertices >> Edges;
    std::vector<std::vector<int>> adjacency(Vertices, std::vector<int>());
    std::vector<std::vector<int>> reversed_adjacency(Vertices, std::vector<int>());
    int Source, Destination, count = 0;
    while (count < Edges) {
        std::cin >> Source >> Destination;
        AddEdge(adjacency, Source - 1, Destination - 1);
        AddEdge(reversed_adjacency, Destination - 1, Source - 1);
        count++;

    }
    std::vector<std::vector<int>> scc = IdentifyStronglyConnected(adjacency, reversed_adjacency, Vertices);

    if (scc.size() == 1) {
        std::cout << 0 << '\n';
        return 0;
    }
    std::vector<std::vector<int>> squeezed_adjacency(scc.size(), std::vector<int>());

    for (int i = 0; i < scc.size(); ++i) {
        for (int vertex : scc[i]) {
            for (int neighbor : adjacency[vertex]) {
                int neighbor_index = -1;
                for (int j = 0; j < scc.size(); ++j) {
                    if (std::find(scc[j].begin(), scc[j].end(), neighbor) != scc[j].end()) {
                        neighbor_index = j;
                        break;
                    }
                }
                if (neighbor_index != -1 && neighbor_index != i) {
                    squeezed_adjacency[i].push_back(neighbor_index);
                }
            }
        }
    }
    std::pair<int, int> degree_info = Degree(squeezed_adjacency, scc.size());
    std::cout << std::max(degree_info.first, degree_info.second) << '\n';

    return 0;
}
