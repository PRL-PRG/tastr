%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.5.2"
%defines

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
  #include <memory>
  #include "rtypes.h"
  class RTypesParser;
}

// The parsing context.
%param { RTypesParser& rtypesparser }

%locations

%define parse.trace
%define parse.error verbose

%code {
#include "RTypesParser.h"

}

%define api.token.prefix {TOKEN_}

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
%nterm <ScalarRType*>          scalartype
%nterm <VectorRType*>          vectortype
%nterm <NoNaRType*>            nonavectortype
%nterm <RTypeSequence*>        typeseq
%nterm <RTypeNamedSequence*>   namedtypeseq
%nterm <FunctionRType*>        functiontype
%nterm <GroupRType*>           grouptype
%nterm <RType*>                nonuniontype
%nterm <ListRType*>            listtype
%nterm <StructRType*>          structtype
%nterm <RType*>                type

%right ARROW
%nonassoc COMMA COLON EXCLAMATION LPAREN LBRACKET LANGLEBRACKET
%left OR

/* %printer { yyo << $$.get(); } <std::unique_ptr<RType>>; */
%printer { yyo << $$; } <*>;

%%
%start type;

scalartype:         INTEGER                                 {
                                                                $$ = new IntegerRType();
                                                            }
          |         DOUBLE                                  {
                                                                $$ = new DoubleRType();
                                                            }
          |         COMPLEX                                 {
                                                                $$ = new ComplexRType();
                                                            }
          |         CHARACTER                               {
                                                                $$ = new CharacterRType();
                                                            }
          |         LOGICAL                                 {
                                                                $$ = new LogicalRType();
                                                            }
          |         RAW                                     {
                                                                $$ = new RawRType();
                                                            }
          ;

vectortype:         scalartype "[" "]"                      {
                                                                std::unique_ptr<ScalarRType> scalar_type($1);
                                                                $$ = new VectorRType(std::move(scalar_type));
                                                            }
          ;

nonavectortype:     "!" vectortype                          {
                                                                std::unique_ptr<VectorRType> vector_type($2);
                                                                $$ = new NoNaRType(std::move(vector_type));
                                                            }
              ;

listtype:           LIST "<" typeseq ">"                    {
                                                                std::unique_ptr<RTypeSequence> type_sequence($3);
                                                                $$ = new ListRType(std::move(type_sequence));
                                                            }
        ;

typeseq:                                                    {
                                                                $$ = new RTypeSequence();
                                                            }
       |            type                                    {
                                                                std::unique_ptr<RType> type($1);
                                                                $$ = new RTypeSequence(std::move(type));
                                                            }
       |            typeseq "," type                        {
                                                                std::unique_ptr<RType> type($3);
                                                                $1 -> push_back(std::move(type));
                                                            }
       ;

structtype:         STRUCT "<" namedtypeseq ">"             {
                                                                std::unique_ptr<RTypeNamedSequence> types($3);
                                                                $$ = new StructRType(std::move(types));
                                                            }
          ;

namedtypeseq:       IDENTIFIER ":" type                     {
                                                                std::unique_ptr<RType> type($3);
                                                                $$ = new RTypeNamedSequence($1, std::move(type));
                                                            }
            |       namedtypeseq "," IDENTIFIER ":" type    {
                                                                std::unique_ptr<RType> type($5);
                                                                $$ = $1; $$ -> push_back($3, std::move(type));
                                                            }
            ;

functiontype:       "<" typeseq ">" "=>" type               {
                                                                std::unique_ptr<RTypeSequence> parameter_types($2);
                                                                std::unique_ptr<RType> return_type($5);
                                                                $$ = new FunctionRType(std::move(parameter_types), std::move(return_type));
                                                            }
            ;

grouptype:          "(" type ")"                            {
                                                                std::unique_ptr<RType> type($2);
                                                                $$ = new GroupRType(std::move(type));
                                                            }
         ;

nonuniontype:       scalartype                              {   $$ = $1; }
            |       vectortype                              {   $$ = $1; }
            |       nonavectortype                          {   $$ = $1; }
            |       functiontype                            {   $$ = $1; }
            |       structtype                              {   $$ = $1; }
            |       listtype                                {   $$ = $1; }
            |       grouptype                               {   $$ = $1; }
            ;

type:               nonuniontype                            {   $$ = $1; }
    |               type "|" nonuniontype                   {
                                                                std::unique_ptr<RType> left_type($1);
                                                                std::unique_ptr<RType> right_type($3);
                                                                $$ = new UnionRType(std::move(left_type), std::move(right_type));
                                                            }
    ;


/*%empty                { $$ = ; } */

%%

void
yy::parser::error (const location_type& l, const std::string& m) {
  std::cerr << l << ": " << m << '\n';
}
