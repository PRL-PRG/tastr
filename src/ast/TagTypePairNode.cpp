#include "ast/TagTypePairNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::TagTypePairNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::TagTypePairNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
