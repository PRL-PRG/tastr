#include "ast/VarargTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::VarargTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::VarargTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::VarargTypeNode::kind_ =
    tastr::ast::Node::Kind::VarargType;
