#ifndef TASTR_AST_EXPRESSION_TYPE_NODE_H
#define TASTR_AST_EXPRESSION_TYPE_NODE_H

#include "TypeNode.hpp"

namespace tastr::ast {

class ExpressionTypeNode final: public TypeNode {
  public:
    ExpressionTypeNode(const std::string& identifier)
        : TypeNode(), identifier_(identifier) {
    }

    ~ExpressionTypeNode() = default;

    ExpressionTypeNode(const ExpressionTypeNode& node)
        : TypeNode(node), identifier_(node.identifier_) {
    }

    ExpressionTypeNode(ExpressionTypeNode&& node)
        : TypeNode(std::move(node)), identifier_(std::move(node.identifier_)) {
    }

    ExpressionTypeNode& operator=(const ExpressionTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        identifier_ = node.identifier_;
        return *this;
    }

    ExpressionTypeNode& operator=(ExpressionTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        identifier_ = std::move(node.identifier_);
        return *this;
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<ExpressionTypeNode> clone() const {
        return std::unique_ptr<ExpressionTypeNode>(this->clone_impl());
    }

    bool is_expression_type_node() const override final {
        return true;
    }

    const std::string& get_identifier() const {
        return identifier_;
    }

  private:
    virtual ExpressionTypeNode* clone_impl() const override final {
        return new ExpressionTypeNode(*this);
    };

    std::string identifier_;
};

using ExpressionTypeNodePtr = ExpressionTypeNode*;
using ExpressionTypeNodeUPtr = std::unique_ptr<ExpressionTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_EXPRESSION_TYPE_NODE_H */
