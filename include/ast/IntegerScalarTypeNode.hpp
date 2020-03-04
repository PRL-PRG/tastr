#ifndef TASTR_AST_INTEGER_SCALAR_TYPE_NODE_H
#define TASTR_AST_INTEGER_SCALAR_TYPE_NODE_H

#include "ScalarTypeNode.hpp"

namespace tastr::ast {

class IntegerScalarTypeNode final: public ScalarTypeNode {
  public:
    IntegerScalarTypeNode(const std::string& identifier)
        : ScalarTypeNode(identifier) {
    }

    ~IntegerScalarTypeNode() = default;

    IntegerScalarTypeNode(const IntegerScalarTypeNode& node)
        : ScalarTypeNode(node) {
    }

    IntegerScalarTypeNode(const IntegerScalarTypeNode&& node)
        : ScalarTypeNode(std::move(node)) {
    }

    IntegerScalarTypeNode& operator=(const IntegerScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        ScalarTypeNode::operator=(node);
        return *this;
    }

    IntegerScalarTypeNode& operator=(IntegerScalarTypeNode&& node) {
        ScalarTypeNode::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<IntegerScalarTypeNode> clone() const {
        return std::unique_ptr<IntegerScalarTypeNode>(this->clone_impl());
    }

    bool is_integer_scalar_type_node() const override final {
        return true;
    }

  private:
    virtual IntegerScalarTypeNode* clone_impl() const override final {
        return new IntegerScalarTypeNode(*this);
    };
};

using IntegerScalarTypeNodePtr = IntegerScalarTypeNode*;
using IntegerScalarTypeNodeUPtr = std::unique_ptr<IntegerScalarTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_INTEGER_SCALAR_TYPE_NODE_H */
