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
#line 279 "Parser.yxx"

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
      case 49: // ascalartype
        value.move< AScalarTypeNodePtr > (std::move (that.value));
        break;

      case 63: // anytype
        value.move< AnyTypeNodePtr > (std::move (that.value));
        break;

      case 58: // bytecodetype
        value.move< BytecodeTypeNodePtr > (std::move (that.value));
        break;

      case 53: // environmenttype
        value.move< EnvironmentTypeNodePtr > (std::move (that.value));
        break;

      case 54: // expressiontype
        value.move< ExpressionTypeNodePtr > (std::move (that.value));
        break;

      case 57: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (std::move (that.value));
        break;

      case 71: // functiontype
        value.move< FunctionTypeNodePtr > (std::move (that.value));
        break;

      case 72: // grouptype
        value.move< GroupTypeNodePtr > (std::move (that.value));
        break;

      case 79: // identifier
        value.move< IdentifierNodePtr > (std::move (that.value));
        break;

      case 55: // languagetype
        value.move< LanguageTypeNodePtr > (std::move (that.value));
        break;

      case 74: // listtype
        value.move< ListTypeNodePtr > (std::move (that.value));
        break;

      case 51: // nascalartype
        value.move< NAScalarTypeNodePtr > (std::move (that.value));
        break;

      case 65: // typeseq
      case 67: // namedtypeseq
      case 69: // paramtypeseq
      case 70: // params
      case 75: // structelements
      case 77: // tupleelements
        value.move< NodePtr > (std::move (that.value));
        break;

      case 59: // pairlisttype
        value.move< PairlistTypeNodePtr > (std::move (that.value));
        break;

      case 50: // rawascalartype
        value.move< RawAScalarTypeNodePtr > (std::move (that.value));
        break;

      case 60: // s4type
        value.move< S4TypeNodePtr > (std::move (that.value));
        break;

      case 52: // scalartype
        value.move< ScalarTypeNodePtr > (std::move (that.value));
        break;

      case 76: // structtype
        value.move< StructTypeNodePtr > (std::move (that.value));
        break;

      case 56: // symboltype
        value.move< SymbolTypeNodePtr > (std::move (that.value));
        break;

      case 66: // namedtype
        value.move< TagTypePairNodePtr > (std::move (that.value));
        break;

      case 78: // tupletype
        value.move< TupleTypeNodePtr > (std::move (that.value));
        break;

      case 83: // decltype
        value.move< TypeDeclarationNodePtr > (std::move (that.value));
        break;

      case 68: // paramtype
      case 73: // nonuniontype
      case 80: // uniontype
      case 81: // nulltype
      case 82: // type
        value.move< TypeNodePtr > (std::move (that.value));
        break;

      case 62: // unknowntype
        value.move< UnknownTypeNodePtr > (std::move (that.value));
        break;

      case 64: // vectortype
        value.move< VectorTypeNodePtr > (std::move (that.value));
        break;

      case 61: // weakreftype
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
      case 41: // STRUCT
      case 42: // ANY
      case 43: // TYPEDECL
      case 44: // IDENTIFIER
      case 45: // QUOTED_IDENTIFIER
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
      case 49: // ascalartype
        value.copy< AScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 63: // anytype
        value.copy< AnyTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 58: // bytecodetype
        value.copy< BytecodeTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 53: // environmenttype
        value.copy< EnvironmentTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 54: // expressiontype
        value.copy< ExpressionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 57: // externalptrtype
        value.copy< ExternalPointerTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 71: // functiontype
        value.copy< FunctionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 72: // grouptype
        value.copy< GroupTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 79: // identifier
        value.copy< IdentifierNodePtr > (YY_MOVE (that.value));
        break;

      case 55: // languagetype
        value.copy< LanguageTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 74: // listtype
        value.copy< ListTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 51: // nascalartype
        value.copy< NAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 65: // typeseq
      case 67: // namedtypeseq
      case 69: // paramtypeseq
      case 70: // params
      case 75: // structelements
      case 77: // tupleelements
        value.copy< NodePtr > (YY_MOVE (that.value));
        break;

      case 59: // pairlisttype
        value.copy< PairlistTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 50: // rawascalartype
        value.copy< RawAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 60: // s4type
        value.copy< S4TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 52: // scalartype
        value.copy< ScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 76: // structtype
        value.copy< StructTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 56: // symboltype
        value.copy< SymbolTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 66: // namedtype
        value.copy< TagTypePairNodePtr > (YY_MOVE (that.value));
        break;

      case 78: // tupletype
        value.copy< TupleTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 83: // decltype
        value.copy< TypeDeclarationNodePtr > (YY_MOVE (that.value));
        break;

      case 68: // paramtype
      case 73: // nonuniontype
      case 80: // uniontype
      case 81: // nulltype
      case 82: // type
        value.copy< TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 62: // unknowntype
        value.copy< UnknownTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 64: // vectortype
        value.copy< VectorTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 61: // weakreftype
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
      case 41: // STRUCT
      case 42: // ANY
      case 43: // TYPEDECL
      case 44: // IDENTIFIER
      case 45: // QUOTED_IDENTIFIER
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
      case 49: // ascalartype
        value.move< AScalarTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 63: // anytype
        value.move< AnyTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 58: // bytecodetype
        value.move< BytecodeTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 53: // environmenttype
        value.move< EnvironmentTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 54: // expressiontype
        value.move< ExpressionTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 57: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 71: // functiontype
        value.move< FunctionTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 72: // grouptype
        value.move< GroupTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 79: // identifier
        value.move< IdentifierNodePtr > (YY_MOVE (s.value));
        break;

      case 55: // languagetype
        value.move< LanguageTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 74: // listtype
        value.move< ListTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 51: // nascalartype
        value.move< NAScalarTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 65: // typeseq
      case 67: // namedtypeseq
      case 69: // paramtypeseq
      case 70: // params
      case 75: // structelements
      case 77: // tupleelements
        value.move< NodePtr > (YY_MOVE (s.value));
        break;

      case 59: // pairlisttype
        value.move< PairlistTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 50: // rawascalartype
        value.move< RawAScalarTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 60: // s4type
        value.move< S4TypeNodePtr > (YY_MOVE (s.value));
        break;

      case 52: // scalartype
        value.move< ScalarTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 76: // structtype
        value.move< StructTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 56: // symboltype
        value.move< SymbolTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 66: // namedtype
        value.move< TagTypePairNodePtr > (YY_MOVE (s.value));
        break;

      case 78: // tupletype
        value.move< TupleTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 83: // decltype
        value.move< TypeDeclarationNodePtr > (YY_MOVE (s.value));
        break;

      case 68: // paramtype
      case 73: // nonuniontype
      case 80: // uniontype
      case 81: // nulltype
      case 82: // type
        value.move< TypeNodePtr > (YY_MOVE (s.value));
        break;

      case 62: // unknowntype
        value.move< UnknownTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 64: // vectortype
        value.move< VectorTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 61: // weakreftype
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
      case 41: // STRUCT
      case 42: // ANY
      case 43: // TYPEDECL
      case 44: // IDENTIFIER
      case 45: // QUOTED_IDENTIFIER
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
      case 49: // ascalartype
        value.YY_MOVE_OR_COPY< AScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 63: // anytype
        value.YY_MOVE_OR_COPY< AnyTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 58: // bytecodetype
        value.YY_MOVE_OR_COPY< BytecodeTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 53: // environmenttype
        value.YY_MOVE_OR_COPY< EnvironmentTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 54: // expressiontype
        value.YY_MOVE_OR_COPY< ExpressionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 57: // externalptrtype
        value.YY_MOVE_OR_COPY< ExternalPointerTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 71: // functiontype
        value.YY_MOVE_OR_COPY< FunctionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 72: // grouptype
        value.YY_MOVE_OR_COPY< GroupTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 79: // identifier
        value.YY_MOVE_OR_COPY< IdentifierNodePtr > (YY_MOVE (that.value));
        break;

      case 55: // languagetype
        value.YY_MOVE_OR_COPY< LanguageTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 74: // listtype
        value.YY_MOVE_OR_COPY< ListTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 51: // nascalartype
        value.YY_MOVE_OR_COPY< NAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 65: // typeseq
      case 67: // namedtypeseq
      case 69: // paramtypeseq
      case 70: // params
      case 75: // structelements
      case 77: // tupleelements
        value.YY_MOVE_OR_COPY< NodePtr > (YY_MOVE (that.value));
        break;

      case 59: // pairlisttype
        value.YY_MOVE_OR_COPY< PairlistTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 50: // rawascalartype
        value.YY_MOVE_OR_COPY< RawAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 60: // s4type
        value.YY_MOVE_OR_COPY< S4TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 52: // scalartype
        value.YY_MOVE_OR_COPY< ScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 76: // structtype
        value.YY_MOVE_OR_COPY< StructTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 56: // symboltype
        value.YY_MOVE_OR_COPY< SymbolTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 66: // namedtype
        value.YY_MOVE_OR_COPY< TagTypePairNodePtr > (YY_MOVE (that.value));
        break;

      case 78: // tupletype
        value.YY_MOVE_OR_COPY< TupleTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 83: // decltype
        value.YY_MOVE_OR_COPY< TypeDeclarationNodePtr > (YY_MOVE (that.value));
        break;

      case 68: // paramtype
      case 73: // nonuniontype
      case 80: // uniontype
      case 81: // nulltype
      case 82: // type
        value.YY_MOVE_OR_COPY< TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 62: // unknowntype
        value.YY_MOVE_OR_COPY< UnknownTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 64: // vectortype
        value.YY_MOVE_OR_COPY< VectorTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 61: // weakreftype
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
      case 41: // STRUCT
      case 42: // ANY
      case 43: // TYPEDECL
      case 44: // IDENTIFIER
      case 45: // QUOTED_IDENTIFIER
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
      case 49: // ascalartype
        value.move< AScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 63: // anytype
        value.move< AnyTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 58: // bytecodetype
        value.move< BytecodeTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 53: // environmenttype
        value.move< EnvironmentTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 54: // expressiontype
        value.move< ExpressionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 57: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 71: // functiontype
        value.move< FunctionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 72: // grouptype
        value.move< GroupTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 79: // identifier
        value.move< IdentifierNodePtr > (YY_MOVE (that.value));
        break;

      case 55: // languagetype
        value.move< LanguageTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 74: // listtype
        value.move< ListTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 51: // nascalartype
        value.move< NAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 65: // typeseq
      case 67: // namedtypeseq
      case 69: // paramtypeseq
      case 70: // params
      case 75: // structelements
      case 77: // tupleelements
        value.move< NodePtr > (YY_MOVE (that.value));
        break;

      case 59: // pairlisttype
        value.move< PairlistTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 50: // rawascalartype
        value.move< RawAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 60: // s4type
        value.move< S4TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 52: // scalartype
        value.move< ScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 76: // structtype
        value.move< StructTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 56: // symboltype
        value.move< SymbolTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 66: // namedtype
        value.move< TagTypePairNodePtr > (YY_MOVE (that.value));
        break;

      case 78: // tupletype
        value.move< TupleTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 83: // decltype
        value.move< TypeDeclarationNodePtr > (YY_MOVE (that.value));
        break;

      case 68: // paramtype
      case 73: // nonuniontype
      case 80: // uniontype
      case 81: // nulltype
      case 82: // type
        value.move< TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 62: // unknowntype
        value.move< UnknownTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 64: // vectortype
        value.move< VectorTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 61: // weakreftype
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
      case 41: // STRUCT
      case 42: // ANY
      case 43: // TYPEDECL
      case 44: // IDENTIFIER
      case 45: // QUOTED_IDENTIFIER
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
      case 49: // ascalartype
        value.copy< AScalarTypeNodePtr > (that.value);
        break;

      case 63: // anytype
        value.copy< AnyTypeNodePtr > (that.value);
        break;

      case 58: // bytecodetype
        value.copy< BytecodeTypeNodePtr > (that.value);
        break;

      case 53: // environmenttype
        value.copy< EnvironmentTypeNodePtr > (that.value);
        break;

      case 54: // expressiontype
        value.copy< ExpressionTypeNodePtr > (that.value);
        break;

      case 57: // externalptrtype
        value.copy< ExternalPointerTypeNodePtr > (that.value);
        break;

      case 71: // functiontype
        value.copy< FunctionTypeNodePtr > (that.value);
        break;

      case 72: // grouptype
        value.copy< GroupTypeNodePtr > (that.value);
        break;

      case 79: // identifier
        value.copy< IdentifierNodePtr > (that.value);
        break;

      case 55: // languagetype
        value.copy< LanguageTypeNodePtr > (that.value);
        break;

      case 74: // listtype
        value.copy< ListTypeNodePtr > (that.value);
        break;

      case 51: // nascalartype
        value.copy< NAScalarTypeNodePtr > (that.value);
        break;

      case 65: // typeseq
      case 67: // namedtypeseq
      case 69: // paramtypeseq
      case 70: // params
      case 75: // structelements
      case 77: // tupleelements
        value.copy< NodePtr > (that.value);
        break;

      case 59: // pairlisttype
        value.copy< PairlistTypeNodePtr > (that.value);
        break;

      case 50: // rawascalartype
        value.copy< RawAScalarTypeNodePtr > (that.value);
        break;

      case 60: // s4type
        value.copy< S4TypeNodePtr > (that.value);
        break;

      case 52: // scalartype
        value.copy< ScalarTypeNodePtr > (that.value);
        break;

      case 76: // structtype
        value.copy< StructTypeNodePtr > (that.value);
        break;

      case 56: // symboltype
        value.copy< SymbolTypeNodePtr > (that.value);
        break;

      case 66: // namedtype
        value.copy< TagTypePairNodePtr > (that.value);
        break;

      case 78: // tupletype
        value.copy< TupleTypeNodePtr > (that.value);
        break;

      case 83: // decltype
        value.copy< TypeDeclarationNodePtr > (that.value);
        break;

      case 68: // paramtype
      case 73: // nonuniontype
      case 80: // uniontype
      case 81: // nulltype
      case 82: // type
        value.copy< TypeNodePtr > (that.value);
        break;

      case 62: // unknowntype
        value.copy< UnknownTypeNodePtr > (that.value);
        break;

      case 64: // vectortype
        value.copy< VectorTypeNodePtr > (that.value);
        break;

      case 61: // weakreftype
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
      case 41: // STRUCT
      case 42: // ANY
      case 43: // TYPEDECL
      case 44: // IDENTIFIER
      case 45: // QUOTED_IDENTIFIER
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
      case 49: // ascalartype
        value.move< AScalarTypeNodePtr > (that.value);
        break;

      case 63: // anytype
        value.move< AnyTypeNodePtr > (that.value);
        break;

      case 58: // bytecodetype
        value.move< BytecodeTypeNodePtr > (that.value);
        break;

      case 53: // environmenttype
        value.move< EnvironmentTypeNodePtr > (that.value);
        break;

      case 54: // expressiontype
        value.move< ExpressionTypeNodePtr > (that.value);
        break;

      case 57: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (that.value);
        break;

      case 71: // functiontype
        value.move< FunctionTypeNodePtr > (that.value);
        break;

      case 72: // grouptype
        value.move< GroupTypeNodePtr > (that.value);
        break;

      case 79: // identifier
        value.move< IdentifierNodePtr > (that.value);
        break;

      case 55: // languagetype
        value.move< LanguageTypeNodePtr > (that.value);
        break;

      case 74: // listtype
        value.move< ListTypeNodePtr > (that.value);
        break;

      case 51: // nascalartype
        value.move< NAScalarTypeNodePtr > (that.value);
        break;

      case 65: // typeseq
      case 67: // namedtypeseq
      case 69: // paramtypeseq
      case 70: // params
      case 75: // structelements
      case 77: // tupleelements
        value.move< NodePtr > (that.value);
        break;

      case 59: // pairlisttype
        value.move< PairlistTypeNodePtr > (that.value);
        break;

      case 50: // rawascalartype
        value.move< RawAScalarTypeNodePtr > (that.value);
        break;

      case 60: // s4type
        value.move< S4TypeNodePtr > (that.value);
        break;

      case 52: // scalartype
        value.move< ScalarTypeNodePtr > (that.value);
        break;

      case 76: // structtype
        value.move< StructTypeNodePtr > (that.value);
        break;

      case 56: // symboltype
        value.move< SymbolTypeNodePtr > (that.value);
        break;

      case 66: // namedtype
        value.move< TagTypePairNodePtr > (that.value);
        break;

      case 78: // tupletype
        value.move< TupleTypeNodePtr > (that.value);
        break;

      case 83: // decltype
        value.move< TypeDeclarationNodePtr > (that.value);
        break;

      case 68: // paramtype
      case 73: // nonuniontype
      case 80: // uniontype
      case 81: // nulltype
      case 82: // type
        value.move< TypeNodePtr > (that.value);
        break;

      case 62: // unknowntype
        value.move< UnknownTypeNodePtr > (that.value);
        break;

      case 64: // vectortype
        value.move< VectorTypeNodePtr > (that.value);
        break;

      case 61: // weakreftype
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
      case 41: // STRUCT
      case 42: // ANY
      case 43: // TYPEDECL
      case 44: // IDENTIFIER
      case 45: // QUOTED_IDENTIFIER
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
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1601 "Parser.cxx"
        break;

      case 4: // "^"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1607 "Parser.cxx"
        break;

      case 5: // "=>"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1613 "Parser.cxx"
        break;

      case 6: // ","
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1619 "Parser.cxx"
        break;

      case 7: // "(("
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1625 "Parser.cxx"
        break;

      case 8: // "("
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1631 "Parser.cxx"
        break;

      case 9: // "))"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1637 "Parser.cxx"
        break;

      case 10: // ")"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1643 "Parser.cxx"
        break;

      case 11: // "[]"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1649 "Parser.cxx"
        break;

      case 12: // "<"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1655 "Parser.cxx"
        break;

      case 13: // ">"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1661 "Parser.cxx"
        break;

      case 14: // "[["
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1667 "Parser.cxx"
        break;

      case 15: // "]]"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1673 "Parser.cxx"
        break;

      case 16: // "{{"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1679 "Parser.cxx"
        break;

      case 17: // "}}"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1685 "Parser.cxx"
        break;

      case 18: // ";"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1691 "Parser.cxx"
        break;

      case 19: // ":"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1697 "Parser.cxx"
        break;

      case 20: // "..."
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1703 "Parser.cxx"
        break;

      case 21: // "???"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1709 "Parser.cxx"
        break;

      case 22: // "?"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1715 "Parser.cxx"
        break;

      case 23: // "null"
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1721 "Parser.cxx"
        break;

      case 24: // INTEGER
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1727 "Parser.cxx"
        break;

      case 25: // DOUBLE
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1733 "Parser.cxx"
        break;

      case 26: // COMPLEX
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1739 "Parser.cxx"
        break;

      case 27: // CHARACTER
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1745 "Parser.cxx"
        break;

      case 28: // LOGICAL
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1751 "Parser.cxx"
        break;

      case 29: // RAW
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1757 "Parser.cxx"
        break;

      case 30: // ENVIRONMENT
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1763 "Parser.cxx"
        break;

      case 31: // EXPRESSION
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1769 "Parser.cxx"
        break;

      case 32: // LANGUAGE
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1775 "Parser.cxx"
        break;

      case 33: // SYMBOL
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1781 "Parser.cxx"
        break;

      case 34: // EXTERNALPOINTER
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1787 "Parser.cxx"
        break;

      case 35: // BYTECODE
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1793 "Parser.cxx"
        break;

      case 36: // PAIRLIST
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1799 "Parser.cxx"
        break;

      case 37: // S4
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1805 "Parser.cxx"
        break;

      case 38: // WEAKREF
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1811 "Parser.cxx"
        break;

      case 39: // TUPLE
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1817 "Parser.cxx"
        break;

      case 40: // LIST
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1823 "Parser.cxx"
        break;

      case 41: // STRUCT
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1829 "Parser.cxx"
        break;

      case 42: // ANY
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1835 "Parser.cxx"
        break;

      case 43: // TYPEDECL
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1841 "Parser.cxx"
        break;

      case 44: // IDENTIFIER
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1847 "Parser.cxx"
        break;

      case 45: // QUOTED_IDENTIFIER
