// A Bison parser, made by GNU Bison 3.5.2.

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
#line 251 "Parser.yxx"

    #include "parser/ParsingContext.hpp"
    #include "parser/Lexer.hpp"
    #undef yylex
    #define yylex lexer.yylex

#line 52 "Parser.cxx"


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
#line 144 "Parser.cxx"


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
      case 53: // anytype
        value.move< AnyTypeNodePtr > (std::move (that.value));
        break;

      case 49: // bytecodetype
        value.move< BytecodeTypeNodePtr > (std::move (that.value));
        break;

      case 44: // environmenttype
        value.move< EnvironmentTypeNodePtr > (std::move (that.value));
        break;

      case 45: // expressiontype
        value.move< ExpressionTypeNodePtr > (std::move (that.value));
        break;

      case 48: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (std::move (that.value));
        break;

      case 61: // functiontype
        value.move< FunctionTypeNodePtr > (std::move (that.value));
        break;

      case 62: // grouptype
        value.move< GroupTypeNodePtr > (std::move (that.value));
        break;

      case 67: // identifier
        value.move< IdentifierNodePtr > (std::move (that.value));
        break;

      case 46: // languagetype
        value.move< LanguageTypeNodePtr > (std::move (that.value));
        break;

      case 64: // listtype
        value.move< ListTypeNodePtr > (std::move (that.value));
        break;

      case 55: // nonavectortype
        value.move< NoNaTypeNodePtr > (std::move (that.value));
        break;

      case 50: // pairlisttype
        value.move< PairlistTypeNodePtr > (std::move (that.value));
        break;

      case 51: // s4type
        value.move< S4TypeNodePtr > (std::move (that.value));
        break;

      case 43: // scalartype
        value.move< ScalarTypeNodePtr > (std::move (that.value));
        break;

      case 65: // structtype
        value.move< StructTypeNodePtr > (std::move (that.value));
        break;

      case 47: // symboltype
        value.move< SymbolTypeNodePtr > (std::move (that.value));
        break;

      case 57: // namedtype
        value.move< TagTypePairNodePtr > (std::move (that.value));
        break;

      case 58: // namedtypeseq
        value.move< TagTypePairNodeSequenceNodePtr > (std::move (that.value));
        break;

      case 66: // tupletype
        value.move< TupleTypeNodePtr > (std::move (that.value));
        break;

      case 71: // decltype
        value.move< TypeDeclarationNodePtr > (std::move (that.value));
        break;

      case 59: // paramtype
      case 63: // nonuniontype
      case 68: // innertype
      case 69: // nulltype
      case 70: // type
        value.move< TypeNodePtr > (std::move (that.value));
        break;

      case 56: // typeseq
      case 60: // paramtypeseq
        value.move< TypeNodeSequenceNodePtr > (std::move (that.value));
        break;

      case 54: // vectortype
        value.move< VectorTypeNodePtr > (std::move (that.value));
        break;

      case 52: // weakreftype
        value.move< WeakReferenceTypeNodePtr > (std::move (that.value));
        break;

      case 3: // "|"
      case 4: // "!"
      case 5: // "=>"
      case 6: // ","
      case 7: // "(("
      case 8: // "("
      case 9: // "))"
      case 10: // ")"
      case 11: // "["
      case 12: // "]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "<<"
      case 16: // ">>"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "?"
      case 23: // INTEGER
      case 24: // DOUBLE
      case 25: // COMPLEX
      case 26: // CHARACTER
      case 27: // LOGICAL
      case 28: // RAW
      case 29: // ENVIRONMENT
      case 30: // EXPRESSION
      case 31: // LANGUAGE
      case 32: // SYMBOL
      case 33: // EXTERNALPOINTER
      case 34: // BYTECODE
      case 35: // PAIRLIST
      case 36: // S4
      case 37: // WEAKREF
      case 38: // ANY
      case 39: // TYPEDECL
      case 40: // IDENTIFIER
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
      case 53: // anytype
        value.copy< AnyTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 49: // bytecodetype
        value.copy< BytecodeTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 44: // environmenttype
        value.copy< EnvironmentTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 45: // expressiontype
        value.copy< ExpressionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 48: // externalptrtype
        value.copy< ExternalPointerTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 61: // functiontype
        value.copy< FunctionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 62: // grouptype
        value.copy< GroupTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 67: // identifier
        value.copy< IdentifierNodePtr > (YY_MOVE (that.value));
        break;

      case 46: // languagetype
        value.copy< LanguageTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 64: // listtype
        value.copy< ListTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 55: // nonavectortype
        value.copy< NoNaTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 50: // pairlisttype
        value.copy< PairlistTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 51: // s4type
        value.copy< S4TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 43: // scalartype
        value.copy< ScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 65: // structtype
        value.copy< StructTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 47: // symboltype
        value.copy< SymbolTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 57: // namedtype
        value.copy< TagTypePairNodePtr > (YY_MOVE (that.value));
        break;

      case 58: // namedtypeseq
        value.copy< TagTypePairNodeSequenceNodePtr > (YY_MOVE (that.value));
        break;

      case 66: // tupletype
        value.copy< TupleTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 71: // decltype
        value.copy< TypeDeclarationNodePtr > (YY_MOVE (that.value));
        break;

      case 59: // paramtype
      case 63: // nonuniontype
      case 68: // innertype
      case 69: // nulltype
      case 70: // type
        value.copy< TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 56: // typeseq
      case 60: // paramtypeseq
        value.copy< TypeNodeSequenceNodePtr > (YY_MOVE (that.value));
        break;

      case 54: // vectortype
        value.copy< VectorTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 52: // weakreftype
        value.copy< WeakReferenceTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 3: // "|"
      case 4: // "!"
      case 5: // "=>"
      case 6: // ","
      case 7: // "(("
      case 8: // "("
      case 9: // "))"
      case 10: // ")"
      case 11: // "["
      case 12: // "]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "<<"
      case 16: // ">>"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "?"
      case 23: // INTEGER
      case 24: // DOUBLE
      case 25: // COMPLEX
      case 26: // CHARACTER
      case 27: // LOGICAL
      case 28: // RAW
      case 29: // ENVIRONMENT
      case 30: // EXPRESSION
      case 31: // LANGUAGE
      case 32: // SYMBOL
      case 33: // EXTERNALPOINTER
      case 34: // BYTECODE
      case 35: // PAIRLIST
      case 36: // S4
      case 37: // WEAKREF
      case 38: // ANY
      case 39: // TYPEDECL
      case 40: // IDENTIFIER
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
      case 53: // anytype
        value.move< AnyTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 49: // bytecodetype
        value.move< BytecodeTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 44: // environmenttype
        value.move< EnvironmentTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 45: // expressiontype
        value.move< ExpressionTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 48: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 61: // functiontype
        value.move< FunctionTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 62: // grouptype
        value.move< GroupTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 67: // identifier
        value.move< IdentifierNodePtr > (YY_MOVE (s.value));
        break;

      case 46: // languagetype
        value.move< LanguageTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 64: // listtype
        value.move< ListTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 55: // nonavectortype
        value.move< NoNaTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 50: // pairlisttype
        value.move< PairlistTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 51: // s4type
        value.move< S4TypeNodePtr > (YY_MOVE (s.value));
        break;

      case 43: // scalartype
        value.move< ScalarTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 65: // structtype
        value.move< StructTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 47: // symboltype
        value.move< SymbolTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 57: // namedtype
        value.move< TagTypePairNodePtr > (YY_MOVE (s.value));
        break;

      case 58: // namedtypeseq
        value.move< TagTypePairNodeSequenceNodePtr > (YY_MOVE (s.value));
        break;

      case 66: // tupletype
        value.move< TupleTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 71: // decltype
        value.move< TypeDeclarationNodePtr > (YY_MOVE (s.value));
        break;

      case 59: // paramtype
      case 63: // nonuniontype
      case 68: // innertype
      case 69: // nulltype
      case 70: // type
        value.move< TypeNodePtr > (YY_MOVE (s.value));
        break;

      case 56: // typeseq
      case 60: // paramtypeseq
        value.move< TypeNodeSequenceNodePtr > (YY_MOVE (s.value));
        break;

      case 54: // vectortype
        value.move< VectorTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 52: // weakreftype
        value.move< WeakReferenceTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 3: // "|"
      case 4: // "!"
      case 5: // "=>"
      case 6: // ","
      case 7: // "(("
      case 8: // "("
      case 9: // "))"
      case 10: // ")"
      case 11: // "["
      case 12: // "]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "<<"
      case 16: // ">>"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "?"
      case 23: // INTEGER
      case 24: // DOUBLE
      case 25: // COMPLEX
      case 26: // CHARACTER
      case 27: // LOGICAL
      case 28: // RAW
      case 29: // ENVIRONMENT
      case 30: // EXPRESSION
      case 31: // LANGUAGE
      case 32: // SYMBOL
      case 33: // EXTERNALPOINTER
      case 34: // BYTECODE
      case 35: // PAIRLIST
      case 36: // S4
      case 37: // WEAKREF
      case 38: // ANY
      case 39: // TYPEDECL
      case 40: // IDENTIFIER
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
      case 53: // anytype
        value.YY_MOVE_OR_COPY< AnyTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 49: // bytecodetype
        value.YY_MOVE_OR_COPY< BytecodeTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 44: // environmenttype
        value.YY_MOVE_OR_COPY< EnvironmentTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 45: // expressiontype
        value.YY_MOVE_OR_COPY< ExpressionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 48: // externalptrtype
        value.YY_MOVE_OR_COPY< ExternalPointerTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 61: // functiontype
        value.YY_MOVE_OR_COPY< FunctionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 62: // grouptype
        value.YY_MOVE_OR_COPY< GroupTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 67: // identifier
        value.YY_MOVE_OR_COPY< IdentifierNodePtr > (YY_MOVE (that.value));
        break;

      case 46: // languagetype
        value.YY_MOVE_OR_COPY< LanguageTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 64: // listtype
        value.YY_MOVE_OR_COPY< ListTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 55: // nonavectortype
        value.YY_MOVE_OR_COPY< NoNaTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 50: // pairlisttype
        value.YY_MOVE_OR_COPY< PairlistTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 51: // s4type
        value.YY_MOVE_OR_COPY< S4TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 43: // scalartype
        value.YY_MOVE_OR_COPY< ScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 65: // structtype
        value.YY_MOVE_OR_COPY< StructTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 47: // symboltype
        value.YY_MOVE_OR_COPY< SymbolTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 57: // namedtype
        value.YY_MOVE_OR_COPY< TagTypePairNodePtr > (YY_MOVE (that.value));
        break;

      case 58: // namedtypeseq
        value.YY_MOVE_OR_COPY< TagTypePairNodeSequenceNodePtr > (YY_MOVE (that.value));
        break;

      case 66: // tupletype
        value.YY_MOVE_OR_COPY< TupleTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 71: // decltype
        value.YY_MOVE_OR_COPY< TypeDeclarationNodePtr > (YY_MOVE (that.value));
        break;

      case 59: // paramtype
      case 63: // nonuniontype
      case 68: // innertype
      case 69: // nulltype
      case 70: // type
        value.YY_MOVE_OR_COPY< TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 56: // typeseq
      case 60: // paramtypeseq
        value.YY_MOVE_OR_COPY< TypeNodeSequenceNodePtr > (YY_MOVE (that.value));
        break;

      case 54: // vectortype
        value.YY_MOVE_OR_COPY< VectorTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 52: // weakreftype
        value.YY_MOVE_OR_COPY< WeakReferenceTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 3: // "|"
      case 4: // "!"
      case 5: // "=>"
      case 6: // ","
      case 7: // "(("
      case 8: // "("
      case 9: // "))"
      case 10: // ")"
      case 11: // "["
      case 12: // "]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "<<"
      case 16: // ">>"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "?"
      case 23: // INTEGER
      case 24: // DOUBLE
      case 25: // COMPLEX
      case 26: // CHARACTER
      case 27: // LOGICAL
      case 28: // RAW
      case 29: // ENVIRONMENT
      case 30: // EXPRESSION
      case 31: // LANGUAGE
      case 32: // SYMBOL
      case 33: // EXTERNALPOINTER
      case 34: // BYTECODE
      case 35: // PAIRLIST
      case 36: // S4
      case 37: // WEAKREF
      case 38: // ANY
      case 39: // TYPEDECL
      case 40: // IDENTIFIER
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
      case 53: // anytype
        value.move< AnyTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 49: // bytecodetype
        value.move< BytecodeTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 44: // environmenttype
        value.move< EnvironmentTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 45: // expressiontype
        value.move< ExpressionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 48: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 61: // functiontype
        value.move< FunctionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 62: // grouptype
        value.move< GroupTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 67: // identifier
        value.move< IdentifierNodePtr > (YY_MOVE (that.value));
        break;

      case 46: // languagetype
        value.move< LanguageTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 64: // listtype
        value.move< ListTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 55: // nonavectortype
        value.move< NoNaTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 50: // pairlisttype
        value.move< PairlistTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 51: // s4type
        value.move< S4TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 43: // scalartype
        value.move< ScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 65: // structtype
        value.move< StructTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 47: // symboltype
        value.move< SymbolTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 57: // namedtype
        value.move< TagTypePairNodePtr > (YY_MOVE (that.value));
        break;

      case 58: // namedtypeseq
        value.move< TagTypePairNodeSequenceNodePtr > (YY_MOVE (that.value));
        break;

      case 66: // tupletype
        value.move< TupleTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 71: // decltype
        value.move< TypeDeclarationNodePtr > (YY_MOVE (that.value));
        break;

      case 59: // paramtype
      case 63: // nonuniontype
      case 68: // innertype
      case 69: // nulltype
      case 70: // type
        value.move< TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 56: // typeseq
      case 60: // paramtypeseq
        value.move< TypeNodeSequenceNodePtr > (YY_MOVE (that.value));
        break;

      case 54: // vectortype
        value.move< VectorTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 52: // weakreftype
        value.move< WeakReferenceTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 3: // "|"
      case 4: // "!"
      case 5: // "=>"
      case 6: // ","
      case 7: // "(("
      case 8: // "("
      case 9: // "))"
      case 10: // ")"
      case 11: // "["
      case 12: // "]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "<<"
      case 16: // ">>"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "?"
      case 23: // INTEGER
      case 24: // DOUBLE
      case 25: // COMPLEX
      case 26: // CHARACTER
      case 27: // LOGICAL
      case 28: // RAW
      case 29: // ENVIRONMENT
      case 30: // EXPRESSION
      case 31: // LANGUAGE
      case 32: // SYMBOL
      case 33: // EXTERNALPOINTER
      case 34: // BYTECODE
      case 35: // PAIRLIST
      case 36: // S4
      case 37: // WEAKREF
      case 38: // ANY
      case 39: // TYPEDECL
      case 40: // IDENTIFIER
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
      case 53: // anytype
        value.copy< AnyTypeNodePtr > (that.value);
        break;

      case 49: // bytecodetype
        value.copy< BytecodeTypeNodePtr > (that.value);
        break;

      case 44: // environmenttype
        value.copy< EnvironmentTypeNodePtr > (that.value);
        break;

      case 45: // expressiontype
        value.copy< ExpressionTypeNodePtr > (that.value);
        break;

      case 48: // externalptrtype
        value.copy< ExternalPointerTypeNodePtr > (that.value);
        break;

      case 61: // functiontype
        value.copy< FunctionTypeNodePtr > (that.value);
        break;

      case 62: // grouptype
        value.copy< GroupTypeNodePtr > (that.value);
        break;

      case 67: // identifier
        value.copy< IdentifierNodePtr > (that.value);
        break;

      case 46: // languagetype
        value.copy< LanguageTypeNodePtr > (that.value);
        break;

      case 64: // listtype
        value.copy< ListTypeNodePtr > (that.value);
        break;

      case 55: // nonavectortype
        value.copy< NoNaTypeNodePtr > (that.value);
        break;

      case 50: // pairlisttype
        value.copy< PairlistTypeNodePtr > (that.value);
        break;

      case 51: // s4type
        value.copy< S4TypeNodePtr > (that.value);
        break;

      case 43: // scalartype
        value.copy< ScalarTypeNodePtr > (that.value);
        break;

      case 65: // structtype
        value.copy< StructTypeNodePtr > (that.value);
        break;

      case 47: // symboltype
        value.copy< SymbolTypeNodePtr > (that.value);
        break;

      case 57: // namedtype
        value.copy< TagTypePairNodePtr > (that.value);
        break;

      case 58: // namedtypeseq
        value.copy< TagTypePairNodeSequenceNodePtr > (that.value);
        break;

      case 66: // tupletype
        value.copy< TupleTypeNodePtr > (that.value);
        break;

      case 71: // decltype
        value.copy< TypeDeclarationNodePtr > (that.value);
        break;

      case 59: // paramtype
      case 63: // nonuniontype
      case 68: // innertype
      case 69: // nulltype
      case 70: // type
        value.copy< TypeNodePtr > (that.value);
        break;

      case 56: // typeseq
      case 60: // paramtypeseq
        value.copy< TypeNodeSequenceNodePtr > (that.value);
        break;

      case 54: // vectortype
        value.copy< VectorTypeNodePtr > (that.value);
        break;

      case 52: // weakreftype
        value.copy< WeakReferenceTypeNodePtr > (that.value);
        break;

      case 3: // "|"
      case 4: // "!"
      case 5: // "=>"
      case 6: // ","
      case 7: // "(("
      case 8: // "("
      case 9: // "))"
      case 10: // ")"
      case 11: // "["
      case 12: // "]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "<<"
      case 16: // ">>"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "?"
      case 23: // INTEGER
      case 24: // DOUBLE
      case 25: // COMPLEX
      case 26: // CHARACTER
      case 27: // LOGICAL
      case 28: // RAW
      case 29: // ENVIRONMENT
      case 30: // EXPRESSION
      case 31: // LANGUAGE
      case 32: // SYMBOL
      case 33: // EXTERNALPOINTER
      case 34: // BYTECODE
      case 35: // PAIRLIST
      case 36: // S4
      case 37: // WEAKREF
      case 38: // ANY
      case 39: // TYPEDECL
      case 40: // IDENTIFIER
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
      case 53: // anytype
        value.move< AnyTypeNodePtr > (that.value);
        break;

      case 49: // bytecodetype
        value.move< BytecodeTypeNodePtr > (that.value);
        break;

      case 44: // environmenttype
        value.move< EnvironmentTypeNodePtr > (that.value);
        break;

      case 45: // expressiontype
        value.move< ExpressionTypeNodePtr > (that.value);
        break;

      case 48: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (that.value);
        break;

      case 61: // functiontype
        value.move< FunctionTypeNodePtr > (that.value);
        break;

      case 62: // grouptype
        value.move< GroupTypeNodePtr > (that.value);
        break;

      case 67: // identifier
        value.move< IdentifierNodePtr > (that.value);
        break;

      case 46: // languagetype
        value.move< LanguageTypeNodePtr > (that.value);
        break;

      case 64: // listtype
        value.move< ListTypeNodePtr > (that.value);
        break;

      case 55: // nonavectortype
        value.move< NoNaTypeNodePtr > (that.value);
        break;

      case 50: // pairlisttype
        value.move< PairlistTypeNodePtr > (that.value);
        break;

      case 51: // s4type
        value.move< S4TypeNodePtr > (that.value);
        break;

      case 43: // scalartype
        value.move< ScalarTypeNodePtr > (that.value);
        break;

      case 65: // structtype
        value.move< StructTypeNodePtr > (that.value);
        break;

      case 47: // symboltype
        value.move< SymbolTypeNodePtr > (that.value);
        break;

      case 57: // namedtype
        value.move< TagTypePairNodePtr > (that.value);
        break;

      case 58: // namedtypeseq
        value.move< TagTypePairNodeSequenceNodePtr > (that.value);
        break;

      case 66: // tupletype
        value.move< TupleTypeNodePtr > (that.value);
        break;

      case 71: // decltype
        value.move< TypeDeclarationNodePtr > (that.value);
        break;

      case 59: // paramtype
      case 63: // nonuniontype
      case 68: // innertype
      case 69: // nulltype
      case 70: // type
        value.move< TypeNodePtr > (that.value);
        break;

      case 56: // typeseq
      case 60: // paramtypeseq
        value.move< TypeNodeSequenceNodePtr > (that.value);
        break;

      case 54: // vectortype
        value.move< VectorTypeNodePtr > (that.value);
        break;

      case 52: // weakreftype
        value.move< WeakReferenceTypeNodePtr > (that.value);
        break;

      case 3: // "|"
      case 4: // "!"
      case 5: // "=>"
      case 6: // ","
      case 7: // "(("
      case 8: // "("
      case 9: // "))"
      case 10: // ")"
      case 11: // "["
      case 12: // "]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "<<"
      case 16: // ">>"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "?"
      case 23: // INTEGER
      case 24: // DOUBLE
      case 25: // COMPLEX
      case 26: // CHARACTER
      case 27: // LOGICAL
      case 28: // RAW
      case 29: // ENVIRONMENT
      case 30: // EXPRESSION
      case 31: // LANGUAGE
      case 32: // SYMBOL
      case 33: // EXTERNALPOINTER
      case 34: // BYTECODE
      case 35: // PAIRLIST
      case 36: // S4
      case 37: // WEAKREF
      case 38: // ANY
      case 39: // TYPEDECL
      case 40: // IDENTIFIER
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
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1428 "Parser.cxx"
        break;

      case 4: // "!"
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1434 "Parser.cxx"
        break;

      case 5: // "=>"
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1440 "Parser.cxx"
        break;

      case 6: // ","
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1446 "Parser.cxx"
        break;

      case 7: // "(("
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1452 "Parser.cxx"
        break;

      case 8: // "("
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1458 "Parser.cxx"
        break;

      case 9: // "))"
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1464 "Parser.cxx"
        break;

      case 10: // ")"
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1470 "Parser.cxx"
        break;

      case 11: // "["
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1476 "Parser.cxx"
        break;

      case 12: // "]"
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1482 "Parser.cxx"
        break;

      case 13: // "<"
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1488 "Parser.cxx"
        break;

      case 14: // ">"
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1494 "Parser.cxx"
        break;

      case 15: // "<<"
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1500 "Parser.cxx"
        break;

      case 16: // ">>"
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1506 "Parser.cxx"
        break;

      case 17: // "{{"
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1512 "Parser.cxx"
        break;

      case 18: // "}}"
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1518 "Parser.cxx"
        break;

      case 19: // ";"
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1524 "Parser.cxx"
        break;

      case 20: // ":"
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1530 "Parser.cxx"
        break;

      case 21: // "..."
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1536 "Parser.cxx"
        break;

      case 22: // "?"
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1542 "Parser.cxx"
        break;

      case 23: // INTEGER
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1548 "Parser.cxx"
        break;

      case 24: // DOUBLE
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1554 "Parser.cxx"
        break;

      case 25: // COMPLEX
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1560 "Parser.cxx"
        break;

      case 26: // CHARACTER
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1566 "Parser.cxx"
        break;

      case 27: // LOGICAL
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1572 "Parser.cxx"
        break;

      case 28: // RAW
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1578 "Parser.cxx"
        break;

      case 29: // ENVIRONMENT
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1584 "Parser.cxx"
        break;

      case 30: // EXPRESSION
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1590 "Parser.cxx"
        break;

      case 31: // LANGUAGE
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1596 "Parser.cxx"
        break;

      case 32: // SYMBOL
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1602 "Parser.cxx"
        break;

      case 33: // EXTERNALPOINTER
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1608 "Parser.cxx"
        break;

      case 34: // BYTECODE
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1614 "Parser.cxx"
        break;

      case 35: // PAIRLIST
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1620 "Parser.cxx"
        break;

      case 36: // S4
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1626 "Parser.cxx"
        break;

      case 37: // WEAKREF
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1632 "Parser.cxx"
        break;

      case 38: // ANY
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1638 "Parser.cxx"
        break;

      case 39: // TYPEDECL
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1644 "Parser.cxx"
        break;

      case 40: // IDENTIFIER
