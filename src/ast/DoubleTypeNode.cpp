#include "ast/DoubleTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::DoubleTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
