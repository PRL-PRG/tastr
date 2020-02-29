#include "ast/IdentifierNode.h"

#include "visitor/Visitor.h"

void tastr::ast::IdentifierNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
