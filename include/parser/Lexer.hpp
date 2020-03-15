#ifndef TASTR_LEXER_HPP
#define TASTR_LEXER_HPP

#include "parser/Parser.hxx"
#include "parser/ParsingContext.hpp"

/* https://stackoverflow.com/questions/40663527/how-to-inherit-from-yyflexlexer
 */
#if !defined(yyFlexLexerOnce)
#    include <FlexLexer.h>
#endif

/* Tell flex which function to define */
#undef YY_DECL
#define YY_DECL                                       \
    int tastr::parser::Lexer::yylex(                  \
        tastr::parser::Parser::semantic_type* yylval, \
        tastr::parser::Parser::location_type* yylloc)

namespace tastr::parser {

class Lexer: public yyFlexLexer {
  public:
    explicit Lexer(tastr::parser::ParsingContext& parsing_context);

    virtual int yylex(tastr::parser::Parser::semantic_type* yylval,
                      tastr::parser::Parser::location_type* yylloc);

    ParsingContext& get_parsing_context() {
        return parsing_context_;
    }

    const ParsingContext& get_parsing_context() const {
        return parsing_context_;
    }

    void set_debug_level(bool debug) {
        yy_flex_debug = debug;
    }

    std::string& get_identifier() {
        return identifier_;
    }

    std::string extract_identifier() {
        std::string result = identifier_;
        identifier_.clear();
        return result;
    }

  private:
    ParsingContext& parsing_context_;
    std::string identifier_;
};

} // namespace tastr::parser

#endif /* TASTR_LEXER_HPP */
