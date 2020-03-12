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
#line 250 "Parser.yxx"

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
      case 55: // anytype
        value.move< AnyTypeNodePtr > (std::move (that.value));
        break;

      case 50: // bytecodetype
        value.move< BytecodeTypeNodePtr > (std::move (that.value));
        break;

      case 45: // environmenttype
        value.move< EnvironmentTypeNodePtr > (std::move (that.value));
        break;

      case 46: // expressiontype
        value.move< ExpressionTypeNodePtr > (std::move (that.value));
        break;

      case 49: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (std::move (that.value));
        break;

      case 63: // functiontype
        value.move< FunctionTypeNodePtr > (std::move (that.value));
        break;

      case 64: // grouptype
        value.move< GroupTypeNodePtr > (std::move (that.value));
        break;

      case 69: // identifier
        value.move< IdentifierNodePtr > (std::move (that.value));
        break;

      case 47: // languagetype
        value.move< LanguageTypeNodePtr > (std::move (that.value));
        break;

      case 66: // listtype
        value.move< ListTypeNodePtr > (std::move (that.value));
        break;

      case 57: // nonavectortype
        value.move< NoNaTypeNodePtr > (std::move (that.value));
        break;

      case 51: // pairlisttype
        value.move< PairlistTypeNodePtr > (std::move (that.value));
        break;

      case 52: // s4type
        value.move< S4TypeNodePtr > (std::move (that.value));
        break;

      case 44: // scalartype
        value.move< ScalarTypeNodePtr > (std::move (that.value));
        break;

      case 67: // structtype
        value.move< StructTypeNodePtr > (std::move (that.value));
        break;

      case 48: // symboltype
        value.move< SymbolTypeNodePtr > (std::move (that.value));
        break;

      case 59: // namedtype
        value.move< TagTypePairNodePtr > (std::move (that.value));
        break;

      case 60: // namedtypeseq
        value.move< TagTypePairNodeSequenceNodePtr > (std::move (that.value));
        break;

      case 68: // tupletype
        value.move< TupleTypeNodePtr > (std::move (that.value));
        break;

      case 73: // decltype
        value.move< TypeDeclarationNodePtr > (std::move (that.value));
        break;

      case 61: // paramtype
      case 65: // nonuniontype
      case 70: // innertype
      case 71: // nulltype
      case 72: // type
        value.move< TypeNodePtr > (std::move (that.value));
        break;

      case 58: // typeseq
      case 62: // paramtypeseq
        value.move< TypeNodeSequenceNodePtr > (std::move (that.value));
        break;

      case 54: // unknowntype
        value.move< UnknownTypeNodePtr > (std::move (that.value));
        break;

      case 56: // vectortype
        value.move< VectorTypeNodePtr > (std::move (that.value));
        break;

      case 53: // weakreftype
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
      case 11: // "["
      case 12: // "]"
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
      case 23: // "?"
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
      case 39: // ANY
      case 40: // TYPEDECL
      case 41: // IDENTIFIER
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
      case 55: // anytype
        value.copy< AnyTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 50: // bytecodetype
        value.copy< BytecodeTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 45: // environmenttype
        value.copy< EnvironmentTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 46: // expressiontype
        value.copy< ExpressionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 49: // externalptrtype
        value.copy< ExternalPointerTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 63: // functiontype
        value.copy< FunctionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 64: // grouptype
        value.copy< GroupTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 69: // identifier
        value.copy< IdentifierNodePtr > (YY_MOVE (that.value));
        break;

      case 47: // languagetype
        value.copy< LanguageTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 66: // listtype
        value.copy< ListTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 57: // nonavectortype
        value.copy< NoNaTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 51: // pairlisttype
        value.copy< PairlistTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 52: // s4type
        value.copy< S4TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 44: // scalartype
        value.copy< ScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 67: // structtype
        value.copy< StructTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 48: // symboltype
        value.copy< SymbolTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 59: // namedtype
        value.copy< TagTypePairNodePtr > (YY_MOVE (that.value));
        break;

      case 60: // namedtypeseq
        value.copy< TagTypePairNodeSequenceNodePtr > (YY_MOVE (that.value));
        break;

      case 68: // tupletype
        value.copy< TupleTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 73: // decltype
        value.copy< TypeDeclarationNodePtr > (YY_MOVE (that.value));
        break;

      case 61: // paramtype
      case 65: // nonuniontype
      case 70: // innertype
      case 71: // nulltype
      case 72: // type
        value.copy< TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 58: // typeseq
      case 62: // paramtypeseq
        value.copy< TypeNodeSequenceNodePtr > (YY_MOVE (that.value));
        break;

      case 54: // unknowntype
        value.copy< UnknownTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 56: // vectortype
        value.copy< VectorTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 53: // weakreftype
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
      case 11: // "["
      case 12: // "]"
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
      case 23: // "?"
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
      case 39: // ANY
      case 40: // TYPEDECL
      case 41: // IDENTIFIER
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
      case 55: // anytype
        value.move< AnyTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 50: // bytecodetype
        value.move< BytecodeTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 45: // environmenttype
        value.move< EnvironmentTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 46: // expressiontype
        value.move< ExpressionTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 49: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 63: // functiontype
        value.move< FunctionTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 64: // grouptype
        value.move< GroupTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 69: // identifier
        value.move< IdentifierNodePtr > (YY_MOVE (s.value));
        break;

      case 47: // languagetype
        value.move< LanguageTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 66: // listtype
        value.move< ListTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 57: // nonavectortype
        value.move< NoNaTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 51: // pairlisttype
        value.move< PairlistTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 52: // s4type
        value.move< S4TypeNodePtr > (YY_MOVE (s.value));
        break;

      case 44: // scalartype
        value.move< ScalarTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 67: // structtype
        value.move< StructTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 48: // symboltype
        value.move< SymbolTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 59: // namedtype
        value.move< TagTypePairNodePtr > (YY_MOVE (s.value));
        break;

      case 60: // namedtypeseq
        value.move< TagTypePairNodeSequenceNodePtr > (YY_MOVE (s.value));
        break;

      case 68: // tupletype
        value.move< TupleTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 73: // decltype
        value.move< TypeDeclarationNodePtr > (YY_MOVE (s.value));
        break;

      case 61: // paramtype
      case 65: // nonuniontype
      case 70: // innertype
      case 71: // nulltype
      case 72: // type
        value.move< TypeNodePtr > (YY_MOVE (s.value));
        break;

      case 58: // typeseq
      case 62: // paramtypeseq
        value.move< TypeNodeSequenceNodePtr > (YY_MOVE (s.value));
        break;

      case 54: // unknowntype
        value.move< UnknownTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 56: // vectortype
        value.move< VectorTypeNodePtr > (YY_MOVE (s.value));
        break;

      case 53: // weakreftype
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
      case 11: // "["
      case 12: // "]"
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
      case 23: // "?"
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
      case 39: // ANY
      case 40: // TYPEDECL
      case 41: // IDENTIFIER
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
      case 55: // anytype
        value.YY_MOVE_OR_COPY< AnyTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 50: // bytecodetype
        value.YY_MOVE_OR_COPY< BytecodeTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 45: // environmenttype
        value.YY_MOVE_OR_COPY< EnvironmentTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 46: // expressiontype
        value.YY_MOVE_OR_COPY< ExpressionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 49: // externalptrtype
        value.YY_MOVE_OR_COPY< ExternalPointerTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 63: // functiontype
        value.YY_MOVE_OR_COPY< FunctionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 64: // grouptype
        value.YY_MOVE_OR_COPY< GroupTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 69: // identifier
        value.YY_MOVE_OR_COPY< IdentifierNodePtr > (YY_MOVE (that.value));
        break;

      case 47: // languagetype
        value.YY_MOVE_OR_COPY< LanguageTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 66: // listtype
        value.YY_MOVE_OR_COPY< ListTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 57: // nonavectortype
        value.YY_MOVE_OR_COPY< NoNaTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 51: // pairlisttype
        value.YY_MOVE_OR_COPY< PairlistTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 52: // s4type
        value.YY_MOVE_OR_COPY< S4TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 44: // scalartype
        value.YY_MOVE_OR_COPY< ScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 67: // structtype
        value.YY_MOVE_OR_COPY< StructTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 48: // symboltype
        value.YY_MOVE_OR_COPY< SymbolTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 59: // namedtype
        value.YY_MOVE_OR_COPY< TagTypePairNodePtr > (YY_MOVE (that.value));
        break;

      case 60: // namedtypeseq
        value.YY_MOVE_OR_COPY< TagTypePairNodeSequenceNodePtr > (YY_MOVE (that.value));
        break;

      case 68: // tupletype
        value.YY_MOVE_OR_COPY< TupleTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 73: // decltype
        value.YY_MOVE_OR_COPY< TypeDeclarationNodePtr > (YY_MOVE (that.value));
        break;

      case 61: // paramtype
      case 65: // nonuniontype
      case 70: // innertype
      case 71: // nulltype
      case 72: // type
        value.YY_MOVE_OR_COPY< TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 58: // typeseq
      case 62: // paramtypeseq
        value.YY_MOVE_OR_COPY< TypeNodeSequenceNodePtr > (YY_MOVE (that.value));
        break;

      case 54: // unknowntype
        value.YY_MOVE_OR_COPY< UnknownTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 56: // vectortype
        value.YY_MOVE_OR_COPY< VectorTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 53: // weakreftype
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
      case 11: // "["
      case 12: // "]"
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
      case 23: // "?"
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
      case 39: // ANY
      case 40: // TYPEDECL
      case 41: // IDENTIFIER
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
      case 55: // anytype
        value.move< AnyTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 50: // bytecodetype
        value.move< BytecodeTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 45: // environmenttype
        value.move< EnvironmentTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 46: // expressiontype
        value.move< ExpressionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 49: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 63: // functiontype
        value.move< FunctionTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 64: // grouptype
        value.move< GroupTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 69: // identifier
        value.move< IdentifierNodePtr > (YY_MOVE (that.value));
        break;

      case 47: // languagetype
        value.move< LanguageTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 66: // listtype
        value.move< ListTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 57: // nonavectortype
        value.move< NoNaTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 51: // pairlisttype
        value.move< PairlistTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 52: // s4type
        value.move< S4TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 44: // scalartype
        value.move< ScalarTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 67: // structtype
        value.move< StructTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 48: // symboltype
        value.move< SymbolTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 59: // namedtype
        value.move< TagTypePairNodePtr > (YY_MOVE (that.value));
        break;

      case 60: // namedtypeseq
        value.move< TagTypePairNodeSequenceNodePtr > (YY_MOVE (that.value));
        break;

      case 68: // tupletype
        value.move< TupleTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 73: // decltype
        value.move< TypeDeclarationNodePtr > (YY_MOVE (that.value));
        break;

      case 61: // paramtype
      case 65: // nonuniontype
      case 70: // innertype
      case 71: // nulltype
      case 72: // type
        value.move< TypeNodePtr > (YY_MOVE (that.value));
        break;

      case 58: // typeseq
      case 62: // paramtypeseq
        value.move< TypeNodeSequenceNodePtr > (YY_MOVE (that.value));
        break;

      case 54: // unknowntype
        value.move< UnknownTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 56: // vectortype
        value.move< VectorTypeNodePtr > (YY_MOVE (that.value));
        break;

      case 53: // weakreftype
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
      case 11: // "["
      case 12: // "]"
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
      case 23: // "?"
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
      case 39: // ANY
      case 40: // TYPEDECL
      case 41: // IDENTIFIER
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
      case 55: // anytype
        value.copy< AnyTypeNodePtr > (that.value);
        break;

      case 50: // bytecodetype
        value.copy< BytecodeTypeNodePtr > (that.value);
        break;

      case 45: // environmenttype
        value.copy< EnvironmentTypeNodePtr > (that.value);
        break;

      case 46: // expressiontype
        value.copy< ExpressionTypeNodePtr > (that.value);
        break;

      case 49: // externalptrtype
        value.copy< ExternalPointerTypeNodePtr > (that.value);
        break;

      case 63: // functiontype
        value.copy< FunctionTypeNodePtr > (that.value);
        break;

      case 64: // grouptype
        value.copy< GroupTypeNodePtr > (that.value);
        break;

      case 69: // identifier
        value.copy< IdentifierNodePtr > (that.value);
        break;

      case 47: // languagetype
        value.copy< LanguageTypeNodePtr > (that.value);
        break;

      case 66: // listtype
        value.copy< ListTypeNodePtr > (that.value);
        break;

      case 57: // nonavectortype
        value.copy< NoNaTypeNodePtr > (that.value);
        break;

      case 51: // pairlisttype
        value.copy< PairlistTypeNodePtr > (that.value);
        break;

      case 52: // s4type
        value.copy< S4TypeNodePtr > (that.value);
        break;

      case 44: // scalartype
        value.copy< ScalarTypeNodePtr > (that.value);
        break;

      case 67: // structtype
        value.copy< StructTypeNodePtr > (that.value);
        break;

      case 48: // symboltype
        value.copy< SymbolTypeNodePtr > (that.value);
        break;

      case 59: // namedtype
        value.copy< TagTypePairNodePtr > (that.value);
        break;

      case 60: // namedtypeseq
        value.copy< TagTypePairNodeSequenceNodePtr > (that.value);
        break;

      case 68: // tupletype
        value.copy< TupleTypeNodePtr > (that.value);
        break;

      case 73: // decltype
        value.copy< TypeDeclarationNodePtr > (that.value);
        break;

      case 61: // paramtype
      case 65: // nonuniontype
      case 70: // innertype
      case 71: // nulltype
      case 72: // type
        value.copy< TypeNodePtr > (that.value);
        break;

      case 58: // typeseq
      case 62: // paramtypeseq
        value.copy< TypeNodeSequenceNodePtr > (that.value);
        break;

      case 54: // unknowntype
        value.copy< UnknownTypeNodePtr > (that.value);
        break;

      case 56: // vectortype
        value.copy< VectorTypeNodePtr > (that.value);
        break;

      case 53: // weakreftype
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
      case 11: // "["
      case 12: // "]"
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
      case 23: // "?"
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
      case 39: // ANY
      case 40: // TYPEDECL
      case 41: // IDENTIFIER
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
      case 55: // anytype
        value.move< AnyTypeNodePtr > (that.value);
        break;

      case 50: // bytecodetype
        value.move< BytecodeTypeNodePtr > (that.value);
        break;

      case 45: // environmenttype
        value.move< EnvironmentTypeNodePtr > (that.value);
        break;

      case 46: // expressiontype
        value.move< ExpressionTypeNodePtr > (that.value);
        break;

      case 49: // externalptrtype
        value.move< ExternalPointerTypeNodePtr > (that.value);
        break;

      case 63: // functiontype
        value.move< FunctionTypeNodePtr > (that.value);
        break;

      case 64: // grouptype
        value.move< GroupTypeNodePtr > (that.value);
        break;

      case 69: // identifier
        value.move< IdentifierNodePtr > (that.value);
        break;

      case 47: // languagetype
        value.move< LanguageTypeNodePtr > (that.value);
        break;

      case 66: // listtype
        value.move< ListTypeNodePtr > (that.value);
        break;

      case 57: // nonavectortype
        value.move< NoNaTypeNodePtr > (that.value);
        break;

      case 51: // pairlisttype
        value.move< PairlistTypeNodePtr > (that.value);
        break;

      case 52: // s4type
        value.move< S4TypeNodePtr > (that.value);
        break;

      case 44: // scalartype
        value.move< ScalarTypeNodePtr > (that.value);
        break;

      case 67: // structtype
        value.move< StructTypeNodePtr > (that.value);
        break;

      case 48: // symboltype
        value.move< SymbolTypeNodePtr > (that.value);
        break;

      case 59: // namedtype
        value.move< TagTypePairNodePtr > (that.value);
        break;

      case 60: // namedtypeseq
        value.move< TagTypePairNodeSequenceNodePtr > (that.value);
        break;

      case 68: // tupletype
        value.move< TupleTypeNodePtr > (that.value);
        break;

      case 73: // decltype
        value.move< TypeDeclarationNodePtr > (that.value);
        break;

      case 61: // paramtype
      case 65: // nonuniontype
      case 70: // innertype
      case 71: // nulltype
      case 72: // type
        value.move< TypeNodePtr > (that.value);
        break;

      case 58: // typeseq
      case 62: // paramtypeseq
        value.move< TypeNodeSequenceNodePtr > (that.value);
        break;

      case 54: // unknowntype
        value.move< UnknownTypeNodePtr > (that.value);
        break;

      case 56: // vectortype
        value.move< VectorTypeNodePtr > (that.value);
        break;

      case 53: // weakreftype
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
      case 11: // "["
      case 12: // "]"
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
      case 23: // "?"
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
      case 39: // ANY
      case 40: // TYPEDECL
      case 41: // IDENTIFIER
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
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1463 "Parser.cxx"
        break;

      case 4: // "^"
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1469 "Parser.cxx"
        break;

      case 5: // "=>"
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1475 "Parser.cxx"
        break;

      case 6: // ","
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1481 "Parser.cxx"
        break;

      case 7: // "(("
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1487 "Parser.cxx"
        break;

      case 8: // "("
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1493 "Parser.cxx"
        break;

      case 9: // "))"
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1499 "Parser.cxx"
        break;

      case 10: // ")"
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1505 "Parser.cxx"
        break;

      case 11: // "["
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1511 "Parser.cxx"
        break;

      case 12: // "]"
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1517 "Parser.cxx"
        break;

      case 13: // "<"
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1523 "Parser.cxx"
        break;

      case 14: // ">"
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1529 "Parser.cxx"
        break;

      case 15: // "[["
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1535 "Parser.cxx"
        break;

      case 16: // "]]"
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1541 "Parser.cxx"
        break;

      case 17: // "{{"
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1547 "Parser.cxx"
        break;

      case 18: // "}}"
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1553 "Parser.cxx"
        break;

      case 19: // ";"
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1559 "Parser.cxx"
        break;

      case 20: // ":"
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1565 "Parser.cxx"
        break;

      case 21: // "..."
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1571 "Parser.cxx"
        break;

      case 22: // "???"
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1577 "Parser.cxx"
        break;

      case 23: // "?"
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1583 "Parser.cxx"
        break;

      case 24: // INTEGER
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1589 "Parser.cxx"
        break;

      case 25: // DOUBLE
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1595 "Parser.cxx"
        break;

      case 26: // COMPLEX
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1601 "Parser.cxx"
        break;

      case 27: // CHARACTER
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1607 "Parser.cxx"
        break;

      case 28: // LOGICAL
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1613 "Parser.cxx"
        break;

      case 29: // RAW
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1619 "Parser.cxx"
        break;

      case 30: // ENVIRONMENT
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1625 "Parser.cxx"
        break;

      case 31: // EXPRESSION
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1631 "Parser.cxx"
        break;

      case 32: // LANGUAGE
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1637 "Parser.cxx"
        break;

      case 33: // SYMBOL
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1643 "Parser.cxx"
        break;

      case 34: // EXTERNALPOINTER
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1649 "Parser.cxx"
        break;

      case 35: // BYTECODE
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1655 "Parser.cxx"
        break;

      case 36: // PAIRLIST
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1661 "Parser.cxx"
        break;

      case 37: // S4
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1667 "Parser.cxx"
        break;

      case 38: // WEAKREF
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1673 "Parser.cxx"
        break;

      case 39: // ANY
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1679 "Parser.cxx"
        break;

      case 40: // TYPEDECL
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1685 "Parser.cxx"
        break;

      case 41: // IDENTIFIER
