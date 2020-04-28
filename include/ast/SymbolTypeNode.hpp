#ifndef TASTR_AST_SYMBOL_TYPE_NODE_HPP
#define TASTR_AST_SYMBOL_TYPE_NODE_HPP

#include "ast/KeywordNode.hpp"
#include "ast/TypeNode.hpp"

namespace tastr {
namespace ast {

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

    Kind get_kind() const override final {
        return kind_;
    }

    const KeywordNode& get_keyword() const {
        return *keyword_.get();
    }

  private:
    virtual SymbolTypeNode* clone_impl() const override final {
        return new SymbolTypeNode(*this);
    }

    KeywordNodeUPtr keyword_;

    static const Kind kind_;
};

using SymbolTypeNodePtr = SymbolTypeNode*;
using SymbolTypeNodeUPtr = std::unique_ptr<SymbolTypeNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_SYMBOL_TYPE_NODE_HPP */
