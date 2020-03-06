#include "ast/WeakReferenceTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::WeakReferenceTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::WeakReferenceTypeNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
