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

const tastr::ast::Node::Kind tastr::ast::WeakReferenceTypeNode::kind_ =
    tastr::ast::Node::Kind::WeakReferenceType;