#line 133 "Parser.yxx"
                 { yyo << yysym.value.template as < std::string > (); }
#line 1691 "Parser.cxx"
        break;

      case 44: // scalartype
#line 108 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ScalarTypeNodePtr > ()); }
#line 1697 "Parser.cxx"
        break;

      case 45: // environmenttype
#line 109 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < EnvironmentTypeNodePtr > ()); }
#line 1703 "Parser.cxx"
        break;

      case 46: // expressiontype
#line 110 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ExpressionTypeNodePtr > ()); }
#line 1709 "Parser.cxx"
        break;

      case 47: // languagetype
#line 111 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < LanguageTypeNodePtr > ()); }
#line 1715 "Parser.cxx"
        break;

      case 48: // symboltype
#line 112 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < SymbolTypeNodePtr > ()); }
#line 1721 "Parser.cxx"
        break;

      case 49: // externalptrtype
#line 113 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ExternalPointerTypeNodePtr > ()); }
#line 1727 "Parser.cxx"
        break;

      case 50: // bytecodetype
#line 114 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < BytecodeTypeNodePtr > ()); }
#line 1733 "Parser.cxx"
        break;

      case 51: // pairlisttype
#line 115 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < PairlistTypeNodePtr > ()); }
#line 1739 "Parser.cxx"
        break;

      case 52: // s4type
