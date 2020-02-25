%{ /* -*- C++ -*- */
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <cstring> // strerror
# include <string>
# include "RTypesParser.h"
# include "parser.hpp"
%}

%option noyywrap nounput noinput batch debug

%{
%}

integer   integer
double    double
complex   complex
character character
logical   logical
raw       raw
list      list
struct    struct
blank     [ \t\r]
id        [a-zA-Z.][a-zA-Z_0-9.]*

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}
%%
%{
  // A handy shortcut to the location held by RTypesParser.
    yy::location& loc = rtypesparser.get_location();
  // Code run each time yylex is called.
  loc.step ();
%}
{blank}+   loc.step ();
\n+        loc.lines (yyleng); loc.step ();


"|"         return yy::parser::make_OR(yytext, loc);
"!"         return yy::parser::make_EXCLAMATION(yytext, loc);
"=>"        return yy::parser::make_ARROW(yytext, loc);
","         return yy::parser::make_COMMA(yytext, loc);
"("         return yy::parser::make_LPAREN(yytext, loc);
")"         return yy::parser::make_RPAREN(yytext, loc);
"["         return yy::parser::make_LBRACKET(yytext, loc);
"]"         return yy::parser::make_RBRACKET(yytext, loc);
"<"         return yy::parser::make_LANGLEBRACKET(yytext, loc);
">"         return yy::parser::make_RANGLEBRACKET(yytext, loc);
":"         return yy::parser::make_COLON(yytext, loc);

{integer}   return yy::parser::make_INTEGER(yytext, loc);
{double}    return yy::parser::make_DOUBLE(yytext, loc);
{complex}   return yy::parser::make_COMPLEX(yytext, loc);
{character} return yy::parser::make_CHARACTER(yytext, loc);
{logical}   return yy::parser::make_LOGICAL(yytext, loc);
{raw}       return yy::parser::make_RAW(yytext, loc);
{list}      return yy::parser::make_LIST(yytext, loc);
{struct}    return yy::parser::make_STRUCT(yytext, loc);
{id}        return yy::parser::make_IDENTIFIER (yytext, loc);
.           {
                throw yy::parser::syntax_error(loc, "invalid character: " + std::string(yytext));
            }
<<EOF>>     return yy::parser::make_END (loc);
%%

void
RTypesParser::scan_begin ()
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
RTypesParser::scan_end ()
{
  fclose (yyin);
}
