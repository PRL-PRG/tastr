#ifndef TASTR_AST_NODE_ENVIRONMENT_TYPE_H
#define TASTR_AST_NODE_ENVIRONMENT_TYPE_H

#include "Type.h"

namespace tastr::ast::node {

class EnvironmentType final: public Type {
  public:
    EnvironmentType(): Type() {
    }

    ~EnvironmentType() {
    }

    void accept(tastr::ast::visitor::Visitor& visitor) const override final;
};

using EnvironmentTypePtr = EnvironmentType*;
using EnvironmentTypeUPtr = std::unique_ptr<EnvironmentType>;

} // namespace tastr::ast::node

#endif /* TASTR_AST_NODE_ENVIRONMENT_TYPE_H */
