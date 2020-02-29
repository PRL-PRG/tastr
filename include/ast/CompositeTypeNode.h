#ifndef TASTR_AST_COMPOSITE_TYPE_NODE_H
#define TASTR_AST_COMPOSITE_TYPE_NODE_H

#include "TypeNode.h"

namespace tastr::ast {

class CompositeTypeNode: public TypeNode {
  public:
    CompositeTypeNode(): TypeNode() {
    }

    virtual ~CompositeTypeNode() {
    }

    virtual void accept(tastr::visitor::Visitor& visitor) const = 0;
};

using CompositeTypeNodePtr = CompositeTypeNode*;
using CompositeTypeNodeUPtr = std::unique_ptr<CompositeTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_COMPOSITE_TYPE_NODE_H */
