#include "ast/ast.hpp"
#include "cxxopts.hpp"
#include "parser/parser.hpp"

#include <cstring>
#include <iostream>

cxxopts::ParseResult parse_program_arguments(int& argc, char* argv[]) {
    cxxopts::Options options("tastr", "Parse type declarations.");

    options.add_options()

        /* HELP */
        ("h,help", "Print usage")

        /* LEXER */
        ("l,lexer",
         "Debug lexer",
         cxxopts::value<bool>()->default_value("false")->implicit_value("true"))

        /* PARSER */
        ("p,parser",
         "Debug parser",
         cxxopts::value<bool>()->default_value("false")->implicit_value("true"))

        /* AST */
        ("a,ast",
         "Show AST structure",
         cxxopts::value<bool>()->default_value("false")->implicit_value("true"))

        /* STYLE */
        ("s,style",
         "Style output",
         cxxopts::value<bool>()->default_value("false")->implicit_value(
             "true"));

    cxxopts::ParseResult program_arguments = options.parse(argc, argv);

    if (program_arguments.count("help")) {
        std::cout << options.help() << std::endl;
        exit(0);
    }

    return program_arguments;
}

int main(int argc, char* argv[]) {
    cxxopts::ParseResult program_arguments =
        parse_program_arguments(argc, argv);

    const bool debug_lexer = program_arguments["lexer"].as<bool>();
    const bool debug_parser = program_arguments["parser"].as<bool>();
    const bool show_ast = program_arguments["ast"].as<bool>();
    const bool style_output = program_arguments["style"].as<bool>();

    auto handle_parse_result =
        [&show_ast, &style_output](const tastr::parser::ParseResult& result) {
            if (!result) {
                std::cerr << "Error: " << result.get_error_location()
                          << " :: " << result.get_error_message() << std::endl;
                exit(1);
            }

            tastr::parser::unparse_stdout(
                *result.get_top_level_node(), show_ast, style_output);
        };

    /*
    const std::vector<std::string>& args =
        program_arguments["positional"].as<std::vector<std::string>>();
    */

    for (int index = 1; index < argc; ++index) {
        std::string arg(argv[index]);

        std::size_t length = arg.length();

        if (length == 0) {
            continue;
        }

        if (arg == "-") {
            handle_parse_result(
                tastr::parser::parse_stdin(debug_lexer, debug_parser));
            continue;
        }

        if ((arg[0] == '"' && arg[length - 1] == '"') ||
            (arg[0] == '\'' && arg[length - 1] == '\'')) {
            /* remove leading and trailing " character */
            std::string string(arg, 1, length - 2);
            handle_parse_result(
                tastr::parser::parse_string(string, debug_lexer, debug_parser));

            continue;
        }

        if ((arg[0] == '"') || (arg[0] == '\'') || (arg[length - 1] == '"') ||
            (arg[length - 1] == '\'')) {
            std::cerr << "Argument " << arg
                      << " should use ' or \" consistently." << std::endl;
            exit(1);
        }

        std::string filepath(arg);
        handle_parse_result(
            tastr::parser::parse_file(filepath, debug_lexer, debug_parser));
    }

    return 0;
}
