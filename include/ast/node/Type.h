#ifndef TASTR_AST_NODE_TYPE_H
#define TASTR_AST_NODE_TYPE_H

#include "ast/node/Node.h"

namespace tastr::ast::node {

class Type: public Node {
  public:
    Type(): Node() {
    }

    virtual ~Type() {
    }

    virtual void accept(tastr::ast::visitor::Visitor& visitor) const = 0;
};

using TypePtr = Type*;
using TypeUPtr = std::unique_ptr<Type>;

} // namespace tastr::ast::node

#endif /* TASTR_AST_NODE_TYPE_H */
