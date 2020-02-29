#include "ast/UnionTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::UnionTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
