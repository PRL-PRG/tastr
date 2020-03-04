#include "ast/S4TypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::S4TypeNode::accept(tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
