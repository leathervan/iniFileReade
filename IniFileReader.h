#ifndef INIFILEREADER_INIFILEREADER_H
#define INIFILEREADER_INIFILEREADER_H


#include <map>
#include <string>
#include <optional>
#include <cstring>
#include <iostream>
#include <fstream>

class IniFileReader {
private:
    static std::map<std::string, std::map<std::string, std::string>> data;

public:
    static bool init(const std::string &filename);

    static std::optional<std::string> getValue(const std::string &section, const std::string &option);
};


#endif
