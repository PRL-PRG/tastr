#include "ast/StructTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::StructTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