#line 143 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1853 "Parser.cxx"
        break;

      case 49: // ascalartype
#line 118 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < AScalarTypeNodePtr > ()); }
#line 1859 "Parser.cxx"
        break;

      case 50: // rawascalartype
#line 117 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < RawAScalarTypeNodePtr > ()); }
#line 1865 "Parser.cxx"
        break;

      case 51: // nascalartype
#line 119 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NAScalarTypeNodePtr > ()); }
#line 1871 "Parser.cxx"
        break;

      case 52: // scalartype
#line 120 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ScalarTypeNodePtr > ()); }
#line 1877 "Parser.cxx"
        break;

      case 53: // environmenttype
#line 121 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < EnvironmentTypeNodePtr > ()); }
#line 1883 "Parser.cxx"
        break;

      case 54: // expressiontype
#line 122 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ExpressionTypeNodePtr > ()); }
#line 1889 "Parser.cxx"
        break;

      case 55: // languagetype
#line 123 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < LanguageTypeNodePtr > ()); }
#line 1895 "Parser.cxx"
        break;

      case 56: // symboltype
#line 124 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < SymbolTypeNodePtr > ()); }
#line 1901 "Parser.cxx"
        break;

      case 57: // externalptrtype
#line 125 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ExternalPointerTypeNodePtr > ()); }
#line 1907 "Parser.cxx"
        break;

      case 58: // bytecodetype
