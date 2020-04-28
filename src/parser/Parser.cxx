// A Bison parser, made by GNU Bison 3.5.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "Parser.hxx"


// Unqualified %code blocks.
#line 287 "Parser.yxx"

    #include "parser/ParsingContext.hpp"
    #include "parser/Lexer.hpp"
    #undef yylex
    #define yylex lexer.yylex
// TODO op
TerminatorNodePtr create_terminator(const std::string& value,
                                    tastr::parser::Location& location,
                                    tastr::parser::ParsingContext& context) {
    TerminatorNodePtr terminator = new TerminatorNode(value);
    terminator -> set_location(location);
    return terminator;
}
// TODO op
IdentifierNodePtr create_identifier(const std::string& value,
                                    bool quoted,
                                    bool missing,
                                    tastr::parser::Location& location,
                                    tastr::parser::ParsingContext& context) {
    IdentifierNodePtr identifier = new IdentifierNode(value, quoted, missing);
    identifier -> set_location(location);
    return identifier;
}
// TODO op
OperatorNodePtr create_operator(const std::string& value,
                                tastr::parser::Location& location,
                                tastr::parser::ParsingContext& context) {
    OperatorNodePtr op = new OperatorNode(value);
    op -> set_location(location);
    return op;
}
// TODO op
SeparatorNodePtr create_separator(const std::string& value,
                                tastr::parser::Location& location,
                                tastr::parser::ParsingContext& context) {
    SeparatorNodePtr op = new SeparatorNode(value);
    op -> set_location(location);
    return op;
}

KeywordNodePtr create_keyword(const std::string& value,
                                tastr::parser::Location& location,
                                tastr::parser::ParsingContext& context) {
    KeywordNodePtr keyword = new KeywordNode(value);
    keyword -> set_location(location);
    return keyword;
}

template<typename T>
T* create_node_with_keyword(const std::string& value,
                            tastr::parser::Location& keyword_location,
                            tastr::parser::Location& node_location,
                            tastr::parser::ParsingContext& context) {
    KeywordNodePtr keyword = new KeywordNode(value);
    keyword -> set_location(keyword_location);
    T* node = new T(std::move(wrap(std::move(keyword))));
    node -> set_location(node_location);
    return node;
}

