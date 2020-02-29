#ifndef R_TYPE_AST_NODE_SYMBOL_TYPE_H
#define R_TYPE_AST_NODE_SYMBOL_TYPE_H

#include "Type.h"

namespace rtype::ast::node {

class SymbolType final: public Type {
  public:
    SymbolType(): Type() {
    }

    ~SymbolType() {
    }

    void accept(rtype::ast::visitor::Visitor& visitor) const override final;
};

using SymbolTypePtr = SymbolType*;
using SymbolTypeUPtr = std::unique_ptr<SymbolType>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_SYMBOL_TYPE_H */
