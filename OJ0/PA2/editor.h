#ifndef _Editor_H
#define _Editor_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
class TextEditor
{
private:
    using Position = std::pair<int, int>;
    std::vector<std::string> data;
    Position cursor;
    std::vector<std::vector<std::string>> history;
public:
    TextEditor();
    void move(Position dest);
    void write(const std::string &str);
    void newline();
    void del();
    void screenShot();
    void undo();
    void apply(const std::string &instruction);
    ~TextEditor();
};

#endif // _Editor_H_