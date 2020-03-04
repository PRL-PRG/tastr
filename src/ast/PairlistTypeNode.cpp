#include "ast/PairlistTypeNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::PairlistTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
