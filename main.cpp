
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "HashTables.h"//change to .h
#include "GeneralHashFunctions.h"//change to .h



//TODO
// read in the two test files (names.txt, randoWords.txt) line by line
// lab1 code comes in handy here

//TODO
//use the STL hash as the hashing function to test your HashTable functionality

//TODO
//use the WeakHash() from GeneralHashFunctions as the hashing function to test your HashTable functionality

//TODO
// now using the same testing methods, pick 2 hashing functions from the included open source library "GeneralHashFunctions"

//TODO
// you will test your HashTable functions using one HashTable per file, per hashing function
// so you should have 2Files*4Hashers = 8 HashTable objects
// each HashTable object contains two different unordered maps for storage using different collision resistance methods
// you will use the addToTables() method once to add one entry into both tables
// you will edit the individual add-to-tables functions to add the appropriate functionality



using namespace std;

HashTables read(string fileName);
HashTables readWeak(string fileName);
HashTables readPJW(string fileName);
HashTables readELF(string fileName);

int main(){
  HashTables tableOne = read("names.txt");
  HashTables tableTwo = read("randoWords.txt");
  tableOne.CollisionReport();
  tableTwo.CollisionReport();

  HashTables tableThree = readWeak("names.txt");
  HashTables tableFour = readWeak("randoWords.txt");
  tableThree.CollisionReport();
  tableFour.CollisionReport();

  HashTables tableFive = readPJW("names.txt");
  HashTables tableSix = readPJW("randoWords.txt");
  tableFive.CollisionReport();
  tableSix.CollisionReport();

  HashTables tableSeven = readELF("names.txt");
  HashTables tableEight = readELF("randoWords.txt");
  tableSeven.CollisionReport();
  tableEight.CollisionReport();

  return 0;
}

HashTables read(string fileName) {
	ifstream in;
	string line;
	HashTables table;
	in.open(fileName);
	if (!in.is_open()) {
		cout << "Bad file path" << endl;
		return table;
	}
	while (getline(in, line)) {
		table.addToTables(hash<string>{}(line), line);
	}
	in.close();
	return table;
}

HashTables readWeak(string fileName) {
	ifstream in;
	string line;
	HashTables table;
	in.open(fileName);
	if (!in.is_open()) {
		cout << "Bad file path" << endl;
		return table;
	}
	while (getline(in, line)) {
		table.addToTables(WeakHash(line), line);
	}
	in.close();
	return table;
}

HashTables readPJW(string fileName) {
	ifstream in;
	string line;
	HashTables table;
	in.open(fileName);
	if (!in.is_open()) {
		cout << "Bad file path" << endl;
		return table;
	}
	while (getline(in, line)) {
		table.addToTables(PJWHash(line), line);
	}
	in.close();
	return table;
}

HashTables readELF(string fileName) {
	ifstream in;
	string line;
	HashTables table;
	in.open(fileName);
	if (!in.is_open()) {
		cout << "Bad file path" << endl;
		return table;
	}
	while (getline(in, line)) {
		table.addToTables(ELFHash(line), line);
	}
	in.close();
	return table;
}
