#include"stl.h"
int main() {
    string filename = "input.txt";

   
    FileHandler fileHandler(filename);
    if (!fileHandler.openFile()) {
        cerr << "Error: Unable to open file '" << filename << "'" << endl;
        return 1;
    }

    WordFrequencyCounter counter;

    counter.countWordFrequency(fileHandler.getStream());

    counter.printWordFrequency();

    auto mostFrequentWord = counter.getMostFrequentWord();
    cout << "Most frequent word: " << mostFrequentWord.first << " (Frequency: " << mostFrequentWord.second << ")" << endl;

    fileHandler.closeFile();

    return 0;
}