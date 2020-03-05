#ifndef TASTR_AST_COMPLEX_SCALAR_TYPE_NODE_H
#define TASTR_AST_COMPLEX_SCALAR_TYPE_NODE_H

#include "ScalarTypeNode.hpp"

namespace tastr::ast {

class ComplexScalarTypeNode final: public ScalarTypeNode {
  public:
    explicit ComplexScalarTypeNode(const std::string& identifier)
        : ScalarTypeNode(identifier) {
    }

    ~ComplexScalarTypeNode() = default;

    ComplexScalarTypeNode(const ComplexScalarTypeNode& node)
        : ScalarTypeNode(node) {
    }

    ComplexScalarTypeNode(ComplexScalarTypeNode&& node)
        : ScalarTypeNode(std::move(node)) {
    }

    ComplexScalarTypeNode& operator=(const ComplexScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        ScalarTypeNode::operator=(node);
        return *this;
    }

    ComplexScalarTypeNode& operator=(ComplexScalarTypeNode&& node) {
        ScalarTypeNode::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<ComplexScalarTypeNode> clone() const {
        return std::unique_ptr<ComplexScalarTypeNode>(this->clone_impl());
    }

    bool is_complex_scalar_type_node() const override final {
        return true;
    }

  private:
    virtual ComplexScalarTypeNode* clone_impl() const override final {
        return new ComplexScalarTypeNode(*this);
    };
};

using ComplexScalarTypeNodePtr = ComplexScalarTypeNode*;
using ComplexScalarTypeNodeUPtr = std::unique_ptr<ComplexScalarTypeNode>;
} // namespace tastr::ast

#endif /* TASTR_AST_COMPLEX_SCALAR_TYPE_NODE_H */
