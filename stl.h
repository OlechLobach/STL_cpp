#ifndef stl_h
#define stl_h
#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;

class Dictionary {
private:
    map<string, string> words;

public:
    void addWord(const string& word, const string& definition) {
        words[word] = definition;
    }

    void removeWord(const string& word) {
        auto it = words.find(word);
        if (it != words.end()) {
            words.erase(it);
        }
    }

    void editDefinition(const string& word, const string& newDefinition) {
        auto it = words.find(word);
        if (it != words.end()) {
            it->second = newDefinition;
        }
    }

    string searchWord(const string& word) const {
        auto it = words.find(word);
        if (it != words.end()) {
            return it->second;
        }
        return "Word not found.";
    }

    void displayAllWords() const {
        cout << "Dictionary:" << endl;
        for (const auto& pair : words) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }

    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& pair : words) {
                file << pair.first << "," << pair.second << endl;
            }
            cout << "Dictionary saved to file." << endl;
        }
        else {
            cerr << "Unable to open file for writing." << endl;
        }
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                size_t pos = line.find(',');
                if (pos != string::npos) {
                    string word = line.substr(0, pos);
                    string definition = line.substr(pos + 1);
                    words[word] = definition;
                }
            }
            cout << "Dictionary loaded from file." << endl;
        }
        else {
            cerr << "Unable to open file for reading." << endl;
        }
    }
};
#endif