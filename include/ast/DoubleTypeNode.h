#ifndef TASTR_AST_DOUBLE_TYPE_H
#define TASTR_AST_DOUBLE_TYPE_H

#include "ScalarTypeNode.h"

namespace tastr::ast {

class DoubleTypeNode final: public ScalarTypeNode {
  public:
    DoubleTypeNode(): ScalarTypeNode() {
    }

    DoubleTypeNode(const DoubleTypeNode& node): ScalarTypeNode(node) {
    }

    ~DoubleTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<DoubleTypeNode> clone() const {
        return std::unique_ptr<DoubleTypeNode>(this->clone_impl());
    }

  private:
    virtual DoubleTypeNode* clone_impl() const override final {
        return new DoubleTypeNode(*this);
    };
};

using DoubleTypeNodePtr = DoubleTypeNode*;
using DoubleTypeNodeUPtr = std::unique_ptr<DoubleTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_DOUBLE_TYPE_H */
