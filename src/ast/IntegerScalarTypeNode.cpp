#include "ast/IntegerScalarTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::IntegerScalarTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
