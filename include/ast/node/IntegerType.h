#ifndef R_TYPE_AST_NODE_INTEGER_TYPE_H
#define R_TYPE_AST_NODE_INTEGER_TYPE_H

#include "ScalarType.h"

namespace rtype::ast::node {

class IntegerType final: public ScalarType {
  public:
    IntegerType(): ScalarType() {
    }

    ~IntegerType() {
    }

    void accept(rtype::ast::visitor::Visitor& visitor) const override final;
};

using IntegerTypePtr = IntegerType*;
using IntegerTypeUPtr = std::unique_ptr<IntegerType>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_INTEGER_TYPE_H */
