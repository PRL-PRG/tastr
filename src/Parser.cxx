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
#line 229 "Parser.yxx"

    #include "ParsingContext.h"
    #include "Lexer.hpp"
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
      case 47: // anytype
        value.move< AnyTypeNodePtr > (std::move (that.value));
        break;

      case 44: // bytecodetype
        value.move< BytecodeTypeNodePtr > (std::move (that.value));
        break;

      case 39: // environmenttype
        value.move< EnvironmentTypeNodePtr > (std::move (that.value));
        break;

      case 40: // expressiontype
        value.move< ExpressionTypeNodePtr > (std::move (that.value));
        break;

      case 43: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (std::move (that.value));
        break;

      case 55: // functiontype
        value.move< FunctionTypeNodePtr > (std::move (that.value));
        break;

      case 56: // grouptype
        value.move< GroupTypeNodePtr > (std::move (that.value));
        break;

      case 60: // identifier
        value.move< IdentifierNodePtr > (std::move (that.value));
        break;

      case 41: // languagetype
        value.move< LanguageTypeNodePtr > (std::move (that.value));
        break;

      case 58: // listtype
        value.move< ListTypeNodePtr > (std::move (that.value));
        break;

      case 49: // nonavectortype
        value.move< NoNaTypeNodePtr > (std::move (that.value));
        break;

      case 45: // pairlisttype
        value.move< PairlistTypeNodePtr > (std::move (that.value));
        break;

      case 46: // s4type
        value.move< S4TypeNodePtr > (std::move (that.value));
        break;

      case 38: // scalartype
        value.move< ScalarTypeNodePtr > (std::move (that.value));
        break;

      case 59: // structtype
        value.move< StructTypeNodePtr > (std::move (that.value));
        break;

      case 42: // symboltype
        value.move< SymbolTypeNodePtr > (std::move (that.value));
        break;

      case 51: // namedtype
        value.move< TagTypePairNodePtr > (std::move (that.value));
        break;

      case 52: // namedtypeseq
        value.move< TagTypePairNodeSequenceNodePtr > (std::move (that.value));
        break;

      case 62: // decltype
        value.move< TypeDeclarationNodePtr > (std::move (that.value));
        break;

      case 53: // paramtype
      case 57: // nonuniontype
      case 61: // type
        value.move< TypeNodePtr > (std::move (that.value));
        break;

      case 50: // typeseq
      case 54: // paramtypeseq
        value.move< TypeNodeSequenceNodePtr > (std::move (that.value));
        break;

      case 48: // vectortype
        value.move< VectorTypeNodePtr > (std::move (that.value));
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
      case 15: // "{{"
      case 16: // "}}"
      case 17: // ";"
      case 18: // ":"
      case 19: // "..."
      case 20: // INTEGER
      case 21: // DOUBLE
      case 22: // COMPLEX
      case 23: // CHARACTER
      case 24: // LOGICAL
      case 25: // RAW
      case 26: // ENVIRONMENT
      case 27: // EXPRESSION
      case 28: // LANGUAGE
      case 29: // SYMBOL
      case 30: // EXTERNALPOINTER
      case 31: // BYTECODE
      case 32: // PAIRLIST
      case 33: // S4
      case 34: // ANY
      case 35: // TYPEDECL
      case 36: // IDENTIFIER
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
      case 47: // anytype
        value.copy< AnyTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 44: // bytecodetype
        value.copy< BytecodeTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 39: // environmenttype
        value.copy< EnvironmentTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 40: // expressiontype
        value.copy< ExpressionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 43: // externalptrtype
        value.copy< ExternalPointerTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 55: // functiontype
        value.copy< FunctionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 56: // grouptype
        value.copy< GroupTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 60: // identifier
        value.copy< IdentifierNodePtr > (YY_MOVE (that.value));
        break;

      case 41: // languagetype
        value.copy< LanguageTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 58: // listtype
        value.copy< ListTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 49: // nonavectortype
        value.copy< NoNaTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 45: // pairlisttype
        value.copy< PairlistTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 46: // s4type
        value.copy< S4TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 38: // scalartype
        value.copy< ScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 59: // structtype
        value.copy< StructTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 42: // symboltype
        value.copy< SymbolTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 51: // namedtype
        value.copy< TagTypePairNodePtr > (YY_MOVE (that.value));
        break;

      case 52: // namedtypeseq
        value.copy< TagTypePairNodeSequenceNodePtr > (YY_MOVE (that.value));
        break;

      case 62: // decltype
        value.copy< TypeDeclarationNodePtr > (YY_MOVE (that.value));
        break;

      case 53: // paramtype
      case 57: // nonuniontype
      case 61: // type
        value.copy< TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 50: // typeseq
      case 54: // paramtypeseq
        value.copy< TypeNodeSequenceNodePtr > (YY_MOVE (that.value));
        break;

      case 48: // vectortype
        value.copy< VectorTypeNodePtr > (YY_MOVE (that.value));
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
      case 15: // "{{"
      case 16: // "}}"
      case 17: // ";"
      case 18: // ":"
      case 19: // "..."
      case 20: // INTEGER
      case 21: // DOUBLE
      case 22: // COMPLEX
      case 23: // CHARACTER
      case 24: // LOGICAL
      case 25: // RAW
      case 26: // ENVIRONMENT
      case 27: // EXPRESSION
      case 28: // LANGUAGE
      case 29: // SYMBOL
      case 30: // EXTERNALPOINTER
      case 31: // BYTECODE
      case 32: // PAIRLIST
      case 33: // S4
      case 34: // ANY
      case 35: // TYPEDECL
      case 36: // IDENTIFIER
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
      case 47: // anytype
        value.move< AnyTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 44: // bytecodetype
        value.move< BytecodeTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 39: // environmenttype
        value.move< EnvironmentTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 40: // expressiontype
        value.move< ExpressionTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 43: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 55: // functiontype
        value.move< FunctionTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 56: // grouptype
        value.move< GroupTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 60: // identifier
        value.move< IdentifierNodePtr > (YY_MOVE (s.value));
        break;

      case 41: // languagetype
        value.move< LanguageTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 58: // listtype
        value.move< ListTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 49: // nonavectortype
        value.move< NoNaTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 45: // pairlisttype
        value.move< PairlistTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 46: // s4type
        value.move< S4TypeNodePtr > (YY_MOVE (s.value));
        break;

      case 38: // scalartype
        value.move< ScalarTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 59: // structtype
        value.move< StructTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 42: // symboltype
        value.move< SymbolTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 51: // namedtype
        value.move< TagTypePairNodePtr > (YY_MOVE (s.value));
        break;

      case 52: // namedtypeseq
        value.move< TagTypePairNodeSequenceNodePtr > (YY_MOVE (s.value));
        break;

      case 62: // decltype
        value.move< TypeDeclarationNodePtr > (YY_MOVE (s.value));
        break;

      case 53: // paramtype
      case 57: // nonuniontype
      case 61: // type
        value.move< TypeNodePtr > (YY_MOVE (s.value));
        break;

      case 50: // typeseq
      case 54: // paramtypeseq
        value.move< TypeNodeSequenceNodePtr > (YY_MOVE (s.value));
        break;

      case 48: // vectortype
        value.move< VectorTypeNodePtr > (YY_MOVE (s.value));
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
      case 15: // "{{"
      case 16: // "}}"
      case 17: // ";"
      case 18: // ":"
      case 19: // "..."
      case 20: // INTEGER
      case 21: // DOUBLE
      case 22: // COMPLEX
      case 23: // CHARACTER
      case 24: // LOGICAL
      case 25: // RAW
      case 26: // ENVIRONMENT
      case 27: // EXPRESSION
      case 28: // LANGUAGE
      case 29: // SYMBOL
      case 30: // EXTERNALPOINTER
      case 31: // BYTECODE
      case 32: // PAIRLIST
      case 33: // S4
      case 34: // ANY
      case 35: // TYPEDECL
      case 36: // IDENTIFIER
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
      case 47: // anytype
        value.YY_MOVE_OR_COPY< AnyTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 44: // bytecodetype
        value.YY_MOVE_OR_COPY< BytecodeTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 39: // environmenttype
        value.YY_MOVE_OR_COPY< EnvironmentTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 40: // expressiontype
        value.YY_MOVE_OR_COPY< ExpressionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 43: // externalptrtype
        value.YY_MOVE_OR_COPY< ExternalPointerTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 55: // functiontype
        value.YY_MOVE_OR_COPY< FunctionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 56: // grouptype
        value.YY_MOVE_OR_COPY< GroupTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 60: // identifier
        value.YY_MOVE_OR_COPY< IdentifierNodePtr > (YY_MOVE (that.value));
        break;

      case 41: // languagetype
        value.YY_MOVE_OR_COPY< LanguageTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 58: // listtype
        value.YY_MOVE_OR_COPY< ListTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 49: // nonavectortype
        value.YY_MOVE_OR_COPY< NoNaTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 45: // pairlisttype
        value.YY_MOVE_OR_COPY< PairlistTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 46: // s4type
        value.YY_MOVE_OR_COPY< S4TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 38: // scalartype
        value.YY_MOVE_OR_COPY< ScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 59: // structtype
        value.YY_MOVE_OR_COPY< StructTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 42: // symboltype
        value.YY_MOVE_OR_COPY< SymbolTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 51: // namedtype
        value.YY_MOVE_OR_COPY< TagTypePairNodePtr > (YY_MOVE (that.value));
        break;

      case 52: // namedtypeseq
        value.YY_MOVE_OR_COPY< TagTypePairNodeSequenceNodePtr > (YY_MOVE (that.value));
        break;

      case 62: // decltype
        value.YY_MOVE_OR_COPY< TypeDeclarationNodePtr > (YY_MOVE (that.value));
        break;

      case 53: // paramtype
      case 57: // nonuniontype
      case 61: // type
        value.YY_MOVE_OR_COPY< TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 50: // typeseq
      case 54: // paramtypeseq
        value.YY_MOVE_OR_COPY< TypeNodeSequenceNodePtr > (YY_MOVE (that.value));
        break;

      case 48: // vectortype
        value.YY_MOVE_OR_COPY< VectorTypeNodePtr > (YY_MOVE (that.value));
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
      case 15: // "{{"
      case 16: // "}}"
      case 17: // ";"
      case 18: // ":"
      case 19: // "..."
      case 20: // INTEGER
      case 21: // DOUBLE
      case 22: // COMPLEX
      case 23: // CHARACTER
      case 24: // LOGICAL
      case 25: // RAW
      case 26: // ENVIRONMENT
      case 27: // EXPRESSION
      case 28: // LANGUAGE
      case 29: // SYMBOL
      case 30: // EXTERNALPOINTER
      case 31: // BYTECODE
      case 32: // PAIRLIST
      case 33: // S4
      case 34: // ANY
      case 35: // TYPEDECL
      case 36: // IDENTIFIER
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
      case 47: // anytype
        value.move< AnyTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 44: // bytecodetype
        value.move< BytecodeTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 39: // environmenttype
        value.move< EnvironmentTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 40: // expressiontype
        value.move< ExpressionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 43: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 55: // functiontype
        value.move< FunctionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 56: // grouptype
        value.move< GroupTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 60: // identifier
        value.move< IdentifierNodePtr > (YY_MOVE (that.value));
        break;

      case 41: // languagetype
        value.move< LanguageTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 58: // listtype
        value.move< ListTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 49: // nonavectortype
        value.move< NoNaTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 45: // pairlisttype
        value.move< PairlistTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 46: // s4type
        value.move< S4TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 38: // scalartype
        value.move< ScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 59: // structtype
        value.move< StructTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 42: // symboltype
        value.move< SymbolTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 51: // namedtype
        value.move< TagTypePairNodePtr > (YY_MOVE (that.value));
        break;

      case 52: // namedtypeseq
        value.move< TagTypePairNodeSequenceNodePtr > (YY_MOVE (that.value));
        break;

      case 62: // decltype
        value.move< TypeDeclarationNodePtr > (YY_MOVE (that.value));
        break;

      case 53: // paramtype
      case 57: // nonuniontype
      case 61: // type
        value.move< TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 50: // typeseq
      case 54: // paramtypeseq
        value.move< TypeNodeSequenceNodePtr > (YY_MOVE (that.value));
        break;

      case 48: // vectortype
        value.move< VectorTypeNodePtr > (YY_MOVE (that.value));
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
      case 15: // "{{"
      case 16: // "}}"
      case 17: // ";"
      case 18: // ":"
      case 19: // "..."
      case 20: // INTEGER
      case 21: // DOUBLE
      case 22: // COMPLEX
      case 23: // CHARACTER
      case 24: // LOGICAL
      case 25: // RAW
      case 26: // ENVIRONMENT
      case 27: // EXPRESSION
      case 28: // LANGUAGE
      case 29: // SYMBOL
      case 30: // EXTERNALPOINTER
      case 31: // BYTECODE
      case 32: // PAIRLIST
      case 33: // S4
      case 34: // ANY
      case 35: // TYPEDECL
      case 36: // IDENTIFIER
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
      case 47: // anytype
        value.copy< AnyTypeNodePtr > (that.value);
        break;

      case 44: // bytecodetype
        value.copy< BytecodeTypeNodePtr > (that.value);
        break;

      case 39: // environmenttype
        value.copy< EnvironmentTypeNodePtr > (that.value);
        break;

      case 40: // expressiontype
        value.copy< ExpressionTypeNodePtr > (that.value);
        break;

      case 43: // externalptrtype
        value.copy< ExternalPointerTypeNodePtr > (that.value);
        break;

      case 55: // functiontype
        value.copy< FunctionTypeNodePtr > (that.value);
        break;

      case 56: // grouptype
        value.copy< GroupTypeNodePtr > (that.value);
        break;

      case 60: // identifier
        value.copy< IdentifierNodePtr > (that.value);
        break;

      case 41: // languagetype
        value.copy< LanguageTypeNodePtr > (that.value);
        break;

      case 58: // listtype
        value.copy< ListTypeNodePtr > (that.value);
        break;

      case 49: // nonavectortype
        value.copy< NoNaTypeNodePtr > (that.value);
        break;

      case 45: // pairlisttype
        value.copy< PairlistTypeNodePtr > (that.value);
        break;

      case 46: // s4type
        value.copy< S4TypeNodePtr > (that.value);
        break;

      case 38: // scalartype
        value.copy< ScalarTypeNodePtr > (that.value);
        break;

      case 59: // structtype
        value.copy< StructTypeNodePtr > (that.value);
        break;

      case 42: // symboltype
        value.copy< SymbolTypeNodePtr > (that.value);
        break;

      case 51: // namedtype
        value.copy< TagTypePairNodePtr > (that.value);
        break;

      case 52: // namedtypeseq
        value.copy< TagTypePairNodeSequenceNodePtr > (that.value);
        break;

      case 62: // decltype
        value.copy< TypeDeclarationNodePtr > (that.value);
        break;

      case 53: // paramtype
      case 57: // nonuniontype
      case 61: // type
        value.copy< TypeNodePtr > (that.value);
        break;

      case 50: // typeseq
      case 54: // paramtypeseq
        value.copy< TypeNodeSequenceNodePtr > (that.value);
        break;

      case 48: // vectortype
        value.copy< VectorTypeNodePtr > (that.value);
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
      case 15: // "{{"
      case 16: // "}}"
      case 17: // ";"
      case 18: // ":"
      case 19: // "..."
      case 20: // INTEGER
      case 21: // DOUBLE
      case 22: // COMPLEX
      case 23: // CHARACTER
      case 24: // LOGICAL
      case 25: // RAW
      case 26: // ENVIRONMENT
      case 27: // EXPRESSION
      case 28: // LANGUAGE
      case 29: // SYMBOL
      case 30: // EXTERNALPOINTER
      case 31: // BYTECODE
      case 32: // PAIRLIST
      case 33: // S4
      case 34: // ANY
      case 35: // TYPEDECL
      case 36: // IDENTIFIER
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
      case 47: // anytype
        value.move< AnyTypeNodePtr > (that.value);
        break;

      case 44: // bytecodetype
        value.move< BytecodeTypeNodePtr > (that.value);
        break;

      case 39: // environmenttype
        value.move< EnvironmentTypeNodePtr > (that.value);
        break;

      case 40: // expressiontype
        value.move< ExpressionTypeNodePtr > (that.value);
        break;

      case 43: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (that.value);
        break;

      case 55: // functiontype
        value.move< FunctionTypeNodePtr > (that.value);
        break;

      case 56: // grouptype
        value.move< GroupTypeNodePtr > (that.value);
        break;

      case 60: // identifier
        value.move< IdentifierNodePtr > (that.value);
        break;

      case 41: // languagetype
        value.move< LanguageTypeNodePtr > (that.value);
        break;

      case 58: // listtype
        value.move< ListTypeNodePtr > (that.value);
        break;

      case 49: // nonavectortype
        value.move< NoNaTypeNodePtr > (that.value);
        break;

      case 45: // pairlisttype
        value.move< PairlistTypeNodePtr > (that.value);
        break;

      case 46: // s4type
        value.move< S4TypeNodePtr > (that.value);
        break;

      case 38: // scalartype
        value.move< ScalarTypeNodePtr > (that.value);
        break;

      case 59: // structtype
        value.move< StructTypeNodePtr > (that.value);
        break;

      case 42: // symboltype
        value.move< SymbolTypeNodePtr > (that.value);
        break;

      case 51: // namedtype
        value.move< TagTypePairNodePtr > (that.value);
        break;

      case 52: // namedtypeseq
        value.move< TagTypePairNodeSequenceNodePtr > (that.value);
        break;

      case 62: // decltype
        value.move< TypeDeclarationNodePtr > (that.value);
        break;

      case 53: // paramtype
      case 57: // nonuniontype
      case 61: // type
        value.move< TypeNodePtr > (that.value);
        break;

      case 50: // typeseq
      case 54: // paramtypeseq
        value.move< TypeNodeSequenceNodePtr > (that.value);
        break;

      case 48: // vectortype
        value.move< VectorTypeNodePtr > (that.value);
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
      case 15: // "{{"
      case 16: // "}}"
      case 17: // ";"
      case 18: // ":"
      case 19: // "..."
      case 20: // INTEGER
      case 21: // DOUBLE
      case 22: // COMPLEX
      case 23: // CHARACTER
      case 24: // LOGICAL
      case 25: // RAW
      case 26: // ENVIRONMENT
      case 27: // EXPRESSION
      case 28: // LANGUAGE
      case 29: // SYMBOL
      case 30: // EXTERNALPOINTER
      case 31: // BYTECODE
      case 32: // PAIRLIST
      case 33: // S4
      case 34: // ANY
      case 35: // TYPEDECL
      case 36: // IDENTIFIER
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
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1330 "Parser.cxx"
        break;

      case 4: // "!"
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1336 "Parser.cxx"
        break;

      case 5: // "=>"
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1342 "Parser.cxx"
        break;

      case 6: // ","
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1348 "Parser.cxx"
        break;

      case 7: // "(("
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1354 "Parser.cxx"
        break;

      case 8: // "("
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1360 "Parser.cxx"
        break;

      case 9: // "))"
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1366 "Parser.cxx"
        break;

      case 10: // ")"
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1372 "Parser.cxx"
        break;

      case 11: // "["
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1378 "Parser.cxx"
        break;

      case 12: // "]"
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1384 "Parser.cxx"
        break;

      case 13: // "<"
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1390 "Parser.cxx"
        break;

      case 14: // ">"
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1396 "Parser.cxx"
        break;

      case 15: // "{{"
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1402 "Parser.cxx"
        break;

      case 16: // "}}"
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1408 "Parser.cxx"
        break;

      case 17: // ";"
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1414 "Parser.cxx"
        break;

      case 18: // ":"
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1420 "Parser.cxx"
        break;

      case 19: // "..."
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1426 "Parser.cxx"
        break;

      case 20: // INTEGER
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1432 "Parser.cxx"
        break;

      case 21: // DOUBLE
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1438 "Parser.cxx"
        break;

      case 22: // COMPLEX
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1444 "Parser.cxx"
        break;

      case 23: // CHARACTER
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1450 "Parser.cxx"
        break;

      case 24: // LOGICAL
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1456 "Parser.cxx"
        break;

      case 25: // RAW
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1462 "Parser.cxx"
        break;

      case 26: // ENVIRONMENT
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1468 "Parser.cxx"
        break;

      case 27: // EXPRESSION
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1474 "Parser.cxx"
        break;

      case 28: // LANGUAGE
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1480 "Parser.cxx"
        break;

      case 29: // SYMBOL
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1486 "Parser.cxx"
        break;

      case 30: // EXTERNALPOINTER
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1492 "Parser.cxx"
        break;

      case 31: // BYTECODE
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1498 "Parser.cxx"
        break;

      case 32: // PAIRLIST
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1504 "Parser.cxx"
        break;

      case 33: // S4
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1510 "Parser.cxx"
        break;

      case 34: // ANY
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1516 "Parser.cxx"
        break;

      case 35: // TYPEDECL
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1522 "Parser.cxx"
        break;

      case 36: // IDENTIFIER
