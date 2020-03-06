// A Bison parser, made by GNU Bison 3.5.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file Parser.hxx
 ** Define the tastr::parser::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_PARSER_HXX_INCLUDED
# define YY_YY_PARSER_HXX_INCLUDED
// "%code requires" blocks.
#line 169 "Parser.yxx"

    namespace tastr::parser {
        class Lexer;
        class ParsingContext;
    }
    #include "parser/location.hh"
    #include "ast/ast.hpp"
    #include "parser/parser.hpp"
    using tastr::ast::CharacterScalarTypeNode;
    using tastr::ast::ComplexScalarTypeNode;
    using tastr::ast::DoubleScalarTypeNode;
    using tastr::ast::ExpressionTypeNode;
    using tastr::ast::ExpressionTypeNodePtr;
    using tastr::ast::EnvironmentTypeNode;
    using tastr::ast::EnvironmentTypeNodePtr;
    using tastr::ast::LanguageTypeNode;
    using tastr::ast::LanguageTypeNodePtr;
    using tastr::ast::SymbolTypeNode;
    using tastr::ast::SymbolTypeNodePtr;
    using tastr::ast::ExternalPointerTypeNode;
    using tastr::ast::ExternalPointerTypeNodePtr;
    using tastr::ast::BytecodeTypeNode;
    using tastr::ast::BytecodeTypeNodePtr;
    using tastr::ast::PairlistTypeNode;
    using tastr::ast::PairlistTypeNodePtr;
    using tastr::ast::S4TypeNode;
    using tastr::ast::S4TypeNodePtr;
    using tastr::ast::WeakReferenceTypeNode;
    using tastr::ast::WeakReferenceTypeNodePtr;
    using tastr::ast::AnyTypeNode;
    using tastr::ast::AnyTypeNodePtr;
    using tastr::ast::FunctionTypeNode;
    using tastr::ast::FunctionTypeNodePtr;
    using tastr::ast::GroupTypeNode;
    using tastr::ast::GroupTypeNodePtr;
    using tastr::ast::IntegerScalarTypeNode;
    using tastr::ast::ListTypeNode;
    using tastr::ast::ListTypeNodePtr;
    using tastr::ast::LogicalScalarTypeNode;
    using tastr::ast::TagTypePairNode;
    using tastr::ast::TagTypePairNodePtr;
    using tastr::ast::TagTypePairNodeUPtr;
    using tastr::ast::NoNaTypeNode;
    using tastr::ast::NoNaTypeNodePtr;
    using tastr::ast::RawScalarTypeNode;
    using tastr::ast::ScalarTypeNodePtr;
    using tastr::ast::ScalarTypeNodeUPtr;
    using tastr::ast::StructTypeNode;
    using tastr::ast::StructTypeNodePtr;
    using tastr::ast::TypeNode;
    using tastr::ast::TypeNodePtr;
    using tastr::ast::TypeNodeUPtr;
    using tastr::ast::UnionTypeNode;
    using tastr::ast::UnionTypeNodePtr;
    using tastr::ast::VectorTypeNode;
    using tastr::ast::VectorTypeNodePtr;
    using tastr::ast::VectorTypeNodeUPtr;
    using tastr::ast::TypeDeclarationNode;
    using tastr::ast::TypeDeclarationNodePtr;
    using tastr::ast::TypeDeclarationNodeUPtr;
    using tastr::ast::TopLevelNodeUPtr;
    using tastr::ast::IdentifierNode;
    using tastr::ast::IdentifierNodePtr;
    using tastr::ast::IdentifierNodeUPtr;
    using tastr::ast::VarargTypeNode;
    using tastr::ast::TypeNodeSequenceNode;
    using tastr::ast::TypeNodeSequenceNodePtr;
    using tastr::ast::TypeNodeSequenceNodeUPtr;
    using tastr::ast::TagTypePairNodeSequenceNode;
    using tastr::ast::TagTypePairNodeSequenceNodePtr;
    using tastr::ast::NullTypeNode;
    using tastr::ast::NullableTypeNode;

#line 122 "Parser.hxx"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 9 "Parser.yxx"
namespace tastr { namespace parser {
#line 257 "Parser.hxx"




  /// A Bison parser.
  class Parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // anytype
      char dummy1[sizeof (AnyTypeNodePtr)];

      // bytecodetype
      char dummy2[sizeof (BytecodeTypeNodePtr)];

      // environmenttype
      char dummy3[sizeof (EnvironmentTypeNodePtr)];

      // expressiontype
      char dummy4[sizeof (ExpressionTypeNodePtr)];

      // externalptrtype
      char dummy5[sizeof (ExternalPointerTypeNodePtr)];

      // functiontype
      char dummy6[sizeof (FunctionTypeNodePtr)];

      // grouptype
      char dummy7[sizeof (GroupTypeNodePtr)];

      // identifier
      char dummy8[sizeof (IdentifierNodePtr)];

      // languagetype
      char dummy9[sizeof (LanguageTypeNodePtr)];

      // listtype
      char dummy10[sizeof (ListTypeNodePtr)];

      // nonavectortype
      char dummy11[sizeof (NoNaTypeNodePtr)];

      // pairlisttype
      char dummy12[sizeof (PairlistTypeNodePtr)];

      // s4type
      char dummy13[sizeof (S4TypeNodePtr)];

      // scalartype
      char dummy14[sizeof (ScalarTypeNodePtr)];

      // structtype
      char dummy15[sizeof (StructTypeNodePtr)];

      // symboltype
      char dummy16[sizeof (SymbolTypeNodePtr)];

      // namedtype
      char dummy17[sizeof (TagTypePairNodePtr)];

      // namedtypeseq
      char dummy18[sizeof (TagTypePairNodeSequenceNodePtr)];

      // decltype
      char dummy19[sizeof (TypeDeclarationNodePtr)];

      // paramtype
      // nonuniontype
      // innertype
      // nulltype
      // type
      char dummy20[sizeof (TypeNodePtr)];

      // typeseq
      // paramtypeseq
      char dummy21[sizeof (TypeNodeSequenceNodePtr)];

      // vectortype
      char dummy22[sizeof (VectorTypeNodePtr)];

      // weakreftype
      char dummy23[sizeof (WeakReferenceTypeNodePtr)];

      // "|"
      // "!"
      // "=>"
      // ","
      // "(("
      // "("
      // "))"
      // ")"
      // "["
      // "]"
      // "<"
      // ">"
      // "{{"
      // "}}"
      // ";"
      // ":"
      // "..."
      // "?"
      // INTEGER
      // DOUBLE
      // COMPLEX
      // CHARACTER
      // LOGICAL
      // RAW
      // ENVIRONMENT
      // EXPRESSION
      // LANGUAGE
      // SYMBOL
      // EXTERNALPOINTER
      // BYTECODE
      // PAIRLIST
      // S4
      // WEAKREF
      // ANY
      // TYPEDECL
      // IDENTIFIER
      char dummy24[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        TOKEN_EOF = 0,
        TOKEN_OR = 258,
        TOKEN_EXCLAMATION = 259,
        TOKEN_ARROW = 260,
        TOKEN_COMMA = 261,
        TOKEN_DOUBLE_LPAREN = 262,
        TOKEN_LPAREN = 263,
        TOKEN_DOUBLE_RPAREN = 264,
        TOKEN_RPAREN = 265,
        TOKEN_LBRACKET = 266,
        TOKEN_RBRACKET = 267,
        TOKEN_LANGLEBRACKET = 268,
        TOKEN_RANGLEBRACKET = 269,
        TOKEN_DOUBLE_LBRACE = 270,
        TOKEN_DOUBLE_RBRACE = 271,
        TOKEN_SEMICOLON = 272,
        TOKEN_COLON = 273,
        TOKEN_VARARG = 274,
        TOKEN_NULLVALUE = 275,
        TOKEN_INTEGER = 276,
        TOKEN_DOUBLE = 277,
        TOKEN_COMPLEX = 278,
        TOKEN_CHARACTER = 279,
        TOKEN_LOGICAL = 280,
        TOKEN_RAW = 281,
        TOKEN_ENVIRONMENT = 282,
        TOKEN_EXPRESSION = 283,
        TOKEN_LANGUAGE = 284,
        TOKEN_SYMBOL = 285,
        TOKEN_EXTERNALPOINTER = 286,
        TOKEN_BYTECODE = 287,
        TOKEN_PAIRLIST = 288,
        TOKEN_S4 = 289,
        TOKEN_WEAKREF = 290,
        TOKEN_ANY = 291,
        TOKEN_TYPEDECL = 292,
        TOKEN_IDENTIFIER = 293,
        TOKEN_LOWER_THAN_OR = 294
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef signed char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AnyTypeNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AnyTypeNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, BytecodeTypeNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const BytecodeTypeNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, EnvironmentTypeNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const EnvironmentTypeNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ExpressionTypeNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ExpressionTypeNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ExternalPointerTypeNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ExternalPointerTypeNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, FunctionTypeNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const FunctionTypeNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, GroupTypeNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const GroupTypeNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, IdentifierNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const IdentifierNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, LanguageTypeNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const LanguageTypeNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ListTypeNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ListTypeNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, NoNaTypeNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const NoNaTypeNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, PairlistTypeNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const PairlistTypeNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, S4TypeNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const S4TypeNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ScalarTypeNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ScalarTypeNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, StructTypeNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const StructTypeNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, SymbolTypeNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const SymbolTypeNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, TagTypePairNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const TagTypePairNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, TagTypePairNodeSequenceNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const TagTypePairNodeSequenceNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, TypeDeclarationNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const TypeDeclarationNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, TypeNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const TypeNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, TypeNodeSequenceNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const TypeNodeSequenceNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, VectorTypeNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const VectorTypeNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, WeakReferenceTypeNodePtr&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const WeakReferenceTypeNodePtr& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_number_type yytype = this->type_get ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yytype)
        {
      case 41: // scalartype
#line 128 "Parser.yxx"
                    { delete yysym.value.template as < ScalarTypeNodePtr > (); }
#line 1041 "Parser.hxx"
        break;

      case 42: // environmenttype
#line 129 "Parser.yxx"
                    { delete yysym.value.template as < EnvironmentTypeNodePtr > (); }
#line 1047 "Parser.hxx"
        break;

      case 43: // expressiontype
#line 130 "Parser.yxx"
                    { delete yysym.value.template as < ExpressionTypeNodePtr > (); }
#line 1053 "Parser.hxx"
        break;

      case 44: // languagetype
#line 131 "Parser.yxx"
                    { delete yysym.value.template as < LanguageTypeNodePtr > (); }
#line 1059 "Parser.hxx"
        break;

      case 45: // symboltype
#line 132 "Parser.yxx"
                    { delete yysym.value.template as < SymbolTypeNodePtr > (); }
#line 1065 "Parser.hxx"
        break;

      case 46: // externalptrtype
#line 133 "Parser.yxx"
                    { delete yysym.value.template as < ExternalPointerTypeNodePtr > (); }
#line 1071 "Parser.hxx"
        break;

      case 47: // bytecodetype
#line 134 "Parser.yxx"
                    { delete yysym.value.template as < BytecodeTypeNodePtr > (); }
#line 1077 "Parser.hxx"
        break;

      case 48: // pairlisttype
#line 135 "Parser.yxx"
                    { delete yysym.value.template as < PairlistTypeNodePtr > (); }
#line 1083 "Parser.hxx"
        break;

      case 49: // s4type
#line 136 "Parser.yxx"
                    { delete yysym.value.template as < S4TypeNodePtr > (); }
#line 1089 "Parser.hxx"
        break;

      case 50: // weakreftype
#line 137 "Parser.yxx"
                    { delete yysym.value.template as < WeakReferenceTypeNodePtr > (); }
#line 1095 "Parser.hxx"
        break;

      case 51: // anytype
#line 138 "Parser.yxx"
                    { delete yysym.value.template as < AnyTypeNodePtr > (); }
#line 1101 "Parser.hxx"
        break;

      case 52: // vectortype
#line 139 "Parser.yxx"
                    { delete yysym.value.template as < VectorTypeNodePtr > (); }
#line 1107 "Parser.hxx"
        break;

      case 53: // nonavectortype
#line 140 "Parser.yxx"
                    { delete yysym.value.template as < NoNaTypeNodePtr > (); }
#line 1113 "Parser.hxx"
        break;

      case 54: // typeseq
#line 141 "Parser.yxx"
                    { delete yysym.value.template as < TypeNodeSequenceNodePtr > (); }
#line 1119 "Parser.hxx"
        break;

      case 55: // namedtype
#line 142 "Parser.yxx"
                    { delete yysym.value.template as < TagTypePairNodePtr > (); }
#line 1125 "Parser.hxx"
        break;

      case 56: // namedtypeseq
#line 143 "Parser.yxx"
                    { delete yysym.value.template as < TagTypePairNodeSequenceNodePtr > (); }
#line 1131 "Parser.hxx"
        break;

      case 57: // paramtype
#line 144 "Parser.yxx"
                    { delete yysym.value.template as < TypeNodePtr > (); }
#line 1137 "Parser.hxx"
        break;

      case 58: // paramtypeseq
#line 145 "Parser.yxx"
                    { delete yysym.value.template as < TypeNodeSequenceNodePtr > (); }
#line 1143 "Parser.hxx"
        break;

      case 59: // functiontype
#line 146 "Parser.yxx"
                    { delete yysym.value.template as < FunctionTypeNodePtr > (); }
#line 1149 "Parser.hxx"
        break;

      case 60: // grouptype
#line 147 "Parser.yxx"
                    { delete yysym.value.template as < GroupTypeNodePtr > (); }
#line 1155 "Parser.hxx"
        break;

      case 61: // nonuniontype
#line 148 "Parser.yxx"
                    { delete yysym.value.template as < TypeNodePtr > (); }
#line 1161 "Parser.hxx"
        break;

      case 62: // listtype
#line 149 "Parser.yxx"
                    { delete yysym.value.template as < ListTypeNodePtr > (); }
#line 1167 "Parser.hxx"
        break;

      case 63: // structtype
#line 150 "Parser.yxx"
                    { delete yysym.value.template as < StructTypeNodePtr > (); }
#line 1173 "Parser.hxx"
        break;

      case 64: // identifier
#line 151 "Parser.yxx"
                    { delete yysym.value.template as < IdentifierNodePtr > (); }
#line 1179 "Parser.hxx"
        break;

      case 65: // innertype
#line 152 "Parser.yxx"
                    { delete yysym.value.template as < TypeNodePtr > (); }
#line 1185 "Parser.hxx"
        break;

      case 66: // nulltype
#line 153 "Parser.yxx"
                    { delete yysym.value.template as < TypeNodePtr > (); }
#line 1191 "Parser.hxx"
        break;

      case 67: // type
#line 154 "Parser.yxx"
                    { delete yysym.value.template as < TypeNodePtr > (); }
#line 1197 "Parser.hxx"
        break;

      case 68: // decltype
#line 155 "Parser.yxx"
                    { delete yysym.value.template as < TypeDeclarationNodePtr > (); }
#line 1203 "Parser.hxx"
        break;

       default:
          break;
        }

        // Type destructor.
switch (yytype)
    {
      case 51: // anytype
        value.template destroy< AnyTypeNodePtr > ();
        break;

      case 47: // bytecodetype
        value.template destroy< BytecodeTypeNodePtr > ();
        break;

      case 42: // environmenttype
        value.template destroy< EnvironmentTypeNodePtr > ();
        break;

      case 43: // expressiontype
        value.template destroy< ExpressionTypeNodePtr > ();
        break;

      case 46: // externalptrtype
        value.template destroy< ExternalPointerTypeNodePtr > ();
        break;

      case 59: // functiontype
        value.template destroy< FunctionTypeNodePtr > ();
        break;

      case 60: // grouptype
        value.template destroy< GroupTypeNodePtr > ();
        break;

      case 64: // identifier
        value.template destroy< IdentifierNodePtr > ();
        break;

      case 44: // languagetype
        value.template destroy< LanguageTypeNodePtr > ();
        break;

      case 62: // listtype
        value.template destroy< ListTypeNodePtr > ();
        break;

      case 53: // nonavectortype
        value.template destroy< NoNaTypeNodePtr > ();
        break;

      case 48: // pairlisttype
        value.template destroy< PairlistTypeNodePtr > ();
        break;

      case 49: // s4type
        value.template destroy< S4TypeNodePtr > ();
        break;

      case 41: // scalartype
        value.template destroy< ScalarTypeNodePtr > ();
        break;

      case 63: // structtype
        value.template destroy< StructTypeNodePtr > ();
        break;

      case 45: // symboltype
        value.template destroy< SymbolTypeNodePtr > ();
        break;

      case 55: // namedtype
        value.template destroy< TagTypePairNodePtr > ();
        break;

      case 56: // namedtypeseq
        value.template destroy< TagTypePairNodeSequenceNodePtr > ();
        break;

      case 68: // decltype
        value.template destroy< TypeDeclarationNodePtr > ();
        break;

      case 57: // paramtype
      case 61: // nonuniontype
      case 65: // innertype
      case 66: // nulltype
      case 67: // type
        value.template destroy< TypeNodePtr > ();
        break;

      case 54: // typeseq
      case 58: // paramtypeseq
        value.template destroy< TypeNodeSequenceNodePtr > ();
        break;

      case 52: // vectortype
        value.template destroy< VectorTypeNodePtr > ();
        break;

      case 50: // weakreftype
        value.template destroy< WeakReferenceTypeNodePtr > ();
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
      case 20: // "?"
      case 21: // INTEGER
      case 22: // DOUBLE
      case 23: // COMPLEX
      case 24: // CHARACTER
      case 25: // LOGICAL
      case 26: // RAW
      case 27: // ENVIRONMENT
      case 28: // EXPRESSION
      case 29: // LANGUAGE
      case 30: // SYMBOL
      case 31: // EXTERNALPOINTER
      case 32: // BYTECODE
      case 33: // PAIRLIST
      case 34: // S4
      case 35: // WEAKREF
      case 36: // ANY
      case 37: // TYPEDECL
      case 38: // IDENTIFIER
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YY_ASSERT (tok == token::TOKEN_EOF || tok == token::TOKEN_LOWER_THAN_OR);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YY_ASSERT (tok == token::TOKEN_EOF || tok == token::TOKEN_LOWER_THAN_OR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOKEN_OR || tok == token::TOKEN_EXCLAMATION || tok == token::TOKEN_ARROW || tok == token::TOKEN_COMMA || tok == token::TOKEN_DOUBLE_LPAREN || tok == token::TOKEN_LPAREN || tok == token::TOKEN_DOUBLE_RPAREN || tok == token::TOKEN_RPAREN || tok == token::TOKEN_LBRACKET || tok == token::TOKEN_RBRACKET || tok == token::TOKEN_LANGLEBRACKET || tok == token::TOKEN_RANGLEBRACKET || tok == token::TOKEN_DOUBLE_LBRACE || tok == token::TOKEN_DOUBLE_RBRACE || tok == token::TOKEN_SEMICOLON || tok == token::TOKEN_COLON || tok == token::TOKEN_VARARG || tok == token::TOKEN_NULLVALUE || tok == token::TOKEN_INTEGER || tok == token::TOKEN_DOUBLE || tok == token::TOKEN_COMPLEX || tok == token::TOKEN_CHARACTER || tok == token::TOKEN_LOGICAL || tok == token::TOKEN_RAW || tok == token::TOKEN_ENVIRONMENT || tok == token::TOKEN_EXPRESSION || tok == token::TOKEN_LANGUAGE || tok == token::TOKEN_SYMBOL || tok == token::TOKEN_EXTERNALPOINTER || tok == token::TOKEN_BYTECODE || tok == token::TOKEN_PAIRLIST || tok == token::TOKEN_S4 || tok == token::TOKEN_WEAKREF || tok == token::TOKEN_ANY || tok == token::TOKEN_TYPEDECL || tok == token::TOKEN_IDENTIFIER);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOKEN_OR || tok == token::TOKEN_EXCLAMATION || tok == token::TOKEN_ARROW || tok == token::TOKEN_COMMA || tok == token::TOKEN_DOUBLE_LPAREN || tok == token::TOKEN_LPAREN || tok == token::TOKEN_DOUBLE_RPAREN || tok == token::TOKEN_RPAREN || tok == token::TOKEN_LBRACKET || tok == token::TOKEN_RBRACKET || tok == token::TOKEN_LANGLEBRACKET || tok == token::TOKEN_RANGLEBRACKET || tok == token::TOKEN_DOUBLE_LBRACE || tok == token::TOKEN_DOUBLE_RBRACE || tok == token::TOKEN_SEMICOLON || tok == token::TOKEN_COLON || tok == token::TOKEN_VARARG || tok == token::TOKEN_NULLVALUE || tok == token::TOKEN_INTEGER || tok == token::TOKEN_DOUBLE || tok == token::TOKEN_COMPLEX || tok == token::TOKEN_CHARACTER || tok == token::TOKEN_LOGICAL || tok == token::TOKEN_RAW || tok == token::TOKEN_ENVIRONMENT || tok == token::TOKEN_EXPRESSION || tok == token::TOKEN_LANGUAGE || tok == token::TOKEN_SYMBOL || tok == token::TOKEN_EXTERNALPOINTER || tok == token::TOKEN_BYTECODE || tok == token::TOKEN_PAIRLIST || tok == token::TOKEN_S4 || tok == token::TOKEN_WEAKREF || tok == token::TOKEN_ANY || tok == token::TOKEN_TYPEDECL || tok == token::TOKEN_IDENTIFIER);
      }
#endif
    };

    /// Build a parser object.
    Parser (tastr::parser::Lexer& lexer_yyarg, tastr::parser::ParsingContext& context_yyarg);
    virtual ~Parser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EOF (location_type l)
      {
        return symbol_type (token::TOKEN_EOF, std::move (l));
      }
#else
      static
      symbol_type
      make_EOF (const location_type& l)
      {
        return symbol_type (token::TOKEN_EOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_OR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_OR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXCLAMATION (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_EXCLAMATION, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EXCLAMATION (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_EXCLAMATION, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARROW (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_ARROW, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ARROW (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_ARROW, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_COMMA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_COMMA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLE_LPAREN (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_DOUBLE_LPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOUBLE_LPAREN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_DOUBLE_LPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_LPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LPAREN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_LPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLE_RPAREN (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_DOUBLE_RPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOUBLE_RPAREN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_DOUBLE_RPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAREN (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_RPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RPAREN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_RPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACKET (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_LBRACKET, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACKET (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_LBRACKET, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACKET (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_RBRACKET, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACKET (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_RBRACKET, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LANGLEBRACKET (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_LANGLEBRACKET, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LANGLEBRACKET (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_LANGLEBRACKET, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RANGLEBRACKET (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_RANGLEBRACKET, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RANGLEBRACKET (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_RANGLEBRACKET, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLE_LBRACE (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_DOUBLE_LBRACE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOUBLE_LBRACE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_DOUBLE_LBRACE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLE_RBRACE (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_DOUBLE_RBRACE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOUBLE_RBRACE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_DOUBLE_RBRACE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_SEMICOLON, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_SEMICOLON, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_COLON, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_COLON, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VARARG (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_VARARG, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VARARG (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_VARARG, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NULLVALUE (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_NULLVALUE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NULLVALUE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_NULLVALUE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTEGER (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_INTEGER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INTEGER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_INTEGER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLE (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_DOUBLE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOUBLE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_DOUBLE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMPLEX (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_COMPLEX, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COMPLEX (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_COMPLEX, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHARACTER (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_CHARACTER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CHARACTER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_CHARACTER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOGICAL (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_LOGICAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LOGICAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_LOGICAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RAW (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_RAW, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RAW (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_RAW, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENVIRONMENT (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_ENVIRONMENT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ENVIRONMENT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_ENVIRONMENT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXPRESSION (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_EXPRESSION, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EXPRESSION (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_EXPRESSION, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LANGUAGE (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_LANGUAGE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LANGUAGE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_LANGUAGE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SYMBOL (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_SYMBOL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SYMBOL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_SYMBOL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXTERNALPOINTER (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_EXTERNALPOINTER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EXTERNALPOINTER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_EXTERNALPOINTER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BYTECODE (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_BYTECODE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BYTECODE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_BYTECODE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PAIRLIST (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_PAIRLIST, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PAIRLIST (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_PAIRLIST, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S4 (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_S4, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_S4 (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_S4, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WEAKREF (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_WEAKREF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_WEAKREF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_WEAKREF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ANY (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_ANY, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ANY (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_ANY, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPEDECL (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_TYPEDECL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TYPEDECL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_TYPEDECL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOWER_THAN_OR (location_type l)
      {
        return symbol_type (token::TOKEN_LOWER_THAN_OR, std::move (l));
      }
#else
      static
      symbol_type
      make_LOWER_THAN_OR (const location_type& l)
      {
        return symbol_type (token::TOKEN_LOWER_THAN_OR, l);
      }
#endif


  private:
    /// This class is not copyable.
    Parser (const Parser&);
    Parser& operator= (const Parser&);

    /// Stored state numbers (used for stacks).
    typedef signed char state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    /// In theory \a t should be a token_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static token_number_type yytranslate_ (int t);

    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const signed char yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      std::ptrdiff_t
      ssize () const YY_NOEXCEPT
      {
        return std::ptrdiff_t (size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Some specific tokens.
    static const token_number_type yy_error_token_ = 1;
    static const token_number_type yy_undef_token_ = 2;

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 132,     ///< Last index in yytable_.
      yynnts_ = 31,  ///< Number of nonterminal symbols.
      yyfinal_ = 28, ///< Termination state number.
      yyntokens_ = 40  ///< Number of tokens.
    };


    // User arguments.
    tastr::parser::Lexer& lexer;
    tastr::parser::ParsingContext& context;
  };


#line 9 "Parser.yxx"
} } // tastr::parser
#line 2375 "Parser.hxx"





#endif // !YY_YY_PARSER_HXX_INCLUDED
