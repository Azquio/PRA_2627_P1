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

    public:
         ListArray(){
                arr = new T(MINSIZE);
                max = MINSIZE;
                n = 0;
         };

         ~ListArray() override{
                delete[] arr;
         };

         T operator[](int pos){
                 if(pos < 0 || pos > size()-1){
                        throw std::out_of_range
                 };
                 return arr[pos];
         }

};
~                                                                                                                                                                                             
~           