#line 106 "Parser.cxx"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 9 "Parser.yxx"
namespace tastr { namespace parser {
#line 198 "Parser.cxx"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (tastr::parser::Lexer& lexer_yyarg, tastr::parser::ParsingContext& context_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      lexer (lexer_yyarg),
      context (context_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
    {
      case 50: // ascalartype
        value.move< AScalarTypeNodePtr > (std::move (that.value));
        break;

      case 64: // anytype
        value.move< AnyTypeNodePtr > (std::move (that.value));
        break;

      case 59: // bytecodetype
        value.move< BytecodeTypeNodePtr > (std::move (that.value));
        break;

      case 77: // dataframetype
        value.move< DataFrameTypeNodePtr > (std::move (that.value));
        break;

      case 54: // environmenttype
        value.move< EnvironmentTypeNodePtr > (std::move (that.value));
        break;

      case 55: // expressiontype
        value.move< ExpressionTypeNodePtr > (std::move (that.value));
        break;

      case 58: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (std::move (that.value));
        break;

      case 72: // functiontype
        value.move< FunctionTypeNodePtr > (std::move (that.value));
        break;

      case 73: // grouptype
        value.move< GroupTypeNodePtr > (std::move (that.value));
        break;

      case 81: // identifier
        value.move< IdentifierNodePtr > (std::move (that.value));
        break;

      case 56: // languagetype
        value.move< LanguageTypeNodePtr > (std::move (that.value));
        break;

      case 75: // listtype
        value.move< ListTypeNodePtr > (std::move (that.value));
        break;

      case 52: // nascalartype
        value.move< NAScalarTypeNodePtr > (std::move (that.value));
        break;

      case 66: // typeseq
      case 68: // namedtypeseq
      case 70: // paramtypeseq
      case 71: // params
      case 76: // structelements
      case 79: // tupleelements
        value.move< NodePtr > (std::move (that.value));
        break;

      case 60: // pairlisttype
        value.move< PairlistTypeNodePtr > (std::move (that.value));
        break;

      case 51: // rawascalartype
        value.move< RawAScalarTypeNodePtr > (std::move (that.value));
        break;

      case 61: // s4type
        value.move< S4TypeNodePtr > (std::move (that.value));
        break;

      case 53: // scalartype
        value.move< ScalarTypeNodePtr > (std::move (that.value));
        break;

      case 78: // structtype
        value.move< StructTypeNodePtr > (std::move (that.value));
        break;

      case 57: // symboltype
        value.move< SymbolTypeNodePtr > (std::move (that.value));
        break;

      case 67: // namedtype
        value.move< TagTypePairNodePtr > (std::move (that.value));
        break;

      case 80: // tupletype
        value.move< TupleTypeNodePtr > (std::move (that.value));
        break;

      case 85: // decltype
        value.move< TypeDeclarationNodePtr > (std::move (that.value));
        break;

      case 69: // paramtype
      case 74: // nonuniontype
      case 82: // uniontype
      case 83: // nulltype
      case 84: // type
        value.move< TypeNodePtr > (std::move (that.value));
        break;

      case 63: // unknowntype
        value.move< UnknownTypeNodePtr > (std::move (that.value));
        break;

      case 65: // vectortype
        value.move< VectorTypeNodePtr > (std::move (that.value));
        break;

      case 62: // weakreftype
        value.move< WeakReferenceTypeNodePtr > (std::move (that.value));
        break;

      case 3: // "|"
      case 4: // "^"
      case 5: // "=>"
      case 6: // ","
      case 7: // "(("
      case 8: // "("
      case 9: // "))"
      case 10: // ")"
      case 11: // "[]"
      case 12: // "<"
      case 13: // ">"
      case 14: // "[["
      case 15: // "]]"
      case 16: // "{{"
      case 17: // "}}"
      case 18: // ";"
      case 19: // ":"
      case 20: // "..."
      case 21: // "???"
      case 22: // "?"
      case 23: // "null"
      case 24: // INTEGER
      case 25: // DOUBLE
      case 26: // COMPLEX
      case 27: // CHARACTER
      case 28: // LOGICAL
      case 29: // RAW
      case 30: // ENVIRONMENT
      case 31: // EXPRESSION
      case 32: // LANGUAGE
      case 33: // SYMBOL
      case 34: // EXTERNALPOINTER
      case 35: // BYTECODE
      case 36: // PAIRLIST
      case 37: // S4
      case 38: // WEAKREF
      case 39: // TUPLE
      case 40: // LIST
      case 41: // DATAFRAME
      case 42: // STRUCT
      case 43: // ANY
      case 44: // TYPEDECL
      case 45: // IDENTIFIER
      case 46: // QUOTED_IDENTIFIER
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
    {
      case 50: // ascalartype
        value.copy< AScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 64: // anytype
        value.copy< AnyTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 59: // bytecodetype
        value.copy< BytecodeTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 77: // dataframetype
        value.copy< DataFrameTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 54: // environmenttype
        value.copy< EnvironmentTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 55: // expressiontype
        value.copy< ExpressionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 58: // externalptrtype
        value.copy< ExternalPointerTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 72: // functiontype
        value.copy< FunctionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 73: // grouptype
        value.copy< GroupTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 81: // identifier
        value.copy< IdentifierNodePtr > (YY_MOVE (that.value));
        break;

      case 56: // languagetype
        value.copy< LanguageTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 75: // listtype
        value.copy< ListTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 52: // nascalartype
        value.copy< NAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 66: // typeseq
      case 68: // namedtypeseq
      case 70: // paramtypeseq
      case 71: // params
      case 76: // structelements
      case 79: // tupleelements
        value.copy< NodePtr > (YY_MOVE (that.value));
        break;

      case 60: // pairlisttype
        value.copy< PairlistTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 51: // rawascalartype
        value.copy< RawAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 61: // s4type
        value.copy< S4TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 53: // scalartype
        value.copy< ScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 78: // structtype
        value.copy< StructTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 57: // symboltype
        value.copy< SymbolTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 67: // namedtype
        value.copy< TagTypePairNodePtr > (YY_MOVE (that.value));
        break;

      case 80: // tupletype
        value.copy< TupleTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 85: // decltype
        value.copy< TypeDeclarationNodePtr > (YY_MOVE (that.value));
        break;

      case 69: // paramtype
      case 74: // nonuniontype
      case 82: // uniontype
      case 83: // nulltype
      case 84: // type
        value.copy< TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 63: // unknowntype
        value.copy< UnknownTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 65: // vectortype
        value.copy< VectorTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 62: // weakreftype
        value.copy< WeakReferenceTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 3: // "|"
      case 4: // "^"
      case 5: // "=>"
      case 6: // ","
      case 7: // "(("
      case 8: // "("
      case 9: // "))"
      case 10: // ")"
      case 11: // "[]"
      case 12: // "<"
      case 13: // ">"
      case 14: // "[["
      case 15: // "]]"
      case 16: // "{{"
      case 17: // "}}"
      case 18: // ";"
      case 19: // ":"
      case 20: // "..."
      case 21: // "???"
      case 22: // "?"
      case 23: // "null"
      case 24: // INTEGER
      case 25: // DOUBLE
      case 26: // COMPLEX
      case 27: // CHARACTER
      case 28: // LOGICAL
      case 29: // RAW
      case 30: // ENVIRONMENT
      case 31: // EXPRESSION
      case 32: // LANGUAGE
      case 33: // SYMBOL
      case 34: // EXTERNALPOINTER
      case 35: // BYTECODE
      case 36: // PAIRLIST
      case 37: // S4
      case 38: // WEAKREF
      case 39: // TUPLE
      case 40: // LIST
      case 41: // DATAFRAME
      case 42: // STRUCT
      case 43: // ANY
      case 44: // TYPEDECL
      case 45: // IDENTIFIER
      case 46: // QUOTED_IDENTIFIER
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 50: // ascalartype
        value.move< AScalarTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 64: // anytype
        value.move< AnyTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 59: // bytecodetype
        value.move< BytecodeTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 77: // dataframetype
        value.move< DataFrameTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 54: // environmenttype
        value.move< EnvironmentTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 55: // expressiontype
        value.move< ExpressionTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 58: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 72: // functiontype
        value.move< FunctionTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 73: // grouptype
        value.move< GroupTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 81: // identifier
        value.move< IdentifierNodePtr > (YY_MOVE (s.value));
        break;

      case 56: // languagetype
        value.move< LanguageTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 75: // listtype
        value.move< ListTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 52: // nascalartype
        value.move< NAScalarTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 66: // typeseq
      case 68: // namedtypeseq
      case 70: // paramtypeseq
      case 71: // params
      case 76: // structelements
      case 79: // tupleelements
        value.move< NodePtr > (YY_MOVE (s.value));
        break;

      case 60: // pairlisttype
        value.move< PairlistTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 51: // rawascalartype
        value.move< RawAScalarTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 61: // s4type
        value.move< S4TypeNodePtr > (YY_MOVE (s.value));
        break;

      case 53: // scalartype
        value.move< ScalarTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 78: // structtype
        value.move< StructTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 57: // symboltype
        value.move< SymbolTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 67: // namedtype
        value.move< TagTypePairNodePtr > (YY_MOVE (s.value));
        break;

      case 80: // tupletype
        value.move< TupleTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 85: // decltype
        value.move< TypeDeclarationNodePtr > (YY_MOVE (s.value));
        break;

      case 69: // paramtype
      case 74: // nonuniontype
      case 82: // uniontype
      case 83: // nulltype
      case 84: // type
        value.move< TypeNodePtr > (YY_MOVE (s.value));
        break;

      case 63: // unknowntype
        value.move< UnknownTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 65: // vectortype
        value.move< VectorTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 62: // weakreftype
        value.move< WeakReferenceTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 3: // "|"
      case 4: // "^"
      case 5: // "=>"
      case 6: // ","
      case 7: // "(("
      case 8: // "("
      case 9: // "))"
      case 10: // ")"
      case 11: // "[]"
      case 12: // "<"
      case 13: // ">"
      case 14: // "[["
      case 15: // "]]"
      case 16: // "{{"
      case 17: // "}}"
      case 18: // ";"
      case 19: // ":"
      case 20: // "..."
      case 21: // "???"
      case 22: // "?"
      case 23: // "null"
      case 24: // INTEGER
      case 25: // DOUBLE
      case 26: // COMPLEX
      case 27: // CHARACTER
      case 28: // LOGICAL
      case 29: // RAW
      case 30: // ENVIRONMENT
      case 31: // EXPRESSION
      case 32: // LANGUAGE
      case 33: // SYMBOL
      case 34: // EXTERNALPOINTER
      case 35: // BYTECODE
      case 36: // PAIRLIST
      case 37: // S4
      case 38: // WEAKREF
      case 39: // TUPLE
      case 40: // LIST
      case 41: // DATAFRAME
      case 42: // STRUCT
      case 43: // ANY
      case 44: // TYPEDECL
      case 45: // IDENTIFIER
      case 46: // QUOTED_IDENTIFIER
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 50: // ascalartype
        value.YY_MOVE_OR_COPY< AScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 64: // anytype
        value.YY_MOVE_OR_COPY< AnyTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 59: // bytecodetype
        value.YY_MOVE_OR_COPY< BytecodeTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 77: // dataframetype
        value.YY_MOVE_OR_COPY< DataFrameTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 54: // environmenttype
        value.YY_MOVE_OR_COPY< EnvironmentTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 55: // expressiontype
        value.YY_MOVE_OR_COPY< ExpressionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 58: // externalptrtype
        value.YY_MOVE_OR_COPY< ExternalPointerTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 72: // functiontype
        value.YY_MOVE_OR_COPY< FunctionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 73: // grouptype
        value.YY_MOVE_OR_COPY< GroupTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 81: // identifier
        value.YY_MOVE_OR_COPY< IdentifierNodePtr > (YY_MOVE (that.value));
        break;

      case 56: // languagetype
        value.YY_MOVE_OR_COPY< LanguageTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 75: // listtype
        value.YY_MOVE_OR_COPY< ListTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 52: // nascalartype
        value.YY_MOVE_OR_COPY< NAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 66: // typeseq
      case 68: // namedtypeseq
      case 70: // paramtypeseq
      case 71: // params
      case 76: // structelements
      case 79: // tupleelements
        value.YY_MOVE_OR_COPY< NodePtr > (YY_MOVE (that.value));
        break;

      case 60: // pairlisttype
        value.YY_MOVE_OR_COPY< PairlistTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 51: // rawascalartype
        value.YY_MOVE_OR_COPY< RawAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 61: // s4type
        value.YY_MOVE_OR_COPY< S4TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 53: // scalartype
        value.YY_MOVE_OR_COPY< ScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 78: // structtype
        value.YY_MOVE_OR_COPY< StructTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 57: // symboltype
        value.YY_MOVE_OR_COPY< SymbolTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 67: // namedtype
        value.YY_MOVE_OR_COPY< TagTypePairNodePtr > (YY_MOVE (that.value));
        break;

      case 80: // tupletype
        value.YY_MOVE_OR_COPY< TupleTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 85: // decltype
        value.YY_MOVE_OR_COPY< TypeDeclarationNodePtr > (YY_MOVE (that.value));
        break;

      case 69: // paramtype
      case 74: // nonuniontype
      case 82: // uniontype
      case 83: // nulltype
      case 84: // type
        value.YY_MOVE_OR_COPY< TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 63: // unknowntype
        value.YY_MOVE_OR_COPY< UnknownTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 65: // vectortype
        value.YY_MOVE_OR_COPY< VectorTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 62: // weakreftype
        value.YY_MOVE_OR_COPY< WeakReferenceTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 3: // "|"
      case 4: // "^"
      case 5: // "=>"
      case 6: // ","
      case 7: // "(("
      case 8: // "("
      case 9: // "))"
      case 10: // ")"
      case 11: // "[]"
      case 12: // "<"
      case 13: // ">"
      case 14: // "[["
      case 15: // "]]"
      case 16: // "{{"
      case 17: // "}}"
      case 18: // ";"
      case 19: // ":"
      case 20: // "..."
      case 21: // "???"
      case 22: // "?"
      case 23: // "null"
      case 24: // INTEGER
      case 25: // DOUBLE
      case 26: // COMPLEX
      case 27: // CHARACTER
      case 28: // LOGICAL
      case 29: // RAW
      case 30: // ENVIRONMENT
      case 31: // EXPRESSION
      case 32: // LANGUAGE
      case 33: // SYMBOL
      case 34: // EXTERNALPOINTER
      case 35: // BYTECODE
      case 36: // PAIRLIST
      case 37: // S4
      case 38: // WEAKREF
      case 39: // TUPLE
      case 40: // LIST
      case 41: // DATAFRAME
      case 42: // STRUCT
      case 43: // ANY
      case 44: // TYPEDECL
      case 45: // IDENTIFIER
      case 46: // QUOTED_IDENTIFIER
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 50: // ascalartype
        value.move< AScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 64: // anytype
        value.move< AnyTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 59: // bytecodetype
        value.move< BytecodeTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 77: // dataframetype
        value.move< DataFrameTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 54: // environmenttype
        value.move< EnvironmentTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 55: // expressiontype
        value.move< ExpressionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 58: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 72: // functiontype
        value.move< FunctionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 73: // grouptype
        value.move< GroupTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 81: // identifier
        value.move< IdentifierNodePtr > (YY_MOVE (that.value));
        break;

      case 56: // languagetype
        value.move< LanguageTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 75: // listtype
        value.move< ListTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 52: // nascalartype
        value.move< NAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 66: // typeseq
      case 68: // namedtypeseq
      case 70: // paramtypeseq
      case 71: // params
      case 76: // structelements
      case 79: // tupleelements
        value.move< NodePtr > (YY_MOVE (that.value));
        break;

      case 60: // pairlisttype
        value.move< PairlistTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 51: // rawascalartype
        value.move< RawAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 61: // s4type
        value.move< S4TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 53: // scalartype
        value.move< ScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 78: // structtype
        value.move< StructTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 57: // symboltype
        value.move< SymbolTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 67: // namedtype
        value.move< TagTypePairNodePtr > (YY_MOVE (that.value));
        break;

      case 80: // tupletype
        value.move< TupleTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 85: // decltype
        value.move< TypeDeclarationNodePtr > (YY_MOVE (that.value));
        break;

      case 69: // paramtype
      case 74: // nonuniontype
      case 82: // uniontype
      case 83: // nulltype
      case 84: // type
        value.move< TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 63: // unknowntype
        value.move< UnknownTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 65: // vectortype
        value.move< VectorTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 62: // weakreftype
        value.move< WeakReferenceTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 3: // "|"
      case 4: // "^"
      case 5: // "=>"
      case 6: // ","
      case 7: // "(("
      case 8: // "("
      case 9: // "))"
      case 10: // ")"
      case 11: // "[]"
      case 12: // "<"
      case 13: // ">"
      case 14: // "[["
      case 15: // "]]"
      case 16: // "{{"
      case 17: // "}}"
      case 18: // ";"
      case 19: // ":"
      case 20: // "..."
      case 21: // "???"
      case 22: // "?"
      case 23: // "null"
      case 24: // INTEGER
      case 25: // DOUBLE
      case 26: // COMPLEX
      case 27: // CHARACTER
      case 28: // LOGICAL
      case 29: // RAW
      case 30: // ENVIRONMENT
      case 31: // EXPRESSION
      case 32: // LANGUAGE
      case 33: // SYMBOL
      case 34: // EXTERNALPOINTER
      case 35: // BYTECODE
      case 36: // PAIRLIST
      case 37: // S4
      case 38: // WEAKREF
      case 39: // TUPLE
      case 40: // LIST
      case 41: // DATAFRAME
      case 42: // STRUCT
      case 43: // ANY
      case 44: // TYPEDECL
      case 45: // IDENTIFIER
      case 46: // QUOTED_IDENTIFIER
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 50: // ascalartype
        value.copy< AScalarTypeNodePtr > (that.value);
        break;

      case 64: // anytype
        value.copy< AnyTypeNodePtr > (that.value);
        break;

      case 59: // bytecodetype
        value.copy< BytecodeTypeNodePtr > (that.value);
        break;

      case 77: // dataframetype
        value.copy< DataFrameTypeNodePtr > (that.value);
        break;

      case 54: // environmenttype
        value.copy< EnvironmentTypeNodePtr > (that.value);
        break;

      case 55: // expressiontype
        value.copy< ExpressionTypeNodePtr > (that.value);
        break;

      case 58: // externalptrtype
        value.copy< ExternalPointerTypeNodePtr > (that.value);
        break;

      case 72: // functiontype
        value.copy< FunctionTypeNodePtr > (that.value);
        break;

      case 73: // grouptype
        value.copy< GroupTypeNodePtr > (that.value);
        break;

      case 81: // identifier
        value.copy< IdentifierNodePtr > (that.value);
        break;

      case 56: // languagetype
        value.copy< LanguageTypeNodePtr > (that.value);
        break;

      case 75: // listtype
        value.copy< ListTypeNodePtr > (that.value);
        break;

      case 52: // nascalartype
        value.copy< NAScalarTypeNodePtr > (that.value);
        break;

      case 66: // typeseq
      case 68: // namedtypeseq
      case 70: // paramtypeseq
      case 71: // params
      case 76: // structelements
      case 79: // tupleelements
        value.copy< NodePtr > (that.value);
        break;

      case 60: // pairlisttype
        value.copy< PairlistTypeNodePtr > (that.value);
        break;

      case 51: // rawascalartype
        value.copy< RawAScalarTypeNodePtr > (that.value);
        break;

      case 61: // s4type
        value.copy< S4TypeNodePtr > (that.value);
        break;

      case 53: // scalartype
        value.copy< ScalarTypeNodePtr > (that.value);
        break;

      case 78: // structtype
        value.copy< StructTypeNodePtr > (that.value);
        break;

      case 57: // symboltype
        value.copy< SymbolTypeNodePtr > (that.value);
        break;

      case 67: // namedtype
        value.copy< TagTypePairNodePtr > (that.value);
        break;

      case 80: // tupletype
        value.copy< TupleTypeNodePtr > (that.value);
        break;

      case 85: // decltype
        value.copy< TypeDeclarationNodePtr > (that.value);
        break;

      case 69: // paramtype
      case 74: // nonuniontype
      case 82: // uniontype
      case 83: // nulltype
      case 84: // type
        value.copy< TypeNodePtr > (that.value);
        break;

      case 63: // unknowntype
        value.copy< UnknownTypeNodePtr > (that.value);
        break;

      case 65: // vectortype
        value.copy< VectorTypeNodePtr > (that.value);
        break;

      case 62: // weakreftype
        value.copy< WeakReferenceTypeNodePtr > (that.value);
        break;

      case 3: // "|"
      case 4: // "^"
      case 5: // "=>"
      case 6: // ","
      case 7: // "(("
      case 8: // "("
      case 9: // "))"
      case 10: // ")"
      case 11: // "[]"
      case 12: // "<"
      case 13: // ">"
      case 14: // "[["
      case 15: // "]]"
      case 16: // "{{"
      case 17: // "}}"
      case 18: // ";"
      case 19: // ":"
      case 20: // "..."
      case 21: // "???"
      case 22: // "?"
      case 23: // "null"
      case 24: // INTEGER
      case 25: // DOUBLE
      case 26: // COMPLEX
      case 27: // CHARACTER
      case 28: // LOGICAL
      case 29: // RAW
      case 30: // ENVIRONMENT
      case 31: // EXPRESSION
      case 32: // LANGUAGE
      case 33: // SYMBOL
      case 34: // EXTERNALPOINTER
      case 35: // BYTECODE
      case 36: // PAIRLIST
      case 37: // S4
      case 38: // WEAKREF
      case 39: // TUPLE
      case 40: // LIST
      case 41: // DATAFRAME
      case 42: // STRUCT
      case 43: // ANY
      case 44: // TYPEDECL
      case 45: // IDENTIFIER
      case 46: // QUOTED_IDENTIFIER
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 50: // ascalartype
        value.move< AScalarTypeNodePtr > (that.value);
        break;

      case 64: // anytype
        value.move< AnyTypeNodePtr > (that.value);
        break;

      case 59: // bytecodetype
        value.move< BytecodeTypeNodePtr > (that.value);
        break;

      case 77: // dataframetype
        value.move< DataFrameTypeNodePtr > (that.value);
        break;

      case 54: // environmenttype
        value.move< EnvironmentTypeNodePtr > (that.value);
        break;

      case 55: // expressiontype
        value.move< ExpressionTypeNodePtr > (that.value);
        break;

      case 58: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (that.value);
        break;

      case 72: // functiontype
        value.move< FunctionTypeNodePtr > (that.value);
        break;

      case 73: // grouptype
        value.move< GroupTypeNodePtr > (that.value);
        break;

      case 81: // identifier
        value.move< IdentifierNodePtr > (that.value);
        break;

      case 56: // languagetype
        value.move< LanguageTypeNodePtr > (that.value);
        break;

      case 75: // listtype
        value.move< ListTypeNodePtr > (that.value);
        break;

      case 52: // nascalartype
        value.move< NAScalarTypeNodePtr > (that.value);
        break;

      case 66: // typeseq
      case 68: // namedtypeseq
      case 70: // paramtypeseq
      case 71: // params
      case 76: // structelements
      case 79: // tupleelements
        value.move< NodePtr > (that.value);
        break;

      case 60: // pairlisttype
        value.move< PairlistTypeNodePtr > (that.value);
        break;

      case 51: // rawascalartype
        value.move< RawAScalarTypeNodePtr > (that.value);
        break;

      case 61: // s4type
        value.move< S4TypeNodePtr > (that.value);
        break;

      case 53: // scalartype
        value.move< ScalarTypeNodePtr > (that.value);
        break;

      case 78: // structtype
        value.move< StructTypeNodePtr > (that.value);
        break;

      case 57: // symboltype
        value.move< SymbolTypeNodePtr > (that.value);
        break;

      case 67: // namedtype
        value.move< TagTypePairNodePtr > (that.value);
        break;

      case 80: // tupletype
        value.move< TupleTypeNodePtr > (that.value);
        break;

      case 85: // decltype
        value.move< TypeDeclarationNodePtr > (that.value);
        break;

      case 69: // paramtype
      case 74: // nonuniontype
      case 82: // uniontype
      case 83: // nulltype
      case 84: // type
        value.move< TypeNodePtr > (that.value);
        break;

      case 63: // unknowntype
        value.move< UnknownTypeNodePtr > (that.value);
        break;

      case 65: // vectortype
        value.move< VectorTypeNodePtr > (that.value);
        break;

      case 62: // weakreftype
        value.move< WeakReferenceTypeNodePtr > (that.value);
        break;

      case 3: // "|"
      case 4: // "^"
      case 5: // "=>"
      case 6: // ","
      case 7: // "(("
      case 8: // "("
      case 9: // "))"
      case 10: // ")"
      case 11: // "[]"
      case 12: // "<"
      case 13: // ">"
      case 14: // "[["
      case 15: // "]]"
      case 16: // "{{"
      case 17: // "}}"
      case 18: // ";"
      case 19: // ":"
      case 20: // "..."
      case 21: // "???"
      case 22: // "?"
      case 23: // "null"
      case 24: // INTEGER
      case 25: // DOUBLE
      case 26: // COMPLEX
      case 27: // CHARACTER
      case 28: // LOGICAL
      case 29: // RAW
      case 30: // ENVIRONMENT
      case 31: // EXPRESSION
      case 32: // LANGUAGE
      case 33: // SYMBOL
      case 34: // EXTERNALPOINTER
      case 35: // BYTECODE
      case 36: // PAIRLIST
      case 37: // S4
      case 38: // WEAKREF
      case 39: // TUPLE
      case 40: // LIST
      case 41: // DATAFRAME
      case 42: // STRUCT
      case 43: // ANY
      case 44: // TYPEDECL
      case 45: // IDENTIFIER
      case 46: // QUOTED_IDENTIFIER
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
      case 3: // "|"
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1636 "Parser.cxx"
        break;

      case 4: // "^"
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1642 "Parser.cxx"
        break;

      case 5: // "=>"
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1648 "Parser.cxx"
        break;

      case 6: // ","
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1654 "Parser.cxx"
        break;

      case 7: // "(("
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1660 "Parser.cxx"
        break;

      case 8: // "("
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1666 "Parser.cxx"
        break;

      case 9: // "))"
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1672 "Parser.cxx"
        break;

      case 10: // ")"
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1678 "Parser.cxx"
        break;

      case 11: // "[]"
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1684 "Parser.cxx"
        break;

      case 12: // "<"
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1690 "Parser.cxx"
        break;

      case 13: // ">"
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1696 "Parser.cxx"
        break;

      case 14: // "[["
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1702 "Parser.cxx"
        break;

      case 15: // "]]"
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1708 "Parser.cxx"
        break;

      case 16: // "{{"
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1714 "Parser.cxx"
        break;

      case 17: // "}}"
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1720 "Parser.cxx"
        break;

      case 18: // ";"
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1726 "Parser.cxx"
        break;

      case 19: // ":"
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1732 "Parser.cxx"
        break;

      case 20: // "..."
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1738 "Parser.cxx"
        break;

      case 21: // "???"
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1744 "Parser.cxx"
        break;

      case 22: // "?"
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1750 "Parser.cxx"
        break;

      case 23: // "null"
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1756 "Parser.cxx"
        break;

      case 24: // INTEGER
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1762 "Parser.cxx"
        break;

      case 25: // DOUBLE
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1768 "Parser.cxx"
        break;

      case 26: // COMPLEX
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1774 "Parser.cxx"
        break;

      case 27: // CHARACTER
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1780 "Parser.cxx"
        break;

      case 28: // LOGICAL
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1786 "Parser.cxx"
        break;

      case 29: // RAW
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1792 "Parser.cxx"
        break;

      case 30: // ENVIRONMENT
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1798 "Parser.cxx"
        break;

      case 31: // EXPRESSION
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1804 "Parser.cxx"
        break;

      case 32: // LANGUAGE
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1810 "Parser.cxx"
        break;

      case 33: // SYMBOL
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1816 "Parser.cxx"
        break;

      case 34: // EXTERNALPOINTER
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1822 "Parser.cxx"
        break;

      case 35: // BYTECODE
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1828 "Parser.cxx"
        break;

      case 36: // PAIRLIST
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1834 "Parser.cxx"
        break;

      case 37: // S4
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1840 "Parser.cxx"
        break;

      case 38: // WEAKREF
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1846 "Parser.cxx"
        break;

      case 39: // TUPLE
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1852 "Parser.cxx"
        break;

      case 40: // LIST
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1858 "Parser.cxx"
        break;

      case 41: // DATAFRAME
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1864 "Parser.cxx"
        break;

      case 42: // STRUCT
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1870 "Parser.cxx"
        break;

      case 43: // ANY
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1876 "Parser.cxx"
        break;

      case 44: // TYPEDECL
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1882 "Parser.cxx"
        break;

      case 45: // IDENTIFIER
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1888 "Parser.cxx"
        break;

      case 46: // QUOTED_IDENTIFIER
#line 146 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1894 "Parser.cxx"
        break;

      case 50: // ascalartype
#line 120 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < AScalarTypeNodePtr > ()); }
#line 1900 "Parser.cxx"
        break;

      case 51: // rawascalartype
#line 119 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < RawAScalarTypeNodePtr > ()); }
#line 1906 "Parser.cxx"
        break;

      case 52: // nascalartype
#line 121 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NAScalarTypeNodePtr > ()); }
#line 1912 "Parser.cxx"
        break;

      case 53: // scalartype
#line 122 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ScalarTypeNodePtr > ()); }
#line 1918 "Parser.cxx"
        break;

      case 54: // environmenttype
#line 123 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < EnvironmentTypeNodePtr > ()); }
#line 1924 "Parser.cxx"
        break;

      case 55: // expressiontype
#line 124 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ExpressionTypeNodePtr > ()); }
#line 1930 "Parser.cxx"
        break;

      case 56: // languagetype
#line 125 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < LanguageTypeNodePtr > ()); }
#line 1936 "Parser.cxx"
        break;

      case 57: // symboltype
#line 126 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < SymbolTypeNodePtr > ()); }
#line 1942 "Parser.cxx"
        break;

      case 58: // externalptrtype
#line 127 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ExternalPointerTypeNodePtr > ()); }
#line 1948 "Parser.cxx"
        break;

      case 59: // bytecodetype
#line 128 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < BytecodeTypeNodePtr > ()); }
#line 1954 "Parser.cxx"
        break;

      case 60: // pairlisttype
#line 129 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < PairlistTypeNodePtr > ()); }
#line 1960 "Parser.cxx"
        break;

      case 61: // s4type
#line 130 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < S4TypeNodePtr > ()); }
#line 1966 "Parser.cxx"
        break;

      case 62: // weakreftype
#line 131 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < WeakReferenceTypeNodePtr > ()); }
#line 1972 "Parser.cxx"
        break;

      case 63: // unknowntype
#line 133 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < UnknownTypeNodePtr > ()); }
#line 1978 "Parser.cxx"
        break;

      case 64: // anytype
#line 132 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < AnyTypeNodePtr > ()); }
#line 1984 "Parser.cxx"
        break;

      case 65: // vectortype
#line 134 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < VectorTypeNodePtr > ()); }
#line 1990 "Parser.cxx"
        break;

      case 66: // typeseq
#line 135 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 1996 "Parser.cxx"
        break;

      case 67: // namedtype
#line 136 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TagTypePairNodePtr > ()); }
#line 2002 "Parser.cxx"
        break;

      case 68: // namedtypeseq
#line 135 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 2008 "Parser.cxx"
        break;

      case 69: // paramtype
#line 144 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2014 "Parser.cxx"
        break;

      case 70: // paramtypeseq
#line 135 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 2020 "Parser.cxx"
        break;

      case 71: // params
#line 135 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 2026 "Parser.cxx"
        break;

      case 72: // functiontype
#line 137 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < FunctionTypeNodePtr > ()); }
#line 2032 "Parser.cxx"
        break;

      case 73: // grouptype
#line 138 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < GroupTypeNodePtr > ()); }
#line 2038 "Parser.cxx"
        break;

      case 74: // nonuniontype
#line 144 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2044 "Parser.cxx"
        break;

      case 75: // listtype
#line 139 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ListTypeNodePtr > ()); }
#line 2050 "Parser.cxx"
        break;

      case 76: // structelements
#line 135 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 2056 "Parser.cxx"
        break;

      case 77: // dataframetype
#line 140 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < DataFrameTypeNodePtr > ()); }
#line 2062 "Parser.cxx"
        break;

      case 78: // structtype
#line 141 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < StructTypeNodePtr > ()); }
#line 2068 "Parser.cxx"
        break;

      case 79: // tupleelements
#line 135 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 2074 "Parser.cxx"
        break;

      case 80: // tupletype
#line 142 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TupleTypeNodePtr > ()); }
#line 2080 "Parser.cxx"
        break;

      case 81: // identifier
#line 143 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < IdentifierNodePtr > ()); }
#line 2086 "Parser.cxx"
        break;

      case 82: // uniontype
#line 144 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2092 "Parser.cxx"
        break;

      case 83: // nulltype
#line 144 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2098 "Parser.cxx"
        break;

      case 84: // type
#line 144 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2104 "Parser.cxx"
        break;

      case 85: // decltype
#line 145 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeDeclarationNodePtr > ()); }
#line 2110 "Parser.cxx"
        break;

      default:
        break;
    }
    yyo << ')';
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
#line 184 "Parser.yxx"
{
    /* filename for locations here
       https://www.gnu.org/software/bison/manual/html_node/Initial-Action-Decl.html
       location stores pointer to a string allocated elsewhere and does not delete it.
       it has been disabled for now since TopLevelNode stores the filename anyways and
       properly deallocates it.
    */

    /* @$.initialize(context.get_input_stream_name()); */
}

#line 2240 "Parser.cxx"


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 50: // ascalartype
        yylhs.value.emplace< AScalarTypeNodePtr > ();
        break;

      case 64: // anytype
        yylhs.value.emplace< AnyTypeNodePtr > ();
        break;

      case 59: // bytecodetype
        yylhs.value.emplace< BytecodeTypeNodePtr > ();
        break;

      case 77: // dataframetype
        yylhs.value.emplace< DataFrameTypeNodePtr > ();
        break;

      case 54: // environmenttype
        yylhs.value.emplace< EnvironmentTypeNodePtr > ();
        break;

      case 55: // expressiontype
        yylhs.value.emplace< ExpressionTypeNodePtr > ();
        break;

      case 58: // externalptrtype
        yylhs.value.emplace< ExternalPointerTypeNodePtr > ();
        break;

      case 72: // functiontype
        yylhs.value.emplace< FunctionTypeNodePtr > ();
        break;

      case 73: // grouptype
        yylhs.value.emplace< GroupTypeNodePtr > ();
        break;

      case 81: // identifier
        yylhs.value.emplace< IdentifierNodePtr > ();
        break;

      case 56: // languagetype
        yylhs.value.emplace< LanguageTypeNodePtr > ();
        break;

      case 75: // listtype
        yylhs.value.emplace< ListTypeNodePtr > ();
        break;

      case 52: // nascalartype
        yylhs.value.emplace< NAScalarTypeNodePtr > ();
        break;

      case 66: // typeseq
      case 68: // namedtypeseq
      case 70: // paramtypeseq
      case 71: // params
      case 76: // structelements
      case 79: // tupleelements
        yylhs.value.emplace< NodePtr > ();
        break;

      case 60: // pairlisttype
        yylhs.value.emplace< PairlistTypeNodePtr > ();
        break;

      case 51: // rawascalartype
        yylhs.value.emplace< RawAScalarTypeNodePtr > ();
        break;

      case 61: // s4type
        yylhs.value.emplace< S4TypeNodePtr > ();
        break;

      case 53: // scalartype
        yylhs.value.emplace< ScalarTypeNodePtr > ();
        break;

      case 78: // structtype
        yylhs.value.emplace< StructTypeNodePtr > ();
        break;

      case 57: // symboltype
        yylhs.value.emplace< SymbolTypeNodePtr > ();
        break;

      case 67: // namedtype
        yylhs.value.emplace< TagTypePairNodePtr > ();
        break;

      case 80: // tupletype
        yylhs.value.emplace< TupleTypeNodePtr > ();
        break;

      case 85: // decltype
        yylhs.value.emplace< TypeDeclarationNodePtr > ();
        break;

      case 69: // paramtype
      case 74: // nonuniontype
      case 82: // uniontype
      case 83: // nulltype
      case 84: // type
        yylhs.value.emplace< TypeNodePtr > ();
        break;

      case 63: // unknowntype
        yylhs.value.emplace< UnknownTypeNodePtr > ();
        break;

      case 65: // vectortype
        yylhs.value.emplace< VectorTypeNodePtr > ();
        break;

      case 62: // weakreftype
        yylhs.value.emplace< WeakReferenceTypeNodePtr > ();
        break;

      case 3: // "|"
      case 4: // "^"
      case 5: // "=>"
      case 6: // ","
      case 7: // "(("
      case 8: // "("
      case 9: // "))"
      case 10: // ")"
      case 11: // "[]"
      case 12: // "<"
      case 13: // ">"
      case 14: // "[["
      case 15: // "]]"
      case 16: // "{{"
      case 17: // "}}"
      case 18: // ";"
      case 19: // ":"
      case 20: // "..."
      case 21: // "???"
      case 22: // "?"
      case 23: // "null"
      case 24: // INTEGER
      case 25: // DOUBLE
      case 26: // COMPLEX
      case 27: // CHARACTER
      case 28: // LOGICAL
      case 29: // RAW
      case 30: // ENVIRONMENT
      case 31: // EXPRESSION
      case 32: // LANGUAGE
      case 33: // SYMBOL
      case 34: // EXTERNALPOINTER
      case 35: // BYTECODE
      case 36: // PAIRLIST
      case 37: // S4
      case 38: // WEAKREF
      case 39: // TUPLE
      case 40: // LIST
      case 41: // DATAFRAME
      case 42: // STRUCT
      case 43: // ANY
      case 44: // TYPEDECL
      case 45: // IDENTIFIER
      case 46: // QUOTED_IDENTIFIER
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 350 "Parser.yxx"
                                                            {   yylhs.value.as < AScalarTypeNodePtr > () = create_node_with_keyword<IntegerAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2530 "Parser.cxx"
    break;

  case 3:
#line 351 "Parser.yxx"
                                                            {   yylhs.value.as < AScalarTypeNodePtr > () = create_node_with_keyword<DoubleAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2536 "Parser.cxx"
    break;

  case 4:
#line 352 "Parser.yxx"
                                                            {   yylhs.value.as < AScalarTypeNodePtr > () = create_node_with_keyword<ComplexAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2542 "Parser.cxx"
    break;

  case 5:
#line 353 "Parser.yxx"
                                                            {   yylhs.value.as < AScalarTypeNodePtr > () = create_node_with_keyword<CharacterAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2548 "Parser.cxx"
    break;

  case 6:
#line 354 "Parser.yxx"
                                                            {   yylhs.value.as < AScalarTypeNodePtr > () = create_node_with_keyword<LogicalAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2554 "Parser.cxx"
    break;

  case 7:
#line 357 "Parser.yxx"
                                                            {   yylhs.value.as < RawAScalarTypeNodePtr > () = create_node_with_keyword<RawAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2560 "Parser.cxx"
    break;

  case 8:
#line 360 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NAScalarTypeNodePtr > () = new NAScalarTypeNode(std::move(wrap(std::move(op))),
                                                                                          std::move(wrap(std::move(yystack_[0].value.as < AScalarTypeNodePtr > ()))));
                                                                yylhs.value.as < NAScalarTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2571 "Parser.cxx"
    break;

  case 9:
#line 367 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = yystack_[0].value.as < AScalarTypeNodePtr > ();
                                                                yystack_[0].value.as < AScalarTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2581 "Parser.cxx"
    break;

  case 10:
#line 372 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = yystack_[0].value.as < RawAScalarTypeNodePtr > ();
                                                                yystack_[0].value.as < RawAScalarTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2591 "Parser.cxx"
    break;

  case 11:
#line 377 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = yystack_[0].value.as < NAScalarTypeNodePtr > ();
                                                                yystack_[0].value.as < NAScalarTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2601 "Parser.cxx"
    break;

  case 12:
#line 384 "Parser.yxx"
                                                            {   yylhs.value.as < EnvironmentTypeNodePtr > () = create_node_with_keyword<EnvironmentTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2607 "Parser.cxx"
    break;

  case 13:
#line 387 "Parser.yxx"
                                                            {   yylhs.value.as < ExpressionTypeNodePtr > () = create_node_with_keyword<ExpressionTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context);  }
#line 2613 "Parser.cxx"
    break;

  case 14:
#line 390 "Parser.yxx"
                                                            {   yylhs.value.as < LanguageTypeNodePtr > () = create_node_with_keyword<LanguageTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context);    }
#line 2619 "Parser.cxx"
    break;

  case 15:
#line 393 "Parser.yxx"
                                                            {   yylhs.value.as < SymbolTypeNodePtr > () = create_node_with_keyword<SymbolTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context);      }
#line 2625 "Parser.cxx"
    break;

  case 16:
#line 396 "Parser.yxx"
                                                            {   yylhs.value.as < ExternalPointerTypeNodePtr > () = create_node_with_keyword<ExternalPointerTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2631 "Parser.cxx"
    break;

  case 17:
#line 399 "Parser.yxx"
                                                            {   yylhs.value.as < BytecodeTypeNodePtr > () = create_node_with_keyword<BytecodeTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2637 "Parser.cxx"
    break;

  case 18:
#line 402 "Parser.yxx"
                                                            {   yylhs.value.as < PairlistTypeNodePtr > () = create_node_with_keyword<PairlistTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2643 "Parser.cxx"
    break;

  case 19:
#line 405 "Parser.yxx"
                                                            {   yylhs.value.as < S4TypeNodePtr > () = create_node_with_keyword<S4TypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2649 "Parser.cxx"
    break;

  case 20:
#line 408 "Parser.yxx"
                                                            {   yylhs.value.as < WeakReferenceTypeNodePtr > () = create_node_with_keyword<WeakReferenceTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2655 "Parser.cxx"
    break;

  case 21:
#line 411 "Parser.yxx"
                                                            {   yylhs.value.as < DataFrameTypeNodePtr > () = create_node_with_keyword<DataFrameTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2661 "Parser.cxx"
    break;

  case 22:
#line 414 "Parser.yxx"
                                                            {   yylhs.value.as < AnyTypeNodePtr > () = create_node_with_keyword<AnyTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2667 "Parser.cxx"
    break;

  case 23:
#line 417 "Parser.yxx"
                                                            {   yylhs.value.as < UnknownTypeNodePtr > () = create_node_with_keyword<UnknownTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2673 "Parser.cxx"
    break;

  case 24:
#line 420 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);
                                                                yylhs.value.as < VectorTypeNodePtr > () = new VectorTypeNode(std::move(wrap(std::move(op))),
                                                                                        std::move(wrap(std::move(yystack_[1].value.as < ScalarTypeNodePtr > ()))));
                                                                yylhs.value.as < VectorTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2684 "Parser.cxx"
    break;

  case 25:
#line 428 "Parser.yxx"
                                                            {
                                                                KeywordNodePtr keyword = create_keyword(yystack_[3].value.as < std::string > (), yystack_[3].location, context);

                                                                OperatorNodePtr left = create_operator(yystack_[2].value.as < std::string > (), yystack_[2].location, context);
                                                                OperatorNodePtr right = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);

                                                                ParameterNode* parameter = new ParameterNode(std::move(wrap(std::move(left))),
                                                                                                             std::move(wrap(std::move(right))),
                                                                                                             std::move(wrap(std::move(yystack_[1].value.as < TypeNodePtr > ()))));

                                                                yylhs.value.as < ListTypeNodePtr > () = new ListTypeNode(std::move(wrap(std::move(keyword))),
                                                                                      std::move(wrap(std::move(parameter))));

                                                                yylhs.value.as < ListTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2704 "Parser.cxx"
    break;

  case 26:
#line 445 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                            }
#line 2713 "Parser.cxx"
    break;

  case 27:
#line 449 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr op = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NodePtr > () = new CommaSeparatorNode(std::move(wrap(std::move(op))),
                                                                                            std::move(wrap(std::move(yystack_[2].value.as < NodePtr > ()))),
                                                                                            std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2725 "Parser.cxx"
    break;

  case 28:
#line 459 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = new EmptyNode();
                                                            }
#line 2733 "Parser.cxx"
    break;

  case 29:
#line 462 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < NodePtr > ();
                                                                yystack_[0].value.as < NodePtr > () = nullptr;
                                                            }
#line 2742 "Parser.cxx"
    break;

  case 30:
#line 467 "Parser.yxx"
                                                            {
                                                                KeywordNodePtr keyword = create_keyword(yystack_[3].value.as < std::string > (), yystack_[3].location, context);

                                                                OperatorNodePtr left = create_operator(yystack_[2].value.as < std::string > (), yystack_[2].location, context);
                                                                OperatorNodePtr right = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);

                                                                ParameterNode* parameter = new ParameterNode(std::move(wrap(std::move(left))),
                                                                                                             std::move(wrap(std::move(right))),
                                                                                                             std::move(wrap(std::move(yystack_[1].value.as < NodePtr > ()))));

                                                                yylhs.value.as < StructTypeNodePtr > () = new StructTypeNode(std::move(wrap(std::move(keyword))),
                                                                                        std::move(wrap(std::move(parameter))));

                                                                yylhs.value.as < StructTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2762 "Parser.cxx"
    break;

  case 31:
#line 485 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = new EmptyNode();
                                                            }
#line 2770 "Parser.cxx"
    break;

  case 32:
#line 488 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < NodePtr > ();
                                                                yystack_[0].value.as < NodePtr > () = nullptr;
                                                            }
#line 2779 "Parser.cxx"
    break;

  case 33:
#line 494 "Parser.yxx"
                                                            {
                                                                KeywordNodePtr keyword = create_keyword(yystack_[3].value.as < std::string > (), yystack_[3].location, context);

                                                                OperatorNodePtr left = create_operator(yystack_[2].value.as < std::string > (), yystack_[2].location, context);
                                                                OperatorNodePtr right = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);

                                                                ParameterNode* parameter = new ParameterNode(std::move(wrap(std::move(left))),
                                                                                                             std::move(wrap(std::move(right))),
                                                                                                             std::move(wrap(std::move(yystack_[1].value.as < NodePtr > ()))));

                                                                yylhs.value.as < TupleTypeNodePtr > () = new TupleTypeNode(std::move(wrap(std::move(keyword))),
                                                                                       std::move(wrap(std::move(parameter))));

                                                                yylhs.value.as < TupleTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2799 "Parser.cxx"
    break;

  case 34:
#line 511 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2805 "Parser.cxx"
    break;

  case 35:
#line 512 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2811 "Parser.cxx"
    break;

  case 36:
#line 513 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2817 "Parser.cxx"
    break;

  case 37:
#line 514 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2823 "Parser.cxx"
    break;

  case 38:
#line 515 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2829 "Parser.cxx"
    break;

  case 39:
#line 516 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2835 "Parser.cxx"
    break;

  case 40:
#line 517 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2841 "Parser.cxx"
    break;

  case 41:
#line 518 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2847 "Parser.cxx"
    break;

  case 42:
#line 519 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2853 "Parser.cxx"
    break;

  case 43:
#line 520 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2859 "Parser.cxx"
    break;

  case 44:
#line 521 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2865 "Parser.cxx"
    break;

  case 45:
#line 522 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2871 "Parser.cxx"
    break;

  case 46:
#line 523 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2877 "Parser.cxx"
    break;

  case 47:
#line 524 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2883 "Parser.cxx"
    break;

  case 48:
#line 525 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2889 "Parser.cxx"
    break;

  case 49:
#line 526 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2895 "Parser.cxx"
    break;

  case 50:
#line 527 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2901 "Parser.cxx"
    break;

  case 51:
#line 528 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2907 "Parser.cxx"
    break;

  case 52:
#line 529 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2913 "Parser.cxx"
    break;

  case 53:
#line 530 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2919 "Parser.cxx"
    break;

  case 54:
#line 531 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2925 "Parser.cxx"
    break;

  case 55:
#line 532 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2931 "Parser.cxx"
    break;

  case 56:
#line 533 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2937 "Parser.cxx"
    break;

  case 57:
#line 534 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), true, false, yystack_[0].location, context);  }
#line 2943 "Parser.cxx"
    break;

  case 58:
#line 537 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr separator = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < TagTypePairNodePtr > () = new TagTypePairNode(std::move(wrap(std::move(yystack_[2].value.as < IdentifierNodePtr > ()))),
                                                                                         std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))),
                                                                                         std::move(wrap(std::move(separator))));
                                                                yylhs.value.as < TagTypePairNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2955 "Parser.cxx"
    break;

  case 59:
#line 544 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr separator = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                IdentifierNodePtr id = create_identifier(yystack_[2].value.as < std::string > (), false, true, yystack_[2].location, context);
                                                                yylhs.value.as < TagTypePairNodePtr > () = new TagTypePairNode(std::move(wrap(std::move(id))),
                                                                                         std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))),
                                                                                         std::move(wrap(std::move(separator))));
                                                                yylhs.value.as < TagTypePairNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2968 "Parser.cxx"
    break;

  case 60:
#line 554 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < TagTypePairNodePtr > ();
                                                                yystack_[0].value.as < TagTypePairNodePtr > () = nullptr;
                                                            }
#line 2977 "Parser.cxx"
    break;

  case 61:
#line 558 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr op = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NodePtr > () = new CommaSeparatorNode(std::move(wrap(std::move(op))),
                                                                                            std::move(wrap(std::move(yystack_[2].value.as < NodePtr > ()))),
                                                                                            std::move(wrap(std::move(yystack_[0].value.as < TagTypePairNodePtr > ()))));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2989 "Parser.cxx"
    break;

