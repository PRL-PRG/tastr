#include "ast/RawScalarTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::RawScalarTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
