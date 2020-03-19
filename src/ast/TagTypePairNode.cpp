#include "ast/TagTypePairNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::TagTypePairNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::TagTypePairNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::TagTypePairNode::kind_ =
    tastr::ast::Node::Kind::TagTypePair;
