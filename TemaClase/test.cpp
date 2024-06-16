#include "pch.h"
#include "Graph.h"
#include "UndirectedGraph.h"
#include "AVLTree.h"
#include "DirectedGraph.h"
#include "Trie.h"
#include "UnionFind.h"
#include "Trie.cpp"
//UndirectedGraph Tests
TEST(UndirectedGraphTest, AddEdgeAndCheckConnected) {
    UndirectedGraph<int> graph(5);
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);

    EXPECT_TRUE(graph.connected());
}

TEST(UndirectedGraphTest, CheckAcyclicAndComplete) {
    UndirectedGraph<int> graph(4);
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);

    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    EXPECT_TRUE(graph.acyclic());

    graph.addEdge(1, 4);  // Adding this edge creates a cycle

    EXPECT_FALSE(graph.acyclic());
    EXPECT_FALSE(graph.complete());
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    EXPECT_TRUE(graph.complete());
}

TEST(UndirectedGraphTest, GetShortestPath) {
    UndirectedGraph<int> graph(5);
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);

    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.addEdge(1, 3);
    graph.addEdge(3, 5);
    vector<int> nonexpectedPath = { 1, 2, 3, 4, 5 };
    vector<int> expectedPath = { 1,  3,  5 };
    EXPECT_NE(graph.getShortestPath(1, 5), nonexpectedPath);
    EXPECT_EQ(graph.getShortestPath(1, 5), expectedPath);
}

TEST(UndirectedGraphTest, GetCheapestPath) {
    UndirectedGraph<int> graph(5);
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);

    graph.addEdge(1, 2, 1);
    graph.addEdge(2, 3, 2);
    graph.addEdge(3, 4, 1);
    graph.addEdge(4, 5, 3);
    graph.addEdge(1, 3, 4);  // Direct but more costly

    vector<int> expectedPath = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(graph.getCheapestPath(1, 5), expectedPath);
}

TEST(UndirectedGraphTest, RemoveEdgeAndCheckConnected) {
    UndirectedGraph<int> graph(5);
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);

    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);

    EXPECT_TRUE(graph.connected());

    graph.removeEdge(3, 4);

    EXPECT_FALSE(graph.connected());
}


//DirectedGraph Tests

TEST(DirectedGraphTest, AddEdgeAndConnected) {
    DirectedGraph<int> graph(5);
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);

    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);

    EXPECT_FALSE(graph.connected()); //In DirectedGraph connected means strongly connected

    graph.addEdge(5, 1); //Now it should work
    EXPECT_TRUE(graph.connected());
}

TEST(DirectedGraphTest, AcyclicAndComplete) {
    DirectedGraph<int> graph(5);
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);

    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);

    EXPECT_TRUE(graph.acyclic());

    graph.addEdge(5, 1);  // Adding a cycle

    EXPECT_FALSE(graph.acyclic());
    EXPECT_FALSE(graph.complete());
}


TEST(DirectedGraphTest, GetShortestPath) {
    DirectedGraph<int> graph(5);
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);

    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);

    vector<int> expectedPath = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(graph.getShortestPath(1, 5), expectedPath);

    EXPECT_TRUE(graph.getShortestPath(5, 1).empty());  // No path from 5 to 1 in our graph
}


TEST(DirectedGraphTest, GetCheapestPath) {
    DirectedGraph<int> graph(5);
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);

    graph.addEdge(1, 2, 1);
    graph.addEdge(2, 3, 2);
    graph.addEdge(3, 4, 1);
    graph.addEdge(4, 5, 3);
    graph.addEdge(1, 5, 10);

    vector<int> expectedPath = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(graph.getCheapestPath(1, 5), expectedPath);

    EXPECT_TRUE(graph.getCheapestPath(5, 1).empty());  // No path from 5 to 1 in directed graph
}

TEST(DirectedGraphTest, RemoveEdge) {
    DirectedGraph<int> graph(5);
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);

    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 1);
    graph.addEdge(4, 5);
    graph.addEdge(5, 1);
    EXPECT_TRUE(graph.connected());
    graph.removeEdge(4, 1);
    EXPECT_TRUE(graph.connected());
    graph.removeEdge(5, 1);
    EXPECT_FALSE(graph.connected());
}