  case 62:
#line 568 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                            }
#line 2998 "Parser.cxx"
    break;

  case 63:
#line 572 "Parser.yxx"
                                                            {   yylhs.value.as < TypeNodePtr > () = create_node_with_keyword<VarargTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 3004 "Parser.cxx"
    break;

  case 64:
#line 575 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                            }
#line 3013 "Parser.cxx"
    break;

  case 65:
#line 579 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr op = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NodePtr > () = new CommaSeparatorNode(std::move(wrap(std::move(op))),
                                                                                            std::move(wrap(std::move(yystack_[2].value.as < NodePtr > ()))),
                                                                                            std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3025 "Parser.cxx"
    break;

  case 66:
#line 588 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr right = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);
                                                                OperatorNodePtr left = create_operator(yystack_[2].value.as < std::string > (), yystack_[2].location, context);
                                                                yylhs.value.as < NodePtr > () = new ParameterNode(std::move(wrap(std::move(left))),
                                                                                       std::move(wrap(std::move(right))),
                                                                                       std::move(wrap(std::move(yystack_[1].value.as < NodePtr > ()))));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3038 "Parser.cxx"
    break;

  case 67:
#line 596 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr right = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);
                                                                OperatorNodePtr left = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NodePtr > () = new ParameterNode(std::move(wrap(std::move(left))),
                                                                                       std::move(wrap(std::move(right))),
                                                                                       std::move(wrap(new EmptyNode())));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3051 "Parser.cxx"
    break;

  case 68:
#line 604 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < AnyTypeNodePtr > ();
                                                                yystack_[0].value.as < AnyTypeNodePtr > () = nullptr;
                                                            }
#line 3060 "Parser.cxx"
    break;

