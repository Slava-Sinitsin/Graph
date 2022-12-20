#pragma once
template <class Name, class Data>
class Vertex
{
private:
	Name name;
	Data data;
	int index;
	bool nameSet, dataSet;
public:
	Vertex(); // Конструктор пустой вершины
	Vertex(Name name, Data data); // Конструктор с параметрами имени и данных
    void setName(Name name_); // Установка имени
	void setData(Data data_); // Установка данных
	Name getName() { return name; } // Получение имени
	Data getData() { return data; } // Получение данных
	bool isNameSet() { return nameSet; } // Проверка установленности имени
	bool isDataSet() { return dataSet; } // Проверка установленности данных
};
template <class Name, class Data>
Vertex <Name, Data>::Vertex() {
	nameSet = false;
	dataSet = false;
	index = -1;
}

template <class Name, class Data>
Vertex <Name, Data>::Vertex(Name name, Data data) {
	this->name = name;
	this->data = data;
	index = -1;
	nameSet = true;
	dataSet = true;
}
template <class Name, class Data>
void Vertex <Name, Data>::setName(Name name_)
{
	this->name = name_;
	index = -1;
	nameSet = true;
}
template <class Name, class Data>
void Vertex <Name, Data>::setData(Data data_)
{
	this->data = data_;
	index = -1;
	dataSet = true;
}
