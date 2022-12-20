#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>
#include <string>
#include "Graph.h"

using namespace std;

template<class Vertex, class EdgeT>
class Task2 {
public:
    ~Task2() = default; // Деструктор

    explicit Task2(Graph<Vertex, EdgeT> *g) { // Конструктор
        Set(g);
    }

    explicit Task2(const Graph<Vertex, EdgeT> &G) {
        if (G.checkDense())
            this->data = new GraphMatrixForm<EdgeT>(*(G.data));
        else
            this->data = new GraphListForm<EdgeT>(*(G.data));
        this->directed = G.directed;
        this->dense = G.dense;
    }

    void Set(Graph<Vertex, EdgeT> *g) { // Связывание графа с задачей
        this->g1 = g;
    }

    Graph<Vertex, EdgeT> *result() { // Решение задачи
        srand((unsigned) time(NULL));
        int size = g1->VertexSize();
        g1->setDirected(false);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (!g1->hasEdge(i, j)) {
                    int val = rand() % 9 + 1;
                    g1->insertEdge(to_string(i), to_string(j));
                    g1->setEdgeWeight(to_string(i), to_string(j), val);
                }
            }
        }
        return g1;
    }

private:
    Graph<Vertex, EdgeT> *g1;
};