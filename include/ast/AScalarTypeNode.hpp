#ifndef TASTR_AST_A_SCALAR_TYPE_NODE_HPP
#define TASTR_AST_A_SCALAR_TYPE_NODE_HPP

#include "ast/KeywordNode.hpp"
#include "ast/ScalarTypeNode.hpp"

namespace tastr::ast {

class AScalarTypeNode: public ScalarTypeNode {
  public:
    explicit AScalarTypeNode(const KeywordNode& keyword)
        : ScalarTypeNode(), keyword_(keyword) {
    }

    virtual ~AScalarTypeNode() = default;

    AScalarTypeNode(const AScalarTypeNode& node)
        : ScalarTypeNode(node), keyword_(node.keyword_) {
    }

    AScalarTypeNode(AScalarTypeNode&& node)
        : ScalarTypeNode(std::move(node)), keyword_(std::move(node.keyword_)) {
    }

    AScalarTypeNode& operator=(const AScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        ScalarTypeNode::operator=(node);
        keyword_ = node.keyword_;
        return *this;
    }

    AScalarTypeNode& operator=(AScalarTypeNode&& node) {
        ScalarTypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        return *this;
    }

    virtual void
    accept(tastr::visitor::ConstNodeVisitor& visitor) const override = 0;

    virtual void
    accept(tastr::visitor::MutableNodeVisitor& visitor) override = 0;

    std::unique_ptr<AScalarTypeNode> clone() const {
        return std::unique_ptr<AScalarTypeNode>(this->clone_impl());
    }

    bool is_a_scalar_type_node() const override final {
        return true;
    }

    const KeywordNode& get_keyword() const {
        return keyword_;
    }

  private:
    virtual AScalarTypeNode* clone_impl() const override = 0;

    KeywordNode keyword_;
};

using AScalarTypeNodePtr = AScalarTypeNode*;
using AScalarTypeNodeUPtr = std::unique_ptr<AScalarTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_A_SCALAR_TYPE_NODE_HPP */