#line 126 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < BytecodeTypeNodePtr > ()); }
#line 1913 "Parser.cxx"
        break;

      case 59: // pairlisttype
#line 127 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < PairlistTypeNodePtr > ()); }
#line 1919 "Parser.cxx"
        break;

      case 60: // s4type
#line 128 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < S4TypeNodePtr > ()); }
#line 1925 "Parser.cxx"
        break;

      case 61: // weakreftype
#line 129 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < WeakReferenceTypeNodePtr > ()); }
#line 1931 "Parser.cxx"
        break;

      case 62: // unknowntype
#line 131 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < UnknownTypeNodePtr > ()); }
#line 1937 "Parser.cxx"
        break;

      case 63: // anytype
#line 130 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < AnyTypeNodePtr > ()); }
#line 1943 "Parser.cxx"
        break;

      case 64: // vectortype
#line 132 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < VectorTypeNodePtr > ()); }
#line 1949 "Parser.cxx"
        break;

      case 65: // typeseq
#line 133 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 1955 "Parser.cxx"
        break;

      case 66: // namedtype
#line 134 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TagTypePairNodePtr > ()); }
#line 1961 "Parser.cxx"
        break;

      case 67: // namedtypeseq
#line 133 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 1967 "Parser.cxx"
        break;

      case 68: // paramtype
