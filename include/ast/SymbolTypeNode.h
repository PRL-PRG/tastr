#ifndef TASTR_AST_SYMBOL_TYPE_H
#define TASTR_AST_SYMBOL_TYPE_H

#include "TypeNode.h"

namespace tastr::ast {

class SymbolTypeNode final: public TypeNode {
  public:
    SymbolTypeNode(): TypeNode() {
    }

    ~SymbolTypeNode() = default;

    SymbolTypeNode(const SymbolTypeNode& node): TypeNode(node) {
    }

    SymbolTypeNode(SymbolTypeNode&& node): TypeNode(std::move(node)) {
    }

    SymbolTypeNode& operator=(const SymbolTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        return *this;
    }

    SymbolTypeNode& operator=(SymbolTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<SymbolTypeNode> clone() const {
        return std::unique_ptr<SymbolTypeNode>(this->clone_impl());
    }

    bool is_symbol_type_node() const override final {
        return true;
    }

  private:
    virtual SymbolTypeNode* clone_impl() const override final {
        return new SymbolTypeNode(*this);
    }
};

using SymbolTypeNodePtr = SymbolTypeNode*;
using SymbolTypeNodeUPtr = std::unique_ptr<SymbolTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_SYMBOL_TYPE_H */
