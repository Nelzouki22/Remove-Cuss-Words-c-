#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Function to load predefined cuss words
std::vector<std::string> loadCussWords() {
    // Predefined list of cuss words
    std::vector<std::string> cussWords = { "badword1", "badword2", "badword3" };
    return cussWords;
}

// Function to replace cuss words in the text
std::string censorText(const std::string& text, const std::vector<std::string>& cussWords) {
    std::string censoredText = text;
    for (const std::string& word : cussWords) {
        size_t pos = censoredText.find(word);
        while (pos != std::string::npos) {
            censoredText.replace(pos, word.length(), std::string(word.length(), '*'));
            pos = censoredText.find(word, pos + 1);
        }
    }
    return censoredText;
}

int main() {
    std::vector<std::string> cussWords = loadCussWords();
    std::string text = "This is a text with badword1 and some other badword2.";

    std::string censoredText = censorText(text, cussWords);
    std::cout << "Original text: " << text << std::endl;
    std::cout << "Censored text: " << censoredText << std::endl;

    return 0;
}
