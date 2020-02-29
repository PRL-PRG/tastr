#ifndef TASTR_AST_NODE_COMPLEX_TYPE_H
#define TASTR_AST_NODE_COMPLEX_TYPE_H

#include "ScalarType.h"

namespace tastr::ast::node {

class ComplexType final: public ScalarType {
  public:
    ComplexType(): ScalarType() {
    }

    ~ComplexType() {
    }

    void accept(tastr::ast::visitor::Visitor& visitor) const override final;
};

using ComplexTypePtr = ComplexType*;
using ComplexTypeUPtr = std::unique_ptr<ComplexType>;
} // namespace tastr::ast::node

#endif /* TASTR_AST_NODE_COMPLEX_TYPE_H */
