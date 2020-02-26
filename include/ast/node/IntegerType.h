#ifndef R_TYPE_AST_NODE_INTEGER_TYPE_H
#define R_TYPE_AST_NODE_INTEGER_TYPE_H

#include "ScalarType.h"

namespace rtype::ast::node {

class IntegerType: public ScalarType {
  public:
    IntegerType(): ScalarType() {
    }

    ~IntegerType() {
    }

    void accept(rtype::ast::visitor::TypeVisitor& visitor) const override;
};

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_INTEGER_TYPE_H */
