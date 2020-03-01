#ifndef TASTR_AST_INTEGER_TYPE_H
#define TASTR_AST_INTEGER_TYPE_H

#include "ScalarTypeNode.h"

namespace tastr::ast {

class IntegerScalarTypeNode final: public ScalarTypeNode {
  public:
    IntegerScalarTypeNode(): ScalarTypeNode() {
    }

    IntegerScalarTypeNode(const IntegerScalarTypeNode& node)
        : ScalarTypeNode(node) {
    }

    ~IntegerScalarTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<IntegerScalarTypeNode> clone() const {
        return std::unique_ptr<IntegerScalarTypeNode>(this->clone_impl());
    }

  private:
    virtual IntegerScalarTypeNode* clone_impl() const override final {
        return new IntegerScalarTypeNode(*this);
    };
};

using IntegerScalarTypeNodePtr = IntegerScalarTypeNode*;
using IntegerScalarTypeNodeUPtr = std::unique_ptr<IntegerScalarTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_INTEGER_TYPE_H */
