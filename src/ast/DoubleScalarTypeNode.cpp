#include "ast/DoubleScalarTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::DoubleScalarTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::DoubleScalarTypeNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
