#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <initializer_list>

using namespace std;

template<typename T>
class UnionFind {
private:
    unordered_map<T, T> parent;
    unordered_map<T, int> rank;
    int groups; 

public:

    UnionFind() : groups(0) {}


    UnionFind(pair<T, T> initialPair) : groups(0) {
        unite(initialPair.first, initialPair.second);
    }


    UnionFind(initializer_list<pair<T, T>> initialPairs) : groups(0) {
        for (const auto& pair : initialPairs) {
            unite(pair.first, pair.second);
        }
    }

    void disconnect(T u, T v) {
        T root_u = find(u);
        T root_v = find(v);

        if (root_u == root_v) {
            parent[v] = v; 
            groups++;
        }
    }
    void unite(T u, T v) {
        T root_u = find(u);
        T root_v = find(v);

        if (root_u != root_v) {
      
            if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
            }
            else if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
            }
            else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
            groups--;
        }
    }

  
    T find(T u) {
        if (parent.find(u) == parent.end()) {
            parent[u] = u;
            rank[u] = 0;
            groups++;
        }
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // path compression
        }
        return parent[u];
    }


    int numberOfGroups() {
        return groups;
    }


    void display() {
        unordered_map<T, vector<T>> groupsMap;
        for (const auto& pair : parent) {
            T root = find(pair.first);
            groupsMap[root].push_back(pair.first);
        }

        int groupNumber = 1;
        for (const auto& group : groupsMap) {
            cout << "G" << groupNumber << "={";
            bool first = true;
            for (const auto& element : group.second) {
                if (!first) cout << ",";
                cout << element;
                first = false;
            }
            cout << "}" << endl;
            groupNumber++;
        }
    }


    bool connected(T u, T v) {
        return find(u) == find(v);
    }

    bool exists(T item) {
        return parent.find(item) != parent.end();
    }
};