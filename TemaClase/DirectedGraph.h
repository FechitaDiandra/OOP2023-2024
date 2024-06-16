#pragma once

// FECHITA DIANDRA
#include "Graph.h"
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <functional>

template <typename T>
class DirectedGraph : public Graph<T>
{
public:
    void addEdge(T, T);
    void addEdge(T, T, int);
    bool connected();
    bool acyclic();
    vector<T> getShortestPath(T node1, T node2);
    vector<T> getCheapestPath(T node1, T node2);
    bool complete();
    bool removeEdge(T node1, T node2);
    DirectedGraph<T> transpose();
    void dfs( T node, unordered_set<T>& visited);
    DirectedGraph(unsigned int nodeCount);
    DirectedGraph(unsigned int count, unsigned int edgeCount);
    DirectedGraph(initializer_list<T> nodes);

};
template <typename T>
void DirectedGraph<T>::dfs( T node, unordered_set<T>& visited) {
    visited.insert(node);
    for (const auto& adj : this->adjacencyList) {
        if (adj.first == node) {
            for (const auto& neighbor : adj.second) {
                if (visited.find(neighbor) == visited.end()) {
                    dfs(neighbor, visited);
                }
            }
            break;
        }
    }
}
template <typename T>
DirectedGraph<T> DirectedGraph<T>::transpose() {
    DirectedGraph<T> transposedGraph(this->nodesSize());
    for (const auto& node : this->nodes) {
        transposedGraph.addNode(node);
    }
    for (const auto& edge : this->edges) {
        transposedGraph.addEdge(edge.node2, edge.node1, edge.cost);
    }
    return transposedGraph;
}
template <typename T>
void DirectedGraph<T>::addEdge(T node1, T node2) {
    bool has1 = false;
    bool has2 = false;
    for (T node : this->nodes) {
        if (node == node1) {
            has1 = true;
        }
        if (node == node2) {
            has2 = true;
        }
        if (has1 && has2) break;
    }
    if (has1 && has2 && node1 != node2) {
        this->edges.push_back({ node1, node2, 0 });
        this->addToAdjacencyList({ node1, node2, 0 });
    }
}

template <typename T>
void DirectedGraph<T>::addEdge(T node1, T node2, int cost) {
    bool has1 = false;
    bool has2 = false;
    for (T node : this->nodes) {
        if (node == node1) {
            has1 = true;
        }
        if (node == node2) {
            has2 = true;
        }
        if (has1 && has2) break;
    }
    if (has1 && has2 && node1 != node2) {
        this->edges.push_back({ node1, node2, cost });
        this->addToAdjacencyList({ node1, node2, cost });
    }
}

template <typename T>
bool DirectedGraph<T>::connected() {
    if (this->nodes.empty()) return true;

    unordered_set<T> visited;
    dfs(this->nodes[0], visited);
    if (visited.size() != this->nodes.size()) return false;

    DirectedGraph<T> transposedGraph = transpose();
    visited.clear();
    transposedGraph.dfs(this->nodes[0], visited);

    return visited.size() == this->nodes.size();
}

template <typename T>
bool DirectedGraph<T>::acyclic() {
    function<bool(T, map<T, bool>&, map<T, bool>&)> dfs = [&](T node, map<T, bool>& visited, map<T, bool>& recStack) {
        visited[node] = true;
        recStack[node] = true;

        for (T neighbor : this->getNeighbors(node)) {
            if (!visited[neighbor] && dfs(neighbor, visited, recStack)) {
                return true;
            }
            else if (recStack[neighbor]) {
                return true;
            }
        }

        recStack[node] = false;
        return false;
    };

    map<T, bool> visited;
    map<T, bool> recStack;
    for (const T& node : this->nodes) {
        visited[node] = false;
        recStack[node] = false;
    }

    for (const T& node : this->nodes) {
        if (!visited[node]) {
            if (dfs(node, visited, recStack)) {
                return false;
            }
        }
    }

    return true;
}

template <typename T>
vector<T> DirectedGraph<T>::getShortestPath(T node1, T node2) {
    unordered_map<T, T> parent;
    unordered_set<T> visited;
    queue<T> q;

    q.push(node1);
    visited.insert(node1);
    parent[node1] = T();

    while (!q.empty()) {
        T current = q.front();
        q.pop();

        if (current == node2) {
            vector<T> path;
            for (T at = node2; at != T(); at = parent[at]) {
                path.push_back(at);
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (const auto& adj : this->adjacencyList) {
            if (adj.first == current) {
                for (const auto& neighbor : adj.second) {
                    if (visited.find(neighbor) == visited.end()) {
                        q.push(neighbor);
                        visited.insert(neighbor);
                        parent[neighbor] = current;
                    }
                }
                break;
            }
        }
    }

    return vector<T>();
}

template <typename T>
vector<T> DirectedGraph<T>::getCheapestPath(T node1, T node2) {
    unordered_map<T, int> dist;
    unordered_map<T, T> parent;
    auto comp = [&](const pair<int, T>& a, const pair<int, T>& b) {
        return a.first > b.first;
    };
    priority_queue<pair<int, T>, vector<pair<int, T>>, decltype(comp)> pq(comp);

    for (const T& node : this->nodes) {
        dist[node] = INT_MAX;
    }

    pq.push({ 0, node1 });
    dist[node1] = 0;
    parent[node1] = T();

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        T current = pq.top().second;
        pq.pop();

        if (current == node2) {
            vector<T> path;
            for (T at = node2; at != T(); at = parent[at]) {
                path.push_back(at);
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (const auto& adj : this->adjacencyList) {
            if (adj.first == current) {
                for (const auto& neighbor : adj.second) {
                    int edgeCost = this->getEdgeCost(current, neighbor);
                    if (currentDist + edgeCost < dist[neighbor]) {
                        dist[neighbor] = currentDist + edgeCost;
                        pq.push({ dist[neighbor], neighbor });
                        parent[neighbor] = current;
                    }
                }
                break;
            }
        }
    }

    return vector<T>();
}

template <typename T>
bool DirectedGraph<T>::removeEdge(T node1, T node2) {
    auto it = this->edges.begin();
    while (it != this->edges.end()) {
        if (it->node1 == node1 && it->node2 == node2) {
            it = this->edges.erase(it);
        }
        else {
            ++it;
        }
    }

    for (auto& adj : this->adjacencyList) {
        if (adj.first == node1) {
            adj.second.erase(remove(adj.second.begin(), adj.second.end(), node2), adj.second.end());
        }
    }

    return true;
}

template <typename T>
DirectedGraph<T>::DirectedGraph(unsigned int nodeCount) : Graph<T>(nodeCount) {}

template <typename T>
DirectedGraph<T>::DirectedGraph(unsigned int count, unsigned int edgeCount) : Graph<T>(count, edgeCount) {}

template <typename T>
DirectedGraph<T>::DirectedGraph(initializer_list<T> nodes) : Graph<T>(nodes) {}
template <typename T>
bool DirectedGraph<T>::complete() {
    return this->edges.size() == this->nodes.size() * (this->nodes.size() - 1);
}