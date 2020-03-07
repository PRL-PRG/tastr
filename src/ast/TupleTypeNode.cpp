#include "ast/TupleTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::TupleTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::TupleTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