#line 141 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 1973 "Parser.cxx"
        break;

      case 69: // paramtypeseq
#line 133 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 1979 "Parser.cxx"
        break;

      case 70: // params
#line 133 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 1985 "Parser.cxx"
        break;

      case 71: // functiontype
#line 135 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < FunctionTypeNodePtr > ()); }
#line 1991 "Parser.cxx"
        break;

      case 72: // grouptype
#line 136 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < GroupTypeNodePtr > ()); }
#line 1997 "Parser.cxx"
        break;

      case 73: // nonuniontype
#line 141 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2003 "Parser.cxx"
        break;

      case 74: // listtype
#line 137 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ListTypeNodePtr > ()); }
#line 2009 "Parser.cxx"
        break;

      case 75: // structelements
#line 133 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 2015 "Parser.cxx"
        break;

      case 76: // structtype
#line 138 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < StructTypeNodePtr > ()); }
#line 2021 "Parser.cxx"
        break;

      case 77: // tupleelements
#line 133 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 2027 "Parser.cxx"
        break;

      case 78: // tupletype
#line 139 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TupleTypeNodePtr > ()); }
#line 2033 "Parser.cxx"
        break;

      case 79: // identifier
#line 140 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < IdentifierNodePtr > ()); }
#line 2039 "Parser.cxx"
        break;

      case 80: // uniontype
#line 141 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2045 "Parser.cxx"
        break;

      case 81: // nulltype
#line 141 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2051 "Parser.cxx"
        break;

      case 82: // type
#line 141 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2057 "Parser.cxx"
        break;

      case 83: // decltype
#line 142 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeDeclarationNodePtr > ()); }
#line 2063 "Parser.cxx"
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
#line 180 "Parser.yxx"
{
    /* filename for locations here
       https://www.gnu.org/software/bison/manual/html_node/Initial-Action-Decl.html
       location stores pointer to a string allocated elsewhere and does not delete it.
       it has been disabled for now since TopLevelNode stores the filename anyways and
       properly deallocates it.
    */

    /* @$.initialize(context.get_input_stream_name()); */
}

