#ifndef TASTR_PARSER_PARSE_RESULT_HPP
#define TASTR_PARSER_PARSE_RESULT_HPP

#include "ast/TopLevelNode.hpp"
#include "parser/location.hh"

#include <iostream>
#include <string>

namespace tastr::parser {

class ParseResult {
  public:
    explicit ParseResult(const std::string& input_stream_name)
        : state_(true)
        , location_()
        , message_()
        , node_(new tastr::ast::TopLevelNode(input_stream_name)) {
    }

    ParseResult(const ParseResult& parse_result)
        : state_(parse_result.state_)
        , location_(parse_result.location_)
        , message_(parse_result.message_)
        , node_(parse_result.node_->clone()) {
    }

    ParseResult(ParseResult&& parse_result)
        : state_(std::move(parse_result.state_))
        , location_(std::move(parse_result.location_))
        , message_(std::move(parse_result.message_))
        , node_(std::move(parse_result.node_)) {
    }

    ~ParseResult() = default;

    explicit operator bool() const {
        return state_;
    }

    const tastr::parser::location& get_error_location() const {
        return location_;
    }

    const std::string& get_error_message() const {
        return message_;
    }

    tastr::ast::TopLevelNodeUPtr& get_top_level_node() {
        return node_;
    }

    const tastr::ast::TopLevelNodeUPtr& get_top_level_node() const {
        return node_;
    }

    void set_error(const tastr::parser::location& location,
                   const std::string& message) {
        state_ = false;
        location_ = location;
        message_ = message;
    }

  private:
    bool state_;
    tastr::parser::location location_;
    std::string message_;
    tastr::ast::TopLevelNodeUPtr node_;
};

} // namespace tastr::parser

#endif /* TASTR_PARSER_PARSE_RESULT_HPP */
