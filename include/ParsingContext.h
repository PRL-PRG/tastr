#ifndef R_TYPES_PARSING_CONTEXT_H
#define R_TYPES_PARSING_CONTEXT_H

#include "ast/node/TypeDeclarationSequence.h"

#include <iostream>
#include <string>

namespace rtype::parser {

class ParsingContext {
  public:
    explicit ParsingContext(std::istream& input_stream,
                            std::string& input_stream_name)
        : input_stream_(input_stream)
        , input_stream_name_(input_stream_name)
        , sequence_(new rtype::ast::node::TypeDeclarationSequence()) {
    }

    ~ParsingContext() {
    }

    std::istream& get_input_stream() {
        return input_stream_;
    }

    std::string *get_input_stream_name() {
        return &input_stream_name_;
    }

    rtype::ast::node::TypeDeclarationSequenceUPtr&
    get_type_declaration_sequence() {
        return sequence_;
    }

  private:
    std::istream& input_stream_;
    std::string& input_stream_name_;
    rtype::ast::node::TypeDeclarationSequenceUPtr sequence_;
};

} // namespace rtype::parser

#endif /* R_TYPES_PARSING_CONTEXT_H */
