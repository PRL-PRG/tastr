#include "ast/S4TypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::S4TypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::S4TypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::S4TypeNode::kind_ =
    tastr::ast::Node::Kind::S4Type;
