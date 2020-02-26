%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.5.2"
%defines

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
#include "ast.h"
class RTypesParser;
using rtype::ast::node::CharacterType;
using rtype::ast::node::ComplexType;
using rtype::ast::node::DoubleType;
using rtype::ast::node::FunctionType;
using rtype::ast::node::FunctionTypePtr;
using rtype::ast::node::GroupType;
using rtype::ast::node::GroupTypePtr;
using rtype::ast::node::IntegerType;
using rtype::ast::node::ListType;
using rtype::ast::node::ListTypePtr;
using rtype::ast::node::LogicalType;
using rtype::ast::node::TaggedType;
using rtype::ast::node::TaggedTypePtr;
using rtype::ast::node::TaggedTypeUPtr;
using rtype::ast::node::NoNaType;
using rtype::ast::node::NoNaTypePtr;
using rtype::ast::node::ParameterType;
using rtype::ast::node::ParameterTypePtr;
using rtype::ast::node::ParameterTypeUPtr;
using rtype::ast::node::RawType;
using rtype::ast::node::ScalarTypePtr;
using rtype::ast::node::ScalarTypeUPtr;
using rtype::ast::node::sequence_t;
using rtype::ast::node::sequence_ptr_t;
using rtype::ast::node::sequence_uptr_t;
using rtype::ast::node::StructType;
using rtype::ast::node::StructTypePtr;
using rtype::ast::node::Type;
using rtype::ast::node::TypePtr;
using rtype::ast::node::TypeUPtr;
using rtype::ast::node::UnionType;
using rtype::ast::node::UnionTypePtr;
using rtype::ast::node::VectorType;
using rtype::ast::node::VectorTypePtr;
using rtype::ast::node::VectorTypeUPtr;
using rtype::ast::node::TypeDeclaration;
using rtype::ast::node::TypeDeclarationPtr;
using rtype::ast::node::TypeDeclarationUPtr;

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

%token EOF                          0             "end of file";
%token <std::string>                OR            "|";
%token <std::string>                EXCLAMATION   "!";
%token <std::string>                ARROW         "=>";
%token <std::string>                COMMA         ",";
%token <std::string>                LPAREN        "(";
%token <std::string>                RPAREN        ")";
%token <std::string>                LBRACKET      "[";
%token <std::string>                RBRACKET      "]";
%token <std::string>                LANGLEBRACKET "<";
%token <std::string>                RANGLEBRACKET ">";
%token <std::string>                SEMICOLON     ";";
%token <std::string>                INTEGER;
%token <std::string>                DOUBLE;
%token <std::string>                COMPLEX;
%token <std::string>                CHARACTER;
%token <std::string>                LOGICAL;
%token <std::string>                RAW;
%token <std::string>                LIST;
%token <std::string>                STRUCT;
%token <std::string>                TYPEDECL;
%token <std::string>                QUALFUN;
%token <std::string>                TAG;
%nterm <ScalarTypePtr>              scalartype
%nterm <VectorTypePtr>              vectortype
%nterm <NoNaTypePtr>                nonavectortype
%nterm <sequence_ptr_t<Type>>       typeseq
%nterm <TaggedTypePtr>              namedtype
%nterm <sequence_ptr_t<TaggedType>> namedtypeseq
%nterm <FunctionTypePtr>            functiontype
%nterm <GroupTypePtr>               grouptype
%nterm <TypePtr>                    nonuniontype
%nterm <ListTypePtr>                listtype
%nterm <StructTypePtr>              structtype
%nterm <TypePtr>                    type
%nterm <TypeDeclarationPtr>         decltype


%right ARROW
%nonassoc COMMA EXCLAMATION LPAREN LBRACKET LANGLEBRACKET
%left OR

