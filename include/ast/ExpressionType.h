#ifndef TASTR_AST_EXPRESSION_TYPE_H
#define TASTR_AST_EXPRESSION_TYPE_H

#include "Type.h"

namespace tastr::ast {

class ExpressionType final: public Type {
  public:
    ExpressionType(): Type() {
    }

    ~ExpressionType() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using ExpressionTypePtr = ExpressionType*;
using ExpressionTypeUPtr = std::unique_ptr<ExpressionType>;

} // namespace tastr::ast

#endif /* TASTR_AST_EXPRESSION_TYPE_H */
