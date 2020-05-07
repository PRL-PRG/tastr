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
#line 285 "Parser.yxx"

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
      case 48: // ascalartype
        value.move< AScalarTypeNodePtr > (std::move (that.value));
        break;

      case 64: // anytype
        value.move< AnyTypeNodePtr > (std::move (that.value));
        break;

      case 59: // bytecodetype
        value.move< BytecodeTypeNodePtr > (std::move (that.value));
        break;

      case 53: // classtype
        value.move< ClassTypeNodePtr > (std::move (that.value));
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

      case 73: // grouptype
        value.move< GroupTypeNodePtr > (std::move (that.value));
        break;

      case 80: // identifier
        value.move< IdentifierNodePtr > (std::move (that.value));
        break;

      case 56: // languagetype
        value.move< LanguageTypeNodePtr > (std::move (that.value));
        break;

      case 75: // listtype
        value.move< ListTypeNodePtr > (std::move (that.value));
        break;

      case 50: // nascalartype
        value.move< NAScalarTypeNodePtr > (std::move (that.value));
        break;

      case 52: // classnameseq
      case 66: // typeseq
      case 68: // namedtypeseq
      case 70: // paramtypeseq
      case 71: // params
      case 76: // structelements
      case 78: // tupleelements
        value.move< NodePtr > (std::move (that.value));
        break;

      case 60: // pairlisttype
        value.move< PairlistTypeNodePtr > (std::move (that.value));
        break;

      case 49: // rawascalartype
        value.move< RawAScalarTypeNodePtr > (std::move (that.value));
        break;

      case 61: // s4type
        value.move< S4TypeNodePtr > (std::move (that.value));
        break;

      case 51: // scalartype
        value.move< ScalarTypeNodePtr > (std::move (that.value));
        break;

      case 77: // structtype
        value.move< StructTypeNodePtr > (std::move (that.value));
        break;

      case 57: // symboltype
        value.move< SymbolTypeNodePtr > (std::move (that.value));
        break;

      case 67: // namedtype
        value.move< TagTypePairNodePtr > (std::move (that.value));
        break;

      case 79: // tupletype
        value.move< TupleTypeNodePtr > (std::move (that.value));
        break;

      case 85: // decltype
        value.move< TypeDeclarationNodePtr > (std::move (that.value));
        break;

      case 69: // paramtype
      case 72: // functiontype
      case 74: // nonconnectivetype
      case 81: // uniontype
      case 82: // intersectiontype
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
      case 6: // "&"
      case 7: // ","
      case 8: // "(("
      case 9: // "("
      case 10: // "))"
      case 11: // ")"
      case 12: // "[]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "[["
      case 16: // "]]"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "???"
      case 23: // "null"
      case 24: // "class"
      case 25: // INTEGER
      case 26: // DOUBLE
      case 27: // COMPLEX
      case 28: // CHARACTER
      case 29: // LOGICAL
      case 30: // RAW
      case 31: // ENVIRONMENT
      case 32: // EXPRESSION
      case 33: // LANGUAGE
      case 34: // SYMBOL
      case 35: // EXTERNALPOINTER
      case 36: // BYTECODE
      case 37: // PAIRLIST
      case 38: // S4
      case 39: // WEAKREF
      case 40: // TUPLE
      case 41: // LIST
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
      case 48: // ascalartype
        value.copy< AScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 64: // anytype
        value.copy< AnyTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 59: // bytecodetype
        value.copy< BytecodeTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 53: // classtype
        value.copy< ClassTypeNodePtr > (YY_MOVE (that.value));
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

      case 73: // grouptype
        value.copy< GroupTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 80: // identifier
        value.copy< IdentifierNodePtr > (YY_MOVE (that.value));
        break;

      case 56: // languagetype
        value.copy< LanguageTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 75: // listtype
        value.copy< ListTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 50: // nascalartype
        value.copy< NAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 52: // classnameseq
      case 66: // typeseq
      case 68: // namedtypeseq
      case 70: // paramtypeseq
      case 71: // params
      case 76: // structelements
      case 78: // tupleelements
        value.copy< NodePtr > (YY_MOVE (that.value));
        break;

      case 60: // pairlisttype
        value.copy< PairlistTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 49: // rawascalartype
        value.copy< RawAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 61: // s4type
        value.copy< S4TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 51: // scalartype
        value.copy< ScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 77: // structtype
        value.copy< StructTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 57: // symboltype
        value.copy< SymbolTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 67: // namedtype
        value.copy< TagTypePairNodePtr > (YY_MOVE (that.value));
        break;

      case 79: // tupletype
        value.copy< TupleTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 85: // decltype
        value.copy< TypeDeclarationNodePtr > (YY_MOVE (that.value));
        break;

      case 69: // paramtype
      case 72: // functiontype
      case 74: // nonconnectivetype
      case 81: // uniontype
      case 82: // intersectiontype
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
      case 6: // "&"
      case 7: // ","
      case 8: // "(("
      case 9: // "("
      case 10: // "))"
      case 11: // ")"
      case 12: // "[]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "[["
      case 16: // "]]"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "???"
      case 23: // "null"
      case 24: // "class"
      case 25: // INTEGER
      case 26: // DOUBLE
      case 27: // COMPLEX
      case 28: // CHARACTER
      case 29: // LOGICAL
      case 30: // RAW
      case 31: // ENVIRONMENT
      case 32: // EXPRESSION
      case 33: // LANGUAGE
      case 34: // SYMBOL
      case 35: // EXTERNALPOINTER
      case 36: // BYTECODE
      case 37: // PAIRLIST
      case 38: // S4
      case 39: // WEAKREF
      case 40: // TUPLE
      case 41: // LIST
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
      case 48: // ascalartype
        value.move< AScalarTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 64: // anytype
        value.move< AnyTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 59: // bytecodetype
        value.move< BytecodeTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 53: // classtype
        value.move< ClassTypeNodePtr > (YY_MOVE (s.value));
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

      case 73: // grouptype
        value.move< GroupTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 80: // identifier
        value.move< IdentifierNodePtr > (YY_MOVE (s.value));
        break;

      case 56: // languagetype
        value.move< LanguageTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 75: // listtype
        value.move< ListTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 50: // nascalartype
        value.move< NAScalarTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 52: // classnameseq
      case 66: // typeseq
      case 68: // namedtypeseq
      case 70: // paramtypeseq
      case 71: // params
      case 76: // structelements
      case 78: // tupleelements
        value.move< NodePtr > (YY_MOVE (s.value));
        break;

      case 60: // pairlisttype
        value.move< PairlistTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 49: // rawascalartype
        value.move< RawAScalarTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 61: // s4type
        value.move< S4TypeNodePtr > (YY_MOVE (s.value));
        break;

      case 51: // scalartype
        value.move< ScalarTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 77: // structtype
        value.move< StructTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 57: // symboltype
        value.move< SymbolTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 67: // namedtype
        value.move< TagTypePairNodePtr > (YY_MOVE (s.value));
        break;

      case 79: // tupletype
        value.move< TupleTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 85: // decltype
        value.move< TypeDeclarationNodePtr > (YY_MOVE (s.value));
        break;

      case 69: // paramtype
      case 72: // functiontype
      case 74: // nonconnectivetype
      case 81: // uniontype
      case 82: // intersectiontype
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
      case 6: // "&"
      case 7: // ","
      case 8: // "(("
      case 9: // "("
      case 10: // "))"
      case 11: // ")"
      case 12: // "[]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "[["
      case 16: // "]]"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "???"
      case 23: // "null"
      case 24: // "class"
      case 25: // INTEGER
      case 26: // DOUBLE
      case 27: // COMPLEX
      case 28: // CHARACTER
      case 29: // LOGICAL
      case 30: // RAW
      case 31: // ENVIRONMENT
      case 32: // EXPRESSION
      case 33: // LANGUAGE
      case 34: // SYMBOL
      case 35: // EXTERNALPOINTER
      case 36: // BYTECODE
      case 37: // PAIRLIST
      case 38: // S4
      case 39: // WEAKREF
      case 40: // TUPLE
      case 41: // LIST
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
      case 48: // ascalartype
        value.YY_MOVE_OR_COPY< AScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 64: // anytype
        value.YY_MOVE_OR_COPY< AnyTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 59: // bytecodetype
        value.YY_MOVE_OR_COPY< BytecodeTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 53: // classtype
        value.YY_MOVE_OR_COPY< ClassTypeNodePtr > (YY_MOVE (that.value));
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

      case 73: // grouptype
        value.YY_MOVE_OR_COPY< GroupTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 80: // identifier
        value.YY_MOVE_OR_COPY< IdentifierNodePtr > (YY_MOVE (that.value));
        break;

      case 56: // languagetype
        value.YY_MOVE_OR_COPY< LanguageTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 75: // listtype
        value.YY_MOVE_OR_COPY< ListTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 50: // nascalartype
        value.YY_MOVE_OR_COPY< NAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 52: // classnameseq
      case 66: // typeseq
      case 68: // namedtypeseq
      case 70: // paramtypeseq
      case 71: // params
      case 76: // structelements
      case 78: // tupleelements
        value.YY_MOVE_OR_COPY< NodePtr > (YY_MOVE (that.value));
        break;

      case 60: // pairlisttype
        value.YY_MOVE_OR_COPY< PairlistTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 49: // rawascalartype
        value.YY_MOVE_OR_COPY< RawAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 61: // s4type
        value.YY_MOVE_OR_COPY< S4TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 51: // scalartype
        value.YY_MOVE_OR_COPY< ScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 77: // structtype
        value.YY_MOVE_OR_COPY< StructTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 57: // symboltype
        value.YY_MOVE_OR_COPY< SymbolTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 67: // namedtype
        value.YY_MOVE_OR_COPY< TagTypePairNodePtr > (YY_MOVE (that.value));
        break;

      case 79: // tupletype
        value.YY_MOVE_OR_COPY< TupleTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 85: // decltype
        value.YY_MOVE_OR_COPY< TypeDeclarationNodePtr > (YY_MOVE (that.value));
        break;

      case 69: // paramtype
      case 72: // functiontype
      case 74: // nonconnectivetype
      case 81: // uniontype
      case 82: // intersectiontype
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
      case 6: // "&"
      case 7: // ","
      case 8: // "(("
      case 9: // "("
      case 10: // "))"
      case 11: // ")"
      case 12: // "[]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "[["
      case 16: // "]]"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "???"
      case 23: // "null"
      case 24: // "class"
      case 25: // INTEGER
      case 26: // DOUBLE
      case 27: // COMPLEX
      case 28: // CHARACTER
      case 29: // LOGICAL
      case 30: // RAW
      case 31: // ENVIRONMENT
      case 32: // EXPRESSION
      case 33: // LANGUAGE
      case 34: // SYMBOL
      case 35: // EXTERNALPOINTER
      case 36: // BYTECODE
      case 37: // PAIRLIST
      case 38: // S4
      case 39: // WEAKREF
      case 40: // TUPLE
      case 41: // LIST
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
      case 48: // ascalartype
        value.move< AScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 64: // anytype
        value.move< AnyTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 59: // bytecodetype
        value.move< BytecodeTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 53: // classtype
        value.move< ClassTypeNodePtr > (YY_MOVE (that.value));
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

      case 73: // grouptype
        value.move< GroupTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 80: // identifier
        value.move< IdentifierNodePtr > (YY_MOVE (that.value));
        break;

      case 56: // languagetype
        value.move< LanguageTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 75: // listtype
        value.move< ListTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 50: // nascalartype
        value.move< NAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 52: // classnameseq
      case 66: // typeseq
      case 68: // namedtypeseq
      case 70: // paramtypeseq
      case 71: // params
      case 76: // structelements
      case 78: // tupleelements
        value.move< NodePtr > (YY_MOVE (that.value));
        break;

      case 60: // pairlisttype
        value.move< PairlistTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 49: // rawascalartype
        value.move< RawAScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 61: // s4type
        value.move< S4TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 51: // scalartype
        value.move< ScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 77: // structtype
        value.move< StructTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 57: // symboltype
        value.move< SymbolTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 67: // namedtype
        value.move< TagTypePairNodePtr > (YY_MOVE (that.value));
        break;

      case 79: // tupletype
        value.move< TupleTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 85: // decltype
        value.move< TypeDeclarationNodePtr > (YY_MOVE (that.value));
        break;

      case 69: // paramtype
      case 72: // functiontype
      case 74: // nonconnectivetype
      case 81: // uniontype
      case 82: // intersectiontype
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
      case 6: // "&"
      case 7: // ","
      case 8: // "(("
      case 9: // "("
      case 10: // "))"
      case 11: // ")"
      case 12: // "[]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "[["
      case 16: // "]]"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "???"
      case 23: // "null"
      case 24: // "class"
      case 25: // INTEGER
      case 26: // DOUBLE
      case 27: // COMPLEX
      case 28: // CHARACTER
      case 29: // LOGICAL
      case 30: // RAW
      case 31: // ENVIRONMENT
      case 32: // EXPRESSION
      case 33: // LANGUAGE
      case 34: // SYMBOL
      case 35: // EXTERNALPOINTER
      case 36: // BYTECODE
      case 37: // PAIRLIST
      case 38: // S4
      case 39: // WEAKREF
      case 40: // TUPLE
      case 41: // LIST
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
      case 48: // ascalartype
        value.copy< AScalarTypeNodePtr > (that.value);
        break;

      case 64: // anytype
        value.copy< AnyTypeNodePtr > (that.value);
        break;

      case 59: // bytecodetype
        value.copy< BytecodeTypeNodePtr > (that.value);
        break;

      case 53: // classtype
        value.copy< ClassTypeNodePtr > (that.value);
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

      case 73: // grouptype
        value.copy< GroupTypeNodePtr > (that.value);
        break;

      case 80: // identifier
        value.copy< IdentifierNodePtr > (that.value);
        break;

      case 56: // languagetype
        value.copy< LanguageTypeNodePtr > (that.value);
        break;

      case 75: // listtype
        value.copy< ListTypeNodePtr > (that.value);
        break;

      case 50: // nascalartype
        value.copy< NAScalarTypeNodePtr > (that.value);
        break;

      case 52: // classnameseq
      case 66: // typeseq
      case 68: // namedtypeseq
      case 70: // paramtypeseq
      case 71: // params
      case 76: // structelements
      case 78: // tupleelements
        value.copy< NodePtr > (that.value);
        break;

      case 60: // pairlisttype
        value.copy< PairlistTypeNodePtr > (that.value);
        break;

      case 49: // rawascalartype
        value.copy< RawAScalarTypeNodePtr > (that.value);
        break;

      case 61: // s4type
        value.copy< S4TypeNodePtr > (that.value);
        break;

      case 51: // scalartype
        value.copy< ScalarTypeNodePtr > (that.value);
        break;

      case 77: // structtype
        value.copy< StructTypeNodePtr > (that.value);
        break;

      case 57: // symboltype
        value.copy< SymbolTypeNodePtr > (that.value);
        break;

      case 67: // namedtype
        value.copy< TagTypePairNodePtr > (that.value);
        break;

      case 79: // tupletype
        value.copy< TupleTypeNodePtr > (that.value);
        break;

      case 85: // decltype
        value.copy< TypeDeclarationNodePtr > (that.value);
        break;

      case 69: // paramtype
      case 72: // functiontype
      case 74: // nonconnectivetype
      case 81: // uniontype
      case 82: // intersectiontype
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
      case 6: // "&"
      case 7: // ","
      case 8: // "(("
      case 9: // "("
      case 10: // "))"
      case 11: // ")"
      case 12: // "[]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "[["
      case 16: // "]]"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "???"
      case 23: // "null"
      case 24: // "class"
      case 25: // INTEGER
      case 26: // DOUBLE
      case 27: // COMPLEX
      case 28: // CHARACTER
      case 29: // LOGICAL
      case 30: // RAW
      case 31: // ENVIRONMENT
      case 32: // EXPRESSION
      case 33: // LANGUAGE
      case 34: // SYMBOL
      case 35: // EXTERNALPOINTER
      case 36: // BYTECODE
      case 37: // PAIRLIST
      case 38: // S4
      case 39: // WEAKREF
      case 40: // TUPLE
      case 41: // LIST
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
      case 48: // ascalartype
        value.move< AScalarTypeNodePtr > (that.value);
        break;

      case 64: // anytype
        value.move< AnyTypeNodePtr > (that.value);
        break;

      case 59: // bytecodetype
        value.move< BytecodeTypeNodePtr > (that.value);
        break;

      case 53: // classtype
        value.move< ClassTypeNodePtr > (that.value);
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

      case 73: // grouptype
        value.move< GroupTypeNodePtr > (that.value);
        break;

      case 80: // identifier
        value.move< IdentifierNodePtr > (that.value);
        break;

      case 56: // languagetype
        value.move< LanguageTypeNodePtr > (that.value);
        break;

      case 75: // listtype
        value.move< ListTypeNodePtr > (that.value);
        break;

      case 50: // nascalartype
        value.move< NAScalarTypeNodePtr > (that.value);
        break;

      case 52: // classnameseq
      case 66: // typeseq
      case 68: // namedtypeseq
      case 70: // paramtypeseq
      case 71: // params
      case 76: // structelements
      case 78: // tupleelements
        value.move< NodePtr > (that.value);
        break;

      case 60: // pairlisttype
        value.move< PairlistTypeNodePtr > (that.value);
        break;

      case 49: // rawascalartype
        value.move< RawAScalarTypeNodePtr > (that.value);
        break;

      case 61: // s4type
        value.move< S4TypeNodePtr > (that.value);
        break;

      case 51: // scalartype
        value.move< ScalarTypeNodePtr > (that.value);
        break;

      case 77: // structtype
        value.move< StructTypeNodePtr > (that.value);
        break;

      case 57: // symboltype
        value.move< SymbolTypeNodePtr > (that.value);
        break;

      case 67: // namedtype
        value.move< TagTypePairNodePtr > (that.value);
        break;

      case 79: // tupletype
        value.move< TupleTypeNodePtr > (that.value);
        break;

      case 85: // decltype
        value.move< TypeDeclarationNodePtr > (that.value);
        break;

      case 69: // paramtype
      case 72: // functiontype
      case 74: // nonconnectivetype
      case 81: // uniontype
      case 82: // intersectiontype
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
      case 6: // "&"
      case 7: // ","
      case 8: // "(("
      case 9: // "("
      case 10: // "))"
      case 11: // ")"
      case 12: // "[]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "[["
      case 16: // "]]"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "???"
      case 23: // "null"
      case 24: // "class"
      case 25: // INTEGER
      case 26: // DOUBLE
      case 27: // COMPLEX
      case 28: // CHARACTER
      case 29: // LOGICAL
      case 30: // RAW
      case 31: // ENVIRONMENT
      case 32: // EXPRESSION
      case 33: // LANGUAGE
      case 34: // SYMBOL
      case 35: // EXTERNALPOINTER
      case 36: // BYTECODE
      case 37: // PAIRLIST
      case 38: // S4
      case 39: // WEAKREF
      case 40: // TUPLE
      case 41: // LIST
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
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1629 "Parser.cxx"
        break;

      case 4: // "^"
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1635 "Parser.cxx"
        break;

      case 5: // "=>"
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1641 "Parser.cxx"
        break;

      case 6: // "&"
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1647 "Parser.cxx"
        break;

      case 7: // ","
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1653 "Parser.cxx"
        break;

      case 8: // "(("
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1659 "Parser.cxx"
        break;

      case 9: // "("
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1665 "Parser.cxx"
        break;

      case 10: // "))"
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1671 "Parser.cxx"
        break;

      case 11: // ")"
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1677 "Parser.cxx"
        break;

      case 12: // "[]"
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1683 "Parser.cxx"
        break;

      case 13: // "<"
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1689 "Parser.cxx"
        break;

      case 14: // ">"
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1695 "Parser.cxx"
        break;

      case 15: // "[["
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1701 "Parser.cxx"
        break;

      case 16: // "]]"
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1707 "Parser.cxx"
        break;

      case 17: // "{{"
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1713 "Parser.cxx"
        break;

      case 18: // "}}"
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1719 "Parser.cxx"
        break;

      case 19: // ";"
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1725 "Parser.cxx"
        break;

      case 20: // ":"
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1731 "Parser.cxx"
        break;

      case 21: // "..."
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1737 "Parser.cxx"
        break;

      case 22: // "???"
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1743 "Parser.cxx"
        break;

      case 23: // "null"
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1749 "Parser.cxx"
        break;

      case 24: // "class"
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1755 "Parser.cxx"
        break;

      case 25: // INTEGER
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1761 "Parser.cxx"
        break;

      case 26: // DOUBLE
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1767 "Parser.cxx"
        break;

      case 27: // COMPLEX
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1773 "Parser.cxx"
        break;

      case 28: // CHARACTER
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1779 "Parser.cxx"
        break;

      case 29: // LOGICAL
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1785 "Parser.cxx"
        break;

      case 30: // RAW
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1791 "Parser.cxx"
        break;

      case 31: // ENVIRONMENT
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1797 "Parser.cxx"
        break;

      case 32: // EXPRESSION
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1803 "Parser.cxx"
        break;

      case 33: // LANGUAGE
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1809 "Parser.cxx"
        break;

      case 34: // SYMBOL
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1815 "Parser.cxx"
        break;

      case 35: // EXTERNALPOINTER
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1821 "Parser.cxx"
        break;

      case 36: // BYTECODE
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1827 "Parser.cxx"
        break;

      case 37: // PAIRLIST
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1833 "Parser.cxx"
        break;

      case 38: // S4
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1839 "Parser.cxx"
        break;

      case 39: // WEAKREF
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1845 "Parser.cxx"
        break;

      case 40: // TUPLE
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1851 "Parser.cxx"
        break;

      case 41: // LIST
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1857 "Parser.cxx"
        break;

      case 42: // STRUCT
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1863 "Parser.cxx"
        break;

      case 43: // ANY
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1869 "Parser.cxx"
        break;

      case 44: // TYPEDECL
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1875 "Parser.cxx"
        break;

      case 45: // IDENTIFIER
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1881 "Parser.cxx"
        break;

      case 46: // QUOTED_IDENTIFIER
