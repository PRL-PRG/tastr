#ifndef TASTR_AST_NODE_INTEGER_TYPE_H
#define TASTR_AST_NODE_INTEGER_TYPE_H

#include "ScalarType.h"

namespace tastr::ast::node {

class IntegerType final: public ScalarType {
  public:
    IntegerType(): ScalarType() {
    }

    ~IntegerType() {
    }

    void accept(tastr::ast::visitor::Visitor& visitor) const override final;
};

using IntegerTypePtr = IntegerType*;
using IntegerTypeUPtr = std::unique_ptr<IntegerType>;

} // namespace tastr::ast::node

#endif /* TASTR_AST_NODE_INTEGER_TYPE_H */