#line 2193 "Parser.cxx"


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
      case 49: // ascalartype
        yylhs.value.emplace< AScalarTypeNodePtr > ();
        break;

      case 63: // anytype
        yylhs.value.emplace< AnyTypeNodePtr > ();
        break;

      case 58: // bytecodetype
        yylhs.value.emplace< BytecodeTypeNodePtr > ();
        break;

      case 53: // environmenttype
        yylhs.value.emplace< EnvironmentTypeNodePtr > ();
        break;

      case 54: // expressiontype
        yylhs.value.emplace< ExpressionTypeNodePtr > ();
        break;

      case 57: // externalptrtype
        yylhs.value.emplace< ExternalPointerTypeNodePtr > ();
        break;

      case 71: // functiontype
        yylhs.value.emplace< FunctionTypeNodePtr > ();
        break;

      case 72: // grouptype
        yylhs.value.emplace< GroupTypeNodePtr > ();
        break;

      case 79: // identifier
        yylhs.value.emplace< IdentifierNodePtr > ();
        break;

      case 55: // languagetype
        yylhs.value.emplace< LanguageTypeNodePtr > ();
        break;

      case 74: // listtype
        yylhs.value.emplace< ListTypeNodePtr > ();
        break;

      case 51: // nascalartype
        yylhs.value.emplace< NAScalarTypeNodePtr > ();
        break;

      case 65: // typeseq
      case 67: // namedtypeseq
      case 69: // paramtypeseq
      case 70: // params
      case 75: // structelements
      case 77: // tupleelements
        yylhs.value.emplace< NodePtr > ();
        break;

      case 59: // pairlisttype
        yylhs.value.emplace< PairlistTypeNodePtr > ();
        break;

      case 50: // rawascalartype
        yylhs.value.emplace< RawAScalarTypeNodePtr > ();
        break;

      case 60: // s4type
        yylhs.value.emplace< S4TypeNodePtr > ();
        break;

      case 52: // scalartype
        yylhs.value.emplace< ScalarTypeNodePtr > ();
        break;

      case 76: // structtype
        yylhs.value.emplace< StructTypeNodePtr > ();
        break;

      case 56: // symboltype
        yylhs.value.emplace< SymbolTypeNodePtr > ();
        break;

      case 66: // namedtype
        yylhs.value.emplace< TagTypePairNodePtr > ();
        break;

      case 78: // tupletype
        yylhs.value.emplace< TupleTypeNodePtr > ();
        break;

      case 83: // decltype
        yylhs.value.emplace< TypeDeclarationNodePtr > ();
        break;

      case 68: // paramtype
      case 73: // nonuniontype
      case 80: // uniontype
      case 81: // nulltype
      case 82: // type
        yylhs.value.emplace< TypeNodePtr > ();
        break;

      case 62: // unknowntype
        yylhs.value.emplace< UnknownTypeNodePtr > ();
        break;

      case 64: // vectortype
        yylhs.value.emplace< VectorTypeNodePtr > ();
        break;

      case 61: // weakreftype
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
      case 41: // STRUCT
      case 42: // ANY
      case 43: // TYPEDECL
      case 44: // IDENTIFIER
      case 45: // QUOTED_IDENTIFIER
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
#line 342 "Parser.yxx"
                                                            {   yylhs.value.as < AScalarTypeNodePtr > () = create_node_with_keyword<IntegerAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2478 "Parser.cxx"
    break;

  case 3:
#line 343 "Parser.yxx"
                                                            {   yylhs.value.as < AScalarTypeNodePtr > () = create_node_with_keyword<DoubleAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2484 "Parser.cxx"
    break;

  case 4:
#line 344 "Parser.yxx"
                                                            {   yylhs.value.as < AScalarTypeNodePtr > () = create_node_with_keyword<ComplexAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2490 "Parser.cxx"
    break;

  case 5:
#line 345 "Parser.yxx"
                                                            {   yylhs.value.as < AScalarTypeNodePtr > () = create_node_with_keyword<CharacterAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2496 "Parser.cxx"
    break;

  case 6:
#line 346 "Parser.yxx"
                                                            {   yylhs.value.as < AScalarTypeNodePtr > () = create_node_with_keyword<LogicalAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2502 "Parser.cxx"
    break;

  case 7:
#line 349 "Parser.yxx"
                                                            {   yylhs.value.as < RawAScalarTypeNodePtr > () = create_node_with_keyword<RawAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2508 "Parser.cxx"
    break;

  case 8:
#line 352 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NAScalarTypeNodePtr > () = new NAScalarTypeNode(std::move(wrap(std::move(op))),
                                                                                          std::move(wrap(std::move(yystack_[0].value.as < AScalarTypeNodePtr > ()))));
                                                                yylhs.value.as < NAScalarTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2519 "Parser.cxx"
    break;

  case 9:
#line 359 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = yystack_[0].value.as < AScalarTypeNodePtr > ();
                                                                yystack_[0].value.as < AScalarTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2529 "Parser.cxx"
    break;

  case 10:
#line 364 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = yystack_[0].value.as < RawAScalarTypeNodePtr > ();
                                                                yystack_[0].value.as < RawAScalarTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2539 "Parser.cxx"
    break;

  case 11:
#line 369 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = yystack_[0].value.as < NAScalarTypeNodePtr > ();
                                                                yystack_[0].value.as < NAScalarTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2549 "Parser.cxx"
    break;

  case 12:
#line 376 "Parser.yxx"
                                                            {   yylhs.value.as < EnvironmentTypeNodePtr > () = create_node_with_keyword<EnvironmentTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2555 "Parser.cxx"
    break;

  case 13:
#line 379 "Parser.yxx"
                                                            {   yylhs.value.as < ExpressionTypeNodePtr > () = create_node_with_keyword<ExpressionTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context);  }
#line 2561 "Parser.cxx"
    break;

  case 14:
#line 382 "Parser.yxx"
                                                            {   yylhs.value.as < LanguageTypeNodePtr > () = create_node_with_keyword<LanguageTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context);    }
#line 2567 "Parser.cxx"
    break;

  case 15:
#line 385 "Parser.yxx"
                                                            {   yylhs.value.as < SymbolTypeNodePtr > () = create_node_with_keyword<SymbolTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context);      }
#line 2573 "Parser.cxx"
    break;

  case 16:
#line 388 "Parser.yxx"
                                                            {   yylhs.value.as < ExternalPointerTypeNodePtr > () = create_node_with_keyword<ExternalPointerTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2579 "Parser.cxx"
    break;

  case 17:
#line 391 "Parser.yxx"
                                                            {   yylhs.value.as < BytecodeTypeNodePtr > () = create_node_with_keyword<BytecodeTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2585 "Parser.cxx"
    break;

  case 18:
#line 394 "Parser.yxx"
                                                            {   yylhs.value.as < PairlistTypeNodePtr > () = create_node_with_keyword<PairlistTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2591 "Parser.cxx"
    break;

  case 19:
#line 397 "Parser.yxx"
                                                            {   yylhs.value.as < S4TypeNodePtr > () = create_node_with_keyword<S4TypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2597 "Parser.cxx"
    break;

  case 20:
#line 400 "Parser.yxx"
                                                            {   yylhs.value.as < WeakReferenceTypeNodePtr > () = create_node_with_keyword<WeakReferenceTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2603 "Parser.cxx"
    break;

  case 21:
#line 403 "Parser.yxx"
                                                            {   yylhs.value.as < AnyTypeNodePtr > () = create_node_with_keyword<AnyTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2609 "Parser.cxx"
    break;

  case 22:
#line 406 "Parser.yxx"
                                                            {   yylhs.value.as < UnknownTypeNodePtr > () = create_node_with_keyword<UnknownTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2615 "Parser.cxx"
    break;

  case 23:
#line 409 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);
                                                                yylhs.value.as < VectorTypeNodePtr > () = new VectorTypeNode(std::move(wrap(std::move(op))),
                                                                                        std::move(wrap(std::move(yystack_[1].value.as < ScalarTypeNodePtr > ()))));
                                                                yylhs.value.as < VectorTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2626 "Parser.cxx"
    break;

  case 24:
#line 417 "Parser.yxx"
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
#line 2646 "Parser.cxx"
    break;

  case 25:
#line 434 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                            }
#line 2655 "Parser.cxx"
    break;

  case 26:
#line 438 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr op = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NodePtr > () = new CommaSeparatorNode(std::move(wrap(std::move(op))),
                                                                                            std::move(wrap(std::move(yystack_[2].value.as < NodePtr > ()))),
                                                                                            std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2667 "Parser.cxx"
    break;

  case 27:
#line 448 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = new EmptyNode();
                                                            }
#line 2675 "Parser.cxx"
    break;

  case 28:
#line 451 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < NodePtr > ();
                                                                yystack_[0].value.as < NodePtr > () = nullptr;
                                                            }
#line 2684 "Parser.cxx"
    break;

  case 29:
#line 456 "Parser.yxx"
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
#line 2704 "Parser.cxx"
    break;

  case 30:
#line 474 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = new EmptyNode();
                                                            }
#line 2712 "Parser.cxx"
    break;

  case 31:
#line 477 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < NodePtr > ();
                                                                yystack_[0].value.as < NodePtr > () = nullptr;
                                                            }
#line 2721 "Parser.cxx"
    break;

  case 32:
#line 483 "Parser.yxx"
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
#line 2741 "Parser.cxx"
    break;

  case 33:
#line 500 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2747 "Parser.cxx"
    break;

  case 34:
#line 501 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2753 "Parser.cxx"
    break;

  case 35:
#line 502 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2759 "Parser.cxx"
    break;

  case 36:
#line 503 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2765 "Parser.cxx"
    break;

  case 37:
#line 504 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2771 "Parser.cxx"
    break;

  case 38:
#line 505 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2777 "Parser.cxx"
    break;

  case 39:
#line 506 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2783 "Parser.cxx"
    break;

  case 40:
#line 507 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2789 "Parser.cxx"
    break;

  case 41:
#line 508 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2795 "Parser.cxx"
    break;

  case 42:
#line 509 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2801 "Parser.cxx"
    break;

  case 43:
#line 510 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2807 "Parser.cxx"
    break;

  case 44:
#line 511 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2813 "Parser.cxx"
    break;

  case 45:
#line 512 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2819 "Parser.cxx"
    break;

  case 46:
#line 513 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2825 "Parser.cxx"
    break;

  case 47:
#line 514 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2831 "Parser.cxx"
    break;

  case 48:
#line 515 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2837 "Parser.cxx"
    break;

  case 49:
#line 516 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2843 "Parser.cxx"
    break;

  case 50:
#line 517 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2849 "Parser.cxx"
    break;

  case 51:
#line 518 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2855 "Parser.cxx"
    break;

  case 52:
#line 519 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2861 "Parser.cxx"
    break;

  case 53:
#line 520 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2867 "Parser.cxx"
    break;

  case 54:
#line 521 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2873 "Parser.cxx"
    break;

  case 55:
#line 522 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), true, false, yystack_[0].location, context);  }
#line 2879 "Parser.cxx"
    break;

  case 56:
#line 525 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr separator = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < TagTypePairNodePtr > () = new TagTypePairNode(std::move(wrap(std::move(yystack_[2].value.as < IdentifierNodePtr > ()))),
                                                                                         std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))),
                                                                                         std::move(wrap(std::move(separator))));
                                                                yylhs.value.as < TagTypePairNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2891 "Parser.cxx"
    break;

  case 57:
#line 532 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr separator = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                IdentifierNodePtr id = create_identifier(yystack_[2].value.as < std::string > (), false, true, yystack_[2].location, context);
                                                                yylhs.value.as < TagTypePairNodePtr > () = new TagTypePairNode(std::move(wrap(std::move(id))),
                                                                                         std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))),
                                                                                         std::move(wrap(std::move(separator))));
                                                                yylhs.value.as < TagTypePairNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2904 "Parser.cxx"
    break;

  case 58:
