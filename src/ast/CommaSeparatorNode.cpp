#include "ast/CommaSeparatorNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::CommaSeparatorNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::CommaSeparatorNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::CommaSeparatorNode::kind_ =
    tastr::ast::Node::Kind::CommaSeparator;
