#include "ast/VarargTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::VarargTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
