#include "ast/ComplexAScalarTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::ComplexAScalarTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::ComplexAScalarTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
