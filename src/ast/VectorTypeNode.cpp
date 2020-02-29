#include "ast/VectorTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::VectorTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
