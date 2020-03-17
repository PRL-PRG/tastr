#include "ast/ParameterNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::ParameterNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::ParameterNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
