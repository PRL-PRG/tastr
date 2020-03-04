#include "ast/BytecodeTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::BytecodeTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
