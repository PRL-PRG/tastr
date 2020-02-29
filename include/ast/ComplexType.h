#ifndef TASTR_AST_COMPLEX_TYPE_H
#define TASTR_AST_COMPLEX_TYPE_H

#include "ScalarType.h"

namespace tastr::ast {

class ComplexType final: public ScalarType {
  public:
    ComplexType(): ScalarType() {
    }

    ~ComplexType() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using ComplexTypePtr = ComplexType*;
using ComplexTypeUPtr = std::unique_ptr<ComplexType>;
} // namespace tastr::ast

#endif /* TASTR_AST_COMPLEX_TYPE_H */
