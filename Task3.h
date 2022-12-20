#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>
#include "Graph.h"


using namespace std;

template<class Vertex, class EdgeT>
class Task3 {
public:
    ~Task3() = default;; // Деструктор

    explicit Task3(Graph<Vertex, EdgeT> *g) { // Конструктор
        Set(g);
    }

    explicit Task3(const Graph<Vertex, EdgeT> &G) {
        if (G.checkDense())
            this->data = new GraphMatrixForm<EdgeT>(*(G.data));
        else
            this->data = new GraphListForm<EdgeT>(*(G.data));
        this->directed = G.directed;
        this->dense = G.dense;
    }

    void Set(Graph<Vertex, EdgeT> *g) { // Установка графа
        if (g->Directed()) cout << " Wrong Graph " << endl;
        this->g1 = g;
    }

    void Restart() {
        result();
    }

    void result(int vertex) { // Получение результата
        int weightOstTree = 0;
        int size = g1->VertexSize();
        auto *keys = new long long[size];
        int *AncestorsEdge = new int[size]; // Предки каждой вершины
        int *q = new int[size];
        for (unsigned i = 0; i < size; ++i) {
            keys[i] = 1000000000000000000;
            AncestorsEdge[i] = -1;
            q[i] = 1;
        }
        keys[vertex] = 0;
        int n = size;
        while (n != 0) {
            int minVertex = -1;
            for (unsigned i = 0; i < size; ++i) {
                if (q[i] == 1 && (minVertex == -1 || keys[i] < keys[minVertex])) {
                    minVertex = i;
                }
            }
            for (unsigned i = 0; i < size; ++i) {
                if (g1->hasEdge(minVertex, i)) {
                    string strMinVertex = to_string(minVertex);
                    string strI = to_string(i);
                    if (i != minVertex && q[i] == 1 && keys[i] > g1->readEdgeWeight(strMinVertex, strI)) {
                        AncestorsEdge[i] = minVertex;
                        keys[i] = g1->readEdgeWeight(strMinVertex, strI);
                        weightOstTree += g1->readEdgeWeight(strMinVertex, strI);
                    }
                }
            }
            --n;
            q[minVertex] = 0;
        }
        for (int i = 0; i < size; i++) {
            if (AncestorsEdge[i] != -1) {
                cout << "Вершина " << i << " " << " Вторая вершина " << " " << AncestorsEdge[i] << endl;
            }
        }
    }

private:
    Graph<Vertex, EdgeT> *g1;
};