#include "ast/WeakReferenceTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::WeakReferenceTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::WeakReferenceTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
