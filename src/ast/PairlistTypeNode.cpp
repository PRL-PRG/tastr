#include "ast/PairlistTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::PairlistTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::PairlistTypeNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
