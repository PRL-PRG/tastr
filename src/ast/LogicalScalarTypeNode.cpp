#include "ast/LogicalScalarTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::LogicalScalarTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