#line 542 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < TagTypePairNodePtr > ();
                                                                yystack_[0].value.as < TagTypePairNodePtr > () = nullptr;
                                                            }
#line 2913 "Parser.cxx"
    break;

  case 59:
#line 546 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr op = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NodePtr > () = new CommaSeparatorNode(std::move(wrap(std::move(op))),
                                                                                            std::move(wrap(std::move(yystack_[2].value.as < NodePtr > ()))),
                                                                                            std::move(wrap(std::move(yystack_[0].value.as < TagTypePairNodePtr > ()))));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2925 "Parser.cxx"
    break;

  case 60:
#line 556 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                            }
#line 2934 "Parser.cxx"
    break;

  case 61:
#line 560 "Parser.yxx"
                                                            {   yylhs.value.as < TypeNodePtr > () = create_node_with_keyword<VarargTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2940 "Parser.cxx"
    break;

  case 62:
#line 563 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                            }
#line 2949 "Parser.cxx"
    break;

  case 63:
#line 567 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr op = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NodePtr > () = new CommaSeparatorNode(std::move(wrap(std::move(op))),
                                                                                            std::move(wrap(std::move(yystack_[2].value.as < NodePtr > ()))),
                                                                                            std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2961 "Parser.cxx"
    break;

  case 64:
#line 576 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr right = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);
                                                                OperatorNodePtr left = create_operator(yystack_[2].value.as < std::string > (), yystack_[2].location, context);
                                                                yylhs.value.as < NodePtr > () = new ParameterNode(std::move(wrap(std::move(left))),
                                                                                       std::move(wrap(std::move(right))),
                                                                                       std::move(wrap(std::move(yystack_[1].value.as < NodePtr > ()))));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2974 "Parser.cxx"
    break;

  case 65:
#line 584 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr right = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);
                                                                OperatorNodePtr left = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NodePtr > () = new ParameterNode(std::move(wrap(std::move(left))),
                                                                                       std::move(wrap(std::move(right))),
                                                                                       std::move(wrap(new EmptyNode())));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2987 "Parser.cxx"
    break;

  case 66:
#line 592 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < AnyTypeNodePtr > ();
                                                                yystack_[0].value.as < AnyTypeNodePtr > () = nullptr;
                                                            }
#line 2996 "Parser.cxx"
    break;

  case 67:
