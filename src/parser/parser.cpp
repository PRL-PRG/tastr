#include "parser/parser.hpp"

#include "ast/ast.hpp"
#include "parser/Lexer.hpp"
#include "parser/Parser.hxx"
#include "parser/ParsingContext.hpp"
#include "parser/Unparser.hpp"

#include <fstream>
#include <sstream>

std::ostream& operator<<(std::ostream& os, const tastr::ast::Node& node) {
    tastr::visitor::Unparser(os).visit(node);
    return os;
}

std::string tastr::parser::to_string(const tastr::ast::Node& node) {
    std::stringstream stream;
    ::operator<<(stream, node);
    return stream.str();
}

tastr::parser::ParseResult parse_(std::istream& input_stream,
                                  const std::string& input_stream_name,
                                  bool debug_lexer,
                                  bool debug_parser) {
    tastr::parser::ParsingContext context(input_stream, input_stream_name);
    tastr::parser::Lexer lexer(context);
    lexer.set_debug_level(debug_lexer);
    tastr::parser::Parser parser(lexer, context);
    parser.set_debug_level(debug_parser);
    parser.parse();
    return std::move(context.get_parse_result());
}

tastr::parser::ParseResult tastr::parser::parse_stdin(bool debug_lexer,
                                                      bool debug_parser) {
    std::string input_stream_name("<stdin>");
    return parse_(std::cin, input_stream_name, debug_lexer, debug_parser);
}

tastr::parser::ParseResult
tastr::parser::parse_string(const std::string& string,
                            bool debug_lexer,
                            bool debug_parser) {
    std::istringstream input_stream(string);
    std::string input_stream_name("<string>");
    return parse_(input_stream, input_stream_name, debug_lexer, debug_parser);
}

tastr::parser::ParseResult
tastr::parser::parse_file(const std::filesystem::path& filepath,
                          bool debug_lexer,
                          bool debug_parser) {
    if (!std::filesystem::exists(filepath)) {
        std::cerr << "Error: path '" << filepath << "' does not exist!";
    }

    if (std::filesystem::is_directory(filepath)) {
        std::cerr << "Error: expected file, path '" << filepath
                  << "' is a directory!";
    }

    std::ifstream input_stream(filepath);
    std::string input_stream_name(filepath.native());
    return parse_(input_stream, input_stream_name, debug_lexer, debug_parser);
}
