#pragma once
#include <type_traits>
#include <iostream>
template<typename T>
class CList {
    static_assert(std::is_default_constructible_v<T>, "T must be default constructible");

public:
    /*Base list expects compacity setups full list with this being the compacity*/
    CList(int compacity) : capacity(compacity), size(0){
        list = new T[capacity];
        if (list == nullptr) {
            this->capacity = 0;
        }
    }
    /*Assumes the compacity is 1*/
    CList() : CList(2) {
    }
    void add(T data) {
        extend();
        if (size < capacity) {
            list[size++] = data;
        }
        else {

        }
    }
    int getSize() {
        return size;
    }
    int getCompacity() {
        
        return this->compacity;
    }
    void clear() {
    }
    void Cleanup() {
        for (int i = 0; i < this->size; i++) {
            free(&this->list[i]);
        }
        free(&this->list);
    }
    T* getList() {
        return this->list;
    }
    void replace(int index, T newData) {
        if (index > this->size || index < 0) {
            return;
        }
        this->list[index] = newData;
    }
private:
    void extend() {
        if (capacity <= size) {
            T* newList = new T[capacity * 2]();
            if (newList != nullptr) {
                std::copy(list, list + size, newList);
                delete[] list;
                list = newList;
                capacity *= 2;
            }
        }
    }
    T* list = nullptr;
    int size = 0;
    int capacity = 0;
};