#include "dnadb.h"
#include <random>
#include <vector>
#include <iostream>

using namespace std;
using namespace dna_db_config;  // Access the constants defined in the namespace for DNA database configuration

// Enum to specify types of random distributions
enum RANDOM { UNIFORMINT, UNIFORMREAL, NORMAL };

// Class to generate random numbers based on specified distributions
class Random {
public:
    // Constructor initializing the random generator with a range and distribution type
    Random(int min, int max, RANDOM type = UNIFORMINT, int mean = 50, int stdev = 20)
    : m_min(min), m_max(max), m_type(type) {
        m_generator = std::mt19937(10);  // Fixed seed for reproducibility during debugging
        switch(type) {
            case NORMAL:
                m_normdist = std::normal_distribution<>(mean, stdev);  // Normal distribution for statistical simulations
                break;
            case UNIFORMINT:
                m_unidist = std::uniform_int_distribution<>(min, max);  // Uniform integer distribution
                break;
            case UNIFORMREAL:
                m_uniReal = std::uniform_real_distribution<double>((double)min, (double)max);  // Uniform real number distribution
                break;
        }
    }

    // Set a new seed for generating non-reproducible results
    void setSeed(int seedNum) {
        m_generator.seed(seedNum);
    }

    // Generate and return a random integer within the range
    int getRandNum() {
        if (m_type == NORMAL) {
            int result;
            do {
                result = m_normdist(m_generator);
            } while (result < m_min || result > m_max);  // Ensure the result is within the specified bounds
            return result;
        } else if (m_type == UNIFORMINT) {
            return m_unidist(m_generator);
        }
        return 0;  // Default case should not occur, provided for safety
    }

    // Generate and return a random real number, rounded to two decimal places
    double getRealRandNum() {
        return std::floor(m_uniReal(m_generator) * 100.0) / 100.0;
    }

private:
    int m_min, m_max;
    RANDOM m_type;
    std::mt19937 m_generator;
    std::normal_distribution<> m_normdist;
    std::uniform_int_distribution<> m_unidist;
    std::uniform_real_distribution<double> m_uniReal;
};

int main() {
    vector<DNA> dataList;  // Vector to store DNA data
    Random RndLocation(MINLOCID, MAXLOCID);  // Random generator for location IDs within specified range
    DnaDb dnadb(MINPRIME, hashCode); // Initialize the DNA database with a hash function and minimum prime capacity
    bool result = true;  // Flag to track if all operations succeed

    cout << "Initial dump:" << endl;
    dnadb.dump();  // Output the current state of the database

    // Insert DNA objects into the database
    for (int i = 0; i < 50; i++) {
        DNA dataObj = DNA(sequencer(5, i), RndLocation.getRandNum());  // Create a DNA object with a random sequence and location
        cout << "Attempting to insert DNA: " << dataObj << endl;
        if (dnadb.insert(dataObj)) {
            cout << "Inserted at index: " << (hashCode(dataObj.getSequence()) % dnadb.getCapacity()) << " -> " << dataObj << endl;
            cout << "Insertion successful." << endl;
            dataList.push_back(dataObj);  // Store the DNA object for later verification
        } else {
            cout << "Insertion failed." << endl;
        }
    }

    cout << "\nDump after insertion:" << endl;
    dnadb.dump();  // Output the state of the database after insertion

    // Verify the integrity of data in the database
    bool allValid = true; // Flag to check the validity of all entries
    for (const auto& it : dataList) {
        DNA retrievedDNA = dnadb.getDNA(it.getSequence(), it.getLocId());
        if (!retrievedDNA.isValid()) {  // Check if the retrieved DNA is valid
            cout << "Missing DNA: " << it << endl;
            allValid = false;
        }
    }
    cout << (allValid ? "All data points exist in the DnaDb!\n" : "Some data points are missing in the DnaDb\n");

    // Attempt to remove the DNA objects
    for (const auto& it : dataList) {
        if (dnadb.remove(it)) {
            cout << "Removal successful: " << it << endl;
        } else {
            cout << "Removal failed: " << it << endl;
        }
    }

    cout << "\nDump after removal:" << endl;
    dnadb.dump();  // Output the state of the database after removal

    return 0;
}