#line 116 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < S4TypeNodePtr > ()); }
#line 1745 "Parser.cxx"
        break;

      case 53: // weakreftype
#line 117 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < WeakReferenceTypeNodePtr > ()); }
#line 1751 "Parser.cxx"
        break;

      case 54: // unknowntype
#line 119 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < UnknownTypeNodePtr > ()); }
#line 1757 "Parser.cxx"
        break;

      case 55: // anytype
#line 118 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < AnyTypeNodePtr > ()); }
#line 1763 "Parser.cxx"
        break;

      case 56: // vectortype
#line 120 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < VectorTypeNodePtr > ()); }
#line 1769 "Parser.cxx"
        break;

      case 57: // nonavectortype
#line 121 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < NoNaTypeNodePtr > ()); }
#line 1775 "Parser.cxx"
        break;

      case 58: // typeseq
#line 122 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodeSequenceNodePtr > ()); }
#line 1781 "Parser.cxx"
        break;

      case 59: // namedtype
#line 123 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TagTypePairNodePtr > ()); }
#line 1787 "Parser.cxx"
        break;

      case 60: // namedtypeseq
#line 124 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TagTypePairNodeSequenceNodePtr > ()); }
#line 1793 "Parser.cxx"
        break;

      case 61: // paramtype
#line 131 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 1799 "Parser.cxx"
        break;

      case 62: // paramtypeseq
