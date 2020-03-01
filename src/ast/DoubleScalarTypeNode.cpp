#include "ast/DoubleScalarTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::DoubleScalarTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