#line 119 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1528 "Parser.cxx"
        break;

      case 38: // scalartype
#line 97 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < ScalarTypeNodePtr > ()); }
#line 1534 "Parser.cxx"
        break;

      case 39: // environmenttype
#line 98 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < EnvironmentTypeNodePtr > ()); }
#line 1540 "Parser.cxx"
        break;

      case 40: // expressiontype
#line 99 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < ExpressionTypeNodePtr > ()); }
#line 1546 "Parser.cxx"
        break;

      case 41: // languagetype
#line 100 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < LanguageTypeNodePtr > ()); }
#line 1552 "Parser.cxx"
        break;

      case 42: // symboltype
#line 101 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < SymbolTypeNodePtr > ()); }
#line 1558 "Parser.cxx"
        break;

      case 43: // externalptrtype
#line 102 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < ExternalPointerTypeNodePtr > ()); }
#line 1564 "Parser.cxx"
        break;

      case 44: // bytecodetype
#line 103 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < BytecodeTypeNodePtr > ()); }
#line 1570 "Parser.cxx"
        break;

      case 45: // pairlisttype
#line 104 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < PairlistTypeNodePtr > ()); }
#line 1576 "Parser.cxx"
        break;

      case 46: // s4type
#line 105 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < S4TypeNodePtr > ()); }
#line 1582 "Parser.cxx"
        break;

      case 47: // anytype