#line 598 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < FunctionTypeNodePtr > () = new FunctionTypeNode(std::move(wrap(std::move(op))),
                                                                                          std::move(wrap(std::move(yystack_[2].value.as < NodePtr > ()))),
                                                                                          std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < FunctionTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3008 "Parser.cxx"
    break;

  case 68:
#line 607 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr right = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);
                                                                OperatorNodePtr left = create_operator(yystack_[2].value.as < std::string > (), yystack_[2].location, context);
                                                                yylhs.value.as < GroupTypeNodePtr > () = new GroupTypeNode(std::move(wrap(std::move(left))),
                                                                                       std::move(wrap(std::move(right))),
                                                                                       std::move(wrap(std::move(yystack_[1].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < GroupTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3021 "Parser.cxx"
    break;

  case 69:
#line 617 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ScalarTypeNodePtr > ();
                                                                yystack_[0].value.as < ScalarTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3031 "Parser.cxx"
    break;

  case 70:
#line 622 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < EnvironmentTypeNodePtr > ();
                                                                yystack_[0].value.as < EnvironmentTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3041 "Parser.cxx"
    break;

  case 71:
#line 627 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ExpressionTypeNodePtr > ();
                                                                yystack_[0].value.as < ExpressionTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3051 "Parser.cxx"
    break;

  case 72:
#line 632 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < LanguageTypeNodePtr > ();
                                                                yystack_[0].value.as < LanguageTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3061 "Parser.cxx"
    break;

  case 73:
#line 637 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < SymbolTypeNodePtr > ();
                                                                yystack_[0].value.as < SymbolTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3071 "Parser.cxx"
    break;

  case 74:
#line 642 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ExternalPointerTypeNodePtr > ();
                                                                yystack_[0].value.as < ExternalPointerTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3081 "Parser.cxx"
    break;

  case 75:
#line 647 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < BytecodeTypeNodePtr > ();
                                                                yystack_[0].value.as < BytecodeTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3091 "Parser.cxx"
    break;

  case 76:
#line 652 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < PairlistTypeNodePtr > ();
                                                                yystack_[0].value.as < PairlistTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3101 "Parser.cxx"
    break;

  case 77:
#line 657 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < S4TypeNodePtr > ();
                                                                yystack_[0].value.as < S4TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3111 "Parser.cxx"
    break;

  case 78:
#line 662 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < WeakReferenceTypeNodePtr > ();
                                                                yystack_[0].value.as < WeakReferenceTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3121 "Parser.cxx"
    break;

  case 79:
#line 667 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < VectorTypeNodePtr > ();
                                                                yystack_[0].value.as < VectorTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3131 "Parser.cxx"
    break;

  case 80:
#line 672 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < FunctionTypeNodePtr > ();
                                                                yystack_[0].value.as < FunctionTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3141 "Parser.cxx"
    break;

  case 81:
#line 677 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < StructTypeNodePtr > ();
                                                                yystack_[0].value.as < StructTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3151 "Parser.cxx"
    break;

  case 82:
#line 682 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ListTypeNodePtr > ();
                                                                yystack_[0].value.as < ListTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3161 "Parser.cxx"
    break;

  case 83:
#line 687 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TupleTypeNodePtr > ();
                                                                yystack_[0].value.as < TupleTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3171 "Parser.cxx"
    break;

  case 84:
#line 692 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < GroupTypeNodePtr > ();
                                                                yystack_[0].value.as < GroupTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3181 "Parser.cxx"
    break;

  case 85:
#line 697 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < UnknownTypeNodePtr > ();
                                                                yystack_[0].value.as < UnknownTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3191 "Parser.cxx"
    break;

  case 86:
#line 705 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3201 "Parser.cxx"
    break;

  case 87:
#line 710 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < TypeNodePtr > () = new UnionTypeNode(std::move(wrap(std::move(op))),
                                                                                       std::move(wrap(std::move(yystack_[2].value.as < TypeNodePtr > ()))),
                                                                                       std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3213 "Parser.cxx"
    break;

  case 88:
#line 720 "Parser.yxx"
                                                            {   yylhs.value.as < TypeNodePtr > () = create_node_with_keyword<NullTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 3219 "Parser.cxx"
    break;

  case 89:
#line 721 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < TypeNodePtr > () = new NullableTypeNode(std::move(wrap(std::move(op))),
                                                                                          std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3230 "Parser.cxx"
    break;

  case 90:
#line 730 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3240 "Parser.cxx"
    break;

  case 91:
#line 735 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3250 "Parser.cxx"
    break;

  case 92:
#line 740 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < AnyTypeNodePtr > ();
                                                                yystack_[0].value.as < AnyTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3260 "Parser.cxx"
    break;

  case 93:
#line 747 "Parser.yxx"
                                                            {
                                                                TerminatorNodePtr terminator = create_terminator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);
                                                                KeywordNodePtr keyword = create_keyword(yystack_[3].value.as < std::string > (), yystack_[3].location, context);
                                                                yylhs.value.as < TypeDeclarationNodePtr > () = new TypeDeclarationNode(std::move(wrap(std::move(keyword))),
                                                                                             std::move(wrap(std::move(yystack_[2].value.as < IdentifierNodePtr > ()))),
                                                                                             std::move(wrap(std::move(yystack_[1].value.as < TypeNodePtr > ()))),
                                                                                             std::move(wrap(std::move(terminator))));
                                                                yylhs.value.as < TypeDeclarationNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3274 "Parser.cxx"
    break;

  case 94:
#line 758 "Parser.yxx"
                                                            {
                                                                TopLevelNodeUPtr& node(context.get_parse_result().get_top_level_node());
                                                                node -> get_type_declarations().push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeDeclarationNodePtr > ()))));
                                                            }
#line 3283 "Parser.cxx"
    break;

  case 95:
#line 762 "Parser.yxx"
                                                            {
                                                                TopLevelNodeUPtr& node(context.get_parse_result().get_top_level_node());
                                                                node -> get_type_declarations().push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeDeclarationNodePtr > ()))));
                                                            }
#line 3292 "Parser.cxx"
    break;

  case 96:
#line 768 "Parser.yxx"
                                                            {
                                                                EofNodeUPtr eof = std::make_unique<EofNode>();
                                                                eof -> set_location(yystack_[0].location);
                                                                TopLevelNodeUPtr& node(context.get_parse_result().get_top_level_node());
                                                                node -> set_location(yylhs.location);
                                                                node -> set_eof_node(eof);
                                                            }
#line 3304 "Parser.cxx"
    break;

  case 97:
#line 775 "Parser.yxx"
                                                            {
                                                                EofNodeUPtr eof = std::make_unique<EofNode>();
                                                                eof -> set_location(yystack_[0].location);
                                                                TopLevelNodeUPtr& node(context.get_parse_result().get_top_level_node());
                                                                node -> set_location(yylhs.location);
                                                                node -> set_eof_node(eof);
                                                            }
