#include "ast/PairlistTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::PairlistTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
