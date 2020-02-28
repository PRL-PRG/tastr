#include "ast.h"

#include <iostream>
#include <cstring>

int main(int argc, char* argv[]) {
    int result = 0;
    for (int i = 1; i < argc; ++i) {
        if (argv[i] == std::string("-p")) {
            // parser_context.trace_parsing();
        } else if (argv[i] == std::string("-s")) {
            // parser_context.trace_scanning();
        } else if (argv[i][0] == '\"') {
            const char* input = argv[i];
            int length = strlen(argv[i]);
            /* remove leading and trailing " character */
            std::string string(input + 1, length - 2);
            result = parse_string(string);
        } else if (std::string(argv[i]) == "-") {
            result = parse_stdin();
        } else {
            std::filesystem::path filepath(argv[i]);
            result = parse_file(filepath);
        }
        if (result != 0) {
            return result;
        }
    }

    return result;
}
