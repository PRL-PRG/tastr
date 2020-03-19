#include "ast/GroupTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::GroupTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::GroupTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::GroupTypeNode::kind_ =
    tastr::ast::Node::Kind::GroupType;
