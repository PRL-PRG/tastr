#ifndef TASTR_AST_COMPLEX_TYPE_H
#define TASTR_AST_COMPLEX_TYPE_H

#include "ScalarTypeNode.h"

namespace tastr::ast {

class ComplexTypeNode final: public ScalarTypeNode {
  public:
    ComplexTypeNode(): ScalarTypeNode() {
    }

    ~ComplexTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using ComplexTypeNodePtr = ComplexTypeNode*;
using ComplexTypeNodeUPtr = std::unique_ptr<ComplexTypeNode>;
} // namespace tastr::ast

#endif /* TASTR_AST_COMPLEX_TYPE_H */
