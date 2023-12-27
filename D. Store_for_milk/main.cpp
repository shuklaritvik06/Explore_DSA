//
// Created by rituparn on 24.12.23.
//

#include <climits>
#include <iostream>
#include <queue>
#include <vector>


std::vector<std::vector<int>> CreateGraph(int Vertices) {
    std::vector<std::vector<int>> AdjacencyList(Vertices);
    return AdjacencyList;
}


void AddEdge(std::vector<std::vector<int>>& AdjacencyList, int Source, int Destination) {
    AdjacencyList[Source].push_back(Destination);
    AdjacencyList[Destination].push_back(Source);
}


int ShortestRoute(int num, const std::vector<int>& FirstSource, const std::vector<int>& SecondSource, const std::vector<int>& Destination) {
    int sum = INT_MAX;
    for (int i = 0; i < num; ++i) {
        if ((FirstSource[i] + SecondSource[i] + Destination[i]) < sum) {
            sum = FirstSource[i] + SecondSource[i] + Destination[i];
        }
    }
    return sum;
}


void BFS(int start, int Vertices, const std::vector<std::vector<int>>& AdjacencyList, std::vector<int>& Distance) {
    std::queue<int> Queue;
    std::vector<bool> Visited(Vertices, false);

    std::fill(Distance.begin(), Distance.end(), INT_MAX);
    Visited[start] = true;
    Distance[start] = 0;
    Queue.push(start);

    while (!Queue.empty()) {
        int element = Queue.front();
        Queue.pop();

        for (int v : AdjacencyList[element]) {
            if (!Visited[v]) {
                Visited[v] = true;
                Distance[v] = Distance[element] + 1;
                Queue.push(v);
            }
        }
    }
}

int ShortestDist(int first_source, int second_source, int destination, int num, const std::vector<std::vector<int>>& adj) {
    std::vector<int> distance_1(num, INT_MAX);
    std::vector<int> distance_2(num, INT_MAX);
    std::vector<int> omega_2(num, INT_MAX);

    BFS(first_source, num, adj, distance_1);
    BFS(second_source, num, adj, distance_2);
    BFS(destination, num, adj, omega_2);

    return ShortestRoute(num, distance_1, distance_2, omega_2);
}

int main() {
    int Vertices, Edges, VertexLeon, VertexMatilda, VertexMilkshop;
    std::cin >> Vertices >> Edges >> VertexLeon >> VertexMatilda >> VertexMilkshop;
    auto Graph1 = CreateGraph(Vertices + 1);
    for (int start = 0; start < Edges; start++) {
        int i, j;
        std::cin >> i >> j;
        AddEdge(Graph1, i, j);
    }
    int shortestDistance = ShortestDist(VertexLeon, VertexMatilda, VertexMilkshop, Vertices + 1, Graph1);
    std::cout << shortestDistance << std::endl;
    return 0;
}