#line 130 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1650 "Parser.cxx"
        break;

      case 43: // scalartype
#line 106 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ScalarTypeNodePtr > ()); }
#line 1656 "Parser.cxx"
        break;

      case 44: // environmenttype
#line 107 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < EnvironmentTypeNodePtr > ()); }
#line 1662 "Parser.cxx"
        break;

      case 45: // expressiontype
#line 108 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ExpressionTypeNodePtr > ()); }
#line 1668 "Parser.cxx"
        break;

      case 46: // languagetype
#line 109 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < LanguageTypeNodePtr > ()); }
#line 1674 "Parser.cxx"
        break;

      case 47: // symboltype
#line 110 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < SymbolTypeNodePtr > ()); }
#line 1680 "Parser.cxx"
        break;

      case 48: // externalptrtype
#line 111 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ExternalPointerTypeNodePtr > ()); }
#line 1686 "Parser.cxx"
        break;

      case 49: // bytecodetype
#line 112 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < BytecodeTypeNodePtr > ()); }
#line 1692 "Parser.cxx"
        break;

      case 50: // pairlisttype
#line 113 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < PairlistTypeNodePtr > ()); }
#line 1698 "Parser.cxx"
        break;

      case 51: // s4type
#line 114 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < S4TypeNodePtr > ()); }
#line 1704 "Parser.cxx"
        break;

      case 52: // weakreftype
