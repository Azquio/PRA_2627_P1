#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;
    int max;
    int n;
    static const int MINSIZE = 2;

    void resize(int new_size) {
        T* new_arr = new T[new_size]; 
        int limit = (new_size < n) ? new_size : n;
        for (int i = 0; i < limit; ++i) {
            new_arr[i] = arr[i];      
        }
        delete[] arr;                 
        arr = new_arr;                
        max = new_size;               
    }

public:
    ListArray() {
        max = MINSIZE;
        n = 0;
        arr = new T[max];
    }

    ~ListArray() override {
        delete[] arr;
    }

    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera del intervalo válido.");
        }
        return arr[pos];
    }

    friend std::ostream& operator<<(std::ostream &out, ListArray<T> &list) {
        out << "[";
        for (int i = 0; i < list.n; ++i) {
            out << list.arr[i];
            if (i < list.n - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición fuera de rango.");
        }
        if (n == max) {
            resize(max * 2); 
        }
        for (int i = n; i > pos; --i) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = e;
        n++;
    }

    void append(T e) override {
        insert(n, e); 
    }

    void prepend(T e) override {
        insert(0, e); 
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango.");
        }
        T element_removed = arr[pos];
        for (int i = pos; i < n - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        n--;
        if (n > 0 && n <= max / 4 && (max / 2) >= MINSIZE) {
            resize(max / 2);
        }
        return element_removed;
    }

    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango.");
        }
        return arr[pos];
    }

    int search(T e) override {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == e) {
                return i;
            }
        }
        return -1; 
    }

    bool empty() override {
        return n == 0;
    }

    int size() override {
        return n;
    }
};
