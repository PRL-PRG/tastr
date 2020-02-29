#include "ast/ComplexTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::ComplexTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
