#ifndef TASTR_AST_LIST_TYPE_NODE_HPP
#define TASTR_AST_LIST_TYPE_NODE_HPP

#include "ast/KeywordNode.hpp"
#include "ast/ParameterNode.hpp"
#include "ast/TypeNode.hpp"

namespace tastr {
namespace ast {

class ListTypeNode final: public TypeNode {
  public:
    explicit ListTypeNode(KeywordNodeUPtr keyword, ParameterNodeUPtr parameters)
        : TypeNode()
        , keyword_(std::move(keyword))
        , parameters_(std::move(parameters)) {
    }

    ~ListTypeNode() = default;

    ListTypeNode(const ListTypeNode& node)
        : TypeNode(node)
        , keyword_(node.keyword_->clone())
        , parameters_(node.parameters_->clone()) {
    }

    ListTypeNode(ListTypeNode&& node)
        : TypeNode(std::move(node))
        , keyword_(std::move(node.keyword_))
        , parameters_(std::move(node.parameters_)) {
    }

    ListTypeNode& operator=(const ListTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_->clone();
        parameters_ = node.parameters_->clone();
        return *this;
    }

    ListTypeNode& operator=(ListTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        parameters_ = std::move(node.parameters_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<ListTypeNode> clone() const {
        return std::unique_ptr<ListTypeNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

    KeywordNode& get_keyword() const {
        return *keyword_.get();
    }

    ParameterNode& get_parameters() const {
        return *parameters_.get();
    }

  private:
    virtual ListTypeNode* clone_impl() const override final {
        return new ListTypeNode(*this);
    };

    KeywordNodeUPtr keyword_;
    ParameterNodeUPtr parameters_;

    static const Kind kind_;
};

using ListTypeNodePtr = ListTypeNode*;
using ListTypeNodeUPtr = std::unique_ptr<ListTypeNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_LIST_TYPE_NODE_HPP */
