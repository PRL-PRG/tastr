#include "ast/TagTypePairNode.h"
#include "visitor/Visitor.h"

void tastr::ast::TagTypePairNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
