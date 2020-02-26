%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.5.2"
%defines

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
  #include "ast/node/CharacterType.h"
  #include "ast/node/ComplexType.h"
  #include "ast/node/CompositeType.h"
  #include "ast/node/DoubleType.h"
  #include "ast/node/FunctionType.h"
  #include "ast/node/GroupType.h"
  #include "ast/node/IntegerType.h"
  #include "ast/node/ListType.h"
  #include "ast/node/LogicalType.h"
  #include "ast/node/NamedType.h"
  #include "ast/node/NoNaType.h"
  #include "ast/node/RawType.h"
  #include "ast/node/ScalarType.h"
  #include "ast/node/StructType.h"
  #include "ast/node/Type.h"
  #include "ast/node/UnionType.h"
  #include "ast/node/VectorType.h"
  #include "ast/node/ParameterType.h"
  class RTypesParser;
  using namespace rtype::ast::node;
  #include "utilities.h"
}

// The parsing context.
%param { RTypesParser& rtypesparser }

%locations

%define parse.trace
%define parse.error verbose

%code {
  #include "RTypesParser.h"
  #include "utilities.h"
}

%define api.token.prefix {TOKEN_}

%token END           0             "end of file";
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
%nterm <ScalarType*>          scalartype
%nterm <VectorType*>          vectortype
%nterm <NoNaType*>            nonavectortype
%nterm <std::vector<std::unique_ptr<Type>>*>         typeseq
%nterm <NamedType*>    namedtype
%nterm <std::vector<std::unique_ptr<NamedType>>*>    namedtypeseq
%nterm <FunctionType*>        functiontype
%nterm <GroupType*>           grouptype
%nterm <Type*>                nonuniontype
%nterm <ListType*>            listtype
%nterm <StructType*>          structtype
%nterm <Type*>                type


%right ARROW
%nonassoc COMMA COLON EXCLAMATION LPAREN LBRACKET LANGLEBRACKET
%left OR

%printer { /* Type& type = *$$; */ yyo << to_string(*$$); } <Type*>;
%printer { /* Type& type = *$$; */ yyo << to_string(*$$); } <VectorType*>;
%printer { /* Type& type = *$$; */ yyo << to_string(*$$); } <NoNaType*>;
%printer { /* Type& type = *$$; */ yyo << to_string(*$$); } <FunctionType*>;
%printer { /* Type& type = *$$; */ yyo << to_string(*$$); } <GroupType*>;
%printer { /* Type& type = *$$; */ yyo << to_string(*$$); } <ListType*>;
%printer { /* Type& type = *$$; */ yyo << to_string(*$$); } <StructType*>;
%printer { /* Type& type = *$$; */ yyo << to_string(*$$); } <ScalarType*>;

%printer { yyo << $$; } <*>;

/*
%destructor { delete $$; } scalartype
%destructor { delete $$; } vectortype
%destructor { delete $$; } nonavectortype
%destructor { delete $$; } typeseq
%destructor { delete $$; } namedtypeseq
%destructor { delete $$; } functiontype
%destructor { delete $$; } grouptype
%destructor { delete $$; } nonuniontype
%destructor { delete $$; } listtype
%destructor { delete $$; } structtype
%destructor { delete $$; } type
*/

%%
%start start;

scalartype:         INTEGER                                 {
                                                                $$ = new IntegerType();
                                                            }
          |         DOUBLE                                  {
                                                                $$ = new DoubleType();
                                                            }
          |         COMPLEX                                 {
                                                                $$ = new ComplexType();
                                                            }
          |         CHARACTER                               {
                                                                $$ = new CharacterType();
                                                            }
          |         LOGICAL                                 {
                                                                $$ = new LogicalType();
                                                            }
          |         RAW                                     {
                                                                $$ = new RawType();
                                                            }
          ;

vectortype:         scalartype "[" "]"                      {
                                                                std::unique_ptr<ScalarType> scalar_type($1);
                                                                $$ = new VectorType(std::move(scalar_type));
                                                            }
          ;

nonavectortype:     "!" vectortype                          {
                                                                std::unique_ptr<VectorType> vector_type($2);
                                                                $$ = new NoNaType(std::move(vector_type));
                                                            }
              ;

listtype:           LIST "<" typeseq ">"                    {
                                                                std::unique_ptr<std::vector<std::unique_ptr<Type>>> sequence($3);
                                                                $$ = new ListType(std::move(sequence));
                                                            }
        ;

typeseq:           %empty                                   {
                                                                $$ = new std::vector<std::unique_ptr<Type>>();
                                                            }
       |            type                                    {
                                                                std::unique_ptr<Type> type($1);
                                                                $$ = new std::vector<std::unique_ptr<Type>>();
                                                                $$ -> push_back(std::move(type));
                                                            }
       |            typeseq "," type                        {
                                                                std::unique_ptr<Type> type($3);
                                                                $1 -> push_back(std::move(type));
                                                                $$ = $1;
                                                            }
       ;

structtype:         STRUCT "<" namedtypeseq ">"             {
                                                                std::unique_ptr<std::vector<std::unique_ptr<NamedType>>> sequences($3);
                                                                $$ = new StructType(std::move(sequences));
                                                            }
          ;


namedtype:          IDENTIFIER ":" type                     {
                                                                std::string name($1);
                                                                std::unique_ptr<Type> type($3);
                                                                $$ = new NamedType(name, std::move(type));
                                                            }
         ;

namedtypeseq:       %empty                                  {
                                                                $$ = new std::vector<std::unique_ptr<NamedType>>();
                                                            }
            |      namedtype                                {
                                                                std::unique_ptr<NamedType> named_type($1);
                                                                $$ = new std::vector<std::unique_ptr<NamedType>>();
                                                                $$ -> push_back(std::move(named_type));
                                                            }
            |       namedtypeseq "," namedtype              {
                                                                std::unique_ptr<NamedType> named_type($3);
                                                                $1 -> push_back(std::move(named_type));
                                                                $$ = $1;
                                                            }
            ;

functiontype:       "<" typeseq ">" "=>" type               {
                                                                std::unique_ptr<std::vector<std::unique_ptr<Type>>> sequence($2);
                                                                ParameterType *types = new ParameterType(std::move(sequence));
                                                                std::unique_ptr<ParameterType> parameter_types(types);
                                                                std::unique_ptr<Type> return_type($5);
                                                                $$ = new FunctionType(std::move(parameter_types), std::move(return_type));
                                                            }
            ;

grouptype:          "(" type ")"                            {
                                                                std::unique_ptr<Type> type($2);
                                                                $$ = new GroupType(std::move(type));
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
                                                                std::unique_ptr<Type> left_type($1);
                                                                std::unique_ptr<Type> right_type($3);
                                                                $$ = new UnionType(std::move(left_type), std::move(right_type));
                                                            }
    ;

start:              %empty                                  { }
     |              type                                    {
                                                                     std::unique_ptr<Type> part_type($1);
                                                                     std::cout << to_string(*part_type.get());
                                                                     /*rtypesparser.get_ast().push_back(std::move(part_type));*/
                                                            }
     |              start ";" type                          {
                                                                     std::unique_ptr<Type> part_type($3);
                                                                     std::cout << to_string(*part_type.get());
                                                                     /*rtypesparser.get_ast().push_back(std::move(part_type));*/
                                                            }

%%

void
yy::parser::error (const location_type& l, const std::string& m) {
  std::cerr << l << ": " << m << '\n';
}
