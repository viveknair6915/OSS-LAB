#include <bits/stdc++.h>
using namespace std;

string toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

string removePunctuation(const string& str) {
    string result;
    for (char ch : str) {
        if (!ispunct(ch)) {
            result += ch;
        }
    }
    return result;
}

int main() {
    string paragraph;

    cout << "Enter a paragraph: ";
    getline(cin, paragraph);
    unordered_map<string, int> wordCount;

    stringstream ss(paragraph);
    string word;

    while (ss >> word) {
        word = removePunctuation(word);
        word = toLowerCase(word);
        if (!word.empty()) {
            ++wordCount[word];
        }
    }

    cout << "Word frequencies:" << endl;
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
