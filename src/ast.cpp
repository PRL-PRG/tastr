#include "ast.h"

#include "Lexer.hpp"
#include "Parser.hxx"
#include "ParsingContext.h"
#include "ast/visitor/Unparser.h"

#include <fstream>
#include <sstream>

std::ostream& operator<<(std::ostream& os, const rtype::ast::node::Node& node) {
    rtype::ast::visitor::Unparser(os).visit(node);
    return os;
}

std::string to_string(const rtype::ast::node::Node& node) {
    std::stringstream stream;
    stream << node;
    return stream.str();
}

int parse_(std::istream& input_stream, std::string& input_stream_name) {
    rtype::parser::ParsingContext context(input_stream, input_stream_name);
    rtype::parser::Lexer lexer(context);
    rtype::parser::Parser parser(lexer, context);
    int result = parser.parse();
    std::cout << *context.get_type_declaration_sequence().get();
    return result;
}

int parse_stdin() {
    std::string input_stream_name("<stdin>");
    return parse_(std::cin, input_stream_name);
}

int parse_string(const std::string& string) {
    std::istringstream input_stream(string);
    std::string input_stream_name("<string>");
    return parse_(input_stream, input_stream_name);
}

int parse_file(const std::filesystem::path& filepath) {
    if (!std::filesystem::exists(filepath)) {
        std::cerr << "Error: path '" << filepath << "' does not exist!";
    }

    if (std::filesystem::is_directory(filepath)) {
        std::cerr << "Error: expected file, path '" << filepath
                  << "' is a directory!";
    }

    std::ifstream input_stream(filepath);
    std::string input_stream_name(filepath.native());
    return parse_(input_stream, input_stream_name);
}
