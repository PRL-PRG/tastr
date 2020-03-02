#include "ast/TypeNodeSequenceNode.h"

#include "visitor/Visitor.h"

void tastr::ast::TypeNodeSequenceNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
