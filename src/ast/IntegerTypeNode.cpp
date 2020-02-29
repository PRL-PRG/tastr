#include "ast/IntegerTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::IntegerTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
