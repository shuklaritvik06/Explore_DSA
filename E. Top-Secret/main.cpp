#include <iostream>
#include <vector>

struct Graph{
    std::vector<std::vector<int>> AdjacencyList;
    std::vector<int> Degree;
};

Graph CreateGraph(int Vertices) {
    Graph MyGraph;
    MyGraph.AdjacencyList.resize(Vertices);
    MyGraph.Degree.resize(Vertices, false);
    return MyGraph;
}
struct Direction {
    int Source;
    int Destination;
};



Graph AddEdge(Graph & Graph, std::vector<std::pair<int, int>> &Edges) {
    for (const auto& Edge : Edges) {
        int Source = Edge.first;
        int Destination = Edge.second;
        Graph.AdjacencyList[Source].push_back(Destination);
        Graph.Degree[Destination]++;
    }
    return  Graph;
}


std::vector<int> TopologicalSort(Graph& graph) {
    std::vector<int> result;
    std::vector<int> degree = graph.Degree;
    std::vector<int> zeroDegreeNodes;

    for (size_t i = 0; i < degree.size(); ++i) {
        if (degree[i] == 0) {
            zeroDegreeNodes.push_back(i);
        }
    }

    while (!zeroDegreeNodes.empty()) {
        int node = zeroDegreeNodes.back();
        zeroDegreeNodes.pop_back();
        result.push_back(node);

        for (int neighbor : graph.AdjacencyList[node]) {
            if (--degree[neighbor] == 0) {
                zeroDegreeNodes.push_back(neighbor);
            }
        }
    }
    if (result.size() == graph.AdjacencyList.size()) {
        return result;
    } else {
        return {};
    }
}


int main() {
    int Vertices, Edges, Edge1, Edge2;
    std::cin >>Vertices >> Edges;
    std::vector<std::pair<int, int>> edges;
    Graph Mygraph= CreateGraph(Vertices);
    for (int i = 0; i < Edges; ++i) {
        std::cin >> Edge1 >> Edge2;
        edges.emplace_back(Edge1, Edge2);
    }
    AddEdge(Mygraph,edges);
    std::vector<int> result = TopologicalSort(Mygraph);
    if (!result.empty()) {
        std::cout << "YES\n";
        for (int i : result) {
            std::cout << i << " ";
        }
    } else {
        std::cout << "NO";
    }

    return 0;
}