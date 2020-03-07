#include "ast/TupleTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::TupleTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::TupleTypeNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
