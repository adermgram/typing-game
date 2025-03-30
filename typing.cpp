#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h> // For live typing feedback
#include <sstream>

using namespace std;
using namespace chrono;

vector<string> loadSentences(const string& filename) {
    vector<string> sentences;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        if (!line.empty())
            sentences.push_back(line);
    }
    file.close();
    return sentences;
}

int countWords(const string& text) {
    stringstream ss(text);
    string word;
    int count = 0;
    while (ss >> word) {
        count++;
    }
    return count;
}

void startTypingTest(const vector<string>& sentences) {
    if (sentences.empty()) {
        cout << "Error: No sentences found in file." << endl;
        return;
    }
    srand(time(0));
    string target = sentences[rand() % sentences.size()];
    cout << "Type this sentence as fast as you can:\n";
    cout << target << endl;

    string userInput(target.size(), '_'); // Placeholder for user input
    auto start = high_resolution_clock::now();
    
    size_t index = 0;
    char ch;
    while (true) {
        ch = _getch(); // Get a single character without pressing Enter
        
        if (ch == 13) { // Enter key to finish
            break;
        }
        
        if (ch == 8) { // Handle backspace
            if (index > 0) {
                index--;
                cout << "\b \b"; // Erase character from console
            }
            continue;
        }
        
        if (index < target.size()) {
            if (ch == target[index]) {
                cout << ch; // Print correct character normally
            } else {
                cout << "\033[31m" << ch << "\033[0m"; // Highlight mistake in red
            }
            userInput[index] = ch;
            index++;
        }
    }
    
    auto end = high_resolution_clock::now();
    double timeTaken = duration<double>(end - start).count() / 60.0; // Convert to minutes
    
    int totalWords = countWords(target);
    int typedWords = countWords(userInput);
    double wpm = typedWords / timeTaken;
    
    int correctChars = 0;
    for (size_t i = 0; i < target.size(); i++) {
        if (target[i] == userInput[i])
            correctChars++;
    }
    double accuracy = (double(correctChars) / target.size()) * 100;
    
    cout << "\n\nResults:\n";
    cout << "Time Taken: " << timeTaken * 60 << " seconds" << endl;
    cout << "Words Per Minute (WPM): " << wpm << endl;
    cout << "Accuracy: " << accuracy << "%" << endl;
}

int main() {
    cout << "Welcome to the Typing Speed Test!" << endl;
    vector<string> sentences = loadSentences("sentences.txt");
    
    char choice;
    do {
        cout << "\nPress Enter when you're ready...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        startTypingTest(sentences);
        
        cout << "\nDo you want to play again? (y/n): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'y' || choice == 'Y');
    
    cout << "Thanks for playing!" << endl;
    return 0;
}

