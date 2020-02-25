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

%token END  0        "end of file";
%token <std::string> OR            "|";
%token <std::string> EXCLAMATION   "!";
%token <std::string> ARROW         "=>";
%token <std::string> COMMA         ",";
%token <std::string> COLON         ":";
%token <std::string> LPAREN        "(";
%token <std::string> RPAREN        ")";
%token <std::string> LBRACKET      "[";
%token <std::string> RBRACKET      "]";
%token <std::string> LANGLEBRACKET "<";
%token <std::string> RANGLEBRACKET ">";
%token <std::string> IDENTIFIER;
%token <std::string> INTEGER;
%token <std::string> DOUBLE;
%token <std::string> COMPLEX;
%token <std::string> CHARACTER;
%token <std::string> LOGICAL;
%token <std::string> RAW;
%token <std::string> LIST;
%token <std::string> STRUCT;
%nterm <int> scalartype
%nterm <int> vectortype
%nterm <int> typeseq
%nterm <int> namedtypeseq
%nterm <int> functiontype
%nterm <int> grouptype
%nterm <int> nonuniontype
%nterm <int> listtype
%nterm <int> structtype
%nterm <int> type

%right ARROW
%nonassoc COMMA COLON EXCLAMATION LPAREN LBRACKET LANGLEBRACKET
%left OR

%printer { yyo << $$; } <*>;

%%
%start type;

scalartype:
  INTEGER     { $$ = 0; std::cout << "PARSER: " << $1 << std::endl; }
| DOUBLE      { $$ = 0; std::cout << "PARSER: " << $1 << std::endl; }
| COMPLEX     { $$ = 0; std::cout << "PARSER: " << $1 << std::endl; }
| CHARACTER   { $$ = 0; std::cout << "PARSER: " << $1 << std::endl; }
| LOGICAL     { $$ = 0; std::cout << "PARSER: " << $1 << std::endl; }
| RAW         { $$ = 0; std::cout << "PARSER: " << $1 << std::endl; }

vectortype:
  scalartype LBRACKET RBRACKET     { $$ = 0; std::cout << "PARSER: " <<  $1 << "[" << "]" << std::endl; }
| EXCLAMATION scalartype LBRACKET RBRACKET  { $$ = 0; std::cout << "PARSER: " <<  "!" << $1 << "[" << "]" << std::endl; }

listtype: LIST LANGLEBRACKET typeseq RANGLEBRACKET { $$ = 0; std::cout << "PARSER: "  << $1 << "<" << ">" << std::endl; }

typeseq:
  type                { $$ = 0; std::cout << "PARSER: "  << $1 << std::endl; }
| typeseq COMMA type    { $$ = 0; std::cout << "PARSER: "  << $1 << std::endl; }

structtype: STRUCT LANGLEBRACKET namedtypeseq RANGLEBRACKET { $$ = 0; std::cout << "PARSER: " << $1 << "<" << ">" << std::endl; }

namedtypeseq:
  IDENTIFIER COLON type                    { $$ = 0; std::cout << "PARSER: "  << $1 << $2 << $3 << std::endl; }
| namedtypeseq COMMA IDENTIFIER COLON type { $$ = 0; std::cout << "PARSER: " << $1 << $2 << $3 << std::endl; }

functiontype:
    LANGLEBRACKET typeseq RANGLEBRACKET ARROW type   { $$ = 0; std::cout << "PARSER: " << $4 << std::endl; }

grouptype: LPAREN type RPAREN                  { $$ = 0; std::cout << "PARSER: " << "(" << ")" <<  std::endl; }

nonuniontype:
   scalartype   { $$ = 0; }
|  vectortype   { $$ = 0; }
|  functiontype   { $$ = 0; }
|  structtype   { $$ = 0; }
|  listtype   { $$ = 0; }
|  grouptype   { $$ = 0; }

type:
  %empty          { $$ = 0; }
 | nonuniontype   { $$ = 0; }
 | type OR nonuniontype { $$ = 0; }

%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
