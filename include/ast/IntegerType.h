#ifndef TASTR_AST_INTEGER_TYPE_H
#define TASTR_AST_INTEGER_TYPE_H

#include "ScalarType.h"

namespace tastr::ast {

class IntegerType final: public ScalarType {
  public:
    IntegerType(): ScalarType() {
    }

    ~IntegerType() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using IntegerTypePtr = IntegerType*;
using IntegerTypeUPtr = std::unique_ptr<IntegerType>;

} // namespace tastr::ast

#endif /* TASTR_AST_INTEGER_TYPE_H */
