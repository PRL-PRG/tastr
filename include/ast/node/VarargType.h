#ifndef TASTR_AST_NODE_VARARG_TYPE_H
#define TASTR_AST_NODE_VARARG_TYPE_H

#include "ast/node/Type.h"

#include <iostream>

namespace tastr::ast::node {

class VarargType final: public Type {
  public:
    explicit VarargType(): Type() {
    }

    ~VarargType() {
    }

    void accept(tastr::ast::visitor::Visitor& visitor) const override final;
};

using VarargTypePtr = VarargType*;
using VarargTypeUPtr = std::unique_ptr<VarargType>;

} // namespace tastr::ast::node

#endif /* TASTR_AST_NODE_VARARG_TYPE_H */
