#include "parser/parser.hpp"

#include "ast/ast.hpp"
#include "parser/Lexer.hpp"
#include "parser/Parser.hxx"
#include "parser/ParsingContext.hpp"
#include "parser/Unparser.hpp"

#include <fstream>
#include <sstream>

void check_filepath(const std::filesystem::path& filepath) {
    if (!std::filesystem::exists(filepath)) {
        std::cerr << "Error: path '" << filepath << "' does not exist!";
        exit(1);
    }

    if (std::filesystem::is_directory(filepath)) {
        std::cerr << "Error: expected file, path '" << filepath
                  << "' is a directory!";
        exit(1);
    }
}

std::ostream& unparse_(const tastr::ast::Node& node,
                       std::ostream& os,
                       bool show_ast,
                       bool style_output) {
    tastr::visitor::Unparser unparser(os, show_ast, style_output);
    unparser.visit(node);
    return os;
}

std::ostream& operator<<(std::ostream& os, const tastr::ast::Node& node) {
    return unparse_(node, os, false, false);
}

std::string tastr::parser::to_string(const tastr::ast::Node& node) {
    std::string output;
    unparse_string(node, output, false, false);
    return output;
}

void tastr::parser::unparse_stdout(const tastr::ast::Node& node,
                                   bool show_ast,
                                   bool style_output) {
    unparse_(node, std::cout, show_ast, style_output);
}

void tastr::parser::unparse_string(const tastr::ast::Node& node,
                                   std::string& string,
                                   bool show_ast,
                                   bool style_output) {
    std::ostringstream output_stream;
    unparse_(node, output_stream, show_ast, style_output);
    string.append(output_stream.str());
}

void tastr::parser::unparse_file(const tastr::ast::Node& node,
                                 const std::filesystem::path& filepath,
                                 bool show_ast,
                                 bool style_output) {
    check_filepath(filepath);
    std::ofstream output_stream(filepath);
    unparse_(node, output_stream, show_ast, style_output);
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
    check_filepath(filepath);
    std::ifstream input_stream(filepath);
    std::string input_stream_name(filepath.native());
    return parse_(input_stream, input_stream_name, debug_lexer, debug_parser);
}
