#ifndef TASTR_AST_VARARG_TYPE_H
#define TASTR_AST_VARARG_TYPE_H

#include "ast/Type.h"

#include <iostream>

namespace tastr::ast {

class VarargType final: public Type {
  public:
    explicit VarargType(): Type() {
    }

    ~VarargType() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using VarargTypePtr = VarargType*;
using VarargTypeUPtr = std::unique_ptr<VarargType>;

} // namespace tastr::ast

#endif /* TASTR_AST_VARARG_TYPE_H */
