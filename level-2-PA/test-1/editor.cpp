#include"editor.h"
#include<iostream>
#include<vector>
#include<sstream>
TextEditor::TextEditor() {
    mouse = {0, 0};
    data.push_back("");
}
void TextEditor::move(Position dest) {
    int x = dest.first;
    int y = dest.second;
    int xa, ya;
    int n = data.size();
    if (x <= n-1 && x >= 0) {
        xa = x;
        int k = data[xa].size();
        if (y <= k && y >= 0) {
            ya = y;
        }
        else if (y < 0) {
            ya = 0;
        }
        else {
            ya = k;
        }
    }
    else if (x < 0) {
        xa = 0;
        int k = data[0].size();
        if (y <= k && y >= 0) {
            ya = y;
        }
        else if (y < 0) {
            ya = 0;
        }
        else {
            ya = k;
        }
    }
    else {
        xa = n - 1;
        int k = data[n-1].size();
        if (y <= k && y >= 0) {
            ya = y;
        }
        else if (y < 0) {
            ya = 0;
        }
        else {
            ya = k;
        }
    }
    mouse = {xa, ya};
    //std::cout << "DEBUG " << xa <<" "<< ya << std::endl;
    return;
}

void TextEditor::write(const std::string &str) {
    std::string oldstring = data[mouse.first];
    std::string newstring = oldstring.insert(mouse.second, str);
    data[mouse.first] = newstring;
    mouse = {mouse.first, mouse.second + str.size()};
    return;
}

void TextEditor::screenShot() {
    std::vector<std::string> data_m = data;
    std::string oldstring = data_m[mouse.first];
    std::string newstring = oldstring.insert(mouse.second, "*");
    data_m[mouse.first] = newstring;
    std::cout << "### SCREENSHOT BEGIN ###" << std::endl;
    for (auto line : data_m) {
        std::cout << line << std::endl;
    }
    std::cout << "### SCREENSHOT END ###" << std::endl;

}

void TextEditor::del() {
    if (mouse.second == 0) {
        if (mouse.first == 0) {
            return;
        }
        else {
        std::string backstring = data[mouse.first];
        std::string newstring = data[mouse.first - 1] + data[mouse.first];
        int xpos = data[mouse.first - 1].size();
        data[mouse.first - 1] = newstring;
        data.erase(data.begin() + mouse.first);
        mouse = {mouse.first -1, xpos};
        }
    }
    else {
        data[mouse.first].erase(mouse.second - 1, 1);
        mouse = {mouse.first, mouse.second - 1};
    }
}
void TextEditor::newline() {
    if (mouse.second == data[mouse.first].size()) {
        data.insert(data.begin() + mouse.first + 1, "");
        mouse = {mouse.first + 1, 0};
        return;
    }
    else {
        std::string prefix = data[mouse.first].substr(0, mouse.second);
        std::string profix = data[mouse.first].substr(mouse.second);
        data[mouse.first] = prefix;
        data.insert(data.begin() + mouse.first + 1, profix);
        //std::cout << "DEBUG" << "Here is an insert."<< std::endl; 
        mouse = {mouse.first + 1, 0};
    }
}
void TextEditor::apply(const std::string &opt) {
    std::stringstream ss(opt);
    std::string o;
    ss >> o;
    if (o == "MOVE") {
        int x, y;
        ss >> x >> y;
        move({x, y});
    }
    if (o == "SCREEN") {
        screenShot();
    }
    if (o == "WRITE") {
        std::string h;
        ss >> h;
        write(h);
    }
    if (o == "DELETE") {
        del();
    }
    if (o == "NEWLINE") {
        newline();
    }
}