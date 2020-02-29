#ifndef TASTR_AST_ENVIRONMENT_TYPE_H
#define TASTR_AST_ENVIRONMENT_TYPE_H

#include "Type.h"

namespace tastr::ast {

class EnvironmentType final: public Type {
  public:
    EnvironmentType(): Type() {
    }

    ~EnvironmentType() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using EnvironmentTypePtr = EnvironmentType*;
using EnvironmentTypeUPtr = std::unique_ptr<EnvironmentType>;

} // namespace tastr::ast

#endif /* TASTR_AST_ENVIRONMENT_TYPE_H */