#line 115 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < WeakReferenceTypeNodePtr > ()); }
#line 1710 "Parser.cxx"
        break;

      case 53: // anytype
#line 116 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < AnyTypeNodePtr > ()); }
#line 1716 "Parser.cxx"
        break;

      case 54: // vectortype
#line 117 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < VectorTypeNodePtr > ()); }
#line 1722 "Parser.cxx"
        break;

      case 55: // nonavectortype
#line 118 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NoNaTypeNodePtr > ()); }
#line 1728 "Parser.cxx"
        break;

      case 56: // typeseq
#line 119 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodeSequenceNodePtr > ()); }
#line 1734 "Parser.cxx"
        break;

      case 57: // namedtype
#line 120 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TagTypePairNodePtr > ()); }
#line 1740 "Parser.cxx"
        break;

      case 58: // namedtypeseq
#line 121 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TagTypePairNodeSequenceNodePtr > ()); }
#line 1746 "Parser.cxx"
        break;

      case 59: // paramtype
#line 128 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 1752 "Parser.cxx"
        break;

      case 60: // paramtypeseq
#line 119 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodeSequenceNodePtr > ()); }
#line 1758 "Parser.cxx"
        break;

      case 61: // functiontype
#line 122 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < FunctionTypeNodePtr > ()); }
#line 1764 "Parser.cxx"
        break;

      case 62: // grouptype
