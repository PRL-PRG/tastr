#ifndef TASTR_AST_RAW_TYPE_H
#define TASTR_AST_RAW_TYPE_H

#include "ScalarTypeNode.h"

namespace tastr::ast {

class RawScalarTypeNode final: public ScalarTypeNode {
  public:
    RawScalarTypeNode(): ScalarTypeNode() {
    }

    RawScalarTypeNode(const RawScalarTypeNode& node): ScalarTypeNode(node) {
    }

    ~RawScalarTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<RawScalarTypeNode> clone() const {
        return std::unique_ptr<RawScalarTypeNode>(this->clone_impl());
    }

    bool is_raw_scalar_type_node() const override final {
        return true;
    }

  private:
    virtual RawScalarTypeNode* clone_impl() const override final {
        return new RawScalarTypeNode(*this);
    };
};

using RawScalarTypeNodePtr = RawScalarTypeNode*;
using RawScalarTypeNodeUPtr = std::unique_ptr<RawScalarTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_RAW_TYPE_H */
