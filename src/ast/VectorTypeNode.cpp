#include "ast/VectorTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::VectorTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::VectorTypeNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
