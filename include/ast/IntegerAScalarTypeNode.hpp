#ifndef TASTR_AST_INTEGER_A_SCALAR_TYPE_NODE_HPP
#define TASTR_AST_INTEGER_A_SCALAR_TYPE_NODE_HPP

#include "AScalarTypeNode.hpp"

namespace tastr::ast {

class IntegerAScalarTypeNode final: public AScalarTypeNode {
  public:
    explicit IntegerAScalarTypeNode(const KeywordNode& keyword)
        : AScalarTypeNode(keyword) {
    }

    ~IntegerAScalarTypeNode() = default;

    IntegerAScalarTypeNode(const IntegerAScalarTypeNode& node)
        : AScalarTypeNode(node) {
    }

    IntegerAScalarTypeNode(const IntegerAScalarTypeNode&& node)
        : AScalarTypeNode(std::move(node)) {
    }

    IntegerAScalarTypeNode& operator=(const IntegerAScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        AScalarTypeNode::operator=(node);
        return *this;
    }

    IntegerAScalarTypeNode& operator=(IntegerAScalarTypeNode&& node) {
        AScalarTypeNode::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<IntegerAScalarTypeNode> clone() const {
        return std::unique_ptr<IntegerAScalarTypeNode>(this->clone_impl());
    }

    bool is_integer_a_scalar_type_node() const override final {
        return true;
    }

  private:
    virtual IntegerAScalarTypeNode* clone_impl() const override final {
        return new IntegerAScalarTypeNode(*this);
    };
};

using IntegerAScalarTypeNodePtr = IntegerAScalarTypeNode*;
using IntegerAScalarTypeNodeUPtr = std::unique_ptr<IntegerAScalarTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_INTEGER_A_SCALAR_TYPE_NODE_HPP */
