#include "ast/IntegerAScalarTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::IntegerAScalarTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::IntegerAScalarTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::IntegerAScalarTypeNode::kind_ =
    tastr::ast::Node::Kind::IntegerAScalarType;