#line 123 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < GroupTypeNodePtr > ()); }
#line 1770 "Parser.cxx"
        break;

      case 63: // nonuniontype
#line 128 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 1776 "Parser.cxx"
        break;

      case 64: // listtype
#line 124 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ListTypeNodePtr > ()); }
#line 1782 "Parser.cxx"
        break;

      case 65: // structtype
#line 125 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < StructTypeNodePtr > ()); }
#line 1788 "Parser.cxx"
        break;

      case 66: // tupletype
#line 126 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TupleTypeNodePtr > ()); }
#line 1794 "Parser.cxx"
        break;

      case 67: // identifier
#line 127 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < IdentifierNodePtr > ()); }
#line 1800 "Parser.cxx"
        break;

      case 68: // innertype
#line 128 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 1806 "Parser.cxx"
        break;

      case 69: // nulltype
#line 128 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 1812 "Parser.cxx"
        break;

      case 70: // type
#line 128 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 1818 "Parser.cxx"
        break;

      case 71: // decltype
#line 129 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeDeclarationNodePtr > ()); }
#line 1824 "Parser.cxx"
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
#line 162 "Parser.yxx"
{
    /* filename for locations here
       https://www.gnu.org/software/bison/manual/html_node/Initial-Action-Decl.html
       location stores pointer to a string allocated elsewhere and does not delete it.
       it has been disabled for now since TopLevelNode stores the filename anyways and
       properly deallocates it.
    */

    /* @$.initialize(context.get_input_stream_name()); */
}