#line 122 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodeSequenceNodePtr > ()); }
#line 1805 "Parser.cxx"
        break;

      case 63: // functiontype
#line 125 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < FunctionTypeNodePtr > ()); }
#line 1811 "Parser.cxx"
        break;

      case 64: // grouptype
#line 126 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < GroupTypeNodePtr > ()); }
#line 1817 "Parser.cxx"
        break;

      case 65: // nonuniontype
#line 131 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 1823 "Parser.cxx"
        break;

      case 66: // listtype
#line 127 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < ListTypeNodePtr > ()); }
#line 1829 "Parser.cxx"
        break;

      case 67: // structtype
#line 128 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < StructTypeNodePtr > ()); }
#line 1835 "Parser.cxx"
        break;

      case 68: // tupletype
#line 129 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TupleTypeNodePtr > ()); }
#line 1841 "Parser.cxx"
        break;

      case 69: // identifier
#line 130 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < IdentifierNodePtr > ()); }
#line 1847 "Parser.cxx"
        break;

      case 70: // innertype
#line 131 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 1853 "Parser.cxx"
        break;

      case 71: // nulltype
#line 131 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 1859 "Parser.cxx"
        break;

      case 72: // type
#line 131 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeNodePtr > ()); }
#line 1865 "Parser.cxx"
        break;

      case 73: // decltype
