#include <vector>
#include <iostream>
#include <windows.h>
#include <string>




class DynArray {
private:
    int * _data;
    size_t _lenght;
    std::vector<int> _vectorIn;
public:
    DynArray(): _data (new int[0]), _lenght(0), _vectorIn(std::vector<int> (0)) {}
    DynArray(size_t size, std::vector<int> vector) :
            _lenght(size), _vectorIn(vector) {
        _data = new int[_lenght];
        for (int i = 0; i < _lenght; ++i){
            _data[i] = i;
        }
    }

    int* getData() const {
        return _data;
    }
    size_t getLenght() const { return _lenght; };

    std::vector<int> getVectorIn() const { return  _vectorIn;};

    int& operator[] (size_t index) {
        return _data[index];
    }

    int operator[] (size_t index) const {
        return _data[index];
    }

    DynArray& operator=(const DynArray& rhs) {
        if(this != &rhs) {
            *_data = *(rhs._data);
            _lenght = rhs._lenght;
            _vectorIn = std::move(rhs._vectorIn);
        }
        return *this;
    }

    int& operator()(int index) {
        return _vectorIn[index];
    }


    void clearVectorIn() {_vectorIn.clear();};

    ~DynArray() {
        delete [] _data;
        _vectorIn.clear();
    }
};

std::ostream& operator<< (std::ostream & out, const std::vector<int>& right) {
    out << "[";
    for (int elem: right) {
        std::cout << elem << " ";
    }
    out << "]";

    return out;
}

std::ostream& operator<< (std::ostream & out, DynArray& right) {
    out << "Наш DynArray:\n";
    out << "Array: [";
    for(size_t i = 0; i < right.getLenght(); ++i) {
        out << right[i] << " ";
    }

    out << "]\n";

    out << "VectorIn: [";
    for(int j = 0; j < std::size(right.getVectorIn()); ++j) {
        out << right(j) << " ";
    }

    out << "]";

    return out;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::vector<int> v(3,1);
    DynArray foo(5,v);
    std::cout << "Так выглядит созданный DynArray - foo:\n";
    std::cout << foo << std::endl;
    std::cout << "\nПоменяем значения в foo:\n";
    foo[0] = 10;
    foo(0) = 5;
    std::cout << foo << std::endl;
    foo[0] = 3;
    DynArray foo2;
    std::cout << "\nТак выглядит default DynArray:\n";
    std::cout << foo2 << std::endl;
    




    return 0;
    }