#line 140 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1887 "Parser.cxx"
        break;

      case 48: // ascalartype
#line 115 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < AScalarTypeNodePtr > ()); }
#line 1893 "Parser.cxx"
        break;

      case 49: // rawascalartype
#line 114 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < RawAScalarTypeNodePtr > ()); }
#line 1899 "Parser.cxx"
        break;

      case 50: // nascalartype
#line 116 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NAScalarTypeNodePtr > ()); }
#line 1905 "Parser.cxx"
        break;

      case 51: // scalartype
#line 117 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ScalarTypeNodePtr > ()); }
#line 1911 "Parser.cxx"
        break;

      case 52: // classnameseq
#line 131 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 1917 "Parser.cxx"
        break;

      case 53: // classtype
#line 118 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ClassTypeNodePtr > ()); }
#line 1923 "Parser.cxx"
        break;

      case 54: // environmenttype
#line 119 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < EnvironmentTypeNodePtr > ()); }
#line 1929 "Parser.cxx"
        break;

      case 55: // expressiontype
#line 120 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ExpressionTypeNodePtr > ()); }
#line 1935 "Parser.cxx"
        break;

      case 56: // languagetype
#line 121 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < LanguageTypeNodePtr > ()); }
#line 1941 "Parser.cxx"
        break;

      case 57: // symboltype
