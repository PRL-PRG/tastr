#include "ast/TagTypePairNodeSequenceNode.h"

#include "visitor/Visitor.h"

void tastr::ast::TagTypePairNodeSequenceNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
