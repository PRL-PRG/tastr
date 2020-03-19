#include "ast/TopLevelNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::TopLevelNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::TopLevelNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::TopLevelNode::kind_ =
    tastr::ast::Node::Kind::TopLevel;