  case 69:
#line 610 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < FunctionTypeNodePtr > () = new FunctionTypeNode(std::move(wrap(std::move(op))),
                                                                                          std::move(wrap(std::move(yystack_[2].value.as < NodePtr > ()))),
                                                                                          std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < FunctionTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3072 "Parser.cxx"
    break;

  case 70:
#line 619 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr right = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);
                                                                OperatorNodePtr left = create_operator(yystack_[2].value.as < std::string > (), yystack_[2].location, context);
                                                                yylhs.value.as < GroupTypeNodePtr > () = new GroupTypeNode(std::move(wrap(std::move(left))),
                                                                                       std::move(wrap(std::move(right))),
                                                                                       std::move(wrap(std::move(yystack_[1].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < GroupTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3085 "Parser.cxx"
    break;

  case 71:
#line 629 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ScalarTypeNodePtr > ();
                                                                yystack_[0].value.as < ScalarTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3095 "Parser.cxx"
    break;

  case 72:
#line 634 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < EnvironmentTypeNodePtr > ();
                                                                yystack_[0].value.as < EnvironmentTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3105 "Parser.cxx"
    break;

  case 73:
#line 639 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ExpressionTypeNodePtr > ();
                                                                yystack_[0].value.as < ExpressionTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3115 "Parser.cxx"
    break;

  case 74:
#line 644 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < LanguageTypeNodePtr > ();
                                                                yystack_[0].value.as < LanguageTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3125 "Parser.cxx"
    break;

  case 75:
#line 649 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < SymbolTypeNodePtr > ();
                                                                yystack_[0].value.as < SymbolTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3135 "Parser.cxx"
    break;

  case 76:
#line 654 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ExternalPointerTypeNodePtr > ();
                                                                yystack_[0].value.as < ExternalPointerTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3145 "Parser.cxx"
    break;

  case 77:
#line 659 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < BytecodeTypeNodePtr > ();
                                                                yystack_[0].value.as < BytecodeTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3155 "Parser.cxx"
    break;

  case 78:
#line 664 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < PairlistTypeNodePtr > ();
                                                                yystack_[0].value.as < PairlistTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3165 "Parser.cxx"
    break;

  case 79:
#line 669 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < S4TypeNodePtr > ();
                                                                yystack_[0].value.as < S4TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3175 "Parser.cxx"
    break;

  case 80:
#line 674 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < WeakReferenceTypeNodePtr > ();
                                                                yystack_[0].value.as < WeakReferenceTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3185 "Parser.cxx"
    break;

  case 81:
#line 679 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < DataFrameTypeNodePtr > ();
                                                                yystack_[0].value.as < DataFrameTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3195 "Parser.cxx"
    break;

  case 82:
#line 684 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < VectorTypeNodePtr > ();
                                                                yystack_[0].value.as < VectorTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3205 "Parser.cxx"
    break;

  case 83:
#line 689 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < FunctionTypeNodePtr > ();
                                                                yystack_[0].value.as < FunctionTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3215 "Parser.cxx"
    break;

  case 84:
#line 694 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < StructTypeNodePtr > ();
                                                                yystack_[0].value.as < StructTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3225 "Parser.cxx"
    break;

  case 85:
#line 699 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ListTypeNodePtr > ();
                                                                yystack_[0].value.as < ListTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3235 "Parser.cxx"
    break;

  case 86:
#line 704 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TupleTypeNodePtr > ();
                                                                yystack_[0].value.as < TupleTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3245 "Parser.cxx"
    break;

  case 87:
#line 709 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < GroupTypeNodePtr > ();
                                                                yystack_[0].value.as < GroupTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3255 "Parser.cxx"
    break;

  case 88:
#line 714 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < UnknownTypeNodePtr > ();
                                                                yystack_[0].value.as < UnknownTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3265 "Parser.cxx"
    break;

  case 89:
#line 722 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3275 "Parser.cxx"
    break;

  case 90:
#line 727 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < TypeNodePtr > () = new UnionTypeNode(std::move(wrap(std::move(op))),
                                                                                       std::move(wrap(std::move(yystack_[2].value.as < TypeNodePtr > ()))),
                                                                                       std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3287 "Parser.cxx"
    break;

  case 91:
#line 737 "Parser.yxx"
                                                            {   yylhs.value.as < TypeNodePtr > () = create_node_with_keyword<NullTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 3293 "Parser.cxx"
    break;

  case 92:
#line 738 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < TypeNodePtr > () = new NullableTypeNode(std::move(wrap(std::move(op))),
                                                                                          std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3304 "Parser.cxx"
    break;

  case 93:
#line 747 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3314 "Parser.cxx"
    break;

  case 94:
#line 752 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3324 "Parser.cxx"
    break;

  case 95:
#line 757 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < AnyTypeNodePtr > ();
                                                                yystack_[0].value.as < AnyTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3334 "Parser.cxx"
    break;

  case 96:
#line 764 "Parser.yxx"
                                                            {
                                                                TerminatorNodePtr terminator = create_terminator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);
                                                                KeywordNodePtr keyword = create_keyword(yystack_[3].value.as < std::string > (), yystack_[3].location, context);
                                                                yylhs.value.as < TypeDeclarationNodePtr > () = new TypeDeclarationNode(std::move(wrap(std::move(keyword))),
                                                                                             std::move(wrap(std::move(yystack_[2].value.as < IdentifierNodePtr > ()))),
                                                                                             std::move(wrap(std::move(yystack_[1].value.as < TypeNodePtr > ()))),
                                                                                             std::move(wrap(std::move(terminator))));
                                                                yylhs.value.as < TypeDeclarationNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3348 "Parser.cxx"
    break;

  case 97:
#line 775 "Parser.yxx"
                                                            {
                                                                TopLevelNodeUPtr& node(context.get_parse_result().get_top_level_node());
                                                                node -> get_type_declarations().push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeDeclarationNodePtr > ()))));
                                                            }
#line 3357 "Parser.cxx"
    break;

  case 98:
#line 779 "Parser.yxx"
                                                            {
                                                                TopLevelNodeUPtr& node(context.get_parse_result().get_top_level_node());
                                                                node -> get_type_declarations().push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeDeclarationNodePtr > ()))));
                                                            }
