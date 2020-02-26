#ifndef R_TYPE_AST_NODE_COMPOSITE_TYPE_H
#define R_TYPE_AST_NODE_COMPOSITE_TYPE_H

#include "Type.h"

namespace rtype::ast::node {

class CompositeType: public Type {
  public:
    CompositeType(): Type() {
    }

    virtual ~CompositeType() {
    }

    virtual void accept(rtype::ast::visitor::TypeVisitor& visitor) const = 0;
};

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_COMPOSITE_TYPE_H */
