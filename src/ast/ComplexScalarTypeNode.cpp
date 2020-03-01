#include "ast/ComplexScalarTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::ComplexScalarTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
