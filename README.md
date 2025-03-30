# Typing Speed Test Game

## Overview
This is a simple **Typing Speed Test Game** built in C++. It challenges users to type randomly selected sentences as quickly and accurately as possible while providing real-time feedback on typing errors. The game calculates Words Per Minute (WPM) and accuracy after each attempt.

## Features
- **Live Typing Feedback**: Mistyped characters are highlighted in red.
- **Real-time WPM & Accuracy Calculation**: Tracks speed and correctness of typing.
- **Backspace Support**: Users can correct mistakes while typing.
- **Random Sentence Selection**: Sentences are randomly picked from a file.
- **Play Again Prompt**: Users can replay without restarting the program.

## How to Play
1. Run the executable.
2. The program will display a random sentence.
3. Type the sentence as quickly and accurately as possible.
4. Press `Enter` when done.
5. View your results (Time Taken, WPM, Accuracy).
6. Choose whether to play again.

## Installation & Compilation
### **Windows**
Make sure you have a C++ compiler installed (such as MinGW).

Compile the program using:
```sh
 g++ typing.cpp -o typing
```
Run the executable:
```sh
 ./typing
```

### **Linux (Not Yet Supported)**
Currently, the program uses `conio.h`, which is **not** available on Linux. To make it cross-platform, consider using **ncurses** or **termios** for real-time input handling.

## File Requirements
The game reads sentences from a file named **`sentences.txt`**. Ensure this file exists in the same directory as the executable and contains multiple sentences, each on a new line.

Example `sentences.txt`:
```
The quick brown fox jumps over the lazy dog.
Coding is fun when you challenge yourself.
Practice makes perfect in typing speed tests.
```

## Future Improvements
- **Linux Support** (Replacing `conio.h` with `ncurses` or `termios`)
- **Sentence Difficulty Levels** (Easy, Medium, Hard)
- **Leaderboard System** (Track highest WPM scores)
- **A graphical UI version**

## Author
Developed by **Adam Idris**

## License
This project is open-source and free to use.

Happy typing! 🎯
