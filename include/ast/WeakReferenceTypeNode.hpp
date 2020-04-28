#ifndef TASTR_AST_WEAK_REFERENCE_TYPE_NODE_HPP
#define TASTR_AST_WEAK_REFERENCE_TYPE_NODE_HPP

#include "ast/KeywordNode.hpp"
#include "ast/TypeNode.hpp"

namespace tastr {
namespace ast {

class WeakReferenceTypeNode final: public TypeNode {
  public:
    explicit WeakReferenceTypeNode(KeywordNodeUPtr keyword)
        : TypeNode(), keyword_(std::move(keyword)) {
    }

    ~WeakReferenceTypeNode() = default;

    WeakReferenceTypeNode(const WeakReferenceTypeNode& node)
        : TypeNode(node), keyword_(node.keyword_->clone()) {
    }

    WeakReferenceTypeNode(WeakReferenceTypeNode&& node)
        : TypeNode(std::move(node)), keyword_(std::move(node.keyword_)) {
    }

    WeakReferenceTypeNode& operator=(const WeakReferenceTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_->clone();
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

    Kind get_kind() const override final {
        return kind_;
    }

    const KeywordNode& get_keyword() const {
        return *keyword_.get();
    }

  private:
    virtual WeakReferenceTypeNode* clone_impl() const override final {
        return new WeakReferenceTypeNode(*this);
    };

    KeywordNodeUPtr keyword_;

    static const Kind kind_;
};

using WeakReferenceTypeNodePtr = WeakReferenceTypeNode*;
using WeakReferenceTypeNodeUPtr = std::unique_ptr<WeakReferenceTypeNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_WEAK_REFERENCE_TYPE_NODE_HPP */
