#ifndef TASTR_AST_EXPRESSION_TYPE_H
#define TASTR_AST_EXPRESSION_TYPE_H

#include "TypeNode.h"

namespace tastr::ast {

class ExpressionTypeNode final: public TypeNode {
  public:
    ExpressionTypeNode(): TypeNode() {
    }

    ExpressionTypeNode(const ExpressionTypeNode& node): TypeNode(node) {
    }

    ~ExpressionTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<ExpressionTypeNode> clone() const {
        return std::unique_ptr<ExpressionTypeNode>(this->clone_impl());
    }

  private:
    virtual ExpressionTypeNode* clone_impl() const override final {
        return new ExpressionTypeNode(*this);
    };
};

using ExpressionTypeNodePtr = ExpressionTypeNode*;
using ExpressionTypeNodeUPtr = std::unique_ptr<ExpressionTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_EXPRESSION_TYPE_H */
