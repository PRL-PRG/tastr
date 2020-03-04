#include "ast/BytecodeTypeNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::BytecodeTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
