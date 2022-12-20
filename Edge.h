#pragma once
template <class Vertex, class Data>
class Edge {
private:
	Vertex* v1, * v2;
	int weight = 1;
	Data data;
	bool weightSet, dataSet;
public:
	Edge(Vertex*, Vertex*); // Ребро с неустановленным весом и данными
	Edge(Vertex*, Vertex*, int); // Ребро с установленным весом
	Edge(Vertex*, Vertex*, int, Data); // Ребро с установленными весом и данными
	void setWeight(int weight) { this->weight = weight; weightSet = true; } // Установка веса
	void setData(Data data) { this->data = data; dataSet = true; } // Установка данных
	int getWeight() { return weight; } // Получение веса
	Data getData() { return data; } // Получение данных
	bool isWeightSet() { return weightSet; } // Установленность веса
	bool isDataSet() { return dataSet; } // Установленность данных
	Vertex* V1() { return v1; } // Получение дескриптора исходящей вершины
	Vertex* V2() { return v2; } // Получение дескриптора входящей вершины
};
template <class Vertex, class Data>
Edge<Vertex, Data>::Edge(Vertex* v1, Vertex* v2) {
	this->v1 = v1;
	this->v2 = v2;
	weightSet = false;
	dataSet = false;
	weight = 0;
}
template <class Vertex, class Data>
Edge<Vertex, Data>::Edge(Vertex* v1, Vertex* v2, int weight) {
	this->v1 = v1;
	this->v2 = v2;
	weightSet = true;
	dataSet = false;
	this->weight = weight;
}
template <class Vertex, class Data>
Edge<Vertex, Data>::Edge(Vertex* v1, Vertex* v2, int weight, Data data) {
	this->v1 = v1;
	this->v2 = v2;
	weightSet = true;
	dataSet = true;
	this->weight = weight;
	this->data = data;
}
