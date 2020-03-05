#ifndef TASTR_PARSER_PARSING_CONTEXT_HPP
#define TASTR_PARSER_PARSING_CONTEXT_HPP

#include "parser/ParseResult.hpp"

#include <iostream>
#include <string>

namespace tastr::parser {

class ParsingContext {
  public:
    explicit ParsingContext(std::istream& input_stream,
                            const std::string& input_stream_name)
        : input_stream_(input_stream), parse_output_(input_stream_name) {
    }

    ~ParsingContext() {
    }

    std::istream& get_input_stream() {
        return input_stream_;
    }

    tastr::parser::ParseResult& get_parse_result() {
        return parse_output_;
    }

  private:
    std::istream& input_stream_;
    ParseResult parse_output_;
};

} // namespace tastr::parser

#endif /* TASTR_PARSER_PARSING_CONTEXT_HPP */
