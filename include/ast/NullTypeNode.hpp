#ifndef TASTR_AST_NULL_TYPE_NODE_HPP
#define TASTR_AST_NULL_TYPE_NODE_HPP

#include "ast/KeywordNode.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class NullTypeNode final: public TypeNode {
  public:
    explicit NullTypeNode(const KeywordNode& keyword)
        : TypeNode(), keyword_(keyword) {
    }

    ~NullTypeNode() = default;

    NullTypeNode(const NullTypeNode& node)
        : TypeNode(node), keyword_(node.keyword_) {
    }

    NullTypeNode(NullTypeNode&& node)
        : TypeNode(std::move(node)), keyword_(std::move(node.keyword_)) {
    }

    NullTypeNode& operator=(const NullTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_;
        return *this;
    }

    NullTypeNode& operator=(NullTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<NullTypeNode> clone() const {
        return std::unique_ptr<NullTypeNode>(this->clone_impl());
    }

    bool is_null_type_node() const override final {
        return true;
    }

    const KeywordNode& get_keyword() const {
        return keyword_;
    }

  private:
    virtual NullTypeNode* clone_impl() const override final {
        return new NullTypeNode(*this);
    }

    KeywordNode keyword_;
};

using NullTypeNodePtr = NullTypeNode*;
using NullTypeNodeUPtr = std::unique_ptr<NullTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_NULL_TYPE_NODE_HPP */
