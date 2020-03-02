#ifndef TASTR_AST_SCALAR_TYPE_NODE_H
#define TASTR_AST_SCALAR_TYPE_NODE_H

#include "TypeNode.h"

namespace tastr::ast {

class ScalarTypeNode: public TypeNode {
  public:
    ScalarTypeNode(): TypeNode() {
    }

    virtual ~ScalarTypeNode() {
    }

    ScalarTypeNode(const ScalarTypeNode& node): TypeNode(node) {
    }

    ScalarTypeNode(ScalarTypeNode&& node): TypeNode(std::move(node)) {
    }

    ScalarTypeNode& operator=(const ScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        return *this;
    }

    ScalarTypeNode& operator=(ScalarTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        return *this;
    }

    virtual void accept(tastr::visitor::Visitor& visitor) const = 0;

    std::unique_ptr<ScalarTypeNode> clone() const {
        return std::unique_ptr<ScalarTypeNode>(this->clone_impl());
    }

    bool is_scalar_type_node() const override final {
        return true;
    }

  private:
    virtual ScalarTypeNode* clone_impl() const = 0;
};

using ScalarTypeNodePtr = ScalarTypeNode*;
using ScalarTypeNodeUPtr = std::unique_ptr<ScalarTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_SCALAR_TYPE_NODE_H */