#line 122 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < SymbolTypeNodePtr > ()); }
#line 1947 "Parser.cxx"
        break;

      case 58: // externalptrtype
#line 123 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ExternalPointerTypeNodePtr > ()); }
#line 1953 "Parser.cxx"
        break;

      case 59: // bytecodetype
#line 124 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < BytecodeTypeNodePtr > ()); }
#line 1959 "Parser.cxx"
        break;

      case 60: // pairlisttype
#line 125 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < PairlistTypeNodePtr > ()); }
#line 1965 "Parser.cxx"
        break;

      case 61: // s4type
#line 126 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < S4TypeNodePtr > ()); }
#line 1971 "Parser.cxx"
        break;

      case 62: // weakreftype
#line 127 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < WeakReferenceTypeNodePtr > ()); }
#line 1977 "Parser.cxx"
        break;

      case 63: // unknowntype
#line 129 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < UnknownTypeNodePtr > ()); }
#line 1983 "Parser.cxx"
        break;

      case 64: // anytype
#line 128 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < AnyTypeNodePtr > ()); }
#line 1989 "Parser.cxx"
        break;

      case 65: // vectortype
#line 130 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < VectorTypeNodePtr > ()); }
#line 1995 "Parser.cxx"
        break;

      case 66: // typeseq