#line 106 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < AnyTypeNodePtr > ()); }
#line 1588 "Parser.cxx"
        break;

      case 48: // vectortype
#line 107 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < VectorTypeNodePtr > ()); }
#line 1594 "Parser.cxx"
        break;

      case 49: // nonavectortype
#line 108 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < NoNaTypeNodePtr > ()); }
#line 1600 "Parser.cxx"
        break;

      case 50: // typeseq
#line 109 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < TypeNodeSequenceNodePtr > ()); }
#line 1606 "Parser.cxx"
        break;

      case 51: // namedtype
#line 110 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < TagTypePairNodePtr > ()); }
#line 1612 "Parser.cxx"
        break;

      case 52: // namedtypeseq
#line 111 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < TagTypePairNodeSequenceNodePtr > ()); }
#line 1618 "Parser.cxx"
        break;

      case 53: // paramtype
#line 117 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 1624 "Parser.cxx"
        break;

      case 54: // paramtypeseq
#line 109 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < TypeNodeSequenceNodePtr > ()); }
#line 1630 "Parser.cxx"
        break;

      case 55: // functiontype
#line 112 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < FunctionTypeNodePtr > ()); }
#line 1636 "Parser.cxx"
        break;

      case 56: // grouptype
#line 113 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < GroupTypeNodePtr > ()); }
#line 1642 "Parser.cxx"
        break;

      case 57: // nonuniontype
