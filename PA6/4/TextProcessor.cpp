#include "TextProcessor.h"
#include <cctype>
#include <algorithm>
#include <sstream>

// Setters and Getters
void TextProcessor::setText(const std::string& text) {
    text_ = text;
}

std::string TextProcessor::getText() const {
    return text_;
}

// Basic String Operations
std::string TextProcessor::removeSpaces() {
    std::string result = text_;
    result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
    return result;
}

std::string TextProcessor::toLowerCase() {
    std::string result = text_;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return result;
}

std::string TextProcessor::toUpperCase() {
    std::string result = text_;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c){ return std::toupper(c); });
    return result;
}

std::string TextProcessor::reverse() {
    std::string result = text_;
    std::reverse(result.begin(), result.end());
    return result;
}

// String Find and Replace
int TextProcessor::countOccurrences(const std::string& substr) {
    if (substr.empty()) {
        return 0;
    }
    int count = 0;
    std::string::size_type pos = 0;
    while ((pos = text_.find(substr, pos)) != std::string::npos) {
        ++count;
        pos += substr.length();
    }
    return count;
}

std::vector<int> TextProcessor::findPositions(const std::string& substr) {
    std::vector<int> positions;
    if (substr.empty()) {
        return positions;
    }
    std::string::size_type pos = 0;
    while ((pos = text_.find(substr, pos)) != std::string::npos) {
        positions.push_back(pos);
        pos += 1; // Move to the next character to find overlapping occurrences
    }
    return positions;
}

std::string TextProcessor::replaceAll(const std::string& from, const std::string& to) {
    if (from.empty()) {
        return text_;
    }
    std::string result = text_;
    std::string::size_type pos = 0;
    while ((pos = result.find(from, pos)) != std::string::npos) {
        result.replace(pos, from.length(), to);
        pos += to.length();
    }
    return result;
}

// String Splitting
std::vector<std::string> TextProcessor::split(char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(text_);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Character and Word Statistics
int TextProcessor::getCharCount() {
    return text_.length();
}

int TextProcessor::getCharCountNoSpaces() {
    int count = 0;
    for (char c : text_) {
        if (c != ' ') {
            count++;
        }
    }
    return count;
}

int TextProcessor::getLineCount() {
    if (text_.empty()) {
        return 1;
    }
    int count = 1;
    for (char c : text_) {
        if (c == '\n') {
            count++;
        }
    }
    return count;
}

// String Validation
bool TextProcessor::isPalindrome() {
    std::string temp = text_;
    // Pre-process the string: remove spaces and convert to lower case
    temp.erase(std::remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
    std::transform(temp.begin(), temp.end(), temp.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    
    std::string reversed_temp = temp;
    std::reverse(reversed_temp.begin(), reversed_temp.end());
    
    return temp == reversed_temp;
}

bool TextProcessor::isNumeric() {
    if (text_.empty()) {
        return false;
    }
    
    std::string s = text_;
    int i = 0;
    
    // Check for optional sign
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    // There must be at least one digit after the sign
    if (i == s.length()) {
        return false;
    }

    bool hasDecimalPoint = false;
    bool hasDigits = false;

    for (; i < s.length(); ++i) {
        if (isDigit(s[i])) {
            hasDigits = true;
        } else if (s[i] == '.') {
            if (hasDecimalPoint) { // More than one decimal point
                return false;
            }
            hasDecimalPoint = true;
        } else { // Invalid character
            return false;
        }
    }

    // A number must contain at least one digit
    return hasDigits;
}


bool TextProcessor::containsOnly(const std::string& charset) {
    for (char c : text_) {
        if (charset.find(c) == std::string::npos) {
            return false;
        }
    }
    return true;
}


// Formatting
std::string TextProcessor::centerAlign(int width, char fillChar) {
    int len = text_.length();
    if (len >= width) {
        return text_;
    }
    int padding = width - len;
    int padLeft = padding / 2;
    int padRight = padding - padLeft;
    return std::string(padLeft, fillChar) + text_ + std::string(padRight, fillChar);
}

std::string TextProcessor::leftAlign(int width, char fillChar) {
    int len = text_.length();
    if (len >= width) {
        return text_;
    }
    return text_ + std::string(width - len, fillChar);
}

std::string TextProcessor::rightAlign(int width, char fillChar) {
    int len = text_.length();
    if (len >= width) {
        return text_;
    }
    return std::string(width - len, fillChar) + text_;
}