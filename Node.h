#ifndef NODE_H
#define NODE_H

#include <ostream>

template <typename T>
class Node {
public:
     //Atributos públicos
  T data;
	Node<T>* next;

    // Constructor con valor por defecto para next
    	Node(T data, Node<T>* next = nullptr) : data(data), next(next) {}

    // Sobrecarga del operador << para imprimir el atributo data
    	friend std::ostream& operator<<(std::ostream &out, const Node<T> &node) {
        	out << node.data;
        	return out;
    }
};

#endif
