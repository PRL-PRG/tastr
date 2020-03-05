#include "ast/ast.hpp"

#include <cstring>
#include <iostream>

static void handle_parse_result(tastr::parser::ParseResult&& result) {
    std::cout << *result.get_top_level_node();

    if (!result) {
        std::cerr << std::endl
                  << "Error: " << result.get_error_location()
                  << " :: " << result.get_error_message() << std::endl;
        exit(1);
    }
}

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
            handle_parse_result(
                std::move(parse_string(string, debug_lexer, debug_parser)));

        } else if (std::string(argv[i]) == "-") {
            handle_parse_result(
                std::move(parse_stdin(debug_lexer, debug_parser)));
        } else {
            std::filesystem::path filepath(argv[i]);
            handle_parse_result(
                std::move(parse_file(filepath, debug_lexer, debug_parser)));
        }
    }
    return 0;
}
