#ifndef TASTR_AST_VARARG_TYPE_H
#define TASTR_AST_VARARG_TYPE_H

#include "ast/TypeNode.h"

#include <iostream>

namespace tastr::ast {

class VarargTypeNode final: public TypeNode {
  public:
    explicit VarargTypeNode(): TypeNode() {
    }

    VarargTypeNode(const VarargTypeNode& node): TypeNode(node) {
    }

    ~VarargTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

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

#endif /* TASTR_AST_VARARG_TYPE_H */
