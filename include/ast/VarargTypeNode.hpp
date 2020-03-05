#ifndef TASTR_AST_VARARG_TYPE_NODE_HPP
#define TASTR_AST_VARARG_TYPE_NODE_HPP

#include "ast/TypeNode.hpp"

#include <iostream>

namespace tastr::ast {

class VarargTypeNode final: public TypeNode {
  public:
    explicit VarargTypeNode(): TypeNode() {
    }

    ~VarargTypeNode() = default;

    VarargTypeNode(const VarargTypeNode& node): TypeNode(node) {
    }

    VarargTypeNode(VarargTypeNode&& node): TypeNode(std::move(node)) {
    }

    VarargTypeNode& operator=(const VarargTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        return *this;
    }

    VarargTypeNode& operator=(VarargTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::ConstVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableVisitor& visitor) override final;

    std::unique_ptr<VarargTypeNode> clone() const {
        return std::unique_ptr<VarargTypeNode>(this->clone_impl());
    }

    bool is_vararg_type_node() const override final {
        return true;
    }

  private:
    virtual VarargTypeNode* clone_impl() const override final {
        return new VarargTypeNode(*this);
    };
};

using VarargTypeNodePtr = VarargTypeNode*;
using VarargTypeNodeUPtr = std::unique_ptr<VarargTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_VARARG_TYPE_NODE_HPP */
