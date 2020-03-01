#ifndef TASTR_AST_ENVIRONMENT_TYPE_H
#define TASTR_AST_ENVIRONMENT_TYPE_H

#include "TypeNode.h"

namespace tastr::ast {

class EnvironmentTypeNode final: public TypeNode {
  public:
    EnvironmentTypeNode(): TypeNode() {
    }

    EnvironmentTypeNode(const EnvironmentTypeNode& node): TypeNode(node) {
    }

    ~EnvironmentTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<EnvironmentTypeNode> clone() const {
        return std::unique_ptr<EnvironmentTypeNode>(this->clone_impl());
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