//AVLTree Tests
TEST(AVLTreeTest, InsertAndCheckExistence) {
    AVLTree<int> tree;
    tree.push(10);
    tree.push(20);
    tree.push(5);
    tree.push(15);

    EXPECT_TRUE(tree.has(10));
    EXPECT_TRUE(tree.has(20));
    EXPECT_TRUE(tree.has(5));
    EXPECT_TRUE(tree.has(15));
    EXPECT_FALSE(tree.has(2));
}
TEST(AVLTreeTest, CheckHeightAfterInsertions) {
    AVLTree<int> tree;
    tree.push(10);
    tree.push(20);
    tree.push(5);
    tree.push(15);

    EXPECT_EQ(tree.getHeight(), 3);
}
TEST(AVLTreeTest, CheckBalanceAfterInsertions) {
    AVLTree<int> tree;
    tree.push(10);
    tree.push(20);
    tree.push(5);
    tree.push(15);

    EXPECT_EQ(tree.getBalance(), -1);
}


TEST(AVLTreeTest, InorderTraversal) {
    AVLTree<int> tree;
    tree.push(10);
    tree.push(20);
    tree.push(5);
    tree.push(15);

    vector<int> expected = { 5, 10, 15, 20 };
    EXPECT_EQ(tree.inorder(), expected);
}

TEST(AVLTreeTest, EmptyAfterFullRemoval) {
    AVLTree<int> tree;
    tree.push(10);
    tree.push(20);
    tree.push(5);
    tree.push(15);
    EXPECT_FALSE(tree.empty());
    tree.removeAll();
    EXPECT_TRUE(tree.empty());
}

//Trie Tests

TEST(TrieTest, RemoveWordAndSearch) {
    Trie trie;
    trie.push("apple");
    trie.push("banana");
    trie.push("orange");

    trie.remove("banana");

    EXPECT_FALSE(trie.exists("banana"));
    EXPECT_TRUE(trie.exists("apple"));
    EXPECT_TRUE(trie.exists("orange"));
}
TEST(TrieTest, IsLeaf) {
    Trie trie;
    trie.push("apple");

    EXPECT_TRUE(trie.isLeaf("apple"));
    EXPECT_FALSE(trie.isLeaf("app"));
}
TEST(TrieTest, LongestCommonPrefix) {
    Trie trie;
    trie.push("apple");
    trie.push("apricot");
    trie.push("ape");

    EXPECT_EQ(trie.longestCommonPrefix(), "ap");
}
TEST(TrieTest, CountWordsStartingWithPrefix) {
    Trie trie;
    trie.push("apple");
    trie.push("apricot");
    trie.push("ape");
    trie.push("banana");

    EXPECT_EQ(trie.countWordsStartingWith("ap"), 3);
    EXPECT_EQ(trie.countWordsStartingWith("ban"), 1);
    EXPECT_EQ(trie.countWordsStartingWith("c"), 0);
}
TEST(TrieTest, ExistsPrefix) {
    Trie trie;
    trie.push("apple");
    trie.push("apricot");
    trie.push("ape");
    trie.push("banana");

    EXPECT_TRUE(trie.existsPrefix("ap"));
    EXPECT_FALSE(trie.existsPrefix("bano"));
}


//UnionFind Tests
TEST(UnionFindTest, BasicUnionAndFind) {
    UnionFind<int> uf;
    uf.unite(1, 2);
    uf.unite(3, 4);
    EXPECT_TRUE(uf.connected(1, 2));
    EXPECT_TRUE(uf.connected(3, 4));
    EXPECT_FALSE(uf.connected(1, 3));
}
TEST(UnionFindTest, InitializationWithPairs) {
    UnionFind<int> uf({ {1, 2}, {3, 4}, {5, 6} });
    EXPECT_TRUE(uf.connected(1, 2));
    EXPECT_TRUE(uf.connected(3, 4));
    EXPECT_TRUE(uf.connected(5, 6));
    EXPECT_FALSE(uf.connected(1, 3));
}
TEST(UnionFindTest, DisconnectElements) {
    UnionFind<int> uf;
    uf.unite(1, 2);
    uf.unite(3, 4);
    uf.disconnect(1, 2);
    EXPECT_FALSE(uf.connected(1, 2));
}
TEST(UnionFindTest, NumberOfGroups) {
    UnionFind<int> uf;
    uf.unite(1, 2);
    uf.unite(3, 4);
    uf.unite(5, 6);
    EXPECT_EQ(uf.numberOfGroups(), 3);
}
TEST(UnionFindTest, ExistsElement) {
    UnionFind<int> uf;
    uf.unite(1, 2);
    uf.unite(3, 4);
    EXPECT_TRUE(uf.exists(1));
    EXPECT_FALSE(uf.exists(5));
}