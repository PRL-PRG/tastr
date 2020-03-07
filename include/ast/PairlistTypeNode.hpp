#ifndef TASTR_AST_PAIRLIST_TYPE_NODE_HPP
#define TASTR_AST_PAIRLIST_TYPE_NODE_HPP

#include "ast/Name.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class PairlistTypeNode final
    : public TypeNode
    , public Name {
  public:
    explicit PairlistTypeNode(const std::string& name): TypeNode(), Name(name) {
    }

    ~PairlistTypeNode() = default;

    PairlistTypeNode(const PairlistTypeNode& node): TypeNode(node), Name(node) {
    }

    PairlistTypeNode(PairlistTypeNode&& node)
        : TypeNode(std::move(node)), Name(std::move(node)) {
    }

    PairlistTypeNode& operator=(const PairlistTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        Name::operator=(node);
        return *this;
    }

    PairlistTypeNode& operator=(PairlistTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        Name::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<PairlistTypeNode> clone() const {
        return std::unique_ptr<PairlistTypeNode>(this->clone_impl());
    }

    bool is_pairlist_type_node() const override final {
        return true;
    }

  private:
    virtual PairlistTypeNode* clone_impl() const override final {
        return new PairlistTypeNode(*this);
    };
};

using PairlistTypeNodePtr = PairlistTypeNode*;
using PairlistTypeNodeUPtr = std::unique_ptr<PairlistTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_PAIRLIST_TYPE_NODE_HPP */
