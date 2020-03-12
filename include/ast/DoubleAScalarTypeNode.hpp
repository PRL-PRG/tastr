#ifndef TASTR_AST_DOUBLE_SCLAR_TYPE_NODE_HPP
#define TASTR_AST_DOUBLE_SCLAR_TYPE_NODE_HPP

#include "AScalarTypeNode.hpp"

namespace tastr::ast {

class DoubleAScalarTypeNode final: public AScalarTypeNode {
  public:
    explicit DoubleAScalarTypeNode(const Keyword& keyword)
        : AScalarTypeNode(keyword) {
    }

    ~DoubleAScalarTypeNode() = default;

    DoubleAScalarTypeNode(const DoubleAScalarTypeNode& node)
        : AScalarTypeNode(node) {
    }

    DoubleAScalarTypeNode(DoubleAScalarTypeNode&& node)
        : AScalarTypeNode(std::move(node)) {
    }

    DoubleAScalarTypeNode& operator=(const DoubleAScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        AScalarTypeNode::operator=(node);
        return *this;
    }

    DoubleAScalarTypeNode& operator=(DoubleAScalarTypeNode&& node) {
        AScalarTypeNode::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<DoubleAScalarTypeNode> clone() const {
        return std::unique_ptr<DoubleAScalarTypeNode>(this->clone_impl());
    }

    bool is_double_scalar_type_node() const override final {
        return true;
    }

  private:
    virtual DoubleAScalarTypeNode* clone_impl() const override final {
        return new DoubleAScalarTypeNode(*this);
    };
};

using DoubleAScalarTypeNodePtr = DoubleAScalarTypeNode*;
using DoubleAScalarTypeNodeUPtr = std::unique_ptr<DoubleAScalarTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_DOUBLE_SCLAR_TYPE_NODE_HPP */
