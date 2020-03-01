#ifndef TASTR_AST_DOUBLE_TYPE_H
#define TASTR_AST_DOUBLE_TYPE_H

#include "ScalarTypeNode.h"

namespace tastr::ast {

class DoubleScalarTypeNode final: public ScalarTypeNode {
  public:
    DoubleScalarTypeNode(): ScalarTypeNode() {
    }

    DoubleScalarTypeNode(const DoubleScalarTypeNode& node)
        : ScalarTypeNode(node) {
    }

    ~DoubleScalarTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<DoubleScalarTypeNode> clone() const {
        return std::unique_ptr<DoubleScalarTypeNode>(this->clone_impl());
    }

    bool is_double_scalar_type_node() const override final {
        return true;
    }

  private:
    virtual DoubleScalarTypeNode* clone_impl() const override final {
        return new DoubleScalarTypeNode(*this);
    };
};

using DoubleScalarTypeNodePtr = DoubleScalarTypeNode*;
using DoubleScalarTypeNodeUPtr = std::unique_ptr<DoubleScalarTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_DOUBLE_TYPE_H */
