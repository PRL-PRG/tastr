#include "ast/BytecodeTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::BytecodeTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::BytecodeTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
