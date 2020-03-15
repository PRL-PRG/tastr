#ifndef TASTR_AST_ANY_TYPE_NODE_HPP
#define TASTR_AST_ANY_TYPE_NODE_HPP

#include "ast/KeywordNode.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {
class AnyTypeNode final: public TypeNode {
  public:
    explicit AnyTypeNode(const KeywordNode& keyword)
        : TypeNode(), keyword_(keyword) {
    }

    ~AnyTypeNode() = default;

    AnyTypeNode(const AnyTypeNode& node)
        : TypeNode(node), keyword_(node.keyword_) {
    }

    AnyTypeNode(AnyTypeNode&& node)
        : TypeNode(std::move(node)), keyword_(std::move(node.keyword_)) {
    }

    AnyTypeNode& operator=(const AnyTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_;
        return *this;
    }

    AnyTypeNode& operator=(AnyTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<AnyTypeNode> clone() const {
        return std::unique_ptr<AnyTypeNode>(this->clone_impl());
    }

    bool is_any_type_node() const override final {
        return true;
    }

    const KeywordNode& get_keyword() const {
        return keyword_;
    }

  private:
    virtual AnyTypeNode* clone_impl() const override final {
        return new AnyTypeNode(*this);
    };

    KeywordNode keyword_;
};

using AnyTypeNodePtr = AnyTypeNode*;
using AnyTypeNodeUPtr = std::unique_ptr<AnyTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_ANY_TYPE_NODE_HPP */
