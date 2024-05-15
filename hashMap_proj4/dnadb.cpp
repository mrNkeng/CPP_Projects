#include "dnadb.h"
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <random>
#include <cmath>

using namespace dna_db_config;

// Definitions for DNA static members
const DNA DNA::DELETED = DNA("DELETED", -1);

// Hash Table Constructor
DnaDb::DnaDb(int size, std::function<unsigned int(const std::string&)> hashFunction)
    : m_currentCap(size), hashFunction(hashFunction), m_currentTable(size, DNA()), m_currentSize(0), m_currNumDeleted(0) {}

// Inserts a DNA record into the database
bool DnaDb::insert(const DNA& data) {
    if (lambda() > 0.7) {
        rehash();
    }
    int index = hashFunction(data.getSequence()) % m_currentCap;
    int startIndex = index;
    while (m_currentTable[index].isValid() && m_currentTable[index] != DNA::DELETED) {
        if (m_currentTable[index] == data) {
            return false;
        }
        index = (index + 1) % m_currentCap;
        if (index == startIndex) {
            return false;
        }
    }
    if (!m_currentTable[index].isValid() || m_currentTable[index] == DNA::DELETED) {
        if (m_currentTable[index] == DNA::DELETED) {
            m_currNumDeleted--;
        }
        m_currentTable[index] = data;
        m_currentSize++;
        return true;
    }
    return false;
}

// Retrieves a DNA record from the database
DNA DnaDb::getDNA(const std::string& sequence, int locId) const {
    int index = hashFunction(sequence) % m_currentCap;
    int startIndex = index;
    while (m_currentTable[index].isValid() || m_currentTable[index] == DNA::DELETED) {
        if (m_currentTable[index].getSequence() == sequence && m_currentTable[index].getLocId() == locId) {
            return m_currentTable[index];
        }
        index = (index + 1) % m_currentCap;
        if (index == startIndex) {
            break;
        }
    }
    return DNA();
}

// Removes a DNA record from the database
bool DnaDb::remove(const DNA& data) {
    int index = hashFunction(data.getSequence()) % m_currentCap;
    int startIndex = index;
    while (m_currentTable[index].isValid() || m_currentTable[index] == DNA::DELETED) {
        if (m_currentTable[index] == data) {
            m_currentTable[index] = DNA::DELETED;
            m_currentSize--;
            m_currNumDeleted++;
            return true;
        }
        index = (index + 1) % m_currentCap;
        if (index == startIndex) {
            break;
        }
    }
    return false;
}

// Dumps the content of the hash table
void DnaDb::dump() const {
    for (int i = 0; i < m_currentCap; ++i) {
        if (m_currentTable[i].isValid()) {
            std::cout << "[" << i << "] : " << m_currentTable[i] << std::endl;
        } else {
            std::cout << "[" << i << "] : " << (m_currentTable[i] == DNA::DELETED ? "DELETED" : "EMPTY") << std::endl;
        }
    }
}

// Rehashes the hash table when the load factor exceeds a threshold
void DnaDb::rehash() {
    int oldCap = m_currentCap;
    std::vector<DNA> oldTable = m_currentTable;

    m_currentCap = findNextPrime(oldCap * 2);
    m_currentTable = std::vector<DNA>(m_currentCap, DNA());
    m_currentSize = 0;
    m_currNumDeleted = 0;

    for (const auto& dna : oldTable) {
        if (dna.isValid()) {
            insert(dna);
        }
    }
}

// Calculates the load factor of the hash table
float DnaDb::lambda() const {
    return static_cast<float>(m_currentSize) / m_currentCap;
}

// Calculates the ratio of deleted elements in the hash table
float DnaDb::deletedRatio() const {
    return static_cast<float>(m_currNumDeleted) / m_currentSize;
}

// Finds the next prime number greater than a given number
int DnaDb::findNextPrime(int num) const {
    while (true) {
        bool isPrime = true;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            return num;
        }
        ++num;
    }
}

// Hash function
unsigned int hashCode(const std::string& str) {
    unsigned int hashValue = 0;
    const unsigned int p = 31;
    for (char c : str) {
        hashValue = p * hashValue + c;
    }
    return hashValue;
}

// Sequencer function
std::string sequencer(int size, int seedNum) {
    std::string sequence = "";
    srand(seedNum);
    for (int i = 0; i < size; ++i) {
        sequence += dna_db_config::ALPHA[rand() % dna_db_config::ALPHA_SIZE];
    }
    return sequence;
}
