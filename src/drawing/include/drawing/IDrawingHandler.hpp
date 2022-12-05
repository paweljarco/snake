#pragma once

namespace drawing
{
class IDrawingHandler
{
public:
    virtual ~IDrawingHandler() = default;
    virtual void start() = 0;
};
} // namespace drawing
