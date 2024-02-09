#include"stl.h"

int main() {
    Dictionary dictionary;

    dictionary.addWord("apple", "a round fruit with red or green skin");
    dictionary.addWord("banana", "a long curved fruit with a yellow skin");
    dictionary.addWord("cat", "a small domesticated carnivorous mammal");

    dictionary.displayAllWords();

    string searchWord;
    cout << "Enter a word to search: ";
    cin >> searchWord;
    cout << dictionary.searchWord(searchWord) << endl;

    string editWord, newDefinition;
    cout << "Enter a word to edit: ";
    cin >> editWord;
    cout << "Enter the new definition: ";
    cin.ignore(); 
    getline(cin, newDefinition);
    dictionary.editDefinition(editWord, newDefinition);

    string removeWord;
    cout << "Enter a word to remove: ";
    cin >> removeWord;
    dictionary.removeWord(removeWord);

    dictionary.saveToFile("dictionary.txt");

    Dictionary newDictionary;
    newDictionary.loadFromFile("dictionary.txt");
    newDictionary.displayAllWords();

    return 0;
}