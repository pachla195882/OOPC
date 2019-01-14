#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class TKey, class TValue> class Map {
    private:
        TKey *keys;
        TValue *values;
        unsigned int size;
    public:
        Map() {
            keys = nullptr;
            values = nullptr;
            this->size = 0;
        }

        Map(const Map &m) {
            TKey *tempKeys = new TKey[m.size];
            TValue *tempValues = new TValue[m.size];
            
            for(unsigned int i = 0; i < m.size; i++){
                tempKeys[i] = m.keys[i];
                tempValues[i] = m.values[i];
            }

            size = m.size;
            keys = tempKeys;
            values = tempValues;
        }

        ~Map() {
            delete[] keys;
            delete[] values;
        }

        void add(TKey newKey, TValue newValue) {
            if (!find(newKey)) {
                TKey *tempKeys = new TKey[size + 1]();
                TValue *tempValues = new TValue[size + 1]();

                for (unsigned int i = 0; i < size; i++) {
                    tempKeys[i] = keys[i];
                    tempValues[i] = values[i];
                }
                
                tempKeys[size] = newKey;
                tempValues[size] = newValue;

                delete[] keys;
                delete[] values;
                keys = tempKeys;
                values = tempValues;
                size++;
            }
        }

        Map& operator=(const Map& map) {
            if (this == &map) {
                return *this;
            }
            
            if (this->size) {
                delete[] keys;
                delete[] values;
            }

            Map<TKey, TValue> tempMap(map);
            
            this->keys = tempMap.keys;
            this->values = tempMap.values;
            this->size = tempMap.size;

            tempMap.keys = nullptr;                         
            tempMap.values = nullptr;                 

            return *this;
        }

        TValue* find(TKey key) {
            for (unsigned int i = 0; i < size; i++) {
                if (keys[i] == key)
                    return &values[i];
            }
            return nullptr;
        }

        friend ostream & operator<<(ostream& out, const Map& map) {
            for (unsigned int i = 0; i < map.size; i++) {
                cout << map.keys[i] << "\t" << map.values[i] << endl;
            }
            return out;
        }
};

class Employee {
    public:
        string name;
        string position;
        unsigned int age;

        Employee() { }

        Employee(string inputName, string inputPosition, unsigned int inputAge) {
            name = inputName;
            position = inputPosition;
            age = inputAge;
        }

        friend ostream & operator<<(ostream& out, const Employee& emp) {
            out << "Name: " << emp.name << "\tPosition: " << emp.position << "\tAge: " << emp.age;
            return out;
        }
};

class Book {
    public:
        string author;
        string category;
        unsigned int noOfPages;
        bool isAvailable;

        Book() { }

        Book(string a, string c, unsigned int p, bool s): author(a), category(c), noOfPages(p), isAvailable(s) {}

        void lendBook() {
            if (isAvailable == true)
                isAvailable = false;
            else
                cout << "Book is borrowed\n" << endl;
        }

        void returnBook() {
            if (isAvailable == true)
                isAvailable = false;
            else
                cout << "Book is available\n" << endl;
        }

        friend ostream & operator<<(ostream& out, const Book& book) {
            out << "Author: " << book.author << "\tCategory: " << book.category << "\tPages: " << book.noOfPages << "\tStatus: " << (book.isAvailable ? "available" : "not available");
            return out;
        }
};
