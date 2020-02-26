#ifndef R_TYPE_AST_NODE_COMPLEX_TYPE_H
#define R_TYPE_AST_NODE_COMPLEX_TYPE_H

#include "ScalarType.h"

namespace rtype::ast::node {

class ComplexType: public ScalarType {
  public:
    ComplexType(): ScalarType() {
    }

    ~ComplexType() {
    }

    void accept(rtype::ast::visitor::TypeVisitor& visitor) const override;
};

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_COMPLEX_TYPE_H */
