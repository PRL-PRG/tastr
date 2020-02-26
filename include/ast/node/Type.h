#ifndef R_TYPE_AST_NODE_TYPE_H
#define R_TYPE_AST_NODE_TYPE_H

#include <ostream>

namespace rtype::ast::visitor {
class TypeVisitor;
}

namespace rtype::ast::node {

class Type {
  public:
    Type() {
    }

    virtual ~Type() {
    }

    virtual void accept(rtype::ast::visitor::TypeVisitor& visitor) const = 0;
};

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_TYPE_H */
