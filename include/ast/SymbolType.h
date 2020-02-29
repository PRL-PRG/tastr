#ifndef TASTR_AST_SYMBOL_TYPE_H
#define TASTR_AST_SYMBOL_TYPE_H

#include "Type.h"

namespace tastr::ast {

class SymbolType final: public Type {
  public:
    SymbolType(): Type() {
    }

    ~SymbolType() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using SymbolTypePtr = SymbolType*;
using SymbolTypeUPtr = std::unique_ptr<SymbolType>;

} // namespace tastr::ast

#endif /* TASTR_AST_SYMBOL_TYPE_H */
