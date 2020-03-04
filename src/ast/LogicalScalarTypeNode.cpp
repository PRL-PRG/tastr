#include "ast/LogicalScalarTypeNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::LogicalScalarTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
