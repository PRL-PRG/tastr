#ifndef TASTR_AST_INTEGER_TYPE_H
#define TASTR_AST_INTEGER_TYPE_H

#include "ScalarTypeNode.h"

namespace tastr::ast {

class IntegerTypeNode final: public ScalarTypeNode {
  public:
    IntegerTypeNode(): ScalarTypeNode() {
    }

    IntegerTypeNode(const IntegerTypeNode& node): ScalarTypeNode(node) {
    }

    ~IntegerTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<IntegerTypeNode> clone() const {
        return std::unique_ptr<IntegerTypeNode>(this->clone_impl());
    }

  private:
    virtual IntegerTypeNode* clone_impl() const override final {
        return new IntegerTypeNode(*this);
    };
};

using IntegerTypeNodePtr = IntegerTypeNode*;
using IntegerTypeNodeUPtr = std::unique_ptr<IntegerTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_INTEGER_TYPE_H */
