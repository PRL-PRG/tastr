#include "ast/PairlistTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::PairlistTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::PairlistTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::PairlistTypeNode::kind_ =
    tastr::ast::Node::Kind::PairlistType;