#line 117 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 1648 "Parser.cxx"
        break;

      case 58: // listtype
#line 114 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < ListTypeNodePtr > ()); }
#line 1654 "Parser.cxx"
        break;

      case 59: // structtype
#line 115 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < StructTypeNodePtr > ()); }
#line 1660 "Parser.cxx"
        break;

      case 60: // identifier
#line 116 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < IdentifierNodePtr > ()); }
#line 1666 "Parser.cxx"
        break;

      case 61: // type
#line 117 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 1672 "Parser.cxx"
        break;

      case 62: // decltype
#line 118 "Parser.yxx"
                 { yyo << to_string(*yysym.value.template as < TypeDeclarationNodePtr > ()); }
#line 1678 "Parser.cxx"
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
#line 147 "Parser.yxx"
{
    /* filename for locations here
       https://www.gnu.org/software/bison/manual/html_node/Initial-Action-Decl.html
       location stores pointer to a string allocated elsewhere and does not delete it.
       it has been disabled for now since TopLevelNode stores the filename anyways and
       properly deallocates it.
    */

    /* @$.initialize(context.get_input_stream_name()); */
}

#line 1808 "Parser.cxx"


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
      case 47: // anytype
        yylhs.value.emplace< AnyTypeNodePtr > ();
        break;

      case 44: // bytecodetype
        yylhs.value.emplace< BytecodeTypeNodePtr > ();
        break;

      case 39: // environmenttype
        yylhs.value.emplace< EnvironmentTypeNodePtr > ();
        break;

      case 40: // expressiontype
        yylhs.value.emplace< ExpressionTypeNodePtr > ();
        break;

      case 43: // externalptrtype
        yylhs.value.emplace< ExternalPointerTypeNodePtr > ();
        break;

      case 55: // functiontype
        yylhs.value.emplace< FunctionTypeNodePtr > ();
        break;

      case 56: // grouptype
        yylhs.value.emplace< GroupTypeNodePtr > ();
        break;

      case 60: // identifier
        yylhs.value.emplace< IdentifierNodePtr > ();
        break;

      case 41: // languagetype
        yylhs.value.emplace< LanguageTypeNodePtr > ();
        break;

      case 58: // listtype
        yylhs.value.emplace< ListTypeNodePtr > ();
        break;

      case 49: // nonavectortype
        yylhs.value.emplace< NoNaTypeNodePtr > ();
        break;

      case 45: // pairlisttype
        yylhs.value.emplace< PairlistTypeNodePtr > ();
        break;

      case 46: // s4type
        yylhs.value.emplace< S4TypeNodePtr > ();
        break;

      case 38: // scalartype
        yylhs.value.emplace< ScalarTypeNodePtr > ();
        break;

      case 59: // structtype
        yylhs.value.emplace< StructTypeNodePtr > ();
        break;

      case 42: // symboltype
        yylhs.value.emplace< SymbolTypeNodePtr > ();
        break;

      case 51: // namedtype
        yylhs.value.emplace< TagTypePairNodePtr > ();
        break;

      case 52: // namedtypeseq
        yylhs.value.emplace< TagTypePairNodeSequenceNodePtr > ();
        break;

      case 62: // decltype
        yylhs.value.emplace< TypeDeclarationNodePtr > ();
        break;

      case 53: // paramtype
      case 57: // nonuniontype
      case 61: // type
        yylhs.value.emplace< TypeNodePtr > ();
        break;

      case 50: // typeseq
      case 54: // paramtypeseq
        yylhs.value.emplace< TypeNodeSequenceNodePtr > ();
        break;

      case 48: // vectortype
        yylhs.value.emplace< VectorTypeNodePtr > ();
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
      case 15: // "{{"
      case 16: // "}}"
      case 17: // ";"
      case 18: // ":"
      case 19: // "..."
      case 20: // INTEGER
      case 21: // DOUBLE
      case 22: // COMPLEX
      case 23: // CHARACTER
      case 24: // LOGICAL
      case 25: // RAW
      case 26: // ENVIRONMENT
      case 27: // EXPRESSION
      case 28: // LANGUAGE
      case 29: // SYMBOL
      case 30: // EXTERNALPOINTER
      case 31: // BYTECODE
      case 32: // PAIRLIST
      case 33: // S4
      case 34: // ANY
      case 35: // TYPEDECL
      case 36: // IDENTIFIER
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
#line 238 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = new IntegerScalarTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2065 "Parser.cxx"
    break;

  case 3:
