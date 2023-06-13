#include "IniFileReader.h"

int main() {
    IniFileReader::init("..\\config.ini");

    std::optional<std::string> result = IniFileReader::getValue("section2", "key4");
    if (result.has_value()) std::cout << result.value() << std::endl;

    return 0;
}
