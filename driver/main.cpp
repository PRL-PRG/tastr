#include "ast.h"

#include <cstring>
#include <iostream>

int main(int argc, char* argv[]) {
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
            tastr::ast::TopLevelNodeUPtr result(
                std::move(parse_string(string)));
            std::cout << *result.get();
        } else if (std::string(argv[i]) == "-") {
            tastr::ast::TopLevelNodeUPtr result(std::move(parse_stdin()));
            std::cout << *result.get();
        } else {
            std::filesystem::path filepath(argv[i]);
            tastr::ast::TopLevelNodeUPtr result(
                std::move(parse_file(filepath)));
            std::cout << *result.get();
        }
    }
    return 0;
}
