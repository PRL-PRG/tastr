#include "ast/FunctionTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::FunctionTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::FunctionTypeNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
