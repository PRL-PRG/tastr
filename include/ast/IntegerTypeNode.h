#ifndef TASTR_AST_INTEGER_TYPE_H
#define TASTR_AST_INTEGER_TYPE_H

#include "ScalarTypeNode.h"

namespace tastr::ast {

class IntegerTypeNode final: public ScalarTypeNode {
  public:
    IntegerTypeNode(): ScalarTypeNode() {
    }

    ~IntegerTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using IntegerTypeNodePtr = IntegerTypeNode*;
using IntegerTypeNodeUPtr = std::unique_ptr<IntegerTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_INTEGER_TYPE_H */
