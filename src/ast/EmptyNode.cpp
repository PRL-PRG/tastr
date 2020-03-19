#include "ast/EmptyNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::EmptyNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::EmptyNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::EmptyNode::kind_ =
    tastr::ast::Node::Kind::Empty;