#line 1954 "Parser.cxx"


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
      case 53: // anytype
        yylhs.value.emplace< AnyTypeNodePtr > ();
        break;

      case 49: // bytecodetype
        yylhs.value.emplace< BytecodeTypeNodePtr > ();
        break;

      case 44: // environmenttype
        yylhs.value.emplace< EnvironmentTypeNodePtr > ();
        break;

      case 45: // expressiontype
        yylhs.value.emplace< ExpressionTypeNodePtr > ();
        break;

      case 48: // externalptrtype
        yylhs.value.emplace< ExternalPointerTypeNodePtr > ();
        break;

      case 61: // functiontype
        yylhs.value.emplace< FunctionTypeNodePtr > ();
        break;

      case 62: // grouptype
        yylhs.value.emplace< GroupTypeNodePtr > ();
        break;

      case 67: // identifier
        yylhs.value.emplace< IdentifierNodePtr > ();
        break;

      case 46: // languagetype
        yylhs.value.emplace< LanguageTypeNodePtr > ();
        break;

      case 64: // listtype
        yylhs.value.emplace< ListTypeNodePtr > ();
        break;

      case 55: // nonavectortype
        yylhs.value.emplace< NoNaTypeNodePtr > ();
        break;

      case 50: // pairlisttype
        yylhs.value.emplace< PairlistTypeNodePtr > ();
        break;

      case 51: // s4type
        yylhs.value.emplace< S4TypeNodePtr > ();
        break;

      case 43: // scalartype
        yylhs.value.emplace< ScalarTypeNodePtr > ();
        break;

      case 65: // structtype
        yylhs.value.emplace< StructTypeNodePtr > ();
        break;

      case 47: // symboltype
        yylhs.value.emplace< SymbolTypeNodePtr > ();
        break;

      case 57: // namedtype
        yylhs.value.emplace< TagTypePairNodePtr > ();
        break;

      case 58: // namedtypeseq
        yylhs.value.emplace< TagTypePairNodeSequenceNodePtr > ();
        break;

      case 66: // tupletype
        yylhs.value.emplace< TupleTypeNodePtr > ();
        break;

      case 71: // decltype
        yylhs.value.emplace< TypeDeclarationNodePtr > ();
        break;

      case 59: // paramtype
      case 63: // nonuniontype
      case 68: // innertype
      case 69: // nulltype
      case 70: // type
        yylhs.value.emplace< TypeNodePtr > ();
        break;

      case 56: // typeseq
      case 60: // paramtypeseq
        yylhs.value.emplace< TypeNodeSequenceNodePtr > ();
        break;

      case 54: // vectortype
        yylhs.value.emplace< VectorTypeNodePtr > ();
        break;

      case 52: // weakreftype
        yylhs.value.emplace< WeakReferenceTypeNodePtr > ();
        break;

      case 3: // "|"
      case 4: // "!"
      case 5: // "=>"
      case 6: // ","
      case 7: // "(("
      case 8: // "("
      case 9: // "))"
      case 10: // ")"
      case 11: // "["
      case 12: // "]"
      case 13: // "<"
      case 14: // ">"
      case 15: // "<<"
      case 16: // ">>"
      case 17: // "{{"
      case 18: // "}}"
      case 19: // ";"
      case 20: // ":"
      case 21: // "..."
      case 22: // "?"
      case 23: // INTEGER
      case 24: // DOUBLE
      case 25: // COMPLEX
      case 26: // CHARACTER
      case 27: // LOGICAL
      case 28: // RAW
      case 29: // ENVIRONMENT
      case 30: // EXPRESSION
      case 31: // LANGUAGE
      case 32: // SYMBOL
      case 33: // EXTERNALPOINTER
      case 34: // BYTECODE
      case 35: // PAIRLIST
      case 36: // S4
      case 37: // WEAKREF
      case 38: // ANY
      case 39: // TYPEDECL
      case 40: // IDENTIFIER
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
#line 260 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = new IntegerScalarTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2225 "Parser.cxx"
    break;

  case 3:
#line 264 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = new DoubleScalarTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2234 "Parser.cxx"
    break;

  case 4:
#line 268 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = new ComplexScalarTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2243 "Parser.cxx"
    break;

  case 5:
#line 272 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = new CharacterScalarTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2252 "Parser.cxx"
    break;

  case 6:
#line 276 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = new LogicalScalarTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2261 "Parser.cxx"
    break;

  case 7:
#line 280 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = new RawScalarTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2270 "Parser.cxx"
    break;

  case 8:
#line 286 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < EnvironmentTypeNodePtr > () = new EnvironmentTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < EnvironmentTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2279 "Parser.cxx"
    break;

  case 9:
#line 292 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ExpressionTypeNodePtr > () = new ExpressionTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ExpressionTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2288 "Parser.cxx"
    break;

  case 10:
#line 298 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < LanguageTypeNodePtr > () = new LanguageTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < LanguageTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2297 "Parser.cxx"
    break;

  case 11:
#line 304 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < SymbolTypeNodePtr > () = new SymbolTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < SymbolTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2306 "Parser.cxx"
    break;

  case 12:
#line 310 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ExternalPointerTypeNodePtr > () = new ExternalPointerTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ExternalPointerTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2315 "Parser.cxx"
    break;

  case 13:
#line 316 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < BytecodeTypeNodePtr > () = new BytecodeTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < BytecodeTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2324 "Parser.cxx"
    break;

  case 14:
#line 322 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < PairlistTypeNodePtr > () = new PairlistTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < PairlistTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2333 "Parser.cxx"
    break;

  case 15:
#line 328 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < S4TypeNodePtr > () = new S4TypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < S4TypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2342 "Parser.cxx"
    break;

  case 16:
#line 334 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < WeakReferenceTypeNodePtr > () = new WeakReferenceTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < WeakReferenceTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2351 "Parser.cxx"
    break;

  case 17:
#line 340 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < AnyTypeNodePtr > () = new AnyTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < AnyTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2360 "Parser.cxx"
    break;

  case 18:
#line 346 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < VectorTypeNodePtr > () = new VectorTypeNode(std::move(wrap(std::move(yystack_[2].value.as < ScalarTypeNodePtr > ()))));
                                                                yylhs.value.as < VectorTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2369 "Parser.cxx"
    break;

  case 19:
#line 352 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NoNaTypeNodePtr > () = new NoNaTypeNode(std::move(wrap(std::move(yystack_[0].value.as < VectorTypeNodePtr > ()))));
                                                                yylhs.value.as < NoNaTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2378 "Parser.cxx"
    break;

  case 20:
#line 358 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ListTypeNodePtr > () = new ListTypeNode(std::move(wrap(std::move(yystack_[1].value.as < TypeNodeSequenceNodePtr > ()))));
                                                                yylhs.value.as < ListTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2387 "Parser.cxx"
    break;

  case 21:
#line 364 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () = new TypeNodeSequenceNode();
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2396 "Parser.cxx"
    break;

  case 22:
#line 368 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () = new TypeNodeSequenceNode();
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2406 "Parser.cxx"
    break;

  case 23:
#line 373 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () = yystack_[2].value.as < TypeNodeSequenceNodePtr > ();
                                                                yystack_[2].value.as < TypeNodeSequenceNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2417 "Parser.cxx"
    break;

  case 24:
#line 381 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < StructTypeNodePtr > () = new StructTypeNode(std::move(wrap(std::move(yystack_[1].value.as < TagTypePairNodeSequenceNodePtr > ()))));
                                                                yylhs.value.as < StructTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2426 "Parser.cxx"
    break;

  case 25:
#line 387 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TupleTypeNodePtr > () = new TupleTypeNode(std::move(wrap(std::move(yystack_[1].value.as < TypeNodeSequenceNodePtr > ()))));
                                                                yylhs.value.as < TupleTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2435 "Parser.cxx"
    break;

  case 26:
#line 393 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2444 "Parser.cxx"
    break;

  case 27:
#line 397 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2453 "Parser.cxx"
    break;

  case 28:
#line 401 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2462 "Parser.cxx"
    break;

  case 29:
#line 405 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2471 "Parser.cxx"
    break;

  case 30:
#line 409 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2480 "Parser.cxx"
    break;

  case 31:
#line 413 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2489 "Parser.cxx"
    break;

  case 32:
#line 417 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2498 "Parser.cxx"
    break;

  case 33:
#line 421 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2507 "Parser.cxx"
    break;

  case 34:
#line 425 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2516 "Parser.cxx"
    break;

  case 35:
#line 429 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2525 "Parser.cxx"
    break;

  case 36:
#line 433 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2534 "Parser.cxx"
    break;

  case 37:
#line 437 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2543 "Parser.cxx"
    break;

  case 38:
#line 441 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2552 "Parser.cxx"
    break;

  case 39:
#line 445 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2561 "Parser.cxx"
    break;

  case 40:
#line 449 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2570 "Parser.cxx"
    break;

  case 41:
#line 453 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2579 "Parser.cxx"
    break;

  case 42:
#line 457 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2588 "Parser.cxx"
    break;

  case 43:
#line 461 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2597 "Parser.cxx"
    break;

  case 44:
#line 465 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2606 "Parser.cxx"
    break;

  case 45:
#line 471 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TagTypePairNodePtr > () = new TagTypePairNode(std::move(wrap(std::move(yystack_[2].value.as < IdentifierNodePtr > ()))), std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TagTypePairNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2615 "Parser.cxx"
    break;

  case 46:
#line 477 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () = new TagTypePairNodeSequenceNode();
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2624 "Parser.cxx"
    break;

  case 47:
#line 481 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () = new TagTypePairNodeSequenceNode();
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () -> push_back(std::move(wrap(std::move(yystack_[0].value.as < TagTypePairNodePtr > ()))));
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2634 "Parser.cxx"
    break;

  case 48:
#line 486 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () = yystack_[2].value.as < TagTypePairNodeSequenceNodePtr > ();
                                                                yystack_[2].value.as < TagTypePairNodeSequenceNodePtr > () = nullptr;
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () -> push_back(std::move(wrap(std::move(yystack_[0].value.as < TagTypePairNodePtr > ()))));
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2645 "Parser.cxx"
    break;

  case 49:
#line 495 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2655 "Parser.cxx"
    break;

  case 50:
#line 500 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = new VarargTypeNode();
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2664 "Parser.cxx"
    break;

  case 51:
#line 506 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () = new TypeNodeSequenceNode();
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2673 "Parser.cxx"
    break;

  case 52:
#line 510 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () = new TypeNodeSequenceNode();
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2683 "Parser.cxx"
    break;

  case 53:
#line 515 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () = yystack_[2].value.as < TypeNodeSequenceNodePtr > ();
                                                                yystack_[2].value.as < TypeNodeSequenceNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2694 "Parser.cxx"
    break;

  case 54:
#line 523 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < FunctionTypeNodePtr > () = new FunctionTypeNode(std::move(wrap(std::move(yystack_[3].value.as < TypeNodeSequenceNodePtr > ()))), std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < FunctionTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2703 "Parser.cxx"
    break;

  case 55:
#line 528 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < GroupTypeNodePtr > () = new GroupTypeNode(std::move(wrap(std::move(yystack_[1].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < GroupTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2712 "Parser.cxx"
    break;

  case 56:
#line 534 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ScalarTypeNodePtr > ();
                                                                yystack_[0].value.as < ScalarTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2722 "Parser.cxx"
    break;

  case 57:
#line 539 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < EnvironmentTypeNodePtr > ();
                                                                yystack_[0].value.as < EnvironmentTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2732 "Parser.cxx"
    break;

  case 58:
#line 544 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ExpressionTypeNodePtr > ();
                                                                yystack_[0].value.as < ExpressionTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2742 "Parser.cxx"
    break;

  case 59:
#line 549 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < LanguageTypeNodePtr > ();
                                                                yystack_[0].value.as < LanguageTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2752 "Parser.cxx"
    break;

  case 60:
#line 554 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < SymbolTypeNodePtr > ();
                                                                yystack_[0].value.as < SymbolTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2762 "Parser.cxx"
    break;

  case 61:
#line 559 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ExternalPointerTypeNodePtr > ();
                                                                yystack_[0].value.as < ExternalPointerTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2772 "Parser.cxx"
    break;

  case 62:
#line 564 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < BytecodeTypeNodePtr > ();
                                                                yystack_[0].value.as < BytecodeTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2782 "Parser.cxx"
    break;

  case 63:
#line 569 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < PairlistTypeNodePtr > ();
                                                                yystack_[0].value.as < PairlistTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2792 "Parser.cxx"
    break;

  case 64:
#line 574 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < S4TypeNodePtr > ();
                                                                yystack_[0].value.as < S4TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2802 "Parser.cxx"
    break;

  case 65:
#line 579 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < WeakReferenceTypeNodePtr > ();
                                                                yystack_[0].value.as < WeakReferenceTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2812 "Parser.cxx"
    break;

  case 66:
#line 584 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < VectorTypeNodePtr > ();
                                                                yystack_[0].value.as < VectorTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2822 "Parser.cxx"
    break;

  case 67:
#line 589 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < NoNaTypeNodePtr > ();
                                                                yystack_[0].value.as < NoNaTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2832 "Parser.cxx"
    break;

  case 68:
#line 594 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < FunctionTypeNodePtr > ();
                                                                yystack_[0].value.as < FunctionTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2842 "Parser.cxx"
    break;

  case 69:
#line 599 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < StructTypeNodePtr > ();
                                                                yystack_[0].value.as < StructTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2852 "Parser.cxx"
    break;

  case 70:
#line 604 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ListTypeNodePtr > ();
                                                                yystack_[0].value.as < ListTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2862 "Parser.cxx"
    break;

  case 71:
#line 609 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TupleTypeNodePtr > ();
                                                                yystack_[0].value.as < TupleTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2872 "Parser.cxx"
    break;

  case 72:
#line 614 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < GroupTypeNodePtr > ();
                                                                yystack_[0].value.as < GroupTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2882 "Parser.cxx"
    break;

  case 73:
#line 622 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2892 "Parser.cxx"
    break;

  case 74:
#line 627 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = new UnionTypeNode(std::move(wrap(std::move(yystack_[2].value.as < TypeNodePtr > ()))), std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2901 "Parser.cxx"
    break;

  case 75:
#line 634 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = new NullTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2910 "Parser.cxx"
    break;

  case 76:
#line 638 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = new NullableTypeNode(std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2919 "Parser.cxx"
    break;

  case 77:
#line 645 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2929 "Parser.cxx"
    break;

  case 78:
#line 650 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2939 "Parser.cxx"
    break;

  case 79:
#line 655 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < AnyTypeNodePtr > ();
                                                                yystack_[0].value.as < AnyTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2949 "Parser.cxx"
    break;

  case 80:
#line 662 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeDeclarationNodePtr > () = new TypeDeclarationNode(std::move(wrap(std::move(yystack_[2].value.as < IdentifierNodePtr > ()))), std::move(wrap(std::move(yystack_[1].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeDeclarationNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2958 "Parser.cxx"
    break;

  case 81:
#line 668 "Parser.yxx"
                                                            {
                                                                TopLevelNodeUPtr& node(context.get_parse_result().get_top_level_node());
                                                                node -> get_type_declarations().push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeDeclarationNodePtr > ()))));
                                                            }
#line 2967 "Parser.cxx"
    break;

  case 82:
#line 672 "Parser.yxx"
                                                            {
                                                                TopLevelNodeUPtr& node(context.get_parse_result().get_top_level_node());
                                                                node -> get_type_declarations().push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeDeclarationNodePtr > ()))));
                                                            }
#line 2976 "Parser.cxx"
    break;

  case 83:
#line 678 "Parser.yxx"
                                                            { }