#line 132 "Parser.yxx"
                 { yyo << tastr::parser::to_string(*yysym.value.template as < TypeDeclarationNodePtr > ()); }
#line 1871 "Parser.cxx"
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
#line 166 "Parser.yxx"
{
    /* filename for locations here
       https://www.gnu.org/software/bison/manual/html_node/Initial-Action-Decl.html
       location stores pointer to a string allocated elsewhere and does not delete it.
       it has been disabled for now since TopLevelNode stores the filename anyways and
       properly deallocates it.
    */

    /* @$.initialize(context.get_input_stream_name()); */
}

#line 2001 "Parser.cxx"


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
      case 55: // anytype
        yylhs.value.emplace< AnyTypeNodePtr > ();
        break;

      case 50: // bytecodetype
        yylhs.value.emplace< BytecodeTypeNodePtr > ();
        break;

      case 45: // environmenttype
        yylhs.value.emplace< EnvironmentTypeNodePtr > ();
        break;

      case 46: // expressiontype
        yylhs.value.emplace< ExpressionTypeNodePtr > ();
        break;

      case 49: // externalptrtype
        yylhs.value.emplace< ExternalPointerTypeNodePtr > ();
        break;

      case 63: // functiontype
        yylhs.value.emplace< FunctionTypeNodePtr > ();
        break;

      case 64: // grouptype
        yylhs.value.emplace< GroupTypeNodePtr > ();
        break;

      case 69: // identifier
        yylhs.value.emplace< IdentifierNodePtr > ();
        break;

      case 47: // languagetype
        yylhs.value.emplace< LanguageTypeNodePtr > ();
        break;

      case 66: // listtype
        yylhs.value.emplace< ListTypeNodePtr > ();
        break;

      case 57: // nonavectortype
        yylhs.value.emplace< NoNaTypeNodePtr > ();
        break;

      case 51: // pairlisttype
        yylhs.value.emplace< PairlistTypeNodePtr > ();
        break;

      case 52: // s4type
        yylhs.value.emplace< S4TypeNodePtr > ();
        break;

      case 44: // scalartype
        yylhs.value.emplace< ScalarTypeNodePtr > ();
        break;

      case 67: // structtype
        yylhs.value.emplace< StructTypeNodePtr > ();
        break;

      case 48: // symboltype
        yylhs.value.emplace< SymbolTypeNodePtr > ();
        break;

      case 59: // namedtype
        yylhs.value.emplace< TagTypePairNodePtr > ();
        break;

      case 60: // namedtypeseq
        yylhs.value.emplace< TagTypePairNodeSequenceNodePtr > ();
        break;

      case 68: // tupletype
        yylhs.value.emplace< TupleTypeNodePtr > ();
        break;

      case 73: // decltype
        yylhs.value.emplace< TypeDeclarationNodePtr > ();
        break;

      case 61: // paramtype
      case 65: // nonuniontype
      case 70: // innertype
      case 71: // nulltype
      case 72: // type
        yylhs.value.emplace< TypeNodePtr > ();
        break;

      case 58: // typeseq
      case 62: // paramtypeseq
        yylhs.value.emplace< TypeNodeSequenceNodePtr > ();
        break;

      case 54: // unknowntype
        yylhs.value.emplace< UnknownTypeNodePtr > ();
        break;

      case 56: // vectortype
        yylhs.value.emplace< VectorTypeNodePtr > ();
        break;

      case 53: // weakreftype
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
      case 11: // "["
      case 12: // "]"
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
      case 23: // "?"
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
      case 39: // ANY
      case 40: // TYPEDECL
      case 41: // IDENTIFIER
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
#line 259 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = new IntegerScalarTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2277 "Parser.cxx"
    break;

  case 3:
#line 263 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = new DoubleScalarTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2286 "Parser.cxx"
    break;

  case 4:
#line 267 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = new ComplexScalarTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2295 "Parser.cxx"
    break;

  case 5:
#line 271 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = new CharacterScalarTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2304 "Parser.cxx"
    break;

  case 6:
#line 275 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = new LogicalScalarTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2313 "Parser.cxx"
    break;

  case 7:
#line 279 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ScalarTypeNodePtr > () = new RawScalarTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ScalarTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2322 "Parser.cxx"
    break;

  case 8:
#line 285 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < EnvironmentTypeNodePtr > () = new EnvironmentTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < EnvironmentTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2331 "Parser.cxx"
    break;

  case 9:
#line 291 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ExpressionTypeNodePtr > () = new ExpressionTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ExpressionTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2340 "Parser.cxx"
    break;

  case 10:
#line 297 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < LanguageTypeNodePtr > () = new LanguageTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < LanguageTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2349 "Parser.cxx"
    break;

  case 11:
#line 303 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < SymbolTypeNodePtr > () = new SymbolTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < SymbolTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2358 "Parser.cxx"
    break;

  case 12:
#line 309 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ExternalPointerTypeNodePtr > () = new ExternalPointerTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < ExternalPointerTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2367 "Parser.cxx"
    break;

  case 13:
#line 315 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < BytecodeTypeNodePtr > () = new BytecodeTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < BytecodeTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2376 "Parser.cxx"
    break;

  case 14:
#line 321 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < PairlistTypeNodePtr > () = new PairlistTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < PairlistTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2385 "Parser.cxx"
    break;

  case 15:
#line 327 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < S4TypeNodePtr > () = new S4TypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < S4TypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2394 "Parser.cxx"
    break;

  case 16:
#line 333 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < WeakReferenceTypeNodePtr > () = new WeakReferenceTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < WeakReferenceTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2403 "Parser.cxx"
    break;

  case 17:
