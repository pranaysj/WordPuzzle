#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to print the word with correct letters in white and first/last letters in green
void printWord(const vector<bool>& correct, const string& word) {
    system("cls");
    for (int i = 0; i < word.size(); i++) {
        if (i == 0 || i == word.size() - 1) {
            cout << "\033[37m" << word[i] << "\033[0m"; // Green color for first and last letters
        }
        else if (correct[i]) {
            cout << "\033[32m" << word[i] << "\033[0m"; // White color for correct letters
            
        }
        else {
            cout << "_";
        }
        
        cout << " ";
    }
    cout << endl;
}

int main() {
    string word = "Apple";
    vector<bool> correct(word.size(), false);
    correct[0] = true; // First letter is always correct
    correct[word.size() - 1] = true; // Last letter is always correct

    int index = 1;
    while (true) {

        printWord(correct, word);
        if (index == word.size() - 1) {
            break;
        }
        cout << "Enter the next letter: ";
        char letter;
        cin >> letter;

        if (index < word.size() && tolower(letter) == tolower(word[index])) {
            correct[index] = true;
            cout << "Correct! The next letter is: " << word[index] << endl;
            index++;
            // Automatically fill the next letter
            if (index < word.size() && !correct[index]) {
                correct[index] = true;
                cout << "Correct! The next letter is: " << "\033[32m" << word[index] << "\033[0m" << endl;
                index++;
            }
        }
        else {
            cout << "Incorrect. Try again." << endl;
        }

    }

    printWord(correct, word);
    cout << "Congratulations! You found the word." << endl;

    return 0;
}