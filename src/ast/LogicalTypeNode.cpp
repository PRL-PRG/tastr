#include "ast/LogicalTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::LogicalTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
