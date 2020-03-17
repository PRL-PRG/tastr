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
        , token_prefixes_({""})
        , finish_(false) {
    }

    ~ParsingContext() {
    }

    std::istream& get_input_stream() {
        return input_stream_;
    }

    tastr::parser::ParseResult& get_parse_result() {
        return parse_output_;
    }

    void append_token_prefix(const char* str) {
        if (finish_) {
            finish_ = false;
            token_prefixes_.push_back(str);
        } else {
            token_prefixes_.back().append(str);
        }
    }

    void finish_token_prefix() {
        if(finish_) {
            token_prefixes_.push_back("");
        }
        finish_ = true;
    }

    std::string extract_token_prefix() {
        std::string result = std::move(token_prefix_);
        token_prefix_ = "";
    std::string pop_token_prefix() {
        if (token_prefixes_.size() == 0) {
            // std::cout << "Trying to pop from empty stack " << std::endl;
            return "";
        }
        std::string result(token_prefixes_.back());
        token_prefixes_.pop_back();
        return result;
    }

  private:
    std::istream& input_stream_;
    ParseResult parse_output_;
    std::vector<std::string> token_prefixes_;
    bool finish_;
};

} // namespace tastr::parser

#endif /* TASTR_PARSER_PARSING_CONTEXT_HPP */
