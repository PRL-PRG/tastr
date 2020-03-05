#include "ast/ComplexScalarTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::ComplexScalarTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::ComplexScalarTypeNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
