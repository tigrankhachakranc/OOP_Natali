#ifndef SLIDE_HPP
#define SLIDE_HPP

#include "ItemFactory.hpp"

class Slide {
    public:
        using SlideIterator = SlideType<std::shared_ptr<Item> >::iterator;

    public:
        Slide() = default;
    
    public:
        SlideType<std::shared_ptr<Item> > getSlide();         
        void addtoSlide(std::shared_ptr<Item> itemPtr);
        void removeFromSlide(ID id);
        std::shared_ptr<Item> getItem(ID id);
        // void setItem(Type type, ID id, Position pos, Attributes attributes);
        SlideIterator begin();
        SlideIterator end();

    private:
        SlideType<std::shared_ptr<Item> > slide_; 
        /// TODO: static or not?
        /// TODO: ID belongs to Item, not command or slide...
};

#endif // SLIDE_HPP