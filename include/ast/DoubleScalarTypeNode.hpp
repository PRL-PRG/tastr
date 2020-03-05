#ifndef TASTR_AST_DOUBLE_SCLAR_TYPE_NODE_H
#define TASTR_AST_DOUBLE_SCLAR_TYPE_NODE_H

#include "ScalarTypeNode.hpp"

namespace tastr::ast {

class DoubleScalarTypeNode final: public ScalarTypeNode {
  public:
    explicit DoubleScalarTypeNode(const std::string& identifier)
        : ScalarTypeNode(identifier) {
    }

    ~DoubleScalarTypeNode() = default;

    DoubleScalarTypeNode(const DoubleScalarTypeNode& node)
        : ScalarTypeNode(node) {
    }

    DoubleScalarTypeNode(DoubleScalarTypeNode&& node)
        : ScalarTypeNode(std::move(node)) {
    }

    DoubleScalarTypeNode& operator=(const DoubleScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        ScalarTypeNode::operator=(node);
        return *this;
    }

    DoubleScalarTypeNode& operator=(DoubleScalarTypeNode&& node) {
        ScalarTypeNode::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<DoubleScalarTypeNode> clone() const {
        return std::unique_ptr<DoubleScalarTypeNode>(this->clone_impl());
    }

    bool is_double_scalar_type_node() const override final {
        return true;
    }

  private:
    virtual DoubleScalarTypeNode* clone_impl() const override final {
        return new DoubleScalarTypeNode(*this);
    };
};

using DoubleScalarTypeNodePtr = DoubleScalarTypeNode*;
using DoubleScalarTypeNodeUPtr = std::unique_ptr<DoubleScalarTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_DOUBLE_SCLAR_TYPE_NODE_H */
