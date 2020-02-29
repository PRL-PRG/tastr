#ifndef TASTR_AST_SYMBOL_TYPE_H
#define TASTR_AST_SYMBOL_TYPE_H

#include "TypeNode.h"

namespace tastr::ast {

class SymbolTypeNode final: public TypeNode {
  public:
    SymbolTypeNode(): TypeNode() {
    }

    ~SymbolTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using SymbolTypeNodePtr = SymbolTypeNode*;
using SymbolTypeNodeUPtr = std::unique_ptr<SymbolTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_SYMBOL_TYPE_H */
