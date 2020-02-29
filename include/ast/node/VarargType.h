#ifndef R_TYPE_AST_NODE_VARARG_TYPE_H
#define R_TYPE_AST_NODE_VARARG_TYPE_H

#include "ast/node/Type.h"

#include <iostream>

namespace rtype::ast::node {

class VarargType final: public Type {
  public:
    explicit VarargType(): Type() {
    }

    ~VarargType() {
    }

    void accept(rtype::ast::visitor::Visitor& visitor) const override final;
};

using VarargTypePtr = VarargType*;
using VarargTypeUPtr = std::unique_ptr<VarargType>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_VARARG_TYPE_H */