#line 131 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 2001 "Parser.cxx"
        break;

      case 67: // namedtype
#line 132 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TagTypePairNodePtr > ()); }
#line 2007 "Parser.cxx"
        break;

      case 68: // namedtypeseq
#line 131 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 2013 "Parser.cxx"
        break;

      case 69: // paramtype
#line 138 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2019 "Parser.cxx"
        break;

      case 70: // paramtypeseq
#line 131 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 2025 "Parser.cxx"
        break;

      case 71: // params
#line 131 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 2031 "Parser.cxx"
        break;

      case 72: // functiontype
#line 138 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2037 "Parser.cxx"
        break;

      case 73: // grouptype
#line 133 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < GroupTypeNodePtr > ()); }
#line 2043 "Parser.cxx"
        break;

      case 74: // nonconnectivetype
#line 138 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2049 "Parser.cxx"
        break;

      case 75: // listtype
#line 134 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ListTypeNodePtr > ()); }
#line 2055 "Parser.cxx"
        break;

      case 76: // structelements
#line 131 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 2061 "Parser.cxx"
        break;

      case 77: // structtype
#line 135 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < StructTypeNodePtr > ()); }
#line 2067 "Parser.cxx"
        break;

      case 78: // tupleelements
#line 131 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NodePtr > ()); }
#line 2073 "Parser.cxx"
        break;

      case 79: // tupletype
#line 136 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TupleTypeNodePtr > ()); }
#line 2079 "Parser.cxx"
        break;

      case 80: // identifier
#line 137 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < IdentifierNodePtr > ()); }
#line 2085 "Parser.cxx"
        break;

      case 81: // uniontype
#line 138 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2091 "Parser.cxx"
        break;

      case 82: // intersectiontype
#line 138 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2097 "Parser.cxx"
        break;

      case 83: // nulltype
#line 138 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2103 "Parser.cxx"
        break;

      case 84: // type
#line 138 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 2109 "Parser.cxx"
        break;

      case 85: // decltype
#line 139 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeDeclarationNodePtr > ()); }
#line 2115 "Parser.cxx"
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