#line 339 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < AnyTypeNodePtr > () = new AnyTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < AnyTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2412 "Parser.cxx"
    break;

  case 18:
#line 345 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < UnknownTypeNodePtr > () = new UnknownTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < UnknownTypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2421 "Parser.cxx"
    break;

  case 19:
#line 351 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < VectorTypeNodePtr > () = new VectorTypeNode(std::move(wrap(std::move(yystack_[2].value.as < ScalarTypeNodePtr > ()))));
                                                                yylhs.value.as < VectorTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2430 "Parser.cxx"
    break;

  case 20:
#line 357 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < NoNaTypeNodePtr > () = new NoNaTypeNode(std::move(wrap(std::move(yystack_[0].value.as < VectorTypeNodePtr > ()))));
                                                                yylhs.value.as < NoNaTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2439 "Parser.cxx"
    break;

  case 21:
#line 363 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < ListTypeNodePtr > () = new ListTypeNode(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > (), std::move(wrap(std::move(yystack_[1].value.as < TypeNodeSequenceNodePtr > ()))));
                                                                yylhs.value.as < ListTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2448 "Parser.cxx"
    break;

  case 22:
#line 369 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () = new TypeNodeSequenceNode(",");
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2457 "Parser.cxx"
    break;

  case 23:
#line 373 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () = new TypeNodeSequenceNode(",");
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2467 "Parser.cxx"
    break;

  case 24:
#line 378 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () = yystack_[2].value.as < TypeNodeSequenceNodePtr > ();
                                                                yystack_[2].value.as < TypeNodeSequenceNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2478 "Parser.cxx"
    break;

  case 25:
#line 386 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < StructTypeNodePtr > () = new StructTypeNode(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > (), std::move(wrap(std::move(yystack_[1].value.as < TagTypePairNodeSequenceNodePtr > ()))));
                                                                yylhs.value.as < StructTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2487 "Parser.cxx"
    break;

  case 26:
#line 392 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TupleTypeNodePtr > () = new TupleTypeNode(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > (), std::move(wrap(std::move(yystack_[1].value.as < TypeNodeSequenceNodePtr > ()))));
                                                                yylhs.value.as < TupleTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2496 "Parser.cxx"
    break;

  case 27:
#line 398 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2505 "Parser.cxx"
    break;

  case 28:
#line 402 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2514 "Parser.cxx"
    break;

  case 29:
#line 406 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2523 "Parser.cxx"
    break;

  case 30:
#line 410 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2532 "Parser.cxx"
    break;

  case 31:
#line 414 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2541 "Parser.cxx"
    break;

  case 32:
#line 418 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2550 "Parser.cxx"
    break;

  case 33:
#line 422 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2559 "Parser.cxx"
    break;

  case 34:
#line 426 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2568 "Parser.cxx"
    break;

  case 35:
#line 430 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2577 "Parser.cxx"
    break;

  case 36:
#line 434 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2586 "Parser.cxx"
    break;

  case 37:
#line 438 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2595 "Parser.cxx"
    break;

  case 38:
#line 442 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2604 "Parser.cxx"
    break;

  case 39:
#line 446 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2613 "Parser.cxx"
    break;

  case 40:
#line 450 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2622 "Parser.cxx"
    break;

  case 41:
#line 454 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2631 "Parser.cxx"
    break;

  case 42:
#line 458 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2640 "Parser.cxx"
    break;

  case 43:
#line 462 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2649 "Parser.cxx"
    break;

  case 44:
#line 466 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2658 "Parser.cxx"
    break;

  case 45:
#line 470 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < IdentifierNodePtr > () = new IdentifierNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < IdentifierNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2667 "Parser.cxx"
    break;

  case 46:
#line 476 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TagTypePairNodePtr > () = new TagTypePairNode(std::move(wrap(std::move(yystack_[2].value.as < IdentifierNodePtr > ()))), std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))), yystack_[1].value.as < std::string > ());
                                                                yylhs.value.as < TagTypePairNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2676 "Parser.cxx"
    break;

  case 47:
#line 482 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () = new TagTypePairNodeSequenceNode(",");
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2685 "Parser.cxx"
    break;

  case 48:
#line 486 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () = new TagTypePairNodeSequenceNode(",");
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () -> push_back(std::move(wrap(std::move(yystack_[0].value.as < TagTypePairNodePtr > ()))));
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2695 "Parser.cxx"
    break;

  case 49:
#line 491 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () = yystack_[2].value.as < TagTypePairNodeSequenceNodePtr > ();
                                                                yystack_[2].value.as < TagTypePairNodeSequenceNodePtr > () = nullptr;
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () -> push_back(std::move(wrap(std::move(yystack_[0].value.as < TagTypePairNodePtr > ()))));
                                                                yylhs.value.as < TagTypePairNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2706 "Parser.cxx"
    break;

  case 50:
#line 500 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2716 "Parser.cxx"
    break;

  case 51:
#line 505 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = new VarargTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yystack_[0].location);
                                                            }
#line 2725 "Parser.cxx"
    break;

  case 52:
#line 511 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () = new TypeNodeSequenceNode(",");
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2734 "Parser.cxx"
    break;

  case 53:
#line 515 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () = new TypeNodeSequenceNode(",");
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2744 "Parser.cxx"
    break;

  case 54:
#line 520 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () = yystack_[2].value.as < TypeNodeSequenceNodePtr > ();
                                                                yystack_[2].value.as < TypeNodeSequenceNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodeSequenceNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2755 "Parser.cxx"
    break;

  case 55:
#line 528 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < FunctionTypeNodePtr > () = new FunctionTypeNode(std::move(wrap(std::move(yystack_[3].value.as < TypeNodeSequenceNodePtr > ()))), std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))), yystack_[1].value.as < std::string > ());
                                                                yylhs.value.as < FunctionTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2764 "Parser.cxx"
    break;

  case 56:
