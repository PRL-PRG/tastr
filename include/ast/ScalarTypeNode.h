#ifndef TASTR_AST_SCALAR_TYPE_NODE_H
#define TASTR_AST_SCALAR_TYPE_NODE_H

#include "TypeNode.h"

namespace tastr::ast {

class ScalarTypeNode: public TypeNode {
  public:
    ScalarTypeNode(): TypeNode() {
    }

    virtual ~ScalarTypeNode() {
    }

    virtual void accept(tastr::visitor::Visitor& visitor) const = 0;
};

using ScalarTypeNodePtr = ScalarTypeNode*;
using ScalarTypeNodeUPtr = std::unique_ptr<ScalarTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_SCALAR_TYPE_NODE_H */