#line 2245 "Parser.cxx"


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
      case 48: // ascalartype
        yylhs.value.emplace< AScalarTypeNodePtr > ();
        break;

      case 64: // anytype
        yylhs.value.emplace< AnyTypeNodePtr > ();
        break;

      case 59: // bytecodetype
        yylhs.value.emplace< BytecodeTypeNodePtr > ();
        break;

      case 53: // classtype
        yylhs.value.emplace< ClassTypeNodePtr > ();
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

      case 73: // grouptype
        yylhs.value.emplace< GroupTypeNodePtr > ();
        break;

      case 80: // identifier
        yylhs.value.emplace< IdentifierNodePtr > ();
        break;

      case 56: // languagetype
        yylhs.value.emplace< LanguageTypeNodePtr > ();
        break;

      case 75: // listtype
        yylhs.value.emplace< ListTypeNodePtr > ();
        break;

      case 50: // nascalartype
        yylhs.value.emplace< NAScalarTypeNodePtr > ();
        break;

      case 52: // classnameseq
      case 66: // typeseq
      case 68: // namedtypeseq
      case 70: // paramtypeseq
      case 71: // params
      case 76: // structelements
      case 78: // tupleelements
        yylhs.value.emplace< NodePtr > ();
        break;

      case 60: // pairlisttype
        yylhs.value.emplace< PairlistTypeNodePtr > ();
        break;

      case 49: // rawascalartype
        yylhs.value.emplace< RawAScalarTypeNodePtr > ();
        break;

      case 61: // s4type
        yylhs.value.emplace< S4TypeNodePtr > ();
        break;

      case 51: // scalartype
        yylhs.value.emplace< ScalarTypeNodePtr > ();
        break;

      case 77: // structtype
        yylhs.value.emplace< StructTypeNodePtr > ();
        break;

      case 57: // symboltype
        yylhs.value.emplace< SymbolTypeNodePtr > ();
        break;

      case 67: // namedtype
        yylhs.value.emplace< TagTypePairNodePtr > ();
        break;

      case 79: // tupletype
        yylhs.value.emplace< TupleTypeNodePtr > ();
        break;

      case 85: // decltype
        yylhs.value.emplace< TypeDeclarationNodePtr > ();
        break;

      case 69: // paramtype
      case 72: // functiontype
      case 74: // nonconnectivetype
      case 81: // uniontype
      case 82: // intersectiontype
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
      case 6: // "&"
      case 7: // ","
      case 8: // "(("
      case 9: // "("
      case 10: // "))"
      case 11: // ")"
      case 12: // "[]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "[["
      case 16: // "]]"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "???"
      case 23: // "null"
      case 24: // "class"
      case 25: // INTEGER
      case 26: // DOUBLE
      case 27: // COMPLEX
      case 28: // CHARACTER
      case 29: // LOGICAL
      case 30: // RAW
      case 31: // ENVIRONMENT
      case 32: // EXPRESSION
      case 33: // LANGUAGE
      case 34: // SYMBOL
      case 35: // EXTERNALPOINTER
      case 36: // BYTECODE
      case 37: // PAIRLIST
      case 38: // S4
      case 39: // WEAKREF
      case 40: // TUPLE
      case 41: // LIST
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
#line 348 "Parser.yxx"
                                                            {   yylhs.value.as < AScalarTypeNodePtr > () = create_node_with_keyword<IntegerAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2534 "Parser.cxx"
    break;

  case 3:
#line 349 "Parser.yxx"
                                                            {   yylhs.value.as < AScalarTypeNodePtr > () = create_node_with_keyword<DoubleAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2540 "Parser.cxx"
    break;

  case 4:
#line 350 "Parser.yxx"
                                                            {   yylhs.value.as < AScalarTypeNodePtr > () = create_node_with_keyword<ComplexAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2546 "Parser.cxx"
    break;

  case 5:
#line 351 "Parser.yxx"
                                                            {   yylhs.value.as < AScalarTypeNodePtr > () = create_node_with_keyword<CharacterAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2552 "Parser.cxx"
    break;

  case 6:
#line 352 "Parser.yxx"
                                                            {   yylhs.value.as < AScalarTypeNodePtr > () = create_node_with_keyword<LogicalAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2558 "Parser.cxx"
    break;

  case 7:
#line 355 "Parser.yxx"
                                                            {   yylhs.value.as < RawAScalarTypeNodePtr > () = create_node_with_keyword<RawAScalarTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2564 "Parser.cxx"
    break;

  case 8:
#line 358 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NAScalarTypeNodePtr > () = new NAScalarTypeNode(std::move(wrap(std::move(op))),
                                                                                          std::move(wrap(std::move(yystack_[0].value.as < AScalarTypeNodePtr > ()))));
                                                                yylhs.value.as < NAScalarTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2575 "Parser.cxx"
    break;

  case 9:
#line 365 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = yystack_[0].value.as < AScalarTypeNodePtr > ();
                                                                yystack_[0].value.as < AScalarTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2585 "Parser.cxx"
    break;

  case 10:
#line 370 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = yystack_[0].value.as < RawAScalarTypeNodePtr > ();
                                                                yystack_[0].value.as < RawAScalarTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2595 "Parser.cxx"
    break;

  case 11:
#line 375 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = yystack_[0].value.as < NAScalarTypeNodePtr > ();
                                                                yystack_[0].value.as < NAScalarTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2605 "Parser.cxx"
    break;

  case 12:
#line 383 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < IdentifierNodePtr > ();
                                                                yystack_[0].value.as < IdentifierNodePtr > () = nullptr;
                                                            }
#line 2614 "Parser.cxx"
    break;

  case 13:
#line 387 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr op = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NodePtr > () = new CommaSeparatorNode(std::move(wrap(std::move(op))),
                                                                                            std::move(wrap(std::move(yystack_[2].value.as < NodePtr > ()))),
                                                                                            std::move(wrap(std::move(yystack_[0].value.as < IdentifierNodePtr > ()))));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2626 "Parser.cxx"
    break;

  case 14:
#line 396 "Parser.yxx"
                                                            {
                                                                KeywordNodePtr keyword = create_keyword(yystack_[3].value.as < std::string > (), yystack_[3].location, context);

                                                                OperatorNodePtr left = create_operator(yystack_[2].value.as < std::string > (), yystack_[2].location, context);
                                                                OperatorNodePtr right = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);

                                                                ParameterNode* parameters = new ParameterNode(std::move(wrap(std::move(left))),
                                                                                                              std::move(wrap(std::move(right))),
                                                                                                              std::move(wrap(std::move(yystack_[1].value.as < NodePtr > ()))));
                                                                yylhs.value.as < ClassTypeNodePtr > () = new ClassTypeNode(std::move(wrap(std::move(keyword))),
                                                                                       std::move(wrap(std::move(parameters))));
                                                                yylhs.value.as < ClassTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2644 "Parser.cxx"
    break;

  case 15:
#line 411 "Parser.yxx"
                                                            {   yylhs.value.as < EnvironmentTypeNodePtr > () = create_node_with_keyword<EnvironmentTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2650 "Parser.cxx"
    break;

  case 16:
#line 414 "Parser.yxx"
                                                            {   yylhs.value.as < ExpressionTypeNodePtr > () = create_node_with_keyword<ExpressionTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context);  }
#line 2656 "Parser.cxx"
    break;

  case 17:
#line 417 "Parser.yxx"
                                                            {   yylhs.value.as < LanguageTypeNodePtr > () = create_node_with_keyword<LanguageTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context);    }
#line 2662 "Parser.cxx"
    break;

  case 18:
#line 420 "Parser.yxx"
                                                            {   yylhs.value.as < SymbolTypeNodePtr > () = create_node_with_keyword<SymbolTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context);      }
#line 2668 "Parser.cxx"
    break;

  case 19:
#line 423 "Parser.yxx"
                                                            {   yylhs.value.as < ExternalPointerTypeNodePtr > () = create_node_with_keyword<ExternalPointerTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2674 "Parser.cxx"
    break;

  case 20:
#line 426 "Parser.yxx"
                                                            {   yylhs.value.as < BytecodeTypeNodePtr > () = create_node_with_keyword<BytecodeTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2680 "Parser.cxx"
    break;

  case 21:
#line 429 "Parser.yxx"
                                                            {   yylhs.value.as < PairlistTypeNodePtr > () = create_node_with_keyword<PairlistTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2686 "Parser.cxx"
    break;

  case 22:
#line 432 "Parser.yxx"
                                                            {   yylhs.value.as < S4TypeNodePtr > () = create_node_with_keyword<S4TypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2692 "Parser.cxx"
    break;

  case 23:
#line 435 "Parser.yxx"
                                                            {   yylhs.value.as < WeakReferenceTypeNodePtr > () = create_node_with_keyword<WeakReferenceTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2698 "Parser.cxx"
    break;

  case 24:
#line 438 "Parser.yxx"
                                                            {   yylhs.value.as < AnyTypeNodePtr > () = create_node_with_keyword<AnyTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2704 "Parser.cxx"
    break;

  case 25:
#line 441 "Parser.yxx"
                                                            {   yylhs.value.as < UnknownTypeNodePtr > () = create_node_with_keyword<UnknownTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2710 "Parser.cxx"
    break;

  case 26:
#line 444 "Parser.yxx"
                                                            {   yylhs.value.as < TypeNodePtr > () = create_node_with_keyword<NullTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 2716 "Parser.cxx"
    break;

  case 27:
#line 447 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);
                                                                yylhs.value.as < VectorTypeNodePtr > () = new VectorTypeNode(std::move(wrap(std::move(op))),
                                                                                        std::move(wrap(std::move(yystack_[1].value.as < ScalarTypeNodePtr > ()))));
                                                                yylhs.value.as < VectorTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2727 "Parser.cxx"
    break;

  case 28:
#line 455 "Parser.yxx"
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
#line 2747 "Parser.cxx"
    break;

  case 29:
#line 472 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                            }
#line 2756 "Parser.cxx"
    break;

  case 30:
#line 476 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr op = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NodePtr > () = new CommaSeparatorNode(std::move(wrap(std::move(op))),
                                                                                            std::move(wrap(std::move(yystack_[2].value.as < NodePtr > ()))),
                                                                                            std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2768 "Parser.cxx"
    break;

  case 31:
#line 486 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = new EmptyNode();
                                                            }
#line 2776 "Parser.cxx"
    break;

  case 32:
#line 489 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < NodePtr > ();
                                                                yystack_[0].value.as < NodePtr > () = nullptr;
                                                            }
#line 2785 "Parser.cxx"
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

                                                                yylhs.value.as < StructTypeNodePtr > () = new StructTypeNode(std::move(wrap(std::move(keyword))),
                                                                                        std::move(wrap(std::move(parameter))));

                                                                yylhs.value.as < StructTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2805 "Parser.cxx"
    break;

  case 34:
#line 512 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = new EmptyNode();
                                                            }
#line 2813 "Parser.cxx"
    break;

  case 35:
#line 515 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < NodePtr > ();
                                                                yystack_[0].value.as < NodePtr > () = nullptr;
                                                            }
#line 2822 "Parser.cxx"
    break;

  case 36:
#line 521 "Parser.yxx"
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
#line 2842 "Parser.cxx"
    break;

  case 37:
#line 538 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2848 "Parser.cxx"
    break;

  case 38:
#line 539 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2854 "Parser.cxx"
    break;

  case 39:
#line 540 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2860 "Parser.cxx"
    break;

  case 40:
#line 541 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2866 "Parser.cxx"
    break;

  case 41:
#line 542 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2872 "Parser.cxx"
    break;

  case 42:
#line 543 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2878 "Parser.cxx"
    break;

  case 43:
#line 544 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2884 "Parser.cxx"
    break;

  case 44:
#line 545 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2890 "Parser.cxx"
    break;

  case 45:
#line 546 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2896 "Parser.cxx"
    break;

  case 46:
#line 547 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2902 "Parser.cxx"
    break;

  case 47:
#line 548 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2908 "Parser.cxx"
    break;

  case 48:
#line 549 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2914 "Parser.cxx"
    break;

  case 49:
#line 550 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2920 "Parser.cxx"
    break;

  case 50:
#line 551 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2926 "Parser.cxx"
    break;

  case 51:
#line 552 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2932 "Parser.cxx"
    break;

  case 52:
#line 553 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2938 "Parser.cxx"
    break;

  case 53:
#line 554 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2944 "Parser.cxx"
    break;

  case 54:
#line 555 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2950 "Parser.cxx"
    break;

  case 55:
#line 556 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2956 "Parser.cxx"
    break;

  case 56:
#line 557 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2962 "Parser.cxx"
    break;

  case 57:
#line 558 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2968 "Parser.cxx"
    break;

  case 58:
#line 559 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2974 "Parser.cxx"
    break;

  case 59:
#line 560 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), false, false, yystack_[0].location, context); }
#line 2980 "Parser.cxx"
    break;

  case 60:
#line 561 "Parser.yxx"
                                                            { yylhs.value.as < IdentifierNodePtr > () = create_identifier(yystack_[0].value.as < std::string > (), true, false, yystack_[0].location, context);  }
#line 2986 "Parser.cxx"
    break;

  case 61:
#line 564 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr separator = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < TagTypePairNodePtr > () = new TagTypePairNode(std::move(wrap(std::move(yystack_[2].value.as < IdentifierNodePtr > ()))),
                                                                                         std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))),
                                                                                         std::move(wrap(std::move(separator))));
                                                                yylhs.value.as < TagTypePairNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2998 "Parser.cxx"
    break;

  case 62:
#line 571 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr separator = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                IdentifierNodePtr id = create_identifier(yystack_[2].value.as < std::string > (), false, true, yystack_[2].location, context);
                                                                yylhs.value.as < TagTypePairNodePtr > () = new TagTypePairNode(std::move(wrap(std::move(id))),
                                                                                         std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))),
                                                                                         std::move(wrap(std::move(separator))));
                                                                yylhs.value.as < TagTypePairNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3011 "Parser.cxx"
    break;

  case 63:
