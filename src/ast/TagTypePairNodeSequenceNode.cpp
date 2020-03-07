#include "ast/TagTypePairNodeSequenceNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::TagTypePairNodeSequenceNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::TagTypePairNodeSequenceNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
