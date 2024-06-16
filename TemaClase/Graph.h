#pragma once
// ANDREI BILIUTI
#include <initializer_list>
#include <utility>
#include <vector>
#include <iostream>
#include "Edge.h"
#include <unordered_set>
using namespace std;

template <typename T>
class Graph
{

protected:
	
	vector<T> nodes;

	vector<pair< T, vector<T>>> adjacencyList;

	unsigned int edgeCount;
	unsigned int nodeCount;
	vector<Edge<T>> edges;

public:
	Graph(unsigned int nodeCount);

	Graph(unsigned int count, unsigned int edgeCount);

	Graph(initializer_list<T> nodes);

	void addNode(T node);
	vector<T> getNeighbors(T node);
	virtual void addEdge(T,T) = 0;
	virtual void addEdge(T, T, int) = 0;
	virtual bool connected() = 0;
	virtual bool acyclic() = 0;
	virtual void dfs( T node, unordered_set<T>& visited) = 0;
	virtual vector<T> getShortestPath(T node1, T node2) = 0;

	virtual vector<T> getCheapestPath(T node1, T node2) = 0;

	virtual bool complete() = 0;

	
	virtual bool removeEdge(T node1, T node2) = 0;
	bool empty();
	int getEdgeCost(T node1, T node2);
	bool removeNode(T node);
	void addToAdjacencyList(Edge<T> edge);

	void setEdgeCount(unsigned int);

	void setNodeCount(unsigned int);

	void printNodes();

	void printEdges();

	unsigned int edgesSize();

	unsigned int nodesSize();
	vector<T> getNodes();
	vector<pair< T, vector<T>>> getAdjacencyList();
};
template <typename T>
vector<T> Graph<T>::getNodes()
{
	return nodes;
}
template <typename T>

vector<pair<T,vector<T>>> Graph<T>::getAdjacencyList()
{
	return adjacencyList;
}
template <typename T>
vector<T> Graph<T>::getNeighbors(T node) {
	for (const auto& adj : adjacencyList) {
		if (adj.first == node) {
			return adj.second;
		}
	}
	return {};
}
template <typename T>
int Graph<T>::getEdgeCost( T node1, T node2) {
	for (const auto& edge : this->edges) {
		if ((edge.node1 == node1 && edge.node2 == node2) || (edge.node1 == node2 && edge.node2 == node1)) {
			return edge.cost;
		}
	}
	return 99999999;  
}
template <typename T>
void Graph<T>::addToAdjacencyList(Edge<T> edge)
{
	bool exists = false;
	for (const auto& adj : adjacencyList) {
		if (adj.first == edge.node1) {
			exists = true;
		}
	}
	if(!exists)
	adjacencyList.push_back({ edge.node1, {} });
	for (auto& adj : adjacencyList) {
		if (adj.first == edge.node1) {
			adj.second.push_back(edge.node2);
			return;
		}
	}
}
template <typename T>
void Graph<T>::printEdges()
{
	cout << "{ ";
	int commas = edges.size() - 1;
	for (Edge<T> edge : edges)
	{
		cout << "{ "<< edge.node1<<", "<<edge.node2<<", cost: "<<edge.cost<<" }";
		if (commas) {
			cout << ", ";
			commas--;
		}
	}
	cout << " }";
}
template <typename T>
void Graph<T>::printNodes() {
	cout << "{ ";
	int commas = nodes.size() - 1;
	for (auto const& node : nodes)
	{
		cout << node;
		if (commas) {
			cout << ", ";
			commas--;
		}
	}
	cout << " }";
}
template <typename T>
unsigned int Graph<T>::nodesSize()
{
	return nodes.size();
}
template <typename T>
unsigned int Graph<T>::edgesSize()
{
	return edges.size();
}
template <typename T>
void Graph<T>::setNodeCount(unsigned int c)
{
	this->nodeCount = c;
}
template <typename T>
void Graph<T>::setEdgeCount(unsigned int c)
{
	this->edgeCount = c;
}
template <typename T>
void Graph<T> ::addNode(T node)
{
	bool exists = false;
	for(T node1 :nodes)
	{
		if (node1 == node)exists = true;
	}
	if(!exists)
	nodes.push_back(node);
}
template <typename T>
Graph<T> ::Graph(unsigned int count, unsigned int edgeCount)
{
	edgeCount = edgeCount;
	nodeCount = count;
}
template <typename T>
Graph<T> ::Graph(unsigned int count) {
	edgeCount = 0;
	nodeCount = count;
}

template <typename T>
Graph<T>::Graph(initializer_list<T> nodesList) {
	nodeCount = nodesList.size();
	edgeCount = 0;
	unsigned int index = 0;
	for (const auto& node : nodesList) {
		nodes.push_back(node);
	}
}
template <typename T>
bool Graph<T>::removeNode(T node) {
	auto it = find(nodes.begin(), nodes.end(), node);
	if (it != nodes.end()) {
		nodes.erase(it);
		adjacencyList.erase(
			remove_if(adjacencyList.begin(), adjacencyList.end(),
				[node](const pair<T, vector<T>>& p) {
					return p.first == node;
				}),
			adjacencyList.end());
		for (auto& pair : adjacencyList) {
			auto& neighbors = pair.second;
			neighbors.erase(
				remove(neighbors.begin(), neighbors.end(), node),
				neighbors.end());
		}
		edges.erase(
			remove_if(edges.begin(), edges.end(),
				[node](const Edge<T>& edge) {
					return edge.node1 == node || edge.node2 == node;
				}),
			edges.end());
		return true;
	}

	return false;
}
template <typename T>
bool Graph<T>::empty() {
	return nodes.empty();
}
