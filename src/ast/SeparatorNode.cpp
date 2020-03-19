#include "ast/SeparatorNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::SeparatorNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::SeparatorNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::SeparatorNode::kind_ =
    tastr::ast::Node::Kind::Separator;
