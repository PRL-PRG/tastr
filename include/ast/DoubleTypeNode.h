#ifndef TASTR_AST_DOUBLE_TYPE_H
#define TASTR_AST_DOUBLE_TYPE_H

#include "ScalarTypeNode.h"

namespace tastr::ast {

class DoubleTypeNode final: public ScalarTypeNode {
  public:
    DoubleTypeNode(): ScalarTypeNode() {
    }

    ~DoubleTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using DoubleTypeNodePtr = DoubleTypeNode*;
using DoubleTypeNodeUPtr = std::unique_ptr<DoubleTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_DOUBLE_TYPE_H */
