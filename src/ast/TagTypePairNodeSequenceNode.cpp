#include "ast/TagTypePairNodeSequenceNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::TagTypePairNodeSequenceNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
