#include "HashTable.h"

int HashTable::size() const {
	int sum = 0;
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < table[j].size(); j++) {
			sum += table[j].size();
		}
	}
	return sum;
}

bool HashTable::isEmpty() const {
	int sum = 0;
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < table[j].size(); j++) {
			sum += table[j].size();
			if (sum) return false;
		}
	}
	return true;
}

int HashTable::getHashCode(int key) {
	return key % m_size;
}


void HashTable::printTable() {
	for (int i = 0; i < m_size; i++) {
		if (table[i].size() == 0) continue;
		for (auto const& pair : table[i])
		{
			std::cout << "[INFO] Key: " << pair.first << " Value: " << pair.second << "\n";
		}
	}
}

void HashTable::push(int key, std::string value) {
	int hashValue = getHashCode(key);
	auto& cells = table[hashValue];
	bool keyExists = false;
	for (auto it = cells.begin(); it != cells.end(); it++) {
		if (it->first == key) {
			keyExists = true;
			it->second = value;
			std::cout << "[WARNING] Key exists, Value replaced" << std::endl;
			break;
		}
	}

	if (!keyExists) {
		cells.emplace_back(std::make_pair(key, value));
	}

}

void HashTable::remove(int key) {
	int hashValue = getHashCode(key);
	auto& cells = table[hashValue];
	bool keyExists = false;
	for (auto it = cells.begin(); it != cells.end(); it++) {
		if (it->first == key) {
			keyExists = true;
			cells.erase(it);
			std::cout << "[INFO] Pair removed" << std::endl;
			break;
		}
	}

	if (!keyExists) {
		std::cout << "[WARNING] Key not found, Pair not removed" << std::endl;
	}
}