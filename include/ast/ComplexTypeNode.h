#ifndef TASTR_AST_COMPLEX_TYPE_H
#define TASTR_AST_COMPLEX_TYPE_H

#include "ScalarTypeNode.h"

namespace tastr::ast {

class ComplexTypeNode final: public ScalarTypeNode {
  public:
    ComplexTypeNode(): ScalarTypeNode() {
    }

    ComplexTypeNode(const ComplexTypeNode& node): ScalarTypeNode(node) {
    }

    ~ComplexTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<ComplexTypeNode> clone() const {
        return std::unique_ptr<ComplexTypeNode>(this->clone_impl());
    }

  private:
    virtual ComplexTypeNode* clone_impl() const override final {
        return new ComplexTypeNode(*this);
    };
};

using ComplexTypeNodePtr = ComplexTypeNode*;
using ComplexTypeNodeUPtr = std::unique_ptr<ComplexTypeNode>;
} // namespace tastr::ast

#endif /* TASTR_AST_COMPLEX_TYPE_H */
