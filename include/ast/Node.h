#ifndef TASTR_AST_NODE_H
#define TASTR_AST_NODE_H

#include <memory>

namespace tastr::visitor {
class Visitor;
}

namespace tastr::ast {

class Node {
  public:
    Node() {
    }

    Node(const Node& node) {
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

    virtual bool is_tag_type_pair_node() const {
        return false;
    }

    virtual bool is_type_declaration_node() const {
        return false;
    }

    virtual bool is_type_declaration_sequence_node() const {
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

  private:
    virtual Node* clone_impl() const = 0;
}; // namespace tastr::ast

using NodePtr = Node*;
using NodeUPtr = std::unique_ptr<Node>;

} // namespace tastr::ast

#endif /* TASTR_AST_NODE_H */