#line 242 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = new DoubleScalarTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2074 "Parser.cxx"
    break;

  case 4:
#line 246 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = new ComplexScalarTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2083 "Parser.cxx"
    break;

  case 5:
#line 250 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = new CharacterScalarTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2092 "Parser.cxx"
    break;

  case 6:
#line 254 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = new LogicalScalarTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2101 "Parser.cxx"
    break;

  case 7:
#line 258 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = new RawScalarTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2110 "Parser.cxx"
    break;

  case 8:
#line 264 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < EnvironmentTypeNodePtr > () = new EnvironmentTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < EnvironmentTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2119 "Parser.cxx"
    break;

  case 9:
#line 270 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ExpressionTypeNodePtr > () = new ExpressionTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ExpressionTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2128 "Parser.cxx"
    break;

  case 10:
#line 276 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < LanguageTypeNodePtr > () = new LanguageTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < LanguageTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2137 "Parser.cxx"
    break;

  case 11:
#line 282 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < SymbolTypeNodePtr > () = new SymbolTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < SymbolTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2146 "Parser.cxx"
    break;

  case 12:
#line 288 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ExternalPointerTypeNodePtr > () = new ExternalPointerTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ExternalPointerTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2155 "Parser.cxx"
    break;

  case 13:
#line 294 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < BytecodeTypeNodePtr > () = new BytecodeTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < BytecodeTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2164 "Parser.cxx"
    break;

  case 14:
