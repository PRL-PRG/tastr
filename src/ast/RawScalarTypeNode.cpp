#include "ast/RawScalarTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::RawScalarTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::RawScalarTypeNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
