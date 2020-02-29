#include "ast/ExpressionTypeNode.h"
#include "visitor/Visitor.h"

void tastr::ast::ExpressionTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