#line 300 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < PairlistTypeNodePtr > () = new PairlistTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < PairlistTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2173 "Parser.cxx"
    break;

  case 15:
#line 306 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < S4TypeNodePtr > () = new S4TypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < S4TypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2182 "Parser.cxx"
    break;

  case 16:
#line 312 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < AnyTypeNodePtr > () = new AnyTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < AnyTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2191 "Parser.cxx"
    break;

  case 17:
#line 318 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < VectorTypeNodePtr > () = new VectorTypeNode(std::move(wrap(std::move(yystack_[2].value.as < ScalarTypeNodePtr > ()))));
                                                                yylhs.value.as < VectorTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2200 "Parser.cxx"
    break;

  case 18:
#line 324 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NoNaTypeNodePtr > () = new NoNaTypeNode(std::move(wrap(std::move(yystack_[0].value.as < VectorTypeNodePtr > ()))));
                                                                yylhs.value.as < NoNaTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2209 "Parser.cxx"
    break;

  case 19:
#line 330 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ListTypeNodePtr > () = new ListTypeNode(std::move(wrap(std::move(yystack_[1].value.as < TypeNodeSequenceNodePtr > ()))));
                                                                yylhs.value.as < ListTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2218 "Parser.cxx"
    break;

  case 20:
#line 336 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () = new TypeNodeSequenceNode();
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2227 "Parser.cxx"
    break;

  case 21:
#line 340 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () = new TypeNodeSequenceNode();
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2237 "Parser.cxx"
    break;

  case 22:
#line 345 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () = yystack_[2].value.as < TypeNodeSequenceNodePtr > ();
                                                                yystack_[2].value.as < TypeNodeSequenceNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2248 "Parser.cxx"
    break;

  case 23:
#line 353 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < StructTypeNodePtr > () = new StructTypeNode(std::move(wrap(std::move(yystack_[1].value.as < TagTypePairNodeSequenceNodePtr > ()))));
                                                                yylhs.value.as < StructTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2257 "Parser.cxx"
    break;

  case 24:
#line 360 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2266 "Parser.cxx"
    break;

  case 25:
#line 364 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2275 "Parser.cxx"
    break;

  case 26:
#line 368 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2284 "Parser.cxx"
    break;

  case 27:
#line 372 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2293 "Parser.cxx"
    break;

  case 28:
#line 376 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2302 "Parser.cxx"
    break;

  case 29:
#line 380 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2311 "Parser.cxx"
    break;

  case 30:
#line 384 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2320 "Parser.cxx"
    break;

  case 31:
#line 388 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2329 "Parser.cxx"
    break;

  case 32:
#line 392 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2338 "Parser.cxx"
    break;

  case 33:
#line 396 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2347 "Parser.cxx"
    break;

  case 34:
#line 400 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2356 "Parser.cxx"
    break;

  case 35:
#line 404 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2365 "Parser.cxx"
    break;

  case 36:
#line 408 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2374 "Parser.cxx"
    break;

  case 37:
#line 412 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2383 "Parser.cxx"
    break;

  case 38:
#line 416 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2392 "Parser.cxx"
    break;

  case 39:
#line 420 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2401 "Parser.cxx"
    break;

  case 40:
#line 424 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2410 "Parser.cxx"
    break;

  case 41:
#line 428 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2419 "Parser.cxx"
    break;

  case 42:
