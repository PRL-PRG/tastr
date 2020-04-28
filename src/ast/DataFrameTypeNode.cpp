#include "ast/DataFrameTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::DataFrameTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::DataFrameTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::DataFrameTypeNode::kind_ =
    tastr::ast::Node::Kind::DataFrameType;
