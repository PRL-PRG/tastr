#include "ast/RawTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::RawTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
