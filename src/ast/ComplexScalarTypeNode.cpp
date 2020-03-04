#include "ast/ComplexScalarTypeNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::ComplexScalarTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
