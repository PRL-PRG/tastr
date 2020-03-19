#include "ast/NAScalarTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::NAScalarTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::NAScalarTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::NAScalarTypeNode::kind_ =
    tastr::ast::Node::Kind::NAScalarType;
