#ifndef TASTR_AST_ENVIRONMENT_TYPE_H
#define TASTR_AST_ENVIRONMENT_TYPE_H

#include "TypeNode.h"

namespace tastr::ast {

class EnvironmentTypeNode final: public TypeNode {
  public:
    EnvironmentTypeNode(): TypeNode() {
    }

    ~EnvironmentTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using EnvironmentTypeNodePtr = EnvironmentTypeNode*;
using EnvironmentTypeNodeUPtr = std::unique_ptr<EnvironmentTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_ENVIRONMENT_TYPE_H */
