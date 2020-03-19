#ifndef TASTR_AST_PAIRLIST_TYPE_NODE_HPP
#define TASTR_AST_PAIRLIST_TYPE_NODE_HPP

#include "ast/KeywordNode.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class PairlistTypeNode final: public TypeNode {
  public:
    explicit PairlistTypeNode(KeywordNodeUPtr keyword)
        : TypeNode(), keyword_(std::move(keyword)) {
    }

    ~PairlistTypeNode() = default;

    PairlistTypeNode(const PairlistTypeNode& node)
        : TypeNode(node), keyword_(node.keyword_->clone()) {
    }

    PairlistTypeNode(PairlistTypeNode&& node)
        : TypeNode(std::move(node)), keyword_(std::move(node.keyword_)) {
    }

    PairlistTypeNode& operator=(const PairlistTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_->clone();
        return *this;
    }

    PairlistTypeNode& operator=(PairlistTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<PairlistTypeNode> clone() const {
        return std::unique_ptr<PairlistTypeNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

    const KeywordNode& get_keyword() const {
        return *keyword_.get();
    }

  private:
    virtual PairlistTypeNode* clone_impl() const override final {
        return new PairlistTypeNode(*this);
    };

    KeywordNodeUPtr keyword_;
    static const Kind kind_;
};

using PairlistTypeNodePtr = PairlistTypeNode*;
using PairlistTypeNodeUPtr = std::unique_ptr<PairlistTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_PAIRLIST_TYPE_NODE_HPP */
