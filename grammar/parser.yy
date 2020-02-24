%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.5.2"
%defines

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
  # include <string>
  class RTypesParser;
}

// The parsing context.
%param { RTypesParser& rtypesparser }

%locations

%define parse.trace
%define parse.error verbose

%code {
# include "RTypesParser.h"
}

%define api.token.prefix {TOK_}
%token
  END  0  "end of file"
  ASSIGN  ":="
  MINUS   "-"
  PLUS    "+"
  STAR    "*"
  SLASH   "/"
  LPAREN  "("
  RPAREN  ")"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%nterm <int> exp

%printer { yyo << $$; } <*>;

%%
%start unit;
unit: assignments exp  { rtypesparser.set_result($2); };

assignments:
  %empty                 {}
| assignments assignment {};

assignment:
  "identifier" ":=" exp { rtypesparser.set_variable($1, $3); };

%left "+" "-";
%left "*" "/";
exp:
  "number"
| "identifier"  { $$ = rtypesparser.get_variable($1); }
| exp "+" exp   { $$ = $1 + $3; }
| exp "-" exp   { $$ = $1 - $3; }
| exp "*" exp   { $$ = $1 * $3; }
| exp "/" exp   { $$ = $1 / $3; }
| "(" exp ")"   { $$ = $2; }
%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
