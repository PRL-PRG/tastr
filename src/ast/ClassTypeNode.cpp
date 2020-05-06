#include "ast/ClassTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::ClassTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::ClassTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::ClassTypeNode::kind_ =
    tastr::ast::Node::Kind::ClassType;
