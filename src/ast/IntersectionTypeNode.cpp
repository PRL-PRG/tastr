#include "ast/IntersectionTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::IntersectionTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::IntersectionTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::IntersectionTypeNode::kind_ =
    tastr::ast::Node::Kind::IntersectionType;
