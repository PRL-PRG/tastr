#include "ast/TagTypePairNode.hpp"
#include "visitor/Visitor.hpp"

void tastr::ast::TagTypePairNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
