#ifndef TASTR_AST_EXPRESSION_TYPE_H
#define TASTR_AST_EXPRESSION_TYPE_H

#include "TypeNode.h"

namespace tastr::ast {

class ExpressionTypeNode final: public TypeNode {
  public:
    ExpressionTypeNode(): TypeNode() {
    }

    ~ExpressionTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using ExpressionTypeNodePtr = ExpressionTypeNode*;
using ExpressionTypeNodeUPtr = std::unique_ptr<ExpressionTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_EXPRESSION_TYPE_H */
