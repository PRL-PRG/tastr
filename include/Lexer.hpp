#ifndef RTYPESPARSER_LEXER_HPP
#define RTYPESPARSER_LEXER_HPP

#include "Parser.hxx"
#include "ParsingContext.h"

/* https://stackoverflow.com/questions/40663527/how-to-inherit-from-yyflexlexer */
#if !defined(yyFlexLexerOnce)
#    include <FlexLexer.h>
#endif

/* Tell flex which function to define */
#undef YY_DECL
#define YY_DECL                                       \
    int rtype::parser::Lexer::yylex(                  \
        rtype::parser::Parser::semantic_type* yylval, \
        rtype::parser::Parser::location_type* yylloc)



namespace rtype::parser {

class Lexer: public yyFlexLexer {
  public:
    explicit Lexer(rtype::parser::ParsingContext& context);

    virtual int yylex(rtype::parser::Parser::semantic_type* yylval,
                      rtype::parser::Parser::location_type* yylloc);
};

} // namespace rtype::parser

#endif /* RTYPESPARSER_LEXER_HPP */
