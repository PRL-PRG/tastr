#include "ast/TagTypePairNodeSequenceNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::TagTypePairNodeSequenceNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::TagTypePairNodeSequenceNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
