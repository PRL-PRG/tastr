#include "RTypesParser.h"

#include <iostream>

int main(int argc, char* argv[]) {
    int result = 0;
    RTypesParser parser;
    for (int i = 1; i < argc; ++i) {
        if (argv[i] == std::string("-p")) {
            parser.trace_parsing();
        } else if (argv[i] == std::string("-s")) {
            parser.trace_scanning();
        } else if (!parser.parse(argv[i])) {
            std::cout << parser.get_result() << '\n';
        } else {
            result = 1;
        }
    }
    return result;
}