#line 434 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TagTypePairNodePtr > () = new TagTypePairNode(std::move(wrap(std::move(yystack_[2].value.as < IdentifierNodePtr > ()))), std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TagTypePairNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2428 "Parser.cxx"
    break;

  case 43:
#line 440 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () = new TagTypePairNodeSequenceNode();
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2437 "Parser.cxx"
    break;

  case 44:
#line 444 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () = new TagTypePairNodeSequenceNode();
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () -> push_back(std::move(wrap(std::move(yystack_[0].value.as < TagTypePairNodePtr > ()))));
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2447 "Parser.cxx"
    break;

  case 45:
#line 449 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () = yystack_[2].value.as < TagTypePairNodeSequenceNodePtr > ();
                                                                yystack_[2].value.as < TagTypePairNodeSequenceNodePtr > () = nullptr;
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () -> push_back(std::move(wrap(std::move(yystack_[0].value.as < TagTypePairNodePtr > ()))));
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2458 "Parser.cxx"
    break;

  case 46:
#line 458 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2468 "Parser.cxx"
    break;

  case 47:
#line 463 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = new VarargTypeNode();
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2477 "Parser.cxx"
    break;

  case 48:
#line 469 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () = new TypeNodeSequenceNode();
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2486 "Parser.cxx"
    break;

  case 49:
#line 473 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () = new TypeNodeSequenceNode();
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2496 "Parser.cxx"
    break;

  case 50:
#line 478 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () = yystack_[2].value.as < TypeNodeSequenceNodePtr > ();
                                                                yystack_[2].value.as < TypeNodeSequenceNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2507 "Parser.cxx"
    break;

  case 51:
#line 486 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < FunctionTypeNodePtr > () = new FunctionTypeNode(std::move(wrap(std::move(yystack_[3].value.as < TypeNodeSequenceNodePtr > ()))), std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < FunctionTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2516 "Parser.cxx"
    break;

  case 52:
#line 491 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < GroupTypeNodePtr > () = new GroupTypeNode(std::move(wrap(std::move(yystack_[1].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < GroupTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2525 "Parser.cxx"
    break;

  case 53:
#line 497 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ScalarTypeNodePtr > ();
                                                                yystack_[0].value.as < ScalarTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2535 "Parser.cxx"
    break;

  case 54:
#line 502 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < EnvironmentTypeNodePtr > ();
                                                                yystack_[0].value.as < EnvironmentTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2545 "Parser.cxx"
    break;

  case 55:
#line 507 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ExpressionTypeNodePtr > ();
                                                                yystack_[0].value.as < ExpressionTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2555 "Parser.cxx"
    break;

  case 56:
#line 512 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < LanguageTypeNodePtr > ();
                                                                yystack_[0].value.as < LanguageTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2565 "Parser.cxx"
    break;

  case 57:
#line 517 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < SymbolTypeNodePtr > ();
                                                                yystack_[0].value.as < SymbolTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2575 "Parser.cxx"
    break;

  case 58:
#line 522 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ExternalPointerTypeNodePtr > ();
                                                                yystack_[0].value.as < ExternalPointerTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2585 "Parser.cxx"
    break;

  case 59:
#line 527 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < BytecodeTypeNodePtr > ();
                                                                yystack_[0].value.as < BytecodeTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2595 "Parser.cxx"
    break;

  case 60:
#line 532 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < PairlistTypeNodePtr > ();
                                                                yystack_[0].value.as < PairlistTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2605 "Parser.cxx"
    break;

  case 61:
#line 537 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < S4TypeNodePtr > ();
                                                                yystack_[0].value.as < S4TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2615 "Parser.cxx"
    break;

  case 62:
#line 542 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < AnyTypeNodePtr > ();
                                                                yystack_[0].value.as < AnyTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2625 "Parser.cxx"
    break;

  case 63:
#line 547 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < VectorTypeNodePtr > ();
                                                                yystack_[0].value.as < VectorTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2635 "Parser.cxx"
    break;

  case 64:
#line 552 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < NoNaTypeNodePtr > ();
                                                                yystack_[0].value.as < NoNaTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2645 "Parser.cxx"
    break;

  case 65:
#line 557 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < FunctionTypeNodePtr > ();
                                                                yystack_[0].value.as < FunctionTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2655 "Parser.cxx"
    break;

  case 66:
#line 562 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < StructTypeNodePtr > ();
                                                                yystack_[0].value.as < StructTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2665 "Parser.cxx"
    break;

  case 67:
#line 567 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ListTypeNodePtr > ();
                                                                yystack_[0].value.as < ListTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2675 "Parser.cxx"
    break;

  case 68:
#line 572 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < GroupTypeNodePtr > ();
                                                                yystack_[0].value.as < GroupTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2685 "Parser.cxx"
    break;

  case 69:
#line 580 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2695 "Parser.cxx"
    break;

  case 70:
#line 585 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = new UnionTypeNode(std::move(wrap(std::move(yystack_[2].value.as < TypeNodePtr > ()))), std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2704 "Parser.cxx"
    break;

  case 71:
#line 592 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeDeclarationNodePtr > () = new TypeDeclarationNode(std::move(wrap(std::move(yystack_[2].value.as < IdentifierNodePtr > ()))), std::move(wrap(std::move(yystack_[1].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeDeclarationNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2713 "Parser.cxx"
    break;

  case 72:
#line 598 "Parser.yxx"
                                                            {
                                                                context.get_top_level_node() -> get_type_declarations().push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeDeclarationNodePtr > ()))));
                                                            }
#line 2721 "Parser.cxx"
    break;

  case 73:
