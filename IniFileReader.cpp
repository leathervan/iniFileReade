#include "IniFileReader.h"

std::map<std::string, std::map<std::string, std::string>> IniFileReader::data;

bool IniFileReader::init(const std::string &filename) {
    std::ifstream inputFile(filename);

    if (!inputFile) {
        if (inputFile.fail()) {
            std::cout << "Failed to open the file " << "\'" << filename << "\' " << std::strerror(errno) << std::endl;
        }
        return false;
    }

    std::string line, section;
    while (std::getline(inputFile, line)) {
        if (!line.empty() && line[0] != '#') {
            line = line.substr(line.find_first_not_of(" \t"));
            line = line.substr(0, line.find_last_not_of(" \t") + 1);

            if (line[0] == '[' && line[line.length() - 1] == ']') {
                section = line.substr(1, line.length() - 2);
            } else {
                int index = line.find('=');
                if (index != std::string::npos) {
                    std::string key = line.substr(0, index);
                    std::string value = line.substr(index + 1);
                    data[section][key] = value;
                }
            }
        }
    }

    return true;
}

std::optional<std::string> IniFileReader::getValue(const std::string &section, const std::string &key) {
    if (data.find(section) != data.end() && data[section].find(key) != data[section].end()) {
        return data[section][key];
    }
    return std::nullopt;
}