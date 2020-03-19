#include "ast/KeywordNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::KeywordNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::KeywordNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::KeywordNode::kind_ =
    tastr::ast::Node::Kind::Keyword;
