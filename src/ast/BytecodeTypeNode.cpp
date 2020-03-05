#include "ast/BytecodeTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::BytecodeTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::BytecodeTypeNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
