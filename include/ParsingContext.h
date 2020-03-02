#ifndef TASTR_PARSING_CONTEXT_H
#define TASTR_PARSING_CONTEXT_H

#include "ast/TopLevelNode.h"

#include <iostream>
#include <string>

namespace tastr::parser {

class ParsingContext {
  public:
    explicit ParsingContext(std::istream& input_stream,
                            std::string& input_stream_name)
        : input_stream_(input_stream)
        , input_stream_name_(input_stream_name)
        , node_(new tastr::ast::TopLevelNode(input_stream_name)) {
    }

    ~ParsingContext() {
    }

    std::istream& get_input_stream() {
        return input_stream_;
    }

    std::string *get_input_stream_name() {
        return &input_stream_name_;
    }

    tastr::ast::TopLevelNodeUPtr&
    get_top_level_node() {
        return node_;
    }

  private:
    std::istream& input_stream_;
    std::string& input_stream_name_;
    tastr::ast::TopLevelNodeUPtr node_;
};

} // namespace tastr::parser

#endif /* TASTR_PARSING_CONTEXT_H */