#line 2982 "Parser.cxx"
    break;

  case 84:
#line 679 "Parser.yxx"
                                                            {   context.get_parse_result().get_top_level_node() -> set_location(yylhs.location); }
#line 2988 "Parser.cxx"
    break;


#line 2992 "Parser.cxx"

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


  const signed char Parser::yypact_ninf_ = -68;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
       1,   -68,   112,   -68,     2,     8,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,    60,   -68,   -68,   -68,    -7,
      60,    60,    21,    60,   112,    95,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,     0,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,     7,   -68,     4,     0,   -68,     3,   -68,    12,   -68,
     -68,    -1,   -68,    -2,   -68,    -3,     6,     7,    15,    95,
     -68,    60,   -68,   -68,    21,    19,   -68,   112,   -68,    60,
     -68,   -68,   -68,   -68,    60,   -68,   -68,   -68
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    83,     0,    81,     0,     0,    43,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    44,     0,    84,    82,     1,     0,
      21,     0,    51,    21,    46,    75,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    79,    66,    67,    68,    72,    73,    70,    69,
      71,    77,    78,     0,     0,    19,     0,    22,     0,    50,
      52,     0,    49,     0,    47,     0,     0,    76,     0,     0,
      80,     0,    20,    55,     0,     0,    25,     0,    24,     0,
      18,    74,    23,    53,     0,    48,    45,    54
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -68,    10,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,    31,   -68,    28,   -67,   -68,   -63,   -68,   -68,
     -68,   -57,   -68,   -68,   -68,    33,    27,   -68,   -25,    29,
     -68,   -68
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    76,    84,    85,    80,    81,    65,
      66,    67,    68,    69,    70,    86,    71,    72,    77,     3,
       4,     5
  };

  const signed char
  Parser::yytable_[] =
  {
      73,     1,    26,    97,    91,    94,    78,    82,    28,    91,
      89,    88,    92,    95,    96,    98,    36,    37,    38,    39,
      40,    41,    93,    90,   104,    29,    99,   100,    30,    31,
     105,   103,   101,    27,    32,    25,    33,     0,    34,    74,
       2,     2,    79,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      75,    83,    87,     0,    29,     0,   102,    30,    31,    82,
       0,     0,     0,    32,   106,    33,     0,    34,     0,   107,
       0,     0,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    29,
       0,     0,    30,    31,     0,     0,     0,     0,    32,     0,
      33,     0,    34,     0,     0,     0,     0,     0,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,     6,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24
  };

  const signed char
  Parser::yycheck_[] =
  {
      25,     0,     0,     6,     6,     6,    31,    32,     0,     6,
       3,    11,     9,    14,    16,    18,    23,    24,    25,    26,
      27,    28,    10,    19,     5,     4,    20,    12,     7,     8,
      97,    94,    89,     4,    13,     2,    15,    -1,    17,    29,
      39,    39,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      29,    33,    35,    -1,     4,    -1,    91,     7,     8,    94,
      -1,    -1,    -1,    13,    99,    15,    -1,    17,    -1,   104,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,     4,
      -1,    -1,     7,     8,    -1,    -1,    -1,    -1,    13,    -1,
      15,    -1,    17,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     0,    39,    71,    72,    73,    21,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    67,     0,    71,     0,     4,
       7,     8,    13,    15,    17,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    61,    62,    63,    64,    65,
      66,    68,    69,    70,    43,    54,    56,    70,    70,    21,
      59,    60,    70,    56,    57,    58,    67,    68,    11,     3,
      19,     6,     9,    10,     6,    14,    16,     6,    18,    20,
      12,    63,    70,    59,     5,    57,    70,    70
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    42,    43,    43,    43,    43,    43,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      64,    56,    56,    56,    65,    66,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    57,    58,    58,    58,    59,
      59,    60,    60,    60,    61,    62,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    68,    68,    69,    69,    70,    70,    70,
      71,    72,    72,    73,    73
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       3,     0,     1,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     1,     3,     1,
       1,     0,     1,     3,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     1,     1,     1,
       4,     1,     2,     1,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"|\"", "\"!\"", "\"=>\"",
  "\",\"", "\"((\"", "\"(\"", "\"))\"", "\")\"", "\"[\"", "\"]\"", "\"<\"",
  "\">\"", "\"<<\"", "\">>\"", "\"{{\"", "\"}}\"", "\";\"", "\":\"",
  "\"...\"", "\"?\"", "INTEGER", "DOUBLE", "COMPLEX", "CHARACTER",
  "LOGICAL", "RAW", "ENVIRONMENT", "EXPRESSION", "LANGUAGE", "SYMBOL",
  "EXTERNALPOINTER", "BYTECODE", "PAIRLIST", "S4", "WEAKREF", "ANY",
  "TYPEDECL", "IDENTIFIER", "LOWER_THAN_OR", "$accept", "scalartype",
  "environmenttype", "expressiontype", "languagetype", "symboltype",
  "externalptrtype", "bytecodetype", "pairlisttype", "s4type",
  "weakreftype", "anytype", "vectortype", "nonavectortype", "typeseq",
  "namedtype", "namedtypeseq", "paramtype", "paramtypeseq", "functiontype",
  "grouptype", "nonuniontype", "listtype", "structtype", "tupletype",
  "identifier", "innertype", "nulltype", "type", "decltype", "decllist",
  "start", YY_NULLPTR
  };

#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   260,   260,   264,   268,   272,   276,   280,   286,   292,
     298,   304,   310,   316,   322,   328,   334,   340,   346,   352,
     358,   364,   368,   373,   381,   387,   393,   397,   401,   405,
     409,   413,   417,   421,   425,   429,   433,   437,   441,   445,
     449,   453,   457,   461,   465,   471,   477,   481,   486,   495,
     500,   506,   510,   515,   523,   528,   534,   539,   544,   549,
     554,   559,   564,   569,   574,   579,   584,   589,   594,   599,
     604,   609,   614,   622,   627,   634,   638,   645,   650,   655,
     662,   668,   672,   678,   679
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
      35,    36,    37,    38,    39,    40,    41
    };
    const int user_token_number_max_ = 296;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 9 "Parser.yxx"
} } // tastr::parser
#line 3522 "Parser.cxx"

#line 682 "Parser.yxx"


void tastr::parser::Parser::error(const location_type& location, const std::string& message) {
    context.get_parse_result().set_error(location, message);
}
