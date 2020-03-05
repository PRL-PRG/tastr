#include "ast/IntegerScalarTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::IntegerScalarTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::IntegerScalarTypeNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
