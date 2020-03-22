#ifndef TASTR_AST_NODE_HPP
#define TASTR_AST_NODE_HPP

#include "parser/Location.hpp"

#include <memory>
#include <ostream>

namespace tastr::visitor {

class ConstNodeVisitor;
class MutableNodeVisitor;

} // namespace tastr::visitor

namespace tastr::ast {

class Node {
  public:
    enum Kind {
        AnyType,
        BytecodeType,
        CharacterAScalarType,
        CommaSeparator,
        ComplexAScalarType,
        DoubleAScalarType,
        Empty,
        EnvironmentType,
        Eof,
        ExpressionType,
        ExternalPointerType,
        FunctionType,
        GroupType,
        Identifier,
        IntegerAScalarType,
        Keyword,
        LanguageType,
        ListType,
        LogicalAScalarType,
        NAScalarType,
        NullableType,
        NullType,
        Operator,
        PairlistType,
        Parameter,
        RawAScalarType,
        S4Type,
        Separator,
        StructType,
        SymbolType,
        TagTypePair,
        Terminator,
        TopLevel,
        TupleType,
        TypeDeclaration,
        UnionType,
        UnknownType,
        VarargType,
        VectorType,
        WeakReferenceType
    };

    using count_t = int;

    Node() {
    }

    Node(const Node& node): location_(node.location_) {
    }

    Node(Node&& node): location_(std::move(node.location_)) {
    }

    Node& operator=(const Node& node) {
        if (&node == this) {
            return *this;
        }
        location_ = node.location_;
        return *this;
    }

    Node& operator=(Node&& node) {
        location_ = std::move(node.location_);
        return *this;
    }

    virtual ~Node() {
    }

    virtual void accept(tastr::visitor::ConstNodeVisitor& visitor) const = 0;

    virtual void accept(tastr::visitor::MutableNodeVisitor& visitor) = 0;

    std::unique_ptr<Node> clone() const {
        return std::unique_ptr<Node>(this->clone_impl());
    }

    virtual Kind get_kind() const = 0;

    bool is_character_a_scalar_type_node() const {
        return get_kind() == Kind::CharacterAScalarType;
    }

    bool is_complex_a_scalar_type_node() const {
        return get_kind() == Kind::ComplexAScalarType;
    }

    bool is_double_a_scalar_type_node() const {
        return get_kind() == Kind::DoubleAScalarType;
    }

    bool is_environment_type_node() const {
        return get_kind() == Kind::EnvironmentType;
    }

    bool is_expression_type_node() const {
        return get_kind() == Kind::ExpressionType;
    }

    bool is_function_type_node() const {
        return get_kind() == Kind::FunctionType;
    }

    bool is_group_type_node() const {
        return get_kind() == Kind::GroupType;
    }

    bool is_identifier_node() const {
        return get_kind() == Kind::Identifier;
    }

    bool is_keyword_node() const {
        return get_kind() == Kind::Keyword;
    }

    bool is_operator_node() const {
        return get_kind() == Kind::Operator;
    }

    bool is_separator_node() const {
        return get_kind() == Kind::Separator;
    }

    bool is_integer_a_scalar_type_node() const {
        return get_kind() == Kind::IntegerAScalarType;
    }

    bool is_language_type_node() const {
        return get_kind() == Kind::LanguageType;
    }

    bool is_list_type_node() const {
        return get_kind() == Kind::ListType;
    }

    bool is_logical_a_scalar_type_node() const {
        return get_kind() == Kind::LogicalAScalarType;
    }

    bool is_raw_a_scalar_type_node() const {
        return get_kind() == Kind::RawAScalarType;
    }

    bool is_na_scalar_type_node() const {
        return get_kind() == Kind::NAScalarType;
    }

    bool is_struct_type_node() const {
        return get_kind() == Kind::StructType;
    }

    bool is_tuple_type_node() const {
        return get_kind() == Kind::TupleType;
    }

    bool is_symbol_type_node() const {
        return get_kind() == Kind::SymbolType;
    }

    bool is_external_pointer_type_node() const {
        return get_kind() == Kind::ExternalPointerType;
    }

    bool is_any_type_node() const {
        return get_kind() == Kind::AnyType;
    }

    bool is_unknown_type_node() const {
        return get_kind() == Kind::UnknownType;
    }

    bool is_s4_type_node() const {
        return get_kind() == Kind::S4Type;
    }

    bool is_pairlist_type_node() const {
        return get_kind() == Kind::PairlistType;
    }

    bool is_bytecode_type_node() const {
        return get_kind() == Kind::BytecodeType;
    }

    bool is_weak_reference_type_node() const {
        return get_kind() == Kind::WeakReferenceType;
    }

    bool is_tag_type_pair_node() const {
        return get_kind() == Kind::TagTypePair;
    }

    bool is_type_declaration_node() const {
        return get_kind() == Kind::TypeDeclaration;
    }

    bool is_top_level_node() const {
        return get_kind() == Kind::TopLevel;
    }

    bool is_union_type_node() const {
        return get_kind() == Kind::UnionType;
    }

    bool is_vararg_type_node() const {
        return get_kind() == Kind::VarargType;
    }

    bool is_vector_type_node() const {
        return get_kind() == Kind::VectorType;
    }

    bool is_null_type_node() const {
        return get_kind() == Kind::NullType;
    }

    bool is_nullable_type_node() const {
        return get_kind() == Kind::NullableType;
    }

    bool is_comma_separator_node() const {
        return get_kind() == Kind::CommaSeparator;
    }

    bool is_parameter_node() const {
        return get_kind() == Kind::Parameter;
    }

    bool is_terminator_node() const {
        return get_kind() == Kind::Terminator;
    }

    bool is_empty_node() const {
        return get_kind() == Kind::Empty;
    }

    bool is_eof_node() const {
        return get_kind() == Kind::Eof;
    }

    void set_location(const tastr::parser::Location& location) {
        location_ = location;
    }

    const tastr::parser::Location& get_location() const {
        return location_;
    }

    tastr::parser::Location& get_location() {
        return location_;
    }

  private:
    virtual Node* clone_impl() const = 0;

    tastr::parser::Location location_;
}; // namespace tastr::ast

using NodePtr = Node*;
using NodeUPtr = std::unique_ptr<Node>;

template <typename T>
std::unique_ptr<T> wrap(T*&& t) {
    auto* tmp = t;
    t = nullptr;
    return std::unique_ptr<T>(tmp);
}

template <typename T, typename U>
const T& as(const U& u) {
    return static_cast<const T&>(u);
}

template <typename T, typename U>
const T* as(const U* u) {
    return static_cast<const T*>(u);
}

template <typename T, typename U>
T& as(U& u) {
    return static_cast<T&>(u);
}

template <typename T, typename U>
T* as(U* u) {
    return static_cast<T*>(u);
}

} // namespace tastr::ast

std::ostream& operator<<(std::ostream& os, const tastr::ast::Node::Kind& kind);

std::string to_string(const tastr::ast::Node::Kind& kind);

#endif /* TASTR_AST_NODE_HPP */
