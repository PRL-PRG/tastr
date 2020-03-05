#ifndef TASTR_AST_SYMBOL_TYPE_NODE_HPP
#define TASTR_AST_SYMBOL_TYPE_NODE_HPP

#include "TypeNode.hpp"

namespace tastr::ast {

class SymbolTypeNode final: public TypeNode {
  public:
    explicit SymbolTypeNode(const std::string& identifier)
        : TypeNode(), identifier_(identifier) {
    }

    ~SymbolTypeNode() = default;

    SymbolTypeNode(const SymbolTypeNode& node)
        : TypeNode(node), identifier_(node.identifier_) {
    }

    SymbolTypeNode(SymbolTypeNode&& node)
        : TypeNode(std::move(node)), identifier_(std::move(node.identifier_)) {
    }

    SymbolTypeNode& operator=(const SymbolTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        identifier_ = node.identifier_;
        return *this;
    }

    SymbolTypeNode& operator=(SymbolTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        identifier_ = std::move(node.identifier_);
        return *this;
    }

    void accept(tastr::visitor::ConstVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableVisitor& visitor) override final;

    std::unique_ptr<SymbolTypeNode> clone() const {
        return std::unique_ptr<SymbolTypeNode>(this->clone_impl());
    }

    bool is_symbol_type_node() const override final {
        return true;
    }

    const std::string& get_identifier() const {
        return identifier_;
    }

  private:
    virtual SymbolTypeNode* clone_impl() const override final {
        return new SymbolTypeNode(*this);
    }

    std::string identifier_;
};

using SymbolTypeNodePtr = SymbolTypeNode*;
using SymbolTypeNodeUPtr = std::unique_ptr<SymbolTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_SYMBOL_TYPE_NODE_HPP */
