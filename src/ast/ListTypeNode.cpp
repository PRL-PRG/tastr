#include "ast/ListTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::ListTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
