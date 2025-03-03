#ifndef _Editor_H
#define _Editor_H

#include <vector>
#include <string>

class TextEditor
{
private:
    using Position = std::pair<int, int>;
    std::vector<std::string> data;

public:
    TextEditor();
    void move(Position dest);
    void write(const std::string &str);
    void newline();
    void del();
    void screenShot();
    void undo();
    void apply(const std::string &opt);
    ~TextEditor();
};

#endif // _Editor_H_