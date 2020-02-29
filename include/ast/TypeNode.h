#ifndef TASTR_AST_TYPE_NODE_H
#define TASTR_AST_TYPE_NODE_H

#include "ast/Node.h"

namespace tastr::ast {

class TypeNode: public Node {
  public:
    TypeNode(): Node() {
    }

    virtual ~TypeNode() {
    }

    virtual void accept(tastr::visitor::Visitor& visitor) const = 0;
};

using TypeNodePtr = TypeNode*;
using TypeNodeUPtr = std::unique_ptr<TypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_TYPE_NODE_H */
