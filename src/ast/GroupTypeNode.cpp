#include "ast/GroupTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::GroupTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
