#include "ast/VectorTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::VectorTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::VectorTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::VectorTypeNode::kind_ =
    tastr::ast::Node::Kind::VectorType;
