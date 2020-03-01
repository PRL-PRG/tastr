#ifndef TASTR_AST_COMPOSITE_TYPE_NODE_H
#define TASTR_AST_COMPOSITE_TYPE_NODE_H

#include "TypeNode.h"

namespace tastr::ast {

class CompositeTypeNode: public TypeNode {
  public:
    CompositeTypeNode(): TypeNode() {
    }

    CompositeTypeNode(const CompositeTypeNode& node): TypeNode(node) {
    }

    virtual ~CompositeTypeNode() {
    }

    virtual void accept(tastr::visitor::Visitor& visitor) const = 0;

    std::unique_ptr<CompositeTypeNode> clone() const {
        return std::unique_ptr<CompositeTypeNode>(this->clone_impl());
    }

  private:
    virtual CompositeTypeNode* clone_impl() const = 0;
};

using CompositeTypeNodePtr = CompositeTypeNode*;
using CompositeTypeNodeUPtr = std::unique_ptr<CompositeTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_COMPOSITE_TYPE_NODE_H */
