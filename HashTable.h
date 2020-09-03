#pragma once
#include <iostream>
#include <list>
#include <string>
#include <algorithm>

class HashTable {
private:
	static constexpr size_t m_size = 10;
	std::list<std::pair<int, std::string>> table[m_size];

public:

	~HashTable()
	{
	}

	int size() const;
	bool isEmpty() const;
	int getHashCode(int key);
	std::string getValueAtIndex(int index);
	void printTable();

	void push(int key, std::string value);
	void remove(int key);
	std::string find(int key);
	int convertToIndex(int hashCode);
};
