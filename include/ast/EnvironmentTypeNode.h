#ifndef TASTR_AST_ENVIRONMENT_TYPE_H
#define TASTR_AST_ENVIRONMENT_TYPE_H

#include "TypeNode.h"

namespace tastr::ast {

class EnvironmentTypeNode final: public TypeNode {
  public:
    EnvironmentTypeNode(): TypeNode() {
    }

    ~EnvironmentTypeNode() = default;

    EnvironmentTypeNode(const EnvironmentTypeNode& node): TypeNode(node) {
    }

    EnvironmentTypeNode(EnvironmentTypeNode&& node): TypeNode(std::move(node)) {
    }

    EnvironmentTypeNode& operator=(const EnvironmentTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        return *this;
    }

    EnvironmentTypeNode& operator=(EnvironmentTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<EnvironmentTypeNode> clone() const {
        return std::unique_ptr<EnvironmentTypeNode>(this->clone_impl());
    }

    bool is_environment_type_node() const override final {
        return true;
    }

  private:
    virtual EnvironmentTypeNode* clone_impl() const override final {
        return new EnvironmentTypeNode(*this);
    };
};

using EnvironmentTypeNodePtr = EnvironmentTypeNode*;
using EnvironmentTypeNodeUPtr = std::unique_ptr<EnvironmentTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_ENVIRONMENT_TYPE_H */
