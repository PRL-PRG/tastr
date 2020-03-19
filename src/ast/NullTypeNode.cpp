#include "ast/NullTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::NullTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::NullTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::NullTypeNode::kind_ =
    tastr::ast::Node::Kind::NullType;
