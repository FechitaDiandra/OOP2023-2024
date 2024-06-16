#pragma once

/// MIHAES ENIRICO 
#include "Graph.h"
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <functional>
template <typename T>
class UndirectedGraph :
    public Graph<T>
{
public:
	void addEdge(T,T);
	void addEdge(T, T, int);
	bool connected();
	bool acyclic();
	vector<T> getShortestPath(T node1, T node2);
	vector<T> getCheapestPath(T node1, T node2);
	bool complete();

	bool removeEdge(T node1, T node2);
	UndirectedGraph(unsigned int nodeCount);
	UndirectedGraph(unsigned int count, unsigned int edgeCount);
	UndirectedGraph(initializer_list<T> nodes);
	void dfs( T node, unordered_set<T>& visited);
	bool isTree();
};
template <typename T>
bool UndirectedGraph<T> ::isTree()
{
	bool conn = connected();

	return (conn && this->edges.size() == 2 * (this->nodes.size() - 1));

}
template <typename T>
void UndirectedGraph<T> ::dfs( T node, unordered_set<T>& visited)
{
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
void UndirectedGraph<T> ::addEdge(T node1, T node2) {
	bool has1 = false;
	bool has2 = false;
	for (T node : this->nodes)
	{
		if(node==node1)
		{
			has1 = true; 
		}
		if (node == node2)
		{
			has2 = true;
		}
		if (has1 && has2)
			break;
	}
	if (has1 && has2 && node1!=node2)
	{
		this->edges.push_back({ node1,node2,0 });
		this->edges.push_back({ node2,node1,0 });
		this->addToAdjacencyList({ node1,node2,0 });
		this->addToAdjacencyList({ node2,node1,0 });
	}
	
}
template <typename T>
void UndirectedGraph<T> ::addEdge(T node1, T node2, int cost) {
	bool has1 = false;
	bool has2 = false;
	for (T node : this->nodes)
	{
		if (node == node1)
		{
			has1 = true;
		}
		if (node == node2)
		{
			has2 = true;
		}
		if (has1 && has2)
			break;
	}
	if (has1 && has2 && node1 != node2)
	{
		this->edges.push_back({ node1,node2,cost });
		this->edges.push_back({ node2,node1,cost });
		this->addToAdjacencyList({ node1,node2,cost });
		this->addToAdjacencyList({ node2,node1,cost });
	}
}
template <typename T>
bool UndirectedGraph<T>::connected()
{
	if (this->nodes.empty()) return true;
	unordered_set<T> visited;
	dfs(this->nodes[0], visited);
	return visited.size() == this->nodes.size();

}
template <typename T>
bool UndirectedGraph<T>::acyclic() {
	function<bool(T, T, map<T, bool>&)> dfs = [&](T node, T parent, map<T, bool>& visited) {
		visited[node] = true;
		for (T neighbor : this->getNeighbors(node)) {
			if (!visited[neighbor]) {
				if (dfs(neighbor, node, visited)) {
					return true;
				}
			}
			else if (neighbor != parent) {
				return true; 
			}
		}
		return false;
	};
	map<T, bool> visited;
	for (const T& node : this->nodes) {
		visited[node] = false;
	}

	for (const T& node : this->nodes) {
		if (!visited[node]) {
			if (dfs(node, T(), visited)) {
				return false;
			}
		}
	}

	return true;
}
template <typename T>
vector<T> UndirectedGraph<T>::getShortestPath(T node1, T node2) {
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
vector<T> UndirectedGraph<T>::getCheapestPath(T node1, T node2) {
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

	return vector<T>();  // Return an empty vector if there is no path
}



template <typename T>
bool UndirectedGraph<T>::removeEdge(T node1, T node2) {
	bool removed = false;

	for (auto it = this->edges.begin(); it != this->edges.end();) {
		if ((it->node1 == node1 && it->node2 == node2) ||
			(it->node1 == node2 && it->node2 == node1)) {
			it = this->edges.erase(it);
			removed = true;
		}
		else {
			++it;
		}
	}

	if (!removed) {
		return false;
	}


	for (auto& adj : this->adjacencyList) {
		if (adj.first == node1) {
			adj.second.erase(remove(adj.second.begin(), adj.second.end(), node2), adj.second.end());
		}
		if (adj.first == node2) {
			adj.second.erase(remove(adj.second.begin(), adj.second.end(), node1), adj.second.end());
		}
	}

	return true;
}
template <typename T>
UndirectedGraph<T>::UndirectedGraph(unsigned int nodeCount):Graph<T>(nodeCount)
{
	
}
template <typename T>
UndirectedGraph<T>::UndirectedGraph(unsigned int count, unsigned int edgeCount): Graph<T>(count, edgeCount)
{
	
}
template <typename T>
UndirectedGraph<T>::UndirectedGraph(initializer_list<T> nodes): Graph<T>(nodes)
{
	
}
template <typename T>
bool UndirectedGraph<T>::complete()
{
	return (this->edges.size() == this->nodes.size() * (this->nodes.size() - 1) );
}