#include "ast.h"

#include <cstring>
#include <iostream>

int main(int argc, char* argv[]) {
    bool debug_lexer = false;
    bool debug_parser = false;
    for (int i = 1; i < argc; ++i) {
        if (argv[i] == std::string("-p")) {
            debug_parser = true;
        } else if (argv[i] == std::string("-l")) {
            debug_lexer = true;
        } else if (argv[i][0] == '\"') {
            const char* input = argv[i];
            int length = strlen(argv[i]);
            /* remove leading and trailing " character */
            std::string string(input + 1, length - 2);
            tastr::ast::TopLevelNodeUPtr result(
                std::move(parse_string(string, debug_lexer, debug_parser)));
            std::cout << *result.get();
        } else if (std::string(argv[i]) == "-") {
            tastr::ast::TopLevelNodeUPtr result(
                std::move(parse_stdin(debug_lexer, debug_parser)));
            std::cout << *result.get();
        } else {
            std::filesystem::path filepath(argv[i]);
            tastr::ast::TopLevelNodeUPtr result(
                std::move(parse_file(filepath, debug_lexer, debug_parser)));
            std::cout << *result.get();
        }
    }
    return 0;
}