#line 3366 "Parser.cxx"
    break;

  case 99:
#line 785 "Parser.yxx"
                                                            {
                                                                EofNodeUPtr eof = std::make_unique<EofNode>();
                                                                eof -> set_location(yystack_[0].location);
                                                                TopLevelNodeUPtr& node(context.get_parse_result().get_top_level_node());
                                                                node -> set_location(yylhs.location);
                                                                node -> set_eof_node(eof);
                                                            }
#line 3378 "Parser.cxx"
    break;

  case 100:
#line 792 "Parser.yxx"
                                                            {
                                                                EofNodeUPtr eof = std::make_unique<EofNode>();
                                                                eof -> set_location(yystack_[0].location);
                                                                TopLevelNodeUPtr& node(context.get_parse_result().get_top_level_node());
                                                                node -> set_location(yylhs.location);
                                                                node -> set_eof_node(eof);
                                                            }
#line 3390 "Parser.cxx"
    break;


#line 3394 "Parser.cxx"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -64;

  const signed char Parser::yytable_ninf_ = -69;

  const short
  Parser::yypact_[] =
  {
       2,   -64,   219,   -64,     3,     6,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     155,   -64,   -64,   -64,    -9,   155,     0,   -64,   195,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,    -3,    -2,   -64,    -1,   -64,
     -64,   -64,   -64,    33,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,    40,   -64,    43,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,    46,   -64,    32,   -64,    41,   -64,
     -64,   -64,     1,   -64,   -64,    46,   155,   155,    72,   -64,
     155,   195,   -64,   -64,   115,   -64,    47,    39,   -64,    42,
      35,   -64,    50,    44,    49,   -64,   -64,   -64,   155,   -64,
     -64,   155,    72,   -64,   155,   -64,   -64,   -64,   -64
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    99,     0,    97,     0,     0,    55,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    52,    51,    53,    54,    56,    57,
       0,   100,    98,     1,     0,     0,     0,    23,     0,    91,
       2,     3,     4,     5,     6,     7,    12,    13,    14,    15,
      16,    17,    18,    19,    20,     0,     0,    21,     0,    22,
       9,    10,    11,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    88,    95,    82,     0,    83,    87,    89,
      85,    81,    84,    86,    93,    94,     0,     8,     0,    67,
      63,    64,     0,    62,    68,    92,    31,     0,    28,    24,
       0,     0,    96,    70,     0,    66,    32,     0,    26,     0,
       0,    60,    29,     0,     0,    69,    90,    65,     0,    33,
      25,     0,     0,    30,     0,    27,    59,    61,    58
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -64,    24,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -37,   -64,   -64,   -63,   -64,
     -44,   -64,   -64,   -64,   -64,   -40,   -64,   -64,   -64,   -64,
     -64,   -64,    60,    25,   -64,   -30,    61,   -64,   -64
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,   106,   111,   112,
      91,    92,    76,    77,    78,    79,    80,   113,    81,    82,
     107,    83,   114,    84,    85,    93,     3,     4,     5
  };

  const short
  Parser::yytable_[] =
  {
      86,    94,     1,    31,    34,    88,    33,   104,    35,    96,
      97,    98,    36,    89,   105,    40,    41,    42,    43,    44,
      90,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    99,   -68,     2,     2,   100,   101,
     102,   103,   119,   118,   121,   120,   122,   123,    87,   127,
     117,   116,    30,    95,    94,    32,   108,   109,   124,     0,
     115,     0,     0,     0,     0,     0,   110,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   125,     0,
       0,   126,     6,     0,   128,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    34,
       0,     0,     0,    35,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,    90,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    34,
       0,     0,     0,    35,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    34,
       0,     0,     0,    35,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     6,
       0,     0,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29
  };

  const signed char
  Parser::yycheck_[] =
  {
      30,    38,     0,     0,     4,    35,     0,     6,     8,    12,
      12,    12,    12,    13,    13,    24,    25,    26,    27,    28,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    11,     5,    44,    44,     5,     3,
      18,    10,    13,     6,    19,    13,     6,    13,    34,   122,
     104,   101,     2,    38,   101,     4,    96,    97,    19,    -1,
     100,    -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,
      -1,   121,    20,    -1,   124,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     4,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     4,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     4,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    20,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     0,    44,    85,    86,    87,    20,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      81,     0,    85,     0,     4,     8,    12,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    71,    72,    73,    74,
      75,    77,    78,    80,    82,    83,    84,    50,    84,    13,
      20,    69,    70,    84,    64,    82,    12,    12,    12,    11,
       5,     3,    18,    10,     6,    13,    66,    79,    84,    84,
       4,    67,    68,    76,    81,    84,    74,    69,     6,    13,
      13,    19,     6,    13,    19,    84,    84,    67,    84
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    49,    50,    50,    50,    50,    50,    51,    52,    53,
      53,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    77,    64,    63,    65,    75,    66,    66,    76,    76,
      78,    79,    79,    80,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    67,    67,
      68,    68,    69,    69,    70,    70,    71,    71,    71,    72,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    82,
      82,    83,    83,    84,    84,    84,    85,    86,    86,    87,
      87
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     1,     3,     0,     1,
       4,     0,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     3,     1,     1,     1,     3,     3,     2,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     1,     1,     1,     4,     1,     2,     1,
       2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"|\"", "\"^\"", "\"=>\"",
  "\",\"", "\"((\"", "\"(\"", "\"))\"", "\")\"", "\"[]\"", "\"<\"",
  "\">\"", "\"[[\"", "\"]]\"", "\"{{\"", "\"}}\"", "\";\"", "\":\"",
  "\"...\"", "\"???\"", "\"?\"", "\"null\"", "INTEGER", "DOUBLE",
  "COMPLEX", "CHARACTER", "LOGICAL", "RAW", "ENVIRONMENT", "EXPRESSION",
  "LANGUAGE", "SYMBOL", "EXTERNALPOINTER", "BYTECODE", "PAIRLIST", "S4",
  "WEAKREF", "TUPLE", "LIST", "DATAFRAME", "STRUCT", "ANY", "TYPEDECL",
  "IDENTIFIER", "QUOTED_IDENTIFIER", "LBRACKET", "LOWER_THAN_OR",
  "$accept", "ascalartype", "rawascalartype", "nascalartype", "scalartype",
  "environmenttype", "expressiontype", "languagetype", "symboltype",
  "externalptrtype", "bytecodetype", "pairlisttype", "s4type",
  "weakreftype", "unknowntype", "anytype", "vectortype", "typeseq",
  "namedtype", "namedtypeseq", "paramtype", "paramtypeseq", "params",
  "functiontype", "grouptype", "nonuniontype", "listtype",
  "structelements", "dataframetype", "structtype", "tupleelements",
  "tupletype", "identifier", "uniontype", "nulltype", "type", "decltype",
  "decllist", "start", YY_NULLPTR
  };

#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   350,   350,   351,   352,   353,   354,   357,   360,   367,
     372,   377,   384,   387,   390,   393,   396,   399,   402,   405,
     408,   411,   414,   417,   420,   428,   445,   449,   459,   462,
     467,   485,   488,   494,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   537,   544,
     554,   558,   568,   572,   575,   579,   588,   596,   604,   610,
     619,   629,   634,   639,   644,   649,   654,   659,   664,   669,
     674,   679,   684,   689,   694,   699,   704,   709,   714,   722,
     727,   737,   738,   747,   752,   757,   764,   775,   779,   785,
     792
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
    };
    const int user_token_number_max_ = 303;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 9 "Parser.yxx"
} } // tastr::parser
#line 3962 "Parser.cxx"

#line 801 "Parser.yxx"


void tastr::parser::Parser::error(const location_type& location, const std::string& message) {
    context.get_parse_result().set_error(location, message);
}