#line 533 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < GroupTypeNodePtr > () = new GroupTypeNode(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > (), std::move(wrap(std::move(yystack_[1].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < GroupTypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2773 "Parser.cxx"
    break;

  case 57:
#line 539 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ScalarTypeNodePtr > ();
                                                                yystack_[0].value.as < ScalarTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2783 "Parser.cxx"
    break;

  case 58:
#line 544 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < EnvironmentTypeNodePtr > ();
                                                                yystack_[0].value.as < EnvironmentTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2793 "Parser.cxx"
    break;

  case 59:
#line 549 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ExpressionTypeNodePtr > ();
                                                                yystack_[0].value.as < ExpressionTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2803 "Parser.cxx"
    break;

  case 60:
#line 554 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < LanguageTypeNodePtr > ();
                                                                yystack_[0].value.as < LanguageTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2813 "Parser.cxx"
    break;

  case 61:
#line 559 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < SymbolTypeNodePtr > ();
                                                                yystack_[0].value.as < SymbolTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2823 "Parser.cxx"
    break;

  case 62:
#line 564 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ExternalPointerTypeNodePtr > ();
                                                                yystack_[0].value.as < ExternalPointerTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2833 "Parser.cxx"
    break;

  case 63:
#line 569 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < BytecodeTypeNodePtr > ();
                                                                yystack_[0].value.as < BytecodeTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2843 "Parser.cxx"
    break;

  case 64:
#line 574 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < PairlistTypeNodePtr > ();
                                                                yystack_[0].value.as < PairlistTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2853 "Parser.cxx"
    break;

  case 65:
#line 579 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < S4TypeNodePtr > ();
                                                                yystack_[0].value.as < S4TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2863 "Parser.cxx"
    break;

  case 66:
#line 584 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < WeakReferenceTypeNodePtr > ();
                                                                yystack_[0].value.as < WeakReferenceTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2873 "Parser.cxx"
    break;

  case 67:
#line 589 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < VectorTypeNodePtr > ();
                                                                yystack_[0].value.as < VectorTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2883 "Parser.cxx"
    break;

  case 68:
#line 594 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < NoNaTypeNodePtr > ();
                                                                yystack_[0].value.as < NoNaTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2893 "Parser.cxx"
    break;

  case 69:
#line 599 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < FunctionTypeNodePtr > ();
                                                                yystack_[0].value.as < FunctionTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2903 "Parser.cxx"
    break;

  case 70:
#line 604 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < StructTypeNodePtr > ();
                                                                yystack_[0].value.as < StructTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2913 "Parser.cxx"
    break;

  case 71:
#line 609 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < ListTypeNodePtr > ();
                                                                yystack_[0].value.as < ListTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2923 "Parser.cxx"
    break;

  case 72:
#line 614 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TupleTypeNodePtr > ();
                                                                yystack_[0].value.as < TupleTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2933 "Parser.cxx"
    break;

  case 73:
#line 619 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < GroupTypeNodePtr > ();
                                                                yystack_[0].value.as < GroupTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2943 "Parser.cxx"
    break;

  case 74:
#line 627 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2953 "Parser.cxx"
    break;

  case 75:
#line 632 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = new UnionTypeNode(std::move(wrap(std::move(yystack_[2].value.as < TypeNodePtr > ()))), std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))), yystack_[1].value.as < std::string > ());
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2962 "Parser.cxx"
    break;

  case 76:
#line 639 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = new NullTypeNode(yystack_[0].value.as < std::string > ());
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2971 "Parser.cxx"
    break;

  case 77:
#line 643 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = new NullableTypeNode(yystack_[1].value.as < std::string > (), std::move(wrap(std::move(yystack_[0].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2980 "Parser.cxx"
    break;

  case 78:
#line 650 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 2990 "Parser.cxx"
    break;

  case 79:
#line 655 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < TypeNodePtr > ();
                                                                yystack_[0].value.as < TypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3000 "Parser.cxx"
    break;

  case 80:
#line 660 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < AnyTypeNodePtr > ();
                                                                yystack_[0].value.as < AnyTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3010 "Parser.cxx"
    break;

  case 81:
#line 665 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeNodePtr > () = yystack_[0].value.as < UnknownTypeNodePtr > ();
                                                                yystack_[0].value.as < UnknownTypeNodePtr > () = nullptr;
                                                                yylhs.value.as < TypeNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3020 "Parser.cxx"
    break;

  case 82:
#line 672 "Parser.yxx"
                                                            {
                                                                yylhs.value.as < TypeDeclarationNodePtr > () = new TypeDeclarationNode(std::move(wrap(std::move(yystack_[2].value.as < IdentifierNodePtr > ()))), std::move(wrap(std::move(yystack_[1].value.as < TypeNodePtr > ()))));
                                                                yylhs.value.as < TypeDeclarationNodePtr > () -> set_location(yylhs.location);
                                                            }
#line 3029 "Parser.cxx"
    break;

  case 83:
#line 678 "Parser.yxx"
                                                            {
                                                                TopLevelNodeUPtr& node(context.get_parse_result().get_top_level_node());
                                                                node -> get_type_declarations().push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeDeclarationNodePtr > ()))));
                                                            }
#line 3038 "Parser.cxx"
    break;

  case 84:
#line 682 "Parser.yxx"
                                                            {
                                                                TopLevelNodeUPtr& node(context.get_parse_result().get_top_level_node());
                                                                node -> get_type_declarations().push_back(std::move(wrap(std::move(yystack_[0].value.as < TypeDeclarationNodePtr > ()))));
                                                            }
#line 3047 "Parser.cxx"
    break;

  case 85:
#line 688 "Parser.yxx"
                                                            { }
#line 3053 "Parser.cxx"
    break;

  case 86:
#line 689 "Parser.yxx"
                                                            {   context.get_parse_result().get_top_level_node() -> set_location(yylhs.location); }
#line 3059 "Parser.cxx"
    break;


