#ifndef TASTR_AST_WEAK_REFERENCE_TYPE_NODE_HPP
#define TASTR_AST_WEAK_REFERENCE_TYPE_NODE_HPP

#include "ast/Keyword.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class WeakReferenceTypeNode final: public TypeNode {
  public:
    explicit WeakReferenceTypeNode(const Keyword& keyword)
        : TypeNode(), keyword_(keyword) {
    }

    ~WeakReferenceTypeNode() = default;

    WeakReferenceTypeNode(const WeakReferenceTypeNode& node)
        : TypeNode(node), keyword_(node.keyword_) {
    }

    WeakReferenceTypeNode(WeakReferenceTypeNode&& node)
        : TypeNode(std::move(node)), keyword_(std::move(node.keyword_)) {
    }

    WeakReferenceTypeNode& operator=(const WeakReferenceTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_;
        return *this;
    }

    WeakReferenceTypeNode& operator=(WeakReferenceTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<WeakReferenceTypeNode> clone() const {
        return std::unique_ptr<WeakReferenceTypeNode>(this->clone_impl());
    }

    bool is_weak_reference_type_node() const override final {
        return true;
    }

    const Keyword& get_keyword() const {
        return keyword_;
    }

  private:
    virtual WeakReferenceTypeNode* clone_impl() const override final {
        return new WeakReferenceTypeNode(*this);
    };

    Keyword keyword_;
};

using WeakReferenceTypeNodePtr = WeakReferenceTypeNode*;
using WeakReferenceTypeNodeUPtr = std::unique_ptr<WeakReferenceTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_WEAK_REFERENCE_TYPE_NODE_HPP */
