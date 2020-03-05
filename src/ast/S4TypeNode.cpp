#include "ast/S4TypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::S4TypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::S4TypeNode::accept(tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
