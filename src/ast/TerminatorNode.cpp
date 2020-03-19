#include "ast/TerminatorNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::TerminatorNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::TerminatorNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::TerminatorNode::kind_ =
    tastr::ast::Node::Kind::Terminator;
