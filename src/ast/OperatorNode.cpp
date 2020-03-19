#include "ast/OperatorNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::OperatorNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::OperatorNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::OperatorNode::kind_ =
    tastr::ast::Node::Kind::Operator;
