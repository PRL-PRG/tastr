#ifndef TASTR_AST_VARARG_TYPE_NODE_HPP
#define TASTR_AST_VARARG_TYPE_NODE_HPP

#include "ast/KeywordNode.hpp"
#include "ast/TypeNode.hpp"

#include <iostream>

namespace tastr::ast {

class VarargTypeNode final: public TypeNode {
  public:
    explicit VarargTypeNode(const KeywordNode& keyword)
        : TypeNode(), keyword_(keyword) {
    }

    ~VarargTypeNode() = default;

    VarargTypeNode(const VarargTypeNode& node)
        : TypeNode(node), keyword_(node.keyword_) {
    }

    VarargTypeNode(VarargTypeNode&& node)
        : TypeNode(std::move(node)), keyword_(std::move(node.keyword_)) {
    }

    VarargTypeNode& operator=(const VarargTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_;
        return *this;
    }

    VarargTypeNode& operator=(VarargTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<VarargTypeNode> clone() const {
        return std::unique_ptr<VarargTypeNode>(this->clone_impl());
    }

    bool is_vararg_type_node() const override final {
        return true;
    }

    const KeywordNode& get_keyword() const {
        return keyword_;
    }

  private:
    virtual VarargTypeNode* clone_impl() const override final {
        return new VarargTypeNode(*this);
    };

    KeywordNode keyword_;
};

using VarargTypeNodePtr = VarargTypeNode*;
using VarargTypeNodeUPtr = std::unique_ptr<VarargTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_VARARG_TYPE_NODE_HPP */
