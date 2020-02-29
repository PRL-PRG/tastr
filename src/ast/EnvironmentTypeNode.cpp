#include "ast/EnvironmentTypeNode.h"
#include "visitor/Visitor.h"

void tastr::ast::EnvironmentTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
