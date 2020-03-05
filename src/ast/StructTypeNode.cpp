#include "ast/StructTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::StructTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::StructTypeNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
