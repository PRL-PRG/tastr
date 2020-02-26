%{ /* -*- C++ -*- */
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <cstring> // strerror
# include <string>
# include "ParserContext.h"
# include "Parser.hpp"
%}

%option noyywrap nounput noinput batch debug

%{
%}

INTEGER      integer
DOUBLE       double
COMPLEX      complex
CHARACTER    character
LOGICAL      logical
RAW          raw
LIST         list
STRUCT       struct
BLANK        [ \t\r]
TYPEDECL     type
PACKAGENAME  [a-zA-Z]+
IDENTIFIER   [a-zA-Z.][a-zA-Z0-9._]*

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}
%%
%{
  // A handy shortcut to the location held by ParserContext.
    yy::location& loc = parser_context.get_location();
  // Code run each time yylex is called.
  loc.step ();
%}

{BLANK}+    loc.step ();
\n+         loc.lines (yyleng); loc.step ();
"|"         return yy::Parser::make_OR(yytext, loc);
"!"         return yy::Parser::make_EXCLAMATION(yytext, loc);
"=>"        return yy::Parser::make_ARROW(yytext, loc);
","         return yy::Parser::make_COMMA(yytext, loc);
"("         return yy::Parser::make_LPAREN(yytext, loc);
")"         return yy::Parser::make_RPAREN(yytext, loc);
"["         return yy::Parser::make_LBRACKET(yytext, loc);
"]"         return yy::Parser::make_RBRACKET(yytext, loc);
"<"         return yy::Parser::make_LANGLEBRACKET(yytext, loc);
">"         return yy::Parser::make_RANGLEBRACKET(yytext, loc);
";"         return yy::Parser::make_SEMICOLON(yytext, loc);
{INTEGER}   return yy::Parser::make_INTEGER(yytext, loc);
{DOUBLE}    return yy::Parser::make_DOUBLE(yytext, loc);
{COMPLEX}   return yy::Parser::make_COMPLEX(yytext, loc);
{CHARACTER} return yy::Parser::make_CHARACTER(yytext, loc);
{LOGICAL}   return yy::Parser::make_LOGICAL(yytext, loc);
{RAW}       return yy::Parser::make_RAW(yytext, loc);
{LIST}      return yy::Parser::make_LIST(yytext, loc);
{STRUCT}    return yy::Parser::make_STRUCT(yytext, loc);
{TYPEDECL}  return yy::Parser::make_TYPEDECL(yytext, loc);
{PACKAGENAME}::{IDENTIFIER} return yy::Parser::make_QUALFUN(yytext, loc);
{IDENTIFIER}       return yy::Parser::make_TAG(yytext, loc);
.           {
                throw yy::Parser::syntax_error(loc, "invalid character: " + std::string(yytext));
            }
<<EOF>>     return yy::Parser::make_EOF(loc);
%%

void
ParserContext::scan_begin ()
{
    yy_flex_debug = is_trace_scanning_enabled();
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      std::cerr << "cannot open " << file << ": " << strerror(errno) << '\n';
      exit (EXIT_FAILURE);
    }
}

void
ParserContext::scan_end ()
{
  fclose (yyin);
}
