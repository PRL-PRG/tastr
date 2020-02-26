#ifndef R_TYPE_AST_NODE_TYPE_H
#define R_TYPE_AST_NODE_TYPE_H

#include "ast/node/Node.h"

namespace rtype::ast::node {

class Type: public Node {
  public:
    Type(): Node() {
    }

    virtual ~Type() {
    }

    virtual void accept(rtype::ast::visitor::Visitor& visitor) const = 0;
};

using TypePtr = Type*;
using TypeUPtr = std::unique_ptr<Type>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_TYPE_H */
