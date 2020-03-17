#include "ast/CommaSeparatorNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::CommaSeparatorNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::CommaSeparatorNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
