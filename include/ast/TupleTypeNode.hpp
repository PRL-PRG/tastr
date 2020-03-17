#ifndef TASTR_AST_TUPLE_TYPE_NODE_HPP
#define TASTR_AST_TUPLE_TYPE_NODE_HPP

#include "ast/Bracket.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class TupleTypeNode final
    : public TypeNode
    , public Bracketed {
  public:
    explicit TupleTypeNode(OperatorNodeUPtr opening_bracket,
                           OperatorNodeUPtr closing_bracket,
                           NodeUPtr elements)
        : TypeNode()
        , Bracketed(std::move(opening_bracket), std::move(closing_bracket))
        , elements_(std::move(elements)) {
    }

    ~TupleTypeNode() = default;

    TupleTypeNode(const TupleTypeNode& node)
        : TypeNode(node), Bracketed(node), elements_(node.elements_->clone()) {
    }

    TupleTypeNode(TupleTypeNode&& node)
        : TypeNode(std::move(node))
        , Bracketed(std::move(node))
        , elements_(std::move(node.elements_)) {
    }

    TupleTypeNode& operator=(const TupleTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        Bracketed::operator=(node);
        elements_ = node.elements_->clone();
        return *this;
    }

    TupleTypeNode& operator=(TupleTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        Bracketed::operator=(std::move(node));
        elements_ = std::move(node.elements_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<TupleTypeNode> clone() const {
        return std::unique_ptr<TupleTypeNode>(this->clone_impl());
    }

    bool is_tuple_type_node() const override final {
        return true;
    }

    Node& get_elements() const {
        return *elements_.get();
    }

  private:
    virtual TupleTypeNode* clone_impl() const override final {
        return new TupleTypeNode(*this);
    };

    NodeUPtr elements_;
};

using TupleTypeNodePtr = TupleTypeNode*;
using TupleTypeNodeUPtr = std::unique_ptr<TupleTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_TUPLE_TYPE_NODE_HPP */
