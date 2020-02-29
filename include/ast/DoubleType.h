#ifndef TASTR_AST_DOUBLE_TYPE_H
#define TASTR_AST_DOUBLE_TYPE_H

#include "ScalarType.h"

namespace tastr::ast {

class DoubleType final: public ScalarType {
  public:
    DoubleType(): ScalarType() {
    }

    ~DoubleType() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using DoubleTypePtr = DoubleType*;
using DoubleTypeUPtr = std::unique_ptr<DoubleType>;

} // namespace tastr::ast

#endif /* TASTR_AST_DOUBLE_TYPE_H */
