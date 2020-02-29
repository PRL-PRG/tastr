#ifndef TASTR_AST_VARARG_TYPE_H
#define TASTR_AST_VARARG_TYPE_H

#include "ast/TypeNode.h"

#include <iostream>

namespace tastr::ast {

class VarargTypeNode final: public TypeNode {
  public:
    explicit VarargTypeNode(): TypeNode() {
    }

    ~VarargTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using VarargTypeNodePtr = VarargTypeNode*;
using VarargTypeNodeUPtr = std::unique_ptr<VarargTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_VARARG_TYPE_H */
