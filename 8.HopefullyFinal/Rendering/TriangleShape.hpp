#ifndef TRIANGLE_SHAPE_HPP
#define TRIANGLE_SHAPE_HPP

#include "ShapeBase.hpp"
#include "IVisualDisplayable.hpp"

class TriangleShape : public ShapeBase, public IVisualDisplayable {
    public:
        std::unique_ptr<IShape> clone();
        void draw(QPainter* painter, std::shared_ptr<ItemBase> item);
};

#endif // TRIANGLE_SHAPE_HPP