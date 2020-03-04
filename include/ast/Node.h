#ifndef TASTR_AST_NODE_H
#define TASTR_AST_NODE_H

#include "location.hh"

#include <memory>

namespace tastr::visitor {
class Visitor;
}

namespace tastr::ast {

class Node {
  public:
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

    virtual void accept(tastr::visitor::Visitor& visitor) const = 0;

    std::unique_ptr<Node> clone() const {
        return std::unique_ptr<Node>(this->clone_impl());
    }

    virtual bool is_character_scalar_type_node() const {
        return false;
    }

    virtual bool is_complex_scalar_type_node() const {
        return false;
    }

    virtual bool is_double_scalar_type_node() const {
        return false;
    }

    virtual bool is_environment_type_node() const {
        return false;
    }

    virtual bool is_expression_type_node() const {
        return false;
    }

    virtual bool is_function_type_node() const {
        return false;
    }

    virtual bool is_group_type_node() const {
        return false;
    }

    virtual bool is_identifier_node() const {
        return false;
    }

    virtual bool is_integer_scalar_type_node() const {
        return false;
    }

    virtual bool is_language_type_node() const {
        return false;
    }

    virtual bool is_list_type_node() const {
        return false;
    }

    virtual bool is_logical_scalar_type_node() const {
        return false;
    }

    virtual bool is_no_na_type_node() const {
        return false;
    }

    virtual bool is_raw_scalar_type_node() const {
        return false;
    }

    virtual bool is_scalar_type_node() const {
        return false;
    }

    virtual bool is_struct_type_node() const {
        return false;
    }

    virtual bool is_symbol_type_node() const {
        return false;
    }

    virtual bool is_any_type_node() const {
        return false;
    }

    virtual bool is_s4_type_node() const {
        return false;
    }

    virtual bool is_pairlist_type_node() const {
        return false;
    }

    virtual bool is_bytecode_type_node() const {
        return false;
    }

    virtual bool is_tag_type_pair_node() const {
        return false;
    }

    virtual bool is_type_declaration_node() const {
        return false;
    }

    virtual bool is_top_level_node() const {
        return false;
    }

    virtual bool is_type_node() const {
        return false;
    }

    virtual bool is_union_type_node() const {
        return false;
    }

    virtual bool is_vararg_type_node() const {
        return false;
    }

    virtual bool is_vector_type_node() const {
        return false;
    }

    virtual bool is_type_declaration_node_sequence_node() const {
        return false;
    }

    virtual bool is_type_node_sequence_node() const {
        return false;
    }

    virtual bool is_tag_type_pair_node_sequence_node() const {
        return false;
    }

    void set_location(const tastr::parser::location& location) {
        location_ = location;
    }

    const tastr::parser::location& get_location() const {
        return location_;
    }

    tastr::parser::location& get_location() {
        return location_;
    }

  private:
    virtual Node* clone_impl() const = 0;

    tastr::parser::location location_;
}; // namespace tastr::ast

using NodePtr = Node*;
using NodeUPtr = std::unique_ptr<Node>;

template <typename T>
std::unique_ptr<T> wrap(T*&& t) {
    auto* tmp = t;
    t = nullptr;
    return std::unique_ptr<T>(tmp);
}

} // namespace tastr::ast

#endif /* TASTR_AST_NODE_H */
