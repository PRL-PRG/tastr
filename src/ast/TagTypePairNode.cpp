#include "ast/TagTypePairNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::TagTypePairNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::TagTypePairNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
