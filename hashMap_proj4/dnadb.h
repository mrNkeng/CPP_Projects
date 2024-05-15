#ifndef DNADB_H
#define DNADB_H

#include <string>
#include <vector>
#include <iostream>
#include <functional>

namespace dna_db_config {
    const int ALPHA_SIZE = 4; // For DNA (A, C, G, T)
    const std::string ALPHA = "ACGT";
    const int MINLOCID = 1000;
    const int MAXLOCID = 9999;
    const int MINPRIME = 101;
    typedef std::function<unsigned int(const std::string&)> hash_fn; // Add this line
}

// DNA Class Definition
class DNA {
public:
    static const DNA DELETED;
    DNA() : sequence(""), locId(-1), isActive(false) {}
    DNA(std::string seq, int loc) : sequence(seq), locId(loc), isActive(true) {}
    std::string getSequence() const { return sequence; }
    int getLocId() const { return locId; }
    bool isValid() const { return !sequence.empty() && isActive; }
    friend std::ostream& operator<<(std::ostream& os, const DNA& dna) {
        os << dna.sequence << " (Location ID " << dna.locId << ")";
        return os;
    }
    bool operator==(const DNA& other) const {
        return sequence == other.sequence && locId == other.locId;
    }
    bool operator!=(const DNA& other) const {
        return !(*this == other);
    }
private:
    std::string sequence;
    int locId;
    bool isActive;
};

// DNA Database Class Definition
class DnaDb {
public:
    DnaDb(int size, dna_db_config::hash_fn hashFunction);
    bool insert(const DNA& data);
    DNA getDNA(const std::string& sequence, int locId) const;
    bool remove(const DNA& data);
    void dump() const;
    int getCapacity() const { return m_currentCap; } // Add this line
private:
    void rehash();
    float lambda() const;
    float deletedRatio() const;
    int findNextPrime(int num) const;

    std::vector<DNA> m_currentTable;
    int m_currentCap;
    int m_currentSize;
    int m_currNumDeleted;
    dna_db_config::hash_fn hashFunction;
};

// Function prototypes for sequencer and hashCode
unsigned int hashCode(const std::string& str);
std::string sequencer(int size, int seedNum);

#endif