#line 581 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < TagTypePairNodePtr > ();
                                                                yystack_[0].value.as < TagTypePairNodePtr > () = nullptr;
                                                            }
#line 3020 "Parser.cxx"
    break;

  case 64:
#line 585 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr op = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NodePtr > () = new CommaSeparatorNode(std::move(wrap(std::move(op))),
                                                                                            std::move(wrap(std::move(yystack_[2].value.as < NodePtr > ()))),
                                                                                            std::move(wrap(std::move(yystack_[0].value.as < TagTypePairNodePtr > ()))));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3032 "Parser.cxx"
    break;

  case 65:
#line 595 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                            }
#line 3041 "Parser.cxx"
    break;

  case 66:
#line 599 "Parser.yxx"
                                                            {   yylhs.value.as < TypeNodePtr > () = create_node_with_keyword<VarargTypeNode>(yystack_[0].value.as < std::string > (), yystack_[0].location, yylhs.location, context); }
#line 3047 "Parser.cxx"
    break;

  case 67:
#line 602 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                            }
#line 3056 "Parser.cxx"
    break;

  case 68:
#line 606 "Parser.yxx"
                                                            {
                                                                SeparatorNodePtr op = create_separator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NodePtr > () = new CommaSeparatorNode(std::move(wrap(std::move(op))),
                                                                                            std::move(wrap(std::move(yystack_[2].value.as < NodePtr > ()))),
                                                                                            std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3068 "Parser.cxx"
    break;

  case 69:
#line 615 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr right = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);
                                                                OperatorNodePtr left = create_operator(yystack_[2].value.as < std::string > (), yystack_[2].location, context);
                                                                yylhs.value.as < NodePtr > () = new ParameterNode(std::move(wrap(std::move(left))),
                                                                                       std::move(wrap(std::move(right))),
                                                                                       std::move(wrap(std::move(yystack_[1].value.as < NodePtr > ()))));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3081 "Parser.cxx"
    break;

  case 70:
#line 623 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr right = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);
                                                                OperatorNodePtr left = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < NodePtr > () = new ParameterNode(std::move(wrap(std::move(left))),
                                                                                       std::move(wrap(std::move(right))),
                                                                                       std::move(wrap(new EmptyNode())));
                                                                yylhs.value.as < NodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3094 "Parser.cxx"
    break;

  case 71:
#line 631 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NodePtr > () = yystack_[0].value.as < AnyTypeNodePtr > ();
                                                                yystack_[0].value.as < AnyTypeNodePtr > () = nullptr;
                                                            }
#line 3103 "Parser.cxx"
    break;

  case 72:
#line 638 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr right = create_operator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);
                                                                OperatorNodePtr left = create_operator(yystack_[2].value.as < std::string > (), yystack_[2].location, context);
                                                                yylhs.value.as < GroupTypeNodePtr > () = new GroupTypeNode(std::move(wrap(std::move(left))),
                                                                                       std::move(wrap(std::move(right))),
                                                                                       std::move(wrap(std::move(yystack_[1].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < GroupTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3116 "Parser.cxx"
    break;

  case 73:
#line 649 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ScalarTypeNodePtr > ();
                                                                yystack_[0].value.as < ScalarTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3126 "Parser.cxx"
    break;

  case 74:
#line 654 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ClassTypeNodePtr > ();
                                                                yystack_[0].value.as < ClassTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3136 "Parser.cxx"
    break;

  case 75:
#line 659 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < EnvironmentTypeNodePtr > ();
                                                                yystack_[0].value.as < EnvironmentTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3146 "Parser.cxx"
    break;

  case 76:
#line 664 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ExpressionTypeNodePtr > ();
                                                                yystack_[0].value.as < ExpressionTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3156 "Parser.cxx"
    break;

  case 77:
#line 669 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < LanguageTypeNodePtr > ();
                                                                yystack_[0].value.as < LanguageTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3166 "Parser.cxx"
    break;

  case 78:
#line 674 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < SymbolTypeNodePtr > ();
                                                                yystack_[0].value.as < SymbolTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3176 "Parser.cxx"
    break;

  case 79:
#line 679 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ExternalPointerTypeNodePtr > ();
                                                                yystack_[0].value.as < ExternalPointerTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3186 "Parser.cxx"
    break;

  case 80:
#line 684 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < BytecodeTypeNodePtr > ();
                                                                yystack_[0].value.as < BytecodeTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3196 "Parser.cxx"
    break;

  case 81:
#line 689 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < PairlistTypeNodePtr > ();
                                                                yystack_[0].value.as < PairlistTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3206 "Parser.cxx"
    break;

  case 82:
#line 694 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < S4TypeNodePtr > ();
                                                                yystack_[0].value.as < S4TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3216 "Parser.cxx"
    break;

  case 83:
#line 699 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < WeakReferenceTypeNodePtr > ();
                                                                yystack_[0].value.as < WeakReferenceTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3226 "Parser.cxx"
    break;

  case 84:
#line 704 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < VectorTypeNodePtr > ();
                                                                yystack_[0].value.as < VectorTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3236 "Parser.cxx"
    break;

  case 85:
#line 709 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < StructTypeNodePtr > ();
                                                                yystack_[0].value.as < StructTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3246 "Parser.cxx"
    break;

  case 86:
#line 714 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ListTypeNodePtr > ();
                                                                yystack_[0].value.as < ListTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3256 "Parser.cxx"
    break;

  case 87:
#line 719 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TupleTypeNodePtr > ();
                                                                yystack_[0].value.as < TupleTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3266 "Parser.cxx"
    break;

  case 88:
#line 724 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < GroupTypeNodePtr > ();
                                                                yystack_[0].value.as < GroupTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3276 "Parser.cxx"
    break;

  case 89:
#line 729 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < UnknownTypeNodePtr > ();
                                                                yystack_[0].value.as < UnknownTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3286 "Parser.cxx"
    break;

  case 90:
#line 734 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3296 "Parser.cxx"
    break;

  case 91:
#line 742 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3306 "Parser.cxx"
    break;

  case 92:
#line 748 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < TypeNodePtr > () = new IntersectionTypeNode(std::move(wrap(std::move(op))),
                                                                                              std::move(wrap(std::move(yystack_[2].value.as < TypeNodePtr > ()))),
                                                                                              std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3318 "Parser.cxx"
    break;

  case 93:
#line 757 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3328 "Parser.cxx"
    break;

  case 94:
#line 763 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < TypeNodePtr > () = new FunctionTypeNode(std::move(wrap(std::move(op))),
                                                                                          std::move(wrap(std::move(yystack_[2].value.as < NodePtr > ()))),
                                                                                          std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3340 "Parser.cxx"
    break;

  case 95:
#line 770 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < TypeNodePtr > () = new FunctionTypeNode(std::move(wrap(std::move(op))),
                                                                                          std::move(wrap(std::move(yystack_[2].value.as < NodePtr > ()))),
                                                                                          std::move(wrap(std::move(yystack_[0].value.as < AnyTypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3352 "Parser.cxx"
    break;

  case 96:
#line 779 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3362 "Parser.cxx"
    break;

  case 97:
#line 785 "Parser.yxx"
                                                            {
                                                                OperatorNodePtr op = create_operator(yystack_[1].value.as < std::string > (), yystack_[1].location, context);
                                                                yylhs.value.as < TypeNodePtr > () = new UnionTypeNode(std::move(wrap(std::move(op))),
                                                                                       std::move(wrap(std::move(yystack_[2].value.as < TypeNodePtr > ()))),
                                                                                       std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3374 "Parser.cxx"
    break;

  case 98:
#line 794 "Parser.yxx"
                                                                {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3384 "Parser.cxx"
    break;

  case 99:
#line 799 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < AnyTypeNodePtr > ();
                                                                yystack_[0].value.as < AnyTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3394 "Parser.cxx"
    break;

  case 100:
#line 806 "Parser.yxx"
                                                            {
                                                                TerminatorNodePtr terminator = create_terminator(yystack_[0].value.as < std::string > (), yystack_[0].location, context);
                                                                KeywordNodePtr keyword = create_keyword(yystack_[3].value.as < std::string > (), yystack_[3].location, context);
                                                                yylhs.value.as < TypeDeclarationNodePtr > () = new TypeDeclarationNode(std::move(wrap(std::move(keyword))),
                                                                                             std::move(wrap(std::move(yystack_[2].value.as < IdentifierNodePtr > ()))),
                                                                                             std::move(wrap(std::move(yystack_[1].value.as < TypeNodePtr > ()))),
                                                                                             std::move(wrap(std::move(terminator))));
                                                                yylhs.value.as < TypeDeclarationNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3408 "Parser.cxx"
    break;

  case 101:
#line 817 "Parser.yxx"
                                                            {
                                                                TopLevelNodeUPtr& node(context.get_parse_result().get_top_level_node());
                                                                node -> get_type_declarations().push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeDeclarationNodePtr > ()))));
                                                            }
#line 3417 "Parser.cxx"
    break;

  case 102:
#line 821 "Parser.yxx"
                                                            {
                                                                TopLevelNodeUPtr& node(context.get_parse_result().get_top_level_node());
                                                                node -> get_type_declarations().push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeDeclarationNodePtr > ()))));
                                                            }
#line 3426 "Parser.cxx"
    break;

  case 103:
#line 827 "Parser.yxx"
                                                            {
                                                                EofNodeUPtr eof = std::make_unique<EofNode>();
                                                                eof -> set_location(yystack_[0].location);
                                                                TopLevelNodeUPtr& node(context.get_parse_result().get_top_level_node());
                                                                node -> set_location(yylhs.location);
                                                                node -> set_eof_node(eof);
                                                            }
#line 3438 "Parser.cxx"
    break;

  case 104:
#line 834 "Parser.yxx"
                                                            {
                                                                EofNodeUPtr eof = std::make_unique<EofNode>();
                                                                eof -> set_location(yystack_[0].location);
                                                                TopLevelNodeUPtr& node(context.get_parse_result().get_top_level_node());
                                                                node -> set_location(yylhs.location);
                                                                node -> set_eof_node(eof);
                                                            }
#line 3450 "Parser.cxx"
    break;


#line 3454 "Parser.cxx"

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


  const signed char Parser::yypact_ninf_ = -84;

  const signed char Parser::yytable_ninf_ = -72;

  const short
  Parser::yypact_[] =
  {
       2,   -84,   202,   -84,     3,     5,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     140,   -84,   -84,   -84,    36,   140,     0,   -84,   -84,    -6,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,    -3,    -1,    31,   -84,   -84,
     -84,   -84,    33,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,    43,   -84,    44,   -84,   -84,   -84,
     -84,   -84,   -84,    49,    48,   -84,    34,   -84,    39,   -84,
     -84,   -84,     1,   -84,   202,   140,   140,    97,   -84,   140,
     140,   180,   -84,   -84,    47,   -84,     4,   -84,    50,    41,
     -84,    45,    38,   -84,    84,    79,    74,    43,   -84,   -84,
     -84,   -84,   -84,   202,   -84,   140,   -84,   -84,   140,    97,
     -84,   140,   -84,   -84,   -84,   -84,   -84
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,   103,     0,   101,     0,     0,    58,    56,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    57,    59,    60,
       0,   104,   102,     1,     0,     0,     0,    25,    26,     0,
       2,     3,     4,     5,     6,     7,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     0,     0,     0,    24,     9,
      10,    11,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    89,    99,    84,     0,    96,    88,    91,
      86,    85,    87,    98,    93,    90,     0,     8,     0,    70,
      66,    67,     0,    65,     0,    34,     0,    31,    27,     0,
       0,     0,   100,    72,     0,    69,     0,    12,    35,     0,
      29,     0,     0,    63,    32,     0,     0,    95,    94,    71,
      97,    92,    68,     0,    14,     0,    36,    28,     0,     0,
      33,     0,    13,    30,    62,    64,    61
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -84,    61,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -83,   -84,   -84,
     -32,   -84,    -4,   -84,   -84,   -80,   -84,     6,   -84,   -84,
     -84,   -84,   -84,    -2,   -84,   -84,   -84,   -29,    94,   -84,
     -84
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    59,    60,    61,    62,   106,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,   108,
     113,   114,    91,    92,    76,    77,    78,    79,    80,   115,
      81,   109,    82,   116,    83,    84,    85,    93,     3,     4,
       5
  };

  const short
  Parser::yytable_[] =
  {
      30,    86,     1,    31,    34,    33,    88,    94,   104,    35,
      95,   123,    96,    36,    89,   105,   117,   119,   124,   118,
     120,    90,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    97,    98,     2,     2,   -71,    99,
     103,    34,   100,   102,   101,   126,    35,   125,   128,   127,
      36,    40,    41,    42,    43,    44,   110,   111,    90,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,   129,   107,   130,   131,    87,   133,   135,    32,   134,
     122,   112,   136,     0,     0,     0,     0,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       7,   132,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    34,     0,     0,     0,     0,    35,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    34,     0,     0,     0,     0,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,     6,     0,     7,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29
  };

  const short
  Parser::yycheck_[] =
  {
       2,    30,     0,     0,     4,     0,    35,    13,     7,     9,
      13,     7,    13,    13,    14,    14,    99,   100,    14,    99,
     100,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    13,    12,    44,    44,     5,     5,
      11,     4,     3,    19,     6,    14,     9,     7,    20,    14,
      13,    25,    26,    27,    28,    29,    95,    96,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     7,    94,    14,    20,    34,   125,   129,     4,   128,
     104,     4,   131,    -1,    -1,    -1,    -1,   101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      23,   123,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,     4,    -1,    -1,    -1,    -1,     9,
      -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     4,    -1,    -1,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    21,    -1,    23,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     0,    44,    85,    86,    87,    21,    23,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      80,     0,    85,     0,     4,     9,    13,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    48,
      49,    50,    51,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    71,    72,    73,    74,
      75,    77,    79,    81,    82,    83,    84,    48,    84,    14,
      21,    69,    70,    84,    13,    13,    13,    13,    12,     5,
       3,     6,    19,    11,     7,    14,    52,    80,    66,    78,
      84,    84,     4,    67,    68,    76,    80,    64,    72,    64,
      72,    74,    69,     7,    14,     7,    14,    14,    20,     7,
      14,    20,    80,    84,    84,    67,    84
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    47,    48,    48,    48,    48,    48,    49,    50,    51,
      51,    51,    52,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    64,    63,    83,    65,    75,    66,
      66,    76,    76,    77,    78,    78,    79,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    71,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    82,    82,    72,    72,    72,    81,    81,    84,    84,
      85,    86,    86,    87,    87
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     3,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     1,
       3,     0,     1,     4,     0,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     3,     1,     1,     1,     3,     3,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     3,     1,     3,     1,     1,
       4,     1,     2,     1,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"|\"", "\"^\"", "\"=>\"",
  "\"&\"", "\",\"", "\"((\"", "\"(\"", "\"))\"", "\")\"", "\"[]\"",
  "\"<\"", "\">\"", "\"[[\"", "\"]]\"", "\"{{\"", "\"}}\"", "\";\"",
  "\":\"", "\"...\"", "\"???\"", "\"null\"", "\"class\"", "INTEGER",
  "DOUBLE", "COMPLEX", "CHARACTER", "LOGICAL", "RAW", "ENVIRONMENT",
  "EXPRESSION", "LANGUAGE", "SYMBOL", "EXTERNALPOINTER", "BYTECODE",
  "PAIRLIST", "S4", "WEAKREF", "TUPLE", "LIST", "STRUCT", "ANY",
  "TYPEDECL", "IDENTIFIER", "QUOTED_IDENTIFIER", "$accept", "ascalartype",
  "rawascalartype", "nascalartype", "scalartype", "classnameseq",
  "classtype", "environmenttype", "expressiontype", "languagetype",
  "symboltype", "externalptrtype", "bytecodetype", "pairlisttype",
  "s4type", "weakreftype", "unknowntype", "anytype", "vectortype",
  "typeseq", "namedtype", "namedtypeseq", "paramtype", "paramtypeseq",
  "params", "functiontype", "grouptype", "nonconnectivetype", "listtype",
  "structelements", "structtype", "tupleelements", "tupletype",
  "identifier", "uniontype", "intersectiontype", "nulltype", "type",
  "decltype", "decllist", "start", YY_NULLPTR
  };

#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   348,   348,   349,   350,   351,   352,   355,   358,   365,
     370,   375,   383,   387,   396,   411,   414,   417,   420,   423,
     426,   429,   432,   435,   438,   441,   444,   447,   455,   472,
     476,   486,   489,   494,   512,   515,   521,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   564,   571,   581,   585,   595,   599,   602,   606,   615,
     623,   631,   638,   649,   654,   659,   664,   669,   674,   679,
     684,   689,   694,   699,   704,   709,   714,   719,   724,   729,
     734,   742,   748,   757,   763,   770,   779,   785,   794,   799,
     806,   817,   821,   827,   834
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
      45,    46
    };
    const int user_token_number_max_ = 301;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 9 "Parser.yxx"
} } // tastr::parser
#line 4023 "Parser.cxx"

#line 843 "Parser.yxx"


void tastr::parser::Parser::error(const location_type& location, const std::string& message) {
    context.get_parse_result().set_error(location, message);
}