%printer { /* Type& type = *$$; */ yyo << to_string(*$$); } <TypePtr>;
%printer { /* Type& type = *$$; */ yyo << to_string(*$$); } <VectorTypePtr>;
%printer { /* Type& type = *$$; */ yyo << to_string(*$$); } <NoNaTypePtr>;
%printer { /* Type& type = *$$; */ yyo << to_string(*$$); } <FunctionTypePtr>;
%printer { /* Type& type = *$$; */ yyo << to_string(*$$); } <GroupTypePtr>;
%printer { /* Type& type = *$$; */ yyo << to_string(*$$); } <ListTypePtr>;
%printer { /* Type& type = *$$; */ yyo << to_string(*$$); } <StructTypePtr>;
%printer { /* Type& type = *$$; */ yyo << to_string(*$$); } <ScalarTypePtr>;

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
                                                                ScalarTypeUPtr scalar_type($1);
                                                                $$ = new VectorType(std::move(scalar_type));
                                                            }
          ;

nonavectortype:     "!" vectortype                          {
                                                                VectorTypeUPtr vector_type($2);
                                                                $$ = new NoNaType(std::move(vector_type));
                                                            }
              ;

listtype:           LIST "<" typeseq ">"                    {
                                                                sequence_uptr_t<Type> sequence($3);
                                                                $$ = new ListType(std::move(sequence));
                                                            }
        ;

typeseq:           %empty                                   {
                                                                $$ = new sequence_t<Type>();
                                                            }
       |            type                                    {
                                                                TypeUPtr type($1);
                                                                $$ = new sequence_t<Type>();
                                                                $$ -> push_back(std::move(type));
                                                            }
       |            typeseq "," type                        {
                                                                TypeUPtr type($3);
                                                                $1 -> push_back(std::move(type));
                                                                $$ = $1;
                                                            }
       ;

structtype:         STRUCT "<" namedtypeseq ">"             {
                                                                sequence_uptr_t<TaggedType> sequences($3);
                                                                $$ = new StructType(std::move(sequences));
                                                            }
          ;


namedtype:          TAG ":" type                            {
                                                                std::string name($1);
                                                                TypeUPtr type($3);
                                                                $$ = new TaggedType(name, std::move(type));
                                                            }
         ;

namedtypeseq:       %empty                                  {
                                                                $$ = new sequence_t<TaggedType>();
                                                            }
            |      namedtype                                {
                                                                TaggedTypeUPtr named_type($1);
                                                                $$ = new sequence_t<TaggedType>();
                                                                $$ -> push_back(std::move(named_type));
                                                            }
            |       namedtypeseq "," namedtype              {
                                                                TaggedTypeUPtr named_type($3);
                                                                $1 -> push_back(std::move(named_type));
                                                                $$ = $1;
                                                            }
            ;

functiontype:       "<" typeseq ">" "=>" type               {
                                                                sequence_uptr_t<Type> sequence($2);
                                                                ParameterTypePtr types = new ParameterType(std::move(sequence));
                                                                ParameterTypeUPtr parameter_types(types);
                                                                TypeUPtr return_type($5);
                                                                $$ = new FunctionType(std::move(parameter_types), std::move(return_type));
                                                            }
            ;

grouptype:          "(" type ")"                            {
                                                                TypeUPtr type($2);
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
                                                                TypeUPtr left_type($1);
                                                                TypeUPtr right_type($3);
                                                                $$ = new UnionType(std::move(left_type), std::move(right_type));
                                                            }
    ;

decltype:           TYPEDECL QUALFUN type ";"               {
                                                                TypeUPtr type($3);
                                                                $$ = new TypeDeclaration($2, std::move(type));
                                                            }
        ;

decllist:           decltype                                {
                                                                TypeDeclarationUPtr type_decl($1);
                                                                std::cout << to_string(*type_decl.get());
                                                                /*rtypesparser.get_ast().push_back(std::move(part_type));*/
                                                            }
        |           decllist decltype                       {
                                                                TypeDeclarationUPtr type_decl($2);
                                                                std::cout << to_string(*type_decl.get());
                                                                /*rtypesparser.get_ast().push_back(std::move(part_type));*/
                                                            }
        ;

start:              EOF                                     { }
     |              decllist EOF                            { }
     ;

%%

void
yy::parser::error (const location_type& l, const std::string& m) {
  std::cerr << l << ": " << m << '\n';
}
