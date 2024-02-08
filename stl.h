#ifndef stl_h
#define stl_h
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class FileHandler {
private:
    string filename;
    ifstream fileStream;

public:
    FileHandler(const string& filename) : filename(filename) {}

    bool openFile() {
        fileStream.open(filename);
        return fileStream.is_open();
    }

    ifstream& getStream() {
        return fileStream;
    }

    void closeFile() {
        if (fileStream.is_open()) {
            fileStream.close();
        }
    }
};

class WordFrequencyCounter {
private:
    map<string, int> wordFrequency;

public:
    void countWordFrequency(istream& inputStream) {
        string word;
        while (inputStream >> word) {
       
            word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());

            transform(word.begin(), word.end(), word.begin(), ::tolower);
        
            wordFrequency[word]++;
        }
    }

    void printWordFrequency() const {
        cout << "Word Frequency:\n";
        for (const auto& pair : wordFrequency) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }

    pair<string, int> getMostFrequentWord() const {
        pair<string, int> mostFrequentWord = { "", 0 };
        for (const auto& pair : wordFrequency) {
            if (pair.second > mostFrequentWord.second) {
                mostFrequentWord = pair;
            }
        }
        return mostFrequentWord;
    }
};

#endif
