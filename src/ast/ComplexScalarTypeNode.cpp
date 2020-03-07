#include "ast/ComplexScalarTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::ComplexScalarTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::ComplexScalarTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
