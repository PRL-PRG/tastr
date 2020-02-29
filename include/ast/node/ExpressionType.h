#ifndef R_TYPE_AST_NODE_EXPRESSION_TYPE_H
#define R_TYPE_AST_NODE_EXPRESSION_TYPE_H

#include "Type.h"

namespace rtype::ast::node {

class ExpressionType final: public Type {
  public:
    ExpressionType(): Type() {
    }

    ~ExpressionType() {
    }

    void accept(rtype::ast::visitor::Visitor& visitor) const override final;
};

using ExpressionTypePtr = ExpressionType*;
using ExpressionTypeUPtr = std::unique_ptr<ExpressionType>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_EXPRESSION_TYPE_H */
