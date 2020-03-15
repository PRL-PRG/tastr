#ifndef TASTR_AST_SYMBOL_TYPE_NODE_HPP
#define TASTR_AST_SYMBOL_TYPE_NODE_HPP

#include "ast/KeywordNode.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class SymbolTypeNode final: public TypeNode {
  public:
    explicit SymbolTypeNode(KeywordNodeUPtr keyword)
        : TypeNode(), keyword_(std::move(keyword)) {
    }

    ~SymbolTypeNode() = default;

    SymbolTypeNode(const SymbolTypeNode& node)
        : TypeNode(node), keyword_(node.keyword_->clone()) {
    }

    SymbolTypeNode(SymbolTypeNode&& node)
        : TypeNode(std::move(node)), keyword_(std::move(node.keyword_)) {
    }

    SymbolTypeNode& operator=(const SymbolTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_->clone();
        return *this;
    }

    SymbolTypeNode& operator=(SymbolTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<SymbolTypeNode> clone() const {
        return std::unique_ptr<SymbolTypeNode>(this->clone_impl());
    }

    bool is_symbol_type_node() const override final {
        return true;
    }

    const KeywordNode& get_keyword() const {
        return *keyword_.get();
    }

  private:
    virtual SymbolTypeNode* clone_impl() const override final {
        return new SymbolTypeNode(*this);
    }

    KeywordNodeUPtr keyword_;
};

using SymbolTypeNodePtr = SymbolTypeNode*;
using SymbolTypeNodeUPtr = std::unique_ptr<SymbolTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_SYMBOL_TYPE_NODE_HPP */