#line 3316 "Parser.cxx"
    break;


#line 3320 "Parser.cxx"

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


  const signed char Parser::yypact_ninf_ = -62;

  const signed char Parser::yytable_ninf_ = -67;

  const short
  Parser::yypact_[] =
  {
       2,   -62,   213,   -62,     3,     6,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   151,
     -62,   -62,   -62,    -9,   151,     0,   -62,   190,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,    -3,    -2,    -1,   -62,   -62,   -62,
     -62,    32,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,    39,   -62,    42,   -62,   -62,   -62,   -62,   -62,
     -62,    45,   -62,    31,   -62,    40,   -62,   -62,   -62,     1,
     -62,   -62,    45,   151,   151,    70,   -62,   151,   190,   -62,
     -62,   112,   -62,    46,    38,   -62,    41,    34,   -62,    49,
      43,    44,   -62,   -62,   -62,   151,   -62,   -62,   151,    70,
     -62,   151,   -62,   -62,   -62,   -62
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    96,     0,    94,     0,     0,    53,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    54,    55,     0,
      97,    95,     1,     0,     0,     0,    22,     0,    88,     2,
       3,     4,     5,     6,     7,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     0,     0,     0,    21,     9,    10,
      11,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    85,    92,    79,     0,    80,    84,    86,    82,    81,
      83,    90,    91,     0,     8,     0,    65,    61,    62,     0,
      60,    66,    89,    30,     0,    27,    23,     0,     0,    93,
      68,     0,    64,    31,     0,    25,     0,     0,    58,    28,
       0,     0,    67,    87,    63,     0,    32,    24,     0,     0,
      29,     0,    26,    57,    59,    56
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -62,    24,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -36,   -62,   -62,   -61,   -62,
     -42,   -62,   -62,   -62,   -62,   -38,   -62,   -62,   -62,   -62,
     -62,    59,    29,   -62,   -29,    63,   -62,   -62
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,   103,   108,   109,
      88,    89,    74,    75,    76,    77,    78,   110,    79,   104,
      80,   111,    81,    82,    90,     3,     4,     5
  };

  const signed char
  Parser::yytable_[] =
  {
      83,    91,     1,    30,    33,    85,    32,   101,    34,    93,
      94,    95,    35,    86,   102,    39,    40,    41,    42,    43,
      87,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    96,   -66,     2,     2,    97,    98,    99,
     100,   116,   115,   118,   117,   119,   120,    84,   124,   114,
     113,    29,    91,   121,   105,   106,    92,    31,   112,     0,
       0,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,     0,     0,   123,
       6,     0,   125,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    33,     0,     0,     0,
      34,     0,     0,     0,    35,     0,     0,     0,     0,     0,
       0,     0,    87,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    33,     0,     0,     0,    34,
       0,     0,     0,    35,     0,     0,     0,     0,     0,     0,
       0,     0,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    33,     0,     0,     0,    34,     0,
       0,     0,    35,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,     0,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,     6,     0,     0,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28
  };

  const signed char
  Parser::yycheck_[] =
  {
      29,    37,     0,     0,     4,    34,     0,     6,     8,    12,
      12,    12,    12,    13,    13,    24,    25,    26,    27,    28,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    11,     5,    43,    43,     5,     3,    18,
      10,    13,     6,    19,    13,     6,    13,    33,   119,   101,
      98,     2,    98,    19,    93,    94,    37,     4,    97,    -1,
      -1,    -1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,   118,
      20,    -1,   121,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,     4,    -1,    -1,    -1,
       8,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     4,    -1,    -1,    -1,     8,
      -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,     4,    -1,    -1,    -1,     8,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    20,    -1,    -1,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     0,    43,    83,    84,    85,    20,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    79,
       0,    83,     0,     4,     8,    12,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    70,    71,    72,    73,    74,    76,
      78,    80,    81,    82,    49,    82,    13,    20,    68,    69,
      82,    63,    80,    12,    12,    12,    11,     5,     3,    18,
      10,     6,    13,    65,    77,    82,    82,     4,    66,    67,
      75,    79,    82,    73,    68,     6,    13,    13,    19,     6,
      13,    19,    82,    82,    66,    82
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    48,    49,    49,    49,    49,    49,    50,    51,    52,
      52,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    63,    62,    64,    74,    65,    65,    75,    75,    76,
      77,    77,    78,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    66,    66,    67,    67,
      68,    68,    69,    69,    70,    70,    70,    71,    72,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    80,    80,    81,    81,
      82,    82,    82,    83,    84,    84,    85,    85
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     1,     3,     0,     1,     4,
       0,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     3,
       1,     1,     1,     3,     3,     2,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     2,
       1,     1,     1,     4,     1,     2,     1,     2
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
  "WEAKREF", "TUPLE", "LIST", "STRUCT", "ANY", "TYPEDECL", "IDENTIFIER",
  "QUOTED_IDENTIFIER", "LBRACKET", "LOWER_THAN_OR", "$accept",
  "ascalartype", "rawascalartype", "nascalartype", "scalartype",
  "environmenttype", "expressiontype", "languagetype", "symboltype",
  "externalptrtype", "bytecodetype", "pairlisttype", "s4type",
  "weakreftype", "unknowntype", "anytype", "vectortype", "typeseq",
  "namedtype", "namedtypeseq", "paramtype", "paramtypeseq", "params",
  "functiontype", "grouptype", "nonuniontype", "listtype",
  "structelements", "structtype", "tupleelements", "tupletype",
  "identifier", "uniontype", "nulltype", "type", "decltype", "decllist",
  "start", YY_NULLPTR
  };

#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   342,   342,   343,   344,   345,   346,   349,   352,   359,
     364,   369,   376,   379,   382,   385,   388,   391,   394,   397,
     400,   403,   406,   409,   417,   434,   438,   448,   451,   456,
     474,   477,   483,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   525,   532,   542,   546,
     556,   560,   563,   567,   576,   584,   592,   598,   607,   617,
     622,   627,   632,   637,   642,   647,   652,   657,   662,   667,
     672,   677,   682,   687,   692,   697,   705,   710,   720,   721,
     730,   735,   740,   747,   758,   762,   768,   775
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
      45,    46,    47
    };
    const int user_token_number_max_ = 302;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 9 "Parser.yxx"
} } // tastr::parser
#line 3883 "Parser.cxx"

#line 784 "Parser.yxx"


void tastr::parser::Parser::error(const location_type& location, const std::string& message) {
    context.get_parse_result().set_error(location, message);
}
