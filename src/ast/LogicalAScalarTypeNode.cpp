#include "ast/LogicalAScalarTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::LogicalAScalarTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::LogicalAScalarTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
