#ifndef TASTR_AST_EXPRESSION_TYPE_NODE_HPP
#define TASTR_AST_EXPRESSION_TYPE_NODE_HPP

#include "ast/KeywordNode.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class ExpressionTypeNode final: public TypeNode {
  public:
    explicit ExpressionTypeNode(KeywordNodeUPtr keyword)
        : TypeNode(), keyword_(std::move(keyword)) {
    }

    ~ExpressionTypeNode() = default;

    ExpressionTypeNode(const ExpressionTypeNode& node)
        : TypeNode(node), keyword_(node.keyword_->clone()) {
    }

    ExpressionTypeNode(ExpressionTypeNode&& node)
        : TypeNode(std::move(node)), keyword_(std::move(node.keyword_)) {
    }

    ExpressionTypeNode& operator=(const ExpressionTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_->clone();
        return *this;
    }

    ExpressionTypeNode& operator=(ExpressionTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<ExpressionTypeNode> clone() const {
        return std::unique_ptr<ExpressionTypeNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

    bool is_expression_type_node() const override final {
        return true;
    }

    const KeywordNode& get_keyword() const {
        return *keyword_.get();
    }

  private:
    virtual ExpressionTypeNode* clone_impl() const override final {
        return new ExpressionTypeNode(*this);
    };

    KeywordNodeUPtr keyword_;

    static const Kind kind_;
};

using ExpressionTypeNodePtr = ExpressionTypeNode*;
using ExpressionTypeNodeUPtr = std::unique_ptr<ExpressionTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_EXPRESSION_TYPE_NODE_HPP */
