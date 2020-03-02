#ifndef TASTR_AST_RAW_TYPE_H
#define TASTR_AST_RAW_TYPE_H

#include "ScalarTypeNode.h"

namespace tastr::ast {

class RawScalarTypeNode final: public ScalarTypeNode {
  public:
    RawScalarTypeNode(): ScalarTypeNode() {
    }

    ~RawScalarTypeNode() = default;

    RawScalarTypeNode(const RawScalarTypeNode& node): ScalarTypeNode(node) {
    }

    RawScalarTypeNode(RawScalarTypeNode&& node)
        : ScalarTypeNode(std::move(node)) {
    }

    RawScalarTypeNode& operator=(const RawScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        ScalarTypeNode::operator=(node);
        return *this;
    }

    RawScalarTypeNode& operator=(RawScalarTypeNode&& node) {
        ScalarTypeNode::operator=(std::move(node));
        return *this;
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
