#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <map>
#include <set>

class Duplicate
{
public:
    Duplicate() = default;
    Duplicate(std::string file_name);
    void open(std::string file_name);
    std::set<std::string> find_dublicate();
    size_t count();
private:
    void fill_table();
    bool is_english_font(char ch);
private:
    std::map<std::string, size_t> m_data;
    std::ifstream m_stream;
};
