#include "ast/TopLevelNode.h"
#include "visitor/Visitor.h"

void tastr::ast::TopLevelNode::accept(tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
