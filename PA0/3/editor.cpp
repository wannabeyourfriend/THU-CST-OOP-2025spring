#include "editor.h"

TextEditor::TextEditor()
{
    data.push_back("");
    cursor = Position(0, 0);
}

void TextEditor::move(Position dest)
{
    int row = std::max(0, std::min(dest.first, static_cast<int>(data.size() - 1)));
    int col = std::max(0, std::min(dest.second, static_cast<int>(data[row].size())));
    cursor = Position(row, col);
}

void TextEditor::write(const std::string &str)
{
    int row = cursor.first;
    int col =cursor.second;
    data[row].insert(col, str);
    cursor.second += str.length();
}
void TextEditor::newline()
{
    int row = cursor.first;
    int col = cursor.second;
    std::string newLine = data[row].substr(col);
    data[row] = data[row].substr(0, col);
    data.insert(data.begin() + row + 1, newLine);
    move(Position(row + 1, 0));
}

void TextEditor::del()
{
    int row = cursor.first;
    int col = cursor.second;
    if (col > 0) {
        data[row].erase(col - 1, 1);
        move(Position(row, col - 1));
    }
    else if (row > 0) {
        int len = data[row - 1].size();
        data[row - 1] += data[row];
        data.erase(data.begin() + row);
        move(Position(row - 1, len));
    }

}

void TextEditor::screenShot()
{
    std::cout << "### SCREENSHOT BEGIN ###" << std::endl;

    for (int i = 0; i < data.size(); ++i) {
        std::string line = data[i];
        if (i == cursor.first) {
            line.insert(cursor.second, "*");  
        }
        std::cout << line << std::endl;
    }

    std::cout << "### SCREENSHOT END ###" << std::endl;
}

void TextEditor::undo()
{
    if (history.empty()) {
        return;
    }
    data = history.back();
    history.pop_back();
    move(Position(cursor.first, cursor.second));
}

void TextEditor::apply(const std::string &instruction)
{
    std::istringstream iss(instruction);
    std::string opt;
    iss >> opt;
    if (opt == "MOVE") {
        int row, col;
        iss >> row >> col;
        Position position(row, col);
        move(position);
    } else if (opt == "WRITE") {
        std::string text;
        iss >> text;
        write(text);
    } else if (opt == "NEWLINE") {
        newline();
    } else if (opt == "DELETE") {
        del();
    } else if (opt == "UNDO") {
        undo();
    } else if (opt == "SCREEN") {
        screenShot();
    }

    // 保存当前的状态到历史栈
    history.push_back(data);
}

TextEditor::~TextEditor()
{
}
