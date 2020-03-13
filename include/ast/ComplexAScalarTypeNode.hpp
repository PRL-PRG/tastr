#ifndef TASTR_AST_COMPLEX_SCALAR_TYPE_NODE_HPP
#define TASTR_AST_COMPLEX_SCALAR_TYPE_NODE_HPP

#include "AScalarTypeNode.hpp"

namespace tastr::ast {

class ComplexAScalarTypeNode final: public AScalarTypeNode {
  public:
    explicit ComplexAScalarTypeNode(const Keyword& keyword)
        : AScalarTypeNode(keyword) {
    }

    ~ComplexAScalarTypeNode() = default;

    ComplexAScalarTypeNode(const ComplexAScalarTypeNode& node)
        : AScalarTypeNode(node) {
    }

    ComplexAScalarTypeNode(ComplexAScalarTypeNode&& node)
        : AScalarTypeNode(std::move(node)) {
    }

    ComplexAScalarTypeNode& operator=(const ComplexAScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        AScalarTypeNode::operator=(node);
        return *this;
    }

    ComplexAScalarTypeNode& operator=(ComplexAScalarTypeNode&& node) {
        AScalarTypeNode::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<ComplexAScalarTypeNode> clone() const {
        return std::unique_ptr<ComplexAScalarTypeNode>(this->clone_impl());
    }

    bool is_complex_a_scalar_type_node() const override final {
        return true;
    }

  private:
    virtual ComplexAScalarTypeNode* clone_impl() const override final {
        return new ComplexAScalarTypeNode(*this);
    };
};

using ComplexAScalarTypeNodePtr = ComplexAScalarTypeNode*;
using ComplexAScalarTypeNodeUPtr = std::unique_ptr<ComplexAScalarTypeNode>;
} // namespace tastr::ast

#endif /* TASTR_AST_COMPLEX_SCALAR_TYPE_NODE_HPP */
