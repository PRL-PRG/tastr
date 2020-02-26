#ifndef R_TYPE_AST_NODE_DOUBLE_TYPE_H
#define R_TYPE_AST_NODE_DOUBLE_TYPE_H

#include "ScalarType.h"

namespace rtype::ast::node {

class DoubleType: public ScalarType {
  public:
    DoubleType(): ScalarType() {
    }

    ~DoubleType() {
    }

    void accept(rtype::ast::visitor::TypeVisitor& visitor) const override;
};

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_DOUBLE_TYPE_H */
