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
