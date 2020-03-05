#include "ast/LogicalScalarTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::LogicalScalarTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::LogicalScalarTypeNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
