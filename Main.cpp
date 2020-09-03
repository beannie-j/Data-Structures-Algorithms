#include <iostream>
#include "HashTable.h"

int main(void)
{
	HashTable hashTable;

	if (hashTable.isEmpty()) {
		std::cout << "Hash Table is currently empty." << std::endl;
	}
	else
		std::cout << "Hash table is currently not empty" << std::endl;


	hashTable.push(905, "Jeannie");
	hashTable.push(201, "Jim");
	hashTable.push(202, "Jem");
	hashTable.push(100, "Rebecca");
	hashTable.push(200, "Bo");
	hashTable.push(300, "Susie");
	hashTable.push(505, "Taylor");
	
	hashTable.printTable();

	hashTable.remove(505);
	hashTable.remove(200);
	
	hashTable.printTable();
}