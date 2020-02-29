#ifndef R_TYPE_AST_NODE_ENVIRONMENT_TYPE_H
#define R_TYPE_AST_NODE_ENVIRONMENT_TYPE_H

#include "Type.h"

namespace rtype::ast::node {

class EnvironmentType final: public Type {
  public:
    EnvironmentType(): Type() {
    }

    ~EnvironmentType() {
    }

    void accept(rtype::ast::visitor::Visitor& visitor) const override final;
};

using EnvironmentTypePtr = EnvironmentType*;
using EnvironmentTypeUPtr = std::unique_ptr<EnvironmentType>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_ENVIRONMENT_TYPE_H */
