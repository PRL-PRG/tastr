#ifndef TASTR_AST_NODE_COMPOSITE_TYPE_H
#define TASTR_AST_NODE_COMPOSITE_TYPE_H

#include "Type.h"

namespace tastr::ast::node {

class CompositeType: public Type {
  public:
    CompositeType(): Type() {
    }

    virtual ~CompositeType() {
    }

    virtual void accept(tastr::ast::visitor::Visitor& visitor) const = 0;
};

using CompositeTypePtr = CompositeType*;
using CompositeTypeUPtr = std::unique_ptr<CompositeType>;

} // namespace tastr::ast::node

#endif /* TASTR_AST_NODE_COMPOSITE_TYPE_H */
