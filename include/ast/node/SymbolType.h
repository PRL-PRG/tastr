#ifndef TASTR_AST_NODE_SYMBOL_TYPE_H
#define TASTR_AST_NODE_SYMBOL_TYPE_H

#include "Type.h"

namespace tastr::ast::node {

class SymbolType final: public Type {
  public:
    SymbolType(): Type() {
    }

    ~SymbolType() {
    }

    void accept(tastr::ast::visitor::Visitor& visitor) const override final;
};

using SymbolTypePtr = SymbolType*;
using SymbolTypeUPtr = std::unique_ptr<SymbolType>;

} // namespace tastr::ast::node

#endif /* TASTR_AST_NODE_SYMBOL_TYPE_H */