#line 601 "Parser.yxx"
                                                            {
                                                                context.get_top_level_node() -> get_type_declarations().push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeDeclarationNodePtr > ()))));
                                                            }
#line 2729 "Parser.cxx"
    break;

  case 74:
#line 606 "Parser.yxx"
                                                            { }
#line 2735 "Parser.cxx"
    break;

  case 75:
#line 607 "Parser.yxx"
                                                            { context.get_top_level_node() -> set_location(yylhs.location); }
#line 2741 "Parser.cxx"
    break;


#line 2745 "Parser.cxx"

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


  const signed char Parser::yypact_ninf_ = -25;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
       1,   -25,    19,   -25,     2,    10,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,    52,   -25,   -25,   -25,    68,    52,
      52,     0,    19,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,     7,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,    84,     7,   -25,     8,     9,
       6,   -25,   -25,    -3,     9,   -25,    55,    17,    46,    52,
     -25,    52,   -25,   -25,     0,    57,    19,   -25,    52,   -25,
     -25,     9,   -25,    52,   -25,     9,     9
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    74,     0,    72,     0,     0,    40,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    41,     0,    75,    73,     1,     0,    20,
       0,    48,    43,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    68,    69,    67,    66,     0,     0,    18,     0,    21,
       0,    47,    49,     0,    46,    44,     0,     0,     0,     0,
      71,     0,    19,    52,     0,     0,     0,    23,     0,    17,
      70,    22,    50,     0,    45,    42,    51
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -25,    35,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,    38,   -25,   -25,   -18,   -25,   -14,   -25,   -25,   -25,
      15,   -25,   -25,    93,   -24,    92,   -25,   -25
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    68,    75,    76,    72,    73,    60,    61,
      62,    63,    64,    77,    74,     3,     4,     5
  };

  const signed char
  Parser::yytable_[] =
  {
      65,     1,    25,    84,    28,    69,    70,    29,    30,    79,
      27,    85,    79,    31,    81,    32,    83,    82,    78,    71,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    88,     2,     2,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    28,    91,    89,    29,
      30,    86,    93,    66,    95,    31,    67,    32,    94,    96,
      92,    87,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    79,    33,    34,
      35,    36,    37,    38,    90,    24,    26,     0,     0,     0,
       0,    80
  };

  const signed char
  Parser::yycheck_[] =
  {
      24,     0,     0,     6,     4,    29,    30,     7,     8,     3,
       0,    14,     3,    13,     6,    15,    10,     9,    11,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    18,    35,    35,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     4,    81,    12,     7,
       8,     6,     5,    28,    88,    13,    28,    15,    86,    93,
      84,    16,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,     3,    20,    21,
      22,    23,    24,    25,    79,     2,     4,    -1,    -1,    -1,
      -1,    17
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     0,    35,    62,    63,    64,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    60,     0,    62,     0,     4,     7,
       8,    13,    15,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      55,    56,    57,    58,    59,    61,    38,    48,    50,    61,
      61,    19,    53,    54,    61,    51,    52,    60,    11,     3,
      17,     6,     9,    10,     6,    14,     6,    16,    18,    12,
      57,    61,    53,     5,    51,    61,    61
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    37,    38,    38,    38,    38,    38,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    58,
      50,    50,    50,    59,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    51,    52,    52,    52,    53,    53,    54,    54,
      54,    55,    56,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    61,
      61,    62,    63,    63,    64,    64
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     3,
       0,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     0,     1,     3,     1,     1,     0,     1,
       3,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     1,     2,     1,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"|\"", "\"!\"", "\"=>\"",
  "\",\"", "\"((\"", "\"(\"", "\"))\"", "\")\"", "\"[\"", "\"]\"", "\"<\"",
  "\">\"", "\"{{\"", "\"}}\"", "\";\"", "\":\"", "\"...\"", "INTEGER",
  "DOUBLE", "COMPLEX", "CHARACTER", "LOGICAL", "RAW", "ENVIRONMENT",
  "EXPRESSION", "LANGUAGE", "SYMBOL", "EXTERNALPOINTER", "BYTECODE",
  "PAIRLIST", "S4", "ANY", "TYPEDECL", "IDENTIFIER", "$accept",
  "scalartype", "environmenttype", "expressiontype", "languagetype",
  "symboltype", "externalptrtype", "bytecodetype", "pairlisttype",
  "s4type", "anytype", "vectortype", "nonavectortype", "typeseq",
  "namedtype", "namedtypeseq", "paramtype", "paramtypeseq", "functiontype",
  "grouptype", "nonuniontype", "listtype", "structtype", "identifier",
  "type", "decltype", "decllist", "start", YY_NULLPTR
  };

#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   238,   238,   242,   246,   250,   254,   258,   264,   270,
     276,   282,   288,   294,   300,   306,   312,   318,   324,   330,
     336,   340,   345,   353,   360,   364,   368,   372,   376,   380,
     384,   388,   392,   396,   400,   404,   408,   412,   416,   420,
     424,   428,   434,   440,   444,   449,   458,   463,   469,   473,
     478,   486,   491,   497,   502,   507,   512,   517,   522,   527,
     532,   537,   542,   547,   552,   557,   562,   567,   572,   580,
     585,   592,   598,   601,   606,   607
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
      35,    36
    };
    const int user_token_number_max_ = 291;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 9 "Parser.yxx"
} } // tastr::parser
#line 3255 "Parser.cxx"

#line 610 "Parser.yxx"


void tastr::parser::Parser::error(const location_type& location, const std::string& message) {
    std::cout << "Parser Error: " << location << " :: " << message << std::endl;
}
