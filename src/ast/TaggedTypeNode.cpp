#include "ast/TaggedTypeNode.h"
#include "visitor/Visitor.h"

void tastr::ast::TaggedTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
