#ifndef TASTR_AST_SCALAR_TYPE_H
#define TASTR_AST_SCALAR_TYPE_H

#include "Type.h"

namespace tastr::ast {

class ScalarType: public Type {
  public:
    ScalarType(): Type() {
    }

    virtual ~ScalarType() {
    }

    virtual void accept(tastr::visitor::Visitor& visitor) const = 0;
};

using ScalarTypePtr = ScalarType*;
using ScalarTypeUPtr = std::unique_ptr<ScalarType>;

} // namespace tastr::ast

#endif /* TASTR_AST_SCALAR_TYPE_H */