#line 3063 "Parser.cxx"

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


  const signed char Parser::yypact_ninf_ = -26;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
       1,   -26,   -16,   -26,     2,     3,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,    62,   -26,   -26,   -26,    92,
      62,    62,    22,    62,   -16,   -26,    98,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,    -7,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,    24,   -26,     9,    -7,   -26,    25,   -26,
      23,   -26,   -26,    26,   -26,    57,   -26,    56,    16,    24,
      52,    98,   -26,    62,   -26,   -26,    22,    33,   -26,   -16,
     -26,    62,   -26,   -26,   -26,   -26,    62,   -26,   -26,   -26
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    85,     0,    83,     0,     0,    44,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    45,     0,    86,    84,     1,     0,
      22,     0,    52,    22,    47,    18,    76,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    81,    80,    67,    68,    69,    73,    74,
      71,    70,    72,    78,    79,     0,     0,    20,     0,    23,
       0,    51,    53,     0,    50,     0,    48,     0,     0,    77,
       0,     0,    82,     0,    21,    56,     0,     0,    26,     0,
      25,     0,    19,    75,    24,    54,     0,    49,    46,    55
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -26,    36,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,    38,   -26,    39,   -21,   -26,   -14,   -26,
     -26,   -26,   -11,   -26,   -26,   -26,    81,    67,   -26,   -25,
     100,   -26,   -26
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    78,    86,    87,    82,    83,
      67,    68,    69,    70,    71,    72,    88,    73,    74,    79,
       3,     4,     5
  };

  const signed char
  Parser::yytable_[] =
  {
      75,     1,    26,    28,    90,     6,    80,    84,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    29,    91,    92,    30,
      31,    93,    96,    95,    94,    32,   101,    33,   106,    34,
      97,     2,     2,    81,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    99,    93,   102,    76,    29,    77,   104,    30,
      31,    84,    85,    98,   100,    32,   108,    33,   107,    34,
     103,   109,   105,    25,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    29,    89,    27,    30,    31,     0,     0,     0,
       0,    32,     0,    33,     0,    34,    37,    38,    39,    40,
      41,    42,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
  };

  const signed char
  Parser::yycheck_[] =
  {
      25,     0,     0,     0,    11,    21,    31,    32,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     4,     3,    19,     7,
       8,     6,     6,    10,     9,    13,    20,    15,     5,    17,
      14,    40,    40,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     6,     6,    12,    29,     4,    29,    93,     7,
       8,    96,    33,    16,    18,    13,   101,    15,    99,    17,
      91,   106,    96,     2,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     4,    36,     4,     7,     8,    -1,    -1,    -1,
      -1,    13,    -1,    15,    -1,    17,    24,    25,    26,    27,
      28,    29,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     0,    40,    73,    74,    75,    21,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    69,     0,    73,     0,     4,
       7,     8,    13,    15,    17,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    63,    64,    65,
      66,    67,    68,    70,    71,    72,    44,    56,    58,    72,
      72,    21,    61,    62,    72,    58,    59,    60,    69,    70,
      11,     3,    19,     6,     9,    10,     6,    14,    16,     6,
      18,    20,    12,    65,    72,    61,     5,    59,    72,    72
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    43,    44,    44,    44,    44,    44,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    55,    54,    56,
      57,    66,    58,    58,    58,    67,    68,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    59,    60,    60,    60,
      61,    61,    62,    62,    62,    63,    64,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    70,    70,    71,    71,    72,    72,
      72,    72,    73,    74,    74,    75,    75
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     0,     1,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     0,     1,     3,
       1,     1,     0,     1,     3,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     1,     1,
       1,     1,     4,     1,     2,     1,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"|\"", "\"^\"", "\"=>\"",
  "\",\"", "\"((\"", "\"(\"", "\"))\"", "\")\"", "\"[\"", "\"]\"", "\"<\"",
  "\">\"", "\"[[\"", "\"]]\"", "\"{{\"", "\"}}\"", "\";\"", "\":\"",
  "\"...\"", "\"???\"", "\"?\"", "INTEGER", "DOUBLE", "COMPLEX",
  "CHARACTER", "LOGICAL", "RAW", "ENVIRONMENT", "EXPRESSION", "LANGUAGE",
  "SYMBOL", "EXTERNALPOINTER", "BYTECODE", "PAIRLIST", "S4", "WEAKREF",
  "ANY", "TYPEDECL", "IDENTIFIER", "LOWER_THAN_OR", "$accept",
  "scalartype", "environmenttype", "expressiontype", "languagetype",
  "symboltype", "externalptrtype", "bytecodetype", "pairlisttype",
  "s4type", "weakreftype", "unknowntype", "anytype", "vectortype",
  "nonavectortype", "typeseq", "namedtype", "namedtypeseq", "paramtype",
  "paramtypeseq", "functiontype", "grouptype", "nonuniontype", "listtype",
  "structtype", "tupletype", "identifier", "innertype", "nulltype", "type",
  "decltype", "decllist", "start", YY_NULLPTR
  };

#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   259,   259,   263,   267,   271,   275,   279,   285,   291,
     297,   303,   309,   315,   321,   327,   333,   339,   345,   351,
     357,   363,   369,   373,   378,   386,   392,   398,   402,   406,
     410,   414,   418,   422,   426,   430,   434,   438,   442,   446,
     450,   454,   458,   462,   466,   470,   476,   482,   486,   491,
     500,   505,   511,   515,   520,   528,   533,   539,   544,   549,
     554,   559,   564,   569,   574,   579,   584,   589,   594,   599,
     604,   609,   614,   619,   627,   632,   639,   643,   650,   655,
     660,   665,   672,   678,   682,   688,   689
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
      35,    36,    37,    38,    39,    40,    41,    42
    };
    const int user_token_number_max_ = 297;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 9 "Parser.yxx"
} } // tastr::parser
#line 3589 "Parser.cxx"

#line 692 "Parser.yxx"


void tastr::parser::Parser::error(const location_type& location, const std::string& message) {
    context.get_parse_result().set_error(location, message);
}
