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
        : input_stream_(input_stream)
        , parse_output_(input_stream_name)
        , token_prefix_("") {
    }

    ~ParsingContext() {
    }

    std::istream& get_input_stream() {
        return input_stream_;
    }

    tastr::parser::ParseResult& get_parse_result() {
        return parse_output_;
    }

    std::string& get_token_prefix() {
        return token_prefix_;
    }

    const std::string& get_token_prefix() const {
        return token_prefix_;
    }

    std::string extract_token_prefix() {
        std::string result = std::move(token_prefix_);
        token_prefix_ = "";
        return result;
    }

  private:
    std::istream& input_stream_;
    ParseResult parse_output_;
    std::string token_prefix_;
};

} // namespace tastr::parser

#endif /* TASTR_PARSER_PARSING_CONTEXT_HPP */
