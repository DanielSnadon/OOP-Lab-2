#include "three.h"
#include <cstddef>
#include <iostream>

Three::Three() : _array{nullptr}, _size(0)
{
    std::cout << "Использован обычный конструктор" << std::endl;
}

Three::Three(const size_t &n, unsigned char t) : _size{n}
{
    if (n < 1) {
        throw std::invalid_argument("Размер не может быть отрицательным или равным нулю.");
    }

    if (t != 0 && t != 1 && t != 2) {
        throw std::invalid_argument("Класс Three предназначен для работы с троичными числами.");
    }

    std::cout << "Использован заполняющий конструктор" << std::endl;
    
    _array = new unsigned char[n];
    for (size_t i {0}; i < n; ++i) {
        _array[i] = '0' + t;
    }
}

Three::Three(const std::initializer_list<unsigned char> &t)
{
    if (t.size() == 0) {
        throw std::invalid_argument("initializer_list не может быть пустым.");
    }

    std::cout << "Использован initializer_list конструктор" << std::endl;
    _array = new unsigned char[t.size()];
    _size = t.size();

    size_t i = 0;
    for (auto curr = t.end(); curr != t.begin(); ) {
         --curr;
        if (*curr != '0' && *curr != '1' && *curr != '2') {
            delete [] _array;
            throw std::invalid_argument("Класс Three предназначен для работы с троичными числами.");
        }

        _array[i++] = *curr;
    }
    
}

Three::Three(const std::string &t)
{
    if (t.empty()) {
        throw std::invalid_argument("Строка не может быть пустой.");
    }

    std::cout << "Использован string конструктор" << std::endl;
    _array = new unsigned char[t.size()];
    _size = t.size();

    for (size_t i{0}; i < _size; ++i) {
        unsigned char c = t[_size - 1 - i];
        if (c != '0' && c != '1' && c != '2') {
            delete [] _array;
            throw std::invalid_argument("Класс Three предназначен для работы с троичными числами.");
        }
        _array[i] = c;
    }
}

Three::Three(const Three &other)
{
    std::cout << "Использован копирующий конструктор" << std::endl;
    _size = other._size;
    _array = new unsigned char[_size];

    for (size_t i{0}; i < _size; ++i) {
        _array[i] = other._array[i];
    }
}

Three::Three(Three &&other) noexcept
{
    std::cout << "Использован перемещающий конструктор" << std::endl;
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}

std::ostream &Three::print(std::ostream &os) const
{
    for (size_t i = 0; i < _size; ++i)
        os << _array[_size - 1 - i];
    return os;
}

Three::~Three() noexcept {
    std::cout << "Использован деструктор" << std::endl;
    delete[] _array;
}

Three Three::add(const Three& other)
{
    size_t result_size = std::max(_size, other._size);
    unsigned char* result_array = new unsigned char[result_size + 1];

    int bonus{0};
    size_t i{0};
    while (i < result_size) {
        int first = (i >= _size) ? 0 : _array[i] - '0';
        int second = (i >= other._size) ? 0 : other._array[i] - '0';

        int res = first + second + bonus;
        result_array[i] = '0' + static_cast<unsigned char>(res % 3);
        bonus = res / 3;

        i++;
    }

    if (bonus) {
        result_array[i] = '0' + static_cast<unsigned char>(bonus);
        result_size++;
    }

    Three result;
    result._size = result_size;
    result._array = result_array;

    return result;
}

Three Three::subtract(const Three& other)
{
    if (this->lessThan(other)) {
        throw std::invalid_argument("Результатом вычитания будет отрицательное число.");
    }

    size_t result_size = std::max(_size, other._size);
    unsigned char* result_array = new unsigned char[result_size + 1];

    int bonus{0};
    size_t i{0};
    while (i < result_size) {
        int first = (i >= _size) ? 0 : _array[i] - '0';
        int second = (i >= other._size) ? 0 : other._array[i] - '0';

        int sub = first - second - bonus;

        if (sub < 0) {
            sub += 3;
            bonus = 1;
        } else {
            bonus = 0;
        }

        result_array[i] = '0' + static_cast<unsigned char>(sub);
        
        i++;
    }

    while (result_array[result_size - 1] == '0') {
        --result_size;
    }

    Three result;
    result._size = result_size;
    result._array = result_array;

    return result;
}

bool Three::equals(const Three& other) {
    if (_size != other._size) {
        return false;
    }

    for (size_t i{0}; i < _size; i++) {
        if (_array[i] != other._array[i]) {
            return false;
        }
    }

    return true;
}

bool Three::greaterThan(const Three& other) const {
    if (_size > other._size) {
        return true;
    }
    if (_size < other._size) {
        return false;
    }

    for (size_t i = _size; i > 0; --i) {
        if (_array[i - 1] > other._array[i - 1]) {
            return true;
        }
        if (_array[i - 1] < other._array[i - 1]) {
            return false;
        }
    }

    return false;
}

bool Three::lessThan(const Three& other) const {
    if (_size < other._size) {
        return true;
    }
    if (_size > other._size) {
        return false;
    }

    for (size_t i = _size; i > 0; --i) {
        if (_array[i - 1] < other._array[i - 1]) {
            return true;
        }
        if (_array[i - 1] > other._array[i - 1]) {
            return false;
        }
    }

    return false;
}