#include "ast/LogicalScalarTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::LogicalScalarTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::LogicalScalarTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
