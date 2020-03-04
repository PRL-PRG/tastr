#ifndef TASTR_LEXER_HPP
#define TASTR_LEXER_HPP

#include "Parser.hxx"
#include "ParsingContext.hpp"

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
    explicit Lexer(tastr::parser::ParsingContext& context);

    virtual int yylex(tastr::parser::Parser::semantic_type* yylval,
                      tastr::parser::Parser::location_type* yylloc);

    void set_debug_level(bool debug) {
        yy_flex_debug = debug;
    }
};

} // namespace tastr::parser

#endif /* TASTR_LEXER_HPP */